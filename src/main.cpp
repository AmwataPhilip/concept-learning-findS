/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/

#include "../include/findS.h"

int main(int argc, const char **argv)
{
    using namespace AMWPHI001;

    // TODO: find a way to not have to hard code these

    int attribNum = std::stoi(argv[1]);                              // User defined number of attributes in hypotheses
    std::string sky, airTemp, humidity, wind, water, forcast;        // Attributes for current training hypotheses
    strVec attribList{sky, airTemp, humidity, wind, water, forcast}; // Vector to hold all attributes

    Hypothesis example1(attribList, true), example2(attribList, true), example3(attribList, false), example4(attribList, true); // Training hypotheses contianing specified attributes
    std::vector<Hypothesis> exampleTable{example1, example2, example3, example4};                                               // Vector holding all training hypotheses objects

    Hypothesis hypothesis(attribList, true); // Initial hypothesis

    findS sFinder(hypothesis, exampleTable); // Instance of findS object
    sFinder.runFindS();                      // Run FindS algorithm on input data

    return 0;
}
