/*
 * fileIO.h
 *
 *  Created on: Jan 24, 2014
 *      Author: jigar
 */

#ifndef FILEIO_H_
#define FILEIO_H_
#include <iostream>
#include <fstream>
#include "../global.h"

char* readFileByBytes(char *);
void writeFileByBytes(unsigned char);
void writePrepare(char *fileName);
void closeFile();
void writeFullArray(char*, char*,int);
void printFileContents(char *fileName);


#endif /* FILEIO_H_ */
