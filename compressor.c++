#include <iostream>
#include <fstream>
#include <cstring>
#include <zlib.h>
using namespace std;

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

    uLongf outputSize = compressBound(inputSize);
    const int result = compress2((Bytef*) outputBuff, &outputSize, (const Bytef*) inputBuff, inputSize, Z_BEST_COMPRESSION);//used highest compression level to compress given file
    if(result != Z_OK){
        cerr << "ERROR: compression failed with code: " << result << "\n";
        delete[] inputBuff;
        delete[] outputBuff;
        return 1;
    }
//print evaluation metrics
    const double compressionRatio = (double) outputSize / (double) inputSize;
    cout << "Input size: " << inputSize << " bytes\n";
    cout << "Output size: " << outputSize << " bytes\n";
    cout << "Compression ratio: " << compressionRatio << " \n";

    char* decompressedBuff = new char[inputSize];
    uLongf decompressedSize = inputSize;
    const int decompResult = uncompress((Bytef*) decompressedBuff, &decompressedSize, (const Bytef*) outputBuff, outputSize);
    if(decompResult != Z_OK){
        cerr << "ERROR: decompression failed with code: " << decompResult << "\n";
        delete[] inputBuff;
        delete[] outputBuff;
        delete[] decompressedBuff;
        return 1;
    }

    if(decompressedSize != inputSize || memcmp(inputBuff, decompressedBuff, inputSize) != 0){
        cerr << "ERROR: decompressed data doesn't match with the input data\n";
        delete[] inputBuff;
        delete[] outputBuff;
        delete[] decompressedBuff;
        return 1;
    }

    cout << "Both compression and decompression are successful!\n";

    delete[] inputBuff;
    delete[] outputBuff;
    delete[] decompressedBuff;
    return 0;
}