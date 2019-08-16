/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/

#include "../include/findS.h"

using namespace AMWPHI001;

void findS::runFindS()
{
	Hypothesis localHypo = this->getHypothesis();
	std::vector<Hypothesis> localHypoVector = this->getExampleTable();
	for (auto hypothesis : localHypoVector)
	{
		if (hypothesis.getStatus())
		{
			for (size_t i = 0; i < hypothesis.size(); i++)
			{
			}
		}
	}
}

void Hypothesis::compareHypotheses(Hypothesis currentHypo, Hypothesis newHypo)
{
}
