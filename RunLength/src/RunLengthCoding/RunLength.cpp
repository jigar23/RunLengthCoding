//============================================================================
// Name        : RunLength.cpp
// Author      : Jigar Gada
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "RunLength.h"

/**
 * This function writes the count and the symbol
 * to the output file.
 */
void writeByte(unsigned char count, unsigned char val){
	//cout << count << " "<< val << endl;
	writeFileByBytes(count);
	writeFileByBytes(val);
}

/**
 * This function decoded the encoded file and outputs the
 * original file.
 * @params -
 * 1. input filename
 * 2. output filename
 */
void decodeRLFile(char *inputFileName, char *outputFileName){

	std::cout << "Decoding the file......." << endl;
	char* a = readFileByBytes(inputFileName);
	int size = FileSizeinBytes;
	//prepare the file for writing
	writePrepare(outputFileName);
//	cout << "Original File---->" << endl;
	int n = 0;
	while(n <= size){
		//read the count and write the symbol
		//count no. of times
		for(int i = 0; i < (unsigned char)a[n]; i++){
			writeFileByBytes(a[n+1]);

		}
		//increment by 2 and point to the next count.
		n = n + 2;
	}
	closeFile();
}

/**
 * This function encodes the original file using run length coding
 * and outputs the the encoded file
 * original file.
 * @params -
 * 1. input filename
 * 2. output filename
 */
void encodeRLFile(char *fileName, char *outputFileName){

	std::cout << "Encoding the file......." << endl;
	//Read the file and stor it in buffer a
	char* a = readFileByBytes(fileName);
	int size = FileSizeinBytes;

	writePrepare(outputFileName);
	int i;
		unsigned char count = 0;
		for(i = 1 ; i < size; i++){

			if(a[i] != a[i-1] || (count >= 254)){
				writeByte(count+1,a[i-1]);
				count = 0;
			}
			else{
				count++;
//				if(count > 126){
//					writeByte(count+1,a[i-1]);
//					count = 0;
//				}
			}
		}
		writeByte(count+1,(unsigned char)a[i-1]);
		closeFile();

//		int count1 = 0;
//		for(int i = 0; i < FileSizeinBytes; i=i+2){
//			count1 +=
//		}
}



