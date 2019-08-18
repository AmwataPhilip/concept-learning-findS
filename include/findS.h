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
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

namespace AMWPHI001
{
typedef std::vector<std::string>
	strVec;

class Hypothesis
{
private:
	strVec attributes;
	bool isPositive;

public:
	Hypothesis(strVec stringVector, bool hypoStatus) : attributes(stringVector), isPositive(hypoStatus) {}
	~Hypothesis() = default;

	Hypothesis compareHypotheses(std::vector<Hypothesis> exampleTable);

	strVec getAttibutes()
	{
		return this->attributes;
	}

	std::string getAttibute(int i)
	{
		return this->attributes[i];
	}

	bool getStatus()
	{
		return this->isPositive;
	}

	int size()
	{
		return this->attributes.size();
	}

	void setAttribute(std::string attrib, int index)
	{
		this->attributes[index] = attrib;
	}

	void setStatus(bool status)
	{
		this->isPositive = status;
	}

	void printHypothesis()
	{
		printf("< %s, %s, %s, %s, %s, %s >\n", this->getAttibute(0).c_str(), this->getAttibute(1).c_str(), this->getAttibute(2).c_str(), this->getAttibute(3).c_str(), this->getAttibute(4).c_str(), this->getAttibute(5).c_str());
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

	std::vector<Hypothesis> getExampleTable()
	{
		return this->trainingHypotheses;
	}

	Hypothesis getHypothesis()
	{
		return this->hypothesis;
	}

	Hypothesis runFindS();
};

};	 // namespace AMWPHI001
#endif // !FINDS_H
