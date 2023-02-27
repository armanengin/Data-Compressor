# Data-Compressor

## Explanation
This program compresses an input using zlib, and evaluates the compression task via informative printed metrics, such as inputFile size, compressedFile size and compression ratio. Moreover, **_after the compression process the program also decompress the compressed data and check if it is decompressed successfully_**.

## How to Use It
To use this program, you would need to have the zlib library installed and linked to your executable. For example, if you were using the g++ compiler on a Linux system, you could compile the program like this:

* g++ -o compress compress.c++ -lz


This would create an executable called compress that you could run like this:

* ./compress input_file

Where input_file is the path to the file you want to compress. The program would then print out the compression metrics.

## Sample Output
<img width="388" alt="Screen Shot 2023-02-28 at 02 41 44" src="https://user-images.githubusercontent.com/63503839/221714486-61395e3d-9136-46e9-bf6c-55a76b8c05fe.png" width="150" height="100">
