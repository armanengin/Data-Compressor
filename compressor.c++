#include <iostream>
#include <fstream>
#include <cstring>
#include <zlib.h>
#include <chrono>
#include <vector>
#include <math.h>

using namespace std;

vector<double> calculate_entropy(const vector<unsigned char>& data) {
    vector<int> freq(256, 0);
    for (unsigned char c : data) {
        freq[c]++;
    }

    vector<double> prob(256, 0);
    for (int i = 0; i < 256; i++) {
        prob[i] = (double)freq[i] / (double)data.size();
    }

    double entropy = 0;
    for (int i = 0; i < 256; i++) {
        if (prob[i] > 0) {
            entropy += prob[i] * log2(prob[i]);
        }
    }
    entropy = -entropy;
    double max_entropy = log2(data.size());
    double min_entropy = log2(1);
    vector<double> res = {entropy, max_entropy, min_entropy};
    return res;
}

int main(int argc, char* argv[]){
    if(argc != 2){//check if num of arguments are correct
        cerr << "Run program in the following format: " << argv[0] << "<inputFile>\n";
        return 1;
    }

    const char* inputFile = argv[1];
    ifstream in(inputFile, ios::binary);
    if(!in){
        cerr << "ERROR: Can't open inpput file " << inputFile << "\n";
        return 1;
    }
    in.seekg(0, ios::end);//make pointer point the end
    const streamsize inputSize = in.tellg();//get the position of the pointer
    in.seekg(0, ios::beg);//make pointer point the beginning position

    char* inputBuff = new char[inputSize];
    char* outputBuff = new char[compressBound(inputSize)];//allocate space for compressed file

    in.read(inputBuff, inputSize);//read the input file and store it into inputBuff

    vector<unsigned char> data(inputBuff, inputBuff + inputSize);
    vector<double> inputFile_entropy = calculate_entropy(data);

    uLongf outputSize = compressBound(inputSize);

    auto start_compression = chrono::high_resolution_clock::now();
    const int result = compress2((Bytef*) outputBuff, &outputSize, (const Bytef*) inputBuff, inputSize, Z_BEST_COMPRESSION);//used highest compression level to compress given file
    auto end_compression = chrono::high_resolution_clock::now();

    if(result != Z_OK){
        cerr << "ERROR: compression failed with code: " << result << "\n";
        delete[] inputBuff;
        delete[] outputBuff;
        return 1;
    }
//print evaluation metrics
    auto compression_time = chrono::duration_cast<chrono::milliseconds>(end_compression - start_compression).count();
    const double compressionRatio = (double) (inputSize - outputSize) / (double) inputSize;



    char* decompressedBuff = new char[inputSize];
    uLongf decompressedSize = inputSize;

    auto start_decompression = chrono::high_resolution_clock::now();
    const int decompResult = uncompress((Bytef*) decompressedBuff, &decompressedSize, (const Bytef*) outputBuff, outputSize);
    auto end_decompression = chrono::high_resolution_clock::now();

    auto decompressioin_time = chrono::duration_cast<chrono::milliseconds>(end_decompression - start_decompression).count();

    if(decompResult != Z_OK){
        cerr << "ERROR: decompression failed with code: " << decompResult << "\n";
        delete[] inputBuff;
        delete[] outputBuff;
        delete[] decompressedBuff;
        return 1;
    }

    bool is_data_integrity_ok = (decompressedSize == inputSize && memcmp(inputBuff, decompressedBuff, inputSize) == 0);
    if(!is_data_integrity_ok){
        cerr << "ERROR: decompressed data doesn't match with the input data\n";
        delete[] inputBuff;
        delete[] outputBuff;
        delete[] decompressedBuff;
        return 1;
    }
    cout << "Input size: " << inputSize << " bytes\n";
    cout << "Output size: " << outputSize << " bytes\n";
    cout << "Compression ratio: " << compressionRatio << " \n";
    cout << "Compression time: " << compression_time << " ms" << endl;
    cout << "Decompression time: " << decompressioin_time << " ms" << endl;
    cout << "max possible entropy of the input file: " << inputFile_entropy[1] << " min possible entropy: " << inputFile_entropy[2] << inputFile_entropy[1] << " real entropy: " << inputFile_entropy[0] << endl;
    cout << "Data integrity: " << (is_data_integrity_ok ? "SUCCESSFULL" : "CORRUPTED") << "\n";

    delete[] inputBuff;
    delete[] outputBuff;
    delete[] decompressedBuff;
    return 0;
}
