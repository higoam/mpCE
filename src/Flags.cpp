/*
 * Flags.cpp
 *
 *  Created on: 07/04/2017
 *      Author: higo
 */

#include "Flags.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

Flags::Flags() {
	// TODO Auto-generated constructor stub

}

Flags::~Flags() {
	// TODO Auto-generated destructor stub
}

bool Flags::checksFlags(int argc, char *argv[]){

	// Auxiliary Variables
	int i;
	size_t found;
	string auxS;
	string flag_command;
	string flag_value;


	if(checkInputFileFormat(string(argv[1])) == 0){

		cout << "Incorrect file extension" << endl;
		return false;
	}

	if( argc == 2 ){	// Check Help, Version and Standard Execution, 2 tickets

		if(string(argv[1]) == "--help"){

			printHelp();
			return false;

		} else if(string(argv[1]) == "--version"){

			printVersion();
			return false;

		} else {

			// Start Default Settings

		}

	}else{	 		// Check variations of executions, variations tickets


		for(i=2;i<argc;i++){

			if(string(argv[i]) == "--esbmc" ){
//				vet_flag[0]++;
			}else if(string(argv[i]) == "--cbmc" ){
//				vet_flag[1]++;
			}else{

				auxS = string(argv[i]);
				found = auxS.find("=");

				if(found!=string::npos){ // has sign =

//					flag_command = auxS.substr(0,found);
//					flag_value = auxS.substr(found+1,auxS.length());

					if(flag_command == "--start-value" ){


					}else if(flag_command == "--timeout-verification" ){


					}else {
							cout << "Flag unknown: " + string(argv[i]) << endl;
							return false;
					}

				}else{	// There is not =
					cout << "Flag unknown: " + string(argv[i]) << endl;
					return false;
				}

			}// End od ELSE to flags with sign "="

		} // End of FOR


	}

	return true;
}



int Flags::checkInputFileFormat(string str){

	int var = 1;

	return var;
}



void Flags::printHelp(){

}



void Flags::printVersion(){

}
