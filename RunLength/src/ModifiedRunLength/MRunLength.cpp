
#include "MRunLength.h"

/**
 * This function writes the count and the symbol
 * to the output file.
 */
void writeMRLBytes(unsigned char count, unsigned char val){
	//cout << count << " "<< val << endl;
	writeFileByBytes(count);
	writeFileByBytes(val);
}

/**
 * This function encodes the original file using modified run length coding
 * and outputs the the encoded file
 * original file.
 * @params -
 * 1. input filename
 * 2. output filename
 */
void encodeMRLFile(char *fileName, char *outputFileName){
	std::cout << "Encoding the file......." << endl;
	//Read the file and stor it in buffer a
	char* a = readFileByBytes(fileName);
	int size = FileSizeinBytes;

	//Prepare the file for writing (i.e open the file)
	writePrepare(outputFileName);
	int i;
	//note the *unsigned* --> range : 0-255
	unsigned char count = 0;
	for(i = 1;i < size; i++){
		//if previous value not equal to current value
		//or count > 125 (This is because we are adding 128 to the
		//the count, so max count value is 127
		if(a[i] != a[i-1] || (count >= 126)){
			//if the symbol has occurred multiple times
			if(count > 0){
				writeMRLBytes(128+count+1, a[i-1]);
				count = 0;
			}
			else{
				//check if MSB is 1
				//if 1, then write (128+1) and the value
				if(a[i-1] & 128) writeMRLBytes(128+1, a[i-1]);
				else writeFileByBytes(a[i-1]);
			}
		}
		else count++;
	}

	//for the last value
	if(count > 0) writeMRLBytes(128+count+1, a[i-1]);
	else{
		if(a[i-1] & 128) writeMRLBytes(128+1, a[i-1]);
		else writeFileByBytes(a[i-1]);
	}
	closeFile();
}

/**
 * This function decoded the encoded file by Modifed RL code
 * and outputs the original file.
 * @params -
 * 1. input filename
 * 2. output filename
 */
void decodeMRLFile(char *inputFileName, char *outputFileName){
	std::cout << "Decoding the file......." << endl;
	char* a = readFileByBytes(inputFileName);
	int size = FileSizeinBytes;
	//prepare the file for writing
	writePrepare(outputFileName);

	int n = 0;
	while(n < size){
		//check if MSB is 1
		if(128 & a[n]){
			//Not the *unsigned*
			//a[n] - 128 will give the count
			for(int i = 0; i < ((unsigned char)a[n] - 128); i++)
				writeFileByBytes(a[n+1]);
			//skip one value coz that value is written
			n = n + 2;
		}
		else{
			//this values occured just once and MSB was not 1.
			writeFileByBytes(a[n]);
			n++;
		}
	}
	closeFile();
}

