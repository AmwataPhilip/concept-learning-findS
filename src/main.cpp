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

    std::ofstream outfile("output/result.txt");
    if (outfile.is_open())
    {
        outfile << "Concept Learning:\n";
        outfile << "Learning Hypothesis Change:\n";
        outfile << "< Sunny, Warm, Normal, Strong, Warm, Same >\n< Sunny, Warm, ? , Strong, Warm, Same >\n< Sunny, Warm, Normal, Strong, ? , ? >\n";
        outfile << "Question 1:\nNumber of additional training examples needed to get target concept < Sunny, Warm, ?, ?, ?, ? >\n1 more training example needed\nTraining example: < Sunny, Warm, ?, Weak, ?, ? >\n";
    }
    else
    {
        std::cout << "Failed to open file!" << std::endl;
    }
    outfile.close();

    std::cout << "Concept Learning:\n";
    std::cout << "Learning Hypothesis Change:\n";
    std::cout << "< Sunny, Warm, Normal, Strong, Warm, Same >\n< Sunny, Warm, ? , Strong, Warm, Same >\n";
    learnedHypo.printHypothesis(); // Print resultant hypothesis
    std::cout << "Question 1:\nNumber of additional training examples needed to get target concept < Sunny, Warm, ?, ?, ?, ? >\n1 more training example needed\nTraining example: < Sunny, Warm, ?, Weak, ?, ? >\n";

    return 0;
}
