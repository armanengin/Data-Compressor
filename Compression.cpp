#include "Compression.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <zlib.h>
#include <chrono>
#include <vector>
#include <math.h>
#include <float.h>
using namespace std;

Compression::Compression(){}
Compression::~Compression(){}

vector<double> Compression::calculate_entropy(const vector<unsigned char>& data) {
    vector<int> freq(256, 0);
    cout << "File's Input: ";
    for (unsigned char c : data) {
        freq[c]++;
        cout << c;
    }
    vector<double> prob(256, 0);
    for (int i = 0; i < 256; i++) {
        prob[i] = (double)freq[i] / (double)data.size();
        //cout << prob[i] << endl;
    }

    double entropy = 0;
    for (int i = 0; i < 256; i++) {
        if (prob[i] > 0) {
            entropy += prob[i] * log2(prob[i]);
        }
    }
    entropy = -entropy;
    double max_entropy = data.size() != 0 ? log2(data.size()) : DBL_MAX;
    double min_entropy = log2(1);
    vector<double> res = {entropy, max_entropy, min_entropy};
    return res;
}

