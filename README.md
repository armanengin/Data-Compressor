# Data-Compressor

## Explanation
This program compresses an input using zlib, and evaluates the compression task via informative printed metrics, such as inputFile size, compressedFile size and compression ratio. Moreover, after the compression process the program also decompress the compressed data and check if it is decompressed successfully.

## How to Use It
To use this program, you would need to have the zlib library installed and linked to your executable. For example, if you were using the g++ compiler on a Linux system, you could compile the program like this:

* g++ -o compress compress.c++ -lz


This would create an executable called compress that you could run like this:

* ./compress input_file

Where input_file is the path to the file you want to compress. The program would then print out the compression metrics.

