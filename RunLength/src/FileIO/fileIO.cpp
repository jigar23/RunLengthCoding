

#include "fileIO.h"
#include <iostream>
#include <fstream>

//This is a global variable which stores the file Size
int FileSizeinBytes;
std::ofstream myFile;

using namespace std;

//int main(){
//
//	char fileName[] = "resources/text.dat";
//	char *memblock = readFileByBytes(fileName);
//
//	for(int i = 0; i < FileSizeinBytes; i++)
//		cout << i << ":" << (int)memblock[i] <<endl;
//}

char* readFileByBytes(char* fileName){
	//object of streampos which is returned by tellg();
		streampos size;
		  char * memblock;

		  //ios::ate-> point to end of file.
		  //ios::binary-> file is binary not text.
		  //ios::in -> read the file
		  ifstream file (fileName, ios::in|ios::binary|ios::ate);
		  if (file.is_open())
		  {
			//get the size of the file in bytes
		    size = file.tellg();
		    //assign memory where the data will be stored/
		    memblock = new char [size];
		    //again make the pointer point at the beginning of the file
		    file.seekg (0, ios::beg);
		    //read the file from beginnning to the size/
		    file.read (memblock, size);
		    //close the file and free the resources
		    file.close();

		    cout << "The entire file content is in memory" <<endl;
		    FileSizeinBytes = size;

//		    cout << "File Size : " << FileSizeinBytes << endl;
		    //delete[] memblock;
		  }
		  else {
			  cout << "Error: Unable to open file..!!!";

		  }

		  return memblock;
}


void writeFullArray(char* fileName, char* data, int size){
	ofstream file;
	file.open(fileName, ios::out|ios::binary);

	for(int i = 0; i < size; i++){
		file << data[i];
	}

	file.close();
}


/**
 * Open the file once.
 * @param-
 * 1. fileName : name of the file in which you
 * want to write
 */
void writePrepare(char *fileName){
	  //ios::app-> append to end of file.//No need to append
	  //ios::binary-> file is binary not text.
	  //ios::out -> write to the file
	  myFile.open(fileName, ios::out|ios::binary);
}

/**
 * write the file.
 * @param -
 * 1. char data : data you want to write in the file.
 */
void writeFileByBytes(unsigned char data){
			  myFile << data;
}

/**
 * Close the file once all write operations done.
 */
void closeFile(){
	myFile.close();
}

/**
 * Simply prints all the contents of the file
 */
void printFileContents(char *fileName){
	char *memblock = readFileByBytes(fileName);
	for(int i = 0; i < FileSizeinBytes; i++){
		cout << (int)memblock[i] << " ";
	}
	cout << endl;
}
