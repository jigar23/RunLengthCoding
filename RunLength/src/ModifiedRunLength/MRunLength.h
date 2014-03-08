/*
 * MRunLength.h
 *
 *  Created on: Feb 6, 2014
 *      Author: jigar
 */

#ifndef MRUNLENGTH_H_
#define MRUNLENGTH_H_

#include <iostream>
#include "../global.h"
#include "../FileIO/fileIO.h"
using namespace std;

void decodeMRLFile(char *inputFileName, char *outputFileName);
void encodeMRLFile(char *fileName, char *outputFileName);



#endif /* MRUNLENGTH_H_ */
