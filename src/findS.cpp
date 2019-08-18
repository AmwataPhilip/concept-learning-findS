/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/

#include "../include/findS.h"

std::string GENERAL = "?", SPECIFIC = "ɸ";

using namespace AMWPHI001;

Hypothesis Hypothesis::compareHypotheses(std::vector<Hypothesis> localExampleTable)
{
	Hypothesis localLearningHypo = localExampleTable[0];

	for (auto hypothesis : localExampleTable)
	{
		if (hypothesis.getStatus())
		{
			for (int i = 0; i < this->size(); i++)
			{
				if ((localLearningHypo.getAttibute(i) == hypothesis.getAttibute(i)) | localLearningHypo.getAttibute(i) == "?")
				{
					continue;
				}
				else
				{
					localLearningHypo.setAttribute(GENERAL, i);
				}
			}
		}
	}
	return localLearningHypo;
}

Hypothesis findS::runFindS()
{
	Hypothesis learningHypo = this->getHypothesis();
	std::vector<Hypothesis> localExampleTable = this->getExampleTable();
	Hypothesis learnedHypo = learningHypo.compareHypotheses(localExampleTable);

	return learnedHypo;
}
