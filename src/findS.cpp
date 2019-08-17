/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/

#include "../include/findS.h"

using namespace AMWPHI001;

void Hypothesis::compareHypotheses(Hypothesis learningHypo)
{
	for (size_t i = 0; i < learningHypo.size(); i++)
	{
		if (learningHypo.getAttibutes[i] == this->getAttibutes[i])
		{
			continue;
		}
		else
		{
			learningHypo.getAttibutes[i].setAttribute(this->getAttibutes[i], i);
		}
	}
}

void findS::runFindS()
{
	Hypothesis learningHypo = this->getHypothesis();
	std::vector<Hypothesis> localHypoVector = this->getExampleTable();
	for (auto hypothesis : localHypoVector)
	{
		if (hypothesis.getStatus())
		{
			for (size_t i = 0; i < hypothesis.size(); i++)
			{
				hypothesis.compareHypotheses(learningHypo);
			}
		}
	}

	hypothesis.printHypothesis();
}
