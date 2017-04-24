/*
 * RunAlgorithm.cpp
 *
 *  Created on: 07/04/2017
 *      Author: higo
 */

#include "RunAlgorithm.h"
#include "SetExperiments.h"



using namespace std;
#include <iostream>
#include <fstream>
//#include <sstream>
//#include <stdlib.h>
//#include <list>

//#include "Set.h"
//#include "Tcexamples.h"
//#include "Runalgorithm.h"





RunAlgorithm::RunAlgorithm() {
	// TODO Auto-generated constructor stub

}

RunAlgorithm::~RunAlgorithm() {
	// TODO Auto-generated destructor stub
}

int RunAlgorithm::checksInputFile(SetExperiments experiment){

	string file_original = "";
	char letter;
	ifstream file;

	string nameFile = experiment.nameInputFile;		// Get name file
	file.open(nameFile.c_str());					// Open File

	// Opens the original function file
	if(!file.is_open( )){							// verifier if file open
		cout<<"Could not open file with function!\n";
		file.clear( ); //reseta o objeto leitura, para limpar memória do sistema}
	}

	// Loads the file into string
	while (file.get(letter)) {
		file_original = file_original + letter;
	}


	cout << file_original << endl;


	int var;

	return var;
}
