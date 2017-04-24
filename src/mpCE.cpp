//============================================================================
// Name        : mpCE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include "Flags.h"
#include "SetExperiments.h"
#include "RunAlgorithm.h"

using namespace std;

int main(int argc, char *argv[ ]) {

	Flags inputFlags;
	SetExperiments experiment;
	RunAlgorithm run;

	//Check input flags and Prepares the inputs to the experiment
	if(inputFlags.checksFlags(argc,argv)){

		experiment.inputForm = inputFlags.inputForm;

	}else{
		return 0;
	}

	//Check input file
	if(run.checksInputFile(experiment)){



	}else{
		return 0;
	}

	cout << "FIM!!!" << endl;
	return 0;
}
