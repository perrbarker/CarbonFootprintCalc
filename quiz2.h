/****************************************************************
File: quiz2.cpp
Description: declares the functions that create and supply the quiz app
Author: Kyler Ross
Class: CSCI 120
Date:12/3/15

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#ifndef QUIZ2_H
#define QUIZ2_H

using namespace std;

struct Question
{
	//the actual question
	string q;
	//whether or not the question was used
	bool used;
	//answer to the question
	char key;
	//all options: a b c d for each question
	string possibilities[4];
};

class Quiz
{
public:

	Quiz();

	//checks the user's answers vs the correct answers
	string checkAnswers(vector<char>);
	//makes sure a question can't be used twice
	void setUsed(int index);
	//checks if a question was already used
	bool checkUsed(int index);

	//outputting a question which is widget friendly
	string printQuestion();
	string printFirstP();
	string printSecondP();
	string PrintThirdP();
	string printFourthP();

	//initializes all question structs within an array of questions
	void setQuestions();
	//takes in vector from calculator frame and compares it to answers on file
	void setPlayerAnswers(int index, char answer);
	//sets a vector full of correct answers keys
	void setKeys(int index);
	//randomized questions are asked
	void askQuestion();

private:
	//variable for the selected question
	int qSelect;
	//stores the correct answers
	vector<char>quizKeys;
	//stores all the questions
	Question allQuestions[37];


};
#endif