#include <iostream>
#include "RunLengthCoding/RunLength.h"
#include "ModifiedRunLength/MRunLength.h"
void printFileSize(long int, long int);

using namespace std;

int main() {

	//Encode the file
//	char fileName[] = "resources/binary.dat";
	cout << "-----------------------------" << endl;
	cout << "Enter the *full* file Path with name: " << endl;
	char fileName[256];
	cin.getline(fileName,256);

	char outPutfile[] = "default.encoded";
	long int encodedFileSize,originalFileSize;
	char encodedFile[] = "default.encoded";
	char outPutfileOrig[] = "default.decoded";
	int flag = 0;


	while(flag == 0){
		int k;
		cout << "Enter" << endl << "1. Run Length Coding" << endl
				<< "2. Modified Run Length coding" << endl;
		cin >> k;
		switch(k){
		case 1:
			cout << "Run Length Coding details are as follows:" << endl;
			cout << endl;
			cout << "Encoded data is stored in *default.encoded*" << endl;
			cout <<"Decoded data recovered back in *default.decoded*" << endl;
			cout << endl ;
			encodeRLFile(fileName,outPutfile);
			originalFileSize = FileSizeinBytes;

			//	decode the file
//			char encodedFile[] = "resources/default.encoded";
//			char outPutfileOrig[] = "resources/default.decoded";
			decodeRLFile(encodedFile,outPutfileOrig);
			encodedFileSize = FileSizeinBytes;

			flag = 1;
			break;

		case 2:
			cout << "Modified Run Length Coding details are as follows:" << endl;
			cout << endl;
			cout << "Encoded data is stored in *default.encoded*" << endl;
			cout <<"Decoded data recovered back in *default.decoded*" << endl;
			cout << endl ;
			encodeRLFile(fileName,outPutfile);
			originalFileSize = FileSizeinBytes;

			//	decode the file
//			char encodedFile[] = "resources/default.encoded";
//			char outPutfileOrig[] = "resources/default.decoded";
			decodeRLFile(encodedFile,outPutfileOrig);
			encodedFileSize = FileSizeinBytes;

			flag = 1;
			break;

		default:
			cout << "Invalid Entry..!!!!" << endl;
			cout << "Try Again" << endl;
		}
	}
	printFileSize(encodedFileSize,originalFileSize);

	return 0;
}


void printFileSize(long int encodedFileSize, long int originalFileSize){
	cout << endl;
	cout << "**********************************" << endl << endl;
	cout << "Original File size   : " << originalFileSize << " bytes" << endl;
	cout << "Compressed File size : " << encodedFileSize << " bytes" << endl;
	cout << "Compression Ratio    : " << (float)encodedFileSize/originalFileSize*100 << "%" << endl << endl;
	cout << "**********************************" << endl;
}

