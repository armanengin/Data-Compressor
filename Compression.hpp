#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <vector>
using namespace std;

class Compression{
public:
    Compression();
    ~Compression();
    
    static vector<double> calculate_entropy(const vector<unsigned char>& data);
};

#endif // COMPRESSION_HPP
