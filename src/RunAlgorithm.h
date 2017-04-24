/*
 * RunAlgorithm.h
 *
 *  Created on: 07/04/2017
 *      Author: higo
 */

#ifndef RUNALGORITHM_H_
#define RUNALGORITHM_H_

#include "SetExperiments.h"

class RunAlgorithm {
public:
	RunAlgorithm();
	virtual ~RunAlgorithm();
	int checksInputFile(SetExperiments experiment);

};

#endif /* RUNALGORITHM_H_ */
