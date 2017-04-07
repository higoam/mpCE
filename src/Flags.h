/*
 * Flags.h
 *
 *  Created on: 07/04/2017
 *      Author: higo
 */

#ifndef FLAGS_H_
#define FLAGS_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Flags {
public:
	Flags();
	virtual ~Flags();

	bool checksFlags(int argc, char *argv[]);
	int checkInputFileFormat(string str);
	void printHelp();
	void printVersion();

};

#endif /* FLAGS_H_ */
