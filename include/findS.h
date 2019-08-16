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

typedef std::vector<std::string> strVec;

class Hypothesis
{
private:
	strVec attributes;
	bool isPositive;

public:
	Hypothesis(strVec stringVector, bool hypoStatus) : attributes(stringVector), isPositive(hypoStatus) {}
	~Hypothesis() = default;

	bool compareHypotheses(Hypothesis hypo1, Hypothesis hypo2);
};

class findS
{
private:
	Hypothesis hypothesis;
	std::vector<Hypothesis> trainingHypotheses;

public:
	findS(Hypothesis hypo, std::vector<Hypothesis> exampleTable) : hypothesis(hypo), trainingHypotheses(exampleTable) {}
	~findS() = default;

	void runFindS(std::vector<Hypothesis> exampleTable);
};

}; // namespace AMWPHI001

#endif // !FINDS_H
