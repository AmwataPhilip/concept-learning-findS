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
    std::string GENERAL = "?", SPECIFIC = "ɸ";
    // TODO: find a way to not have to hard code these
    // std::string sky, airTemp, humidity, wind, water, forcast;        // Attributes for current training hypotheses
    strVec learningAttribList{SPECIFIC, SPECIFIC, SPECIFIC, SPECIFIC, SPECIFIC, SPECIFIC}; // Vector contains attributes that will be modieifed to get target hypothesis
    strVec targetAttribList{"Sunny", "Warm", GENERAL, GENERAL, GENERAL, GENERAL};          // Vector contains attributes that are the constraints to get the target hypothesis
    Hypothesis learningHypothesis(learningAttribList, true);                               // Learning hypothesis
    Hypothesis targetHypothesis(targetAttribList, true);                                   // Target hypothesis

    strVec attribList1{"Sunny", "Warm", "Normal", "Strong", "Warm", "Same"};
    strVec attribList2{"Sunny", "Warm", "High", "Strong", "Warm", "Same"};
    strVec attribList3{"Rainy", "Cold", "High", "Strong", "Warm", "Change"};
    strVec attribList4{"Sunny", "Warm", "Normal", "Strong", "Cool", "Change"};
    Hypothesis example1(attribList1, true), example2(attribList2, true), example4(attribList4, true); // Training hypotheses contianing specified attributes
    std::vector<Hypothesis> exampleTable{example1, example2, example4};                               // Vector holding all training hypotheses objects

    findS sFinder(learningHypothesis, exampleTable); // Instance of findS object

    Hypothesis learnedHypo = sFinder.runFindS(); // Run FindS algorithm on input data and store resultant hypothesis in var learnedHypo

    learnedHypo.printHypothesis(); // Print resultant hypothesis

    std::ofstream outfile;
    outfile.open("../output/result.txt");
    if(outfile.is_open()){
        outfile << "Question 1: Number of additional training examples needed to get target concept < Sunny, Warm, ?, ?, ?, ? >\n1 more training example needed\nTraining example: < Sunny, Warm, ?, Strong, ?, ? >\n";
    }else{
        std::cout << "Failed to open file!\n";
    }
    outfile.close();

    std::cout << "Question 1:\nNumber of additional training examples needed to get target concept < Sunny, Warm, ?, ?, ?, ? >\n1 more training example needed\nTraining example: < Sunny, Warm, ?, Strong, ?, ? >\n";

    return 0;
}
