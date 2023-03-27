# Data-Compressor with New Metrics and Unit Testing

## Explanation
This program presents detailed insights on zlib performance by providing more metrics compared to the evlaution task.
This program compresses an input file using zlib, and evaluates the compression task via informative printed metrics, such as **_inputFile size, compressed file size, compression ratio, compression time, decompression time, entropy values and data integrity_**.

## How to Use It
To use this program, you would need to have the zlib library installed and linked to your executable. For example, if you were using the g++ compiler on a Linux system, you could compile the program like this:

* g++ -std=c++14 -o exe main.cpp Compression.cpp -lz 


This would create an executable called exe that you could run like this:

* ./exe input_file

Where input_file is the path to the file you want to compress. The program would then print out the compression metrics.

### Unit Testing
* g++ -std=c++14 -o test unit_test.cpp Compression.cpp -lz -lgtest

This would create an executable called test that you could run like this:

* ./test

## Sample Outputs
<img width="503" alt="Screen Shot 2023-03-20 at 02 19 09" src="https://user-images.githubusercontent.com/63503839/226222446-09bddc0b-ecd2-45d6-bcba-1f971dd93f1d.png">
<img width="374" alt="Screen Shot 2023-03-26 at 17 51 35" src="https://user-images.githubusercontent.com/63503839/227884301-ef328c7d-b340-4372-99ee-c0f8f4b1d980.png">
<img width="364" alt="Screen Shot 2023-03-26 at 17 51 47" src="https://user-images.githubusercontent.com/63503839/227884325-f5c3b7c7-d808-458e-ad29-aa7449d57663.png">
