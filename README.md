# Data-Compressor With Detailed Metrics

## Explanation
This program presents detailed insights on zlib performance by providing more metrics compared to the evlaution task.
This program compresses an input using zlib, and evaluates the compression task via informative printed metrics, such as **_inputFile size, compressed file size, compression ratio, compression time, decompression time, entropy values and data integrity_**.

## How to Use It
To use this program, you would need to have the zlib library installed and linked to your executable. For example, if you were using the g++ compiler on a Linux system, you could compile the program like this:

* g++ -std=c++11 -o compress compress.c++ -lz


This would create an executable called compress that you could run like this:

* ./compress input_file

Where input_file is the path to the file you want to compress. The program would then print out the compression metrics.

## Sample Output
<img width="503" alt="Screen Shot 2023-03-20 at 02 19 09" src="https://user-images.githubusercontent.com/63503839/226222446-09bddc0b-ecd2-45d6-bcba-1f971dd93f1d.png">
