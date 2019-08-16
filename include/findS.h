/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/

#ifndef FINDS_H
#define FINDS_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

namespace AMWPHI001
{

enum attributeType
{
	GENERAL = '?',
	SPECIFIC = 'ɸ'
};

typedef std::vector<std::string> strVec;

class Hypothesis
{
private:
	strVec attributes;
	bool isPositive;

public:
	Hypothesis(strVec stringVector, bool hypoStatus) : attributes(stringVector), isPositive(hypoStatus) {}
	~Hypothesis() = default;

	void compareHypotheses(Hypothesis currentHypo, Hypothesis newHypo);

	strVec getAttibutes()
	{
		return this->attributes;
	}

	bool getStatus()
	{
		return this->isPositive;
	}

	int size()
	{
		return this->attributes.size();
	}

	//TODO: overload [] operator for this class to return attributes at specified index
};

class findS
{
private:
	Hypothesis hypothesis;
	std::vector<Hypothesis> trainingHypotheses;

public:
	findS(Hypothesis hypo, std::vector<Hypothesis> exampleTable) : hypothesis(hypo), trainingHypotheses(exampleTable) {}
	~findS() = default;

	void runFindS();

	std::vector<Hypothesis> getExampleTable()
	{
		return this->trainingHypotheses;
	}

	Hypothesis getHypothesis()
	{
		return this->hypothesis;
	}
};

}; // namespace AMWPHI001

#endif // !FINDS_H
