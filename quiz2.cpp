/****************************************************************
File: quiz2.cpp
Description: Definitions of the functions that create and supply the quiz app
Author: Kyler Ross
Class: CSCI 120
Date:12/3/15

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
#include "quiz2.h"



//default contstructor
Quiz::Quiz()
{
	
}



//Passes the user's answers from calculator frame and checks them
string Quiz::checkAnswers(vector<char>userAnswers)
{
	//counts the number of correct answers
	int counter = 0;
	for (int i = 0; i < 14; i++)
	{
		
		if (userAnswers.at(i) == quizKeys.at(i))
		{
			counter++;
		}
		}
	//returns the number correct 
	switch (counter){
	case 0: return "0"; break;
	case 1: return "1"; break;
	case 2: return "2"; break;
	case 3: return "3"; break;
	case 4: return "4"; break;
	case 5: return "5"; break;
	case 6: return "6"; break;
	case 7: return "7"; break;
	case 8: return "8"; break;
	case 9: return "9"; break;
	case 10: return "10"; break;
	case 11: return "11"; break;
	case 12: return "12"; break;
	case 13: return "13"; break;
	case 14: return "14"; break;
	case 15: return "15"; break;

}
}

//Sets questions to used
void Quiz::setUsed(int index)
{
	allQuestions[index].used = true;
}

//checks if question is used
bool Quiz::checkUsed(int index)
{
	if (allQuestions[index].used == true)
	{
		return true;
	}
	else
		return false;
}

//returns the question as a string
string Quiz::printQuestion()
{
	allQuestions[qSelect].used = true;
	return allQuestions[qSelect].q;
}

//returns the possible answers as string
string Quiz::printFirstP()
{
	return allQuestions[qSelect].possibilities[0];
}
string Quiz::printSecondP()
{
	return allQuestions[qSelect].possibilities[1];
}
string Quiz::PrintThirdP()
{
	return allQuestions[qSelect].possibilities[2];
}
string Quiz::printFourthP()
{
	return allQuestions[qSelect].possibilities[3];
}

//sets the correct answers to quizKeys array
void Quiz::setKeys(int index)
{
	char tempKey;
	tempKey = allQuestions[index].key;
	quizKeys.push_back(tempKey);
}



//Randomizes the questions
void Quiz::askQuestion()
{
	char playerAnswer;
	char tempKey;
	srand(time(NULL));
	int tempArrayIndex;

	qSelect = rand() % 37;
	while (checkUsed(qSelect) == true)
	{
		qSelect = rand() % 37;
		checkUsed(qSelect);
	}
	setKeys(qSelect);
}


//Default set of quesitons being initialized
void Quiz::setQuestions()
{
	quizKeys.clear();
	allQuestions[0].q = "What percent of US emissions are CO2?";
	allQuestions[0].possibilities[0] = "a] 50 %";
	allQuestions[0].possibilities[1] = "b] 90 %";
	allQuestions[0].possibilities[2] = "c] 80 %";
	allQuestions[0].possibilities[3] = "d] 20 %";
	allQuestions[0].key = 'c';
	allQuestions[0].used = false;

	allQuestions[1].q = "What is the largest source of CO2 emissions in the US?";
	allQuestions[1].possibilities[0] = "a] Electricity";
	allQuestions[1].possibilities[1] = "b] Transporation";
	allQuestions[1].possibilities[2] = "c] Industry";
	allQuestions[1].possibilities[3] = "d] Agriculture";
	allQuestions[1].key = 'a';
	allQuestions[1].used = false;

	allQuestions[2].q = "Why is electricity the largest source of carbon emissions in the US?";
	allQuestions[2].possibilities[0] = "a] Electricity produces chemical waste";
	allQuestions[2].possibilities[1] = "b] Most energy comes from nuclear power plants";
	allQuestions[2].possibilities[2] = "c] Most energy comes from burning coal";
	allQuestions[2].possibilities[3] = "d] None of the above";
	allQuestions[2].key = 'c';
	allQuestions[2].used = false;

	allQuestions[3].q = "Which is false about carbon emissions?";
	allQuestions[3].possibilities[0] = "a] US releases 10x metric tons of carbon than it did in 1950";
	allQuestions[3].possibilities[1] = "b] Vehicles have a large footprint because 90% of fuel is petroleum based";
	allQuestions[3].possibilities[2] = "c] Worldwide, agriculture is the second largest carbon emitting sector";
	allQuestions[3].possibilities[3] = "d] Carbon emissions have been directly tied to global warming";
	allQuestions[3].key = 'd';
	allQuestions[3].used = false;

	allQuestions[4].q = " CO2 emissions come primarily from which of the following?";
	allQuestions[4].possibilities[0] = "a] Fossil fuel use";
	allQuestions[4].possibilities[1] = "b] Agriculture waste";
	allQuestions[4].possibilities[2] = "c] Industrial processes";
	allQuestions[4].possibilities[3] = "d]  Breathing";
	allQuestions[4].key = 'a';
	allQuestions[4].used = false;

	allQuestions[5].q = "Which of the following is true about carbon emissions?";
	allQuestions[5].possibilities[0] = "a] India produces the same amount of carbon emissions as all of Europe";
	allQuestions[5].possibilities[1] = "b] China and the US make up almost half of all carbon emissions in the entire world";
	allQuestions[5].possibilities[2] = "c] US emissions have been stedily declining since 1990";
	allQuestions[5].possibilities[3] = "d] Japanese releases as much carbon as India";
	allQuestions[5].key = 'b';
	allQuestions[5].used = false;

	allQuestions[6].q = "What is the United States' carbon emission per capita?";
	allQuestions[6].possibilities[0] = "a] 14 metric tons ";
	allQuestions[6].possibilities[1] = "b] 10 metric tons";
	allQuestions[6].possibilities[2] = "c] 17 metric tons";
	allQuestions[6].possibilities[3] = "d] 12 metric tons";
	allQuestions[6].key = 'c';
	allQuestions[6].used = false;

	allQuestions[7].q = "What is China's carbon emission per capita?";
	allQuestions[7].possibilities[0] = "a] 25 metric tons";
	allQuestions[7].possibilities[1] = "b] 30 metric tons";
	allQuestions[7].possibilities[2] = "c] 10 metric tons";
	allQuestions[7].possibilities[3] = "d] 6 metric tons";
	allQuestions[7].key = 'd';
	allQuestions[7].used = false;

	allQuestions[8].q = "Which of the following is true?";
	allQuestions[8].possibilities[0] = "a] There is a greenhouse gas 7100x more deadly than CO2";
	allQuestions[8].possibilities[1] = "b] This gas, PFTBA, has no natural occurances on Earth which can absorb it";
	allQuestions[8].possibilities[2] = "c] In the atmopshere, there is currently 400ppm of CO2 and 0.18 ppm of PFTBA";
	allQuestions[8].possibilities[3] = "d] All of the above";
	allQuestions[8].key = 'd';
	allQuestions[8].used = false;

	allQuestions[9].q = "If you take two very large flights per year, which is true?";
	allQuestions[9].possibilities[0] = "a] That does not outweigh your carbon emissions for driving all year";
	allQuestions[9].possibilities[1] = "b] That makes up for more than half of your yearly carbon footprint";
	allQuestions[9].possibilities[2] = "c] Electricity and travl has more of a carbon footprint than thos two flights";
	allQuestions[9].possibilities[3] = "d] Flying doesn't have a very large impact on your carbon footprint because the fuel is so efficient";
	allQuestions[9].key = 'b';
	allQuestions[9].used = false;

	allQuestions[10].q = "What is the second most emitted greenhouse gas in the US?";
	allQuestions[10].possibilities[0] = "a] Methane";
	allQuestions[10].possibilities[1] = "b] PFTBA";
	allQuestions[10].possibilities[2] = "c] Nitrous Oxide";
	allQuestions[10].possibilities[3] = "d] Fluoride gasses";
	allQuestions[10].key = 'a';
	allQuestions[10].used = false;

	allQuestions[11].q = "Which of the following is false about carbon emissions in the US?";
	allQuestions[11].possibilities[0] = "a] Electricity generation has more of an impact than transporation (car, planes, etc)";
	allQuestions[11].possibilities[1] = "b] Agriculture is the deadliest greenhouse gas emitter because of its methane emissions";
	allQuestions[11].possibilities[2] = "c] Industry is only the thirdmost carbon emitter";
	allQuestions[11].possibilities[3] = "d] In comparison, residential carbon footprints are almost obsolete";
	allQuestions[11].key = 'b';
	allQuestions[11].used = false;

	allQuestions[12].q = "How long does methane stay in the atmosphere";
	allQuestions[12].possibilities[0] = "a] 200 years";
	allQuestions[12].possibilities[1] = "b] 108 years";
	allQuestions[12].possibilities[2] = "c] 12 years";
	allQuestions[12].possibilities[3] = "d] 59 years";
	allQuestions[12].key = 'c';
	allQuestions[12].used = false;

	allQuestions[13].q = "How long does Nitrous Oxide stay in the atmosphere";
	allQuestions[13].possibilities[0] = "a] 165 years";
	allQuestions[13].possibilities[1] = "b] 121 years";
	allQuestions[13].possibilities[2] = "c] 50 years";
	allQuestions[13].possibilities[3] = "d] 114 years";
	allQuestions[13].key = 'd';
	allQuestions[13].used = false;

	allQuestions[14].q = "Which of the following is true about CO2's life in the atmopshere?";
	allQuestions[14].possibilities[0] = "a] It's hard to determine the length because of natural processes removing it";
	allQuestions[14].possibilities[1] = "b] It can range between 20 years to thousands of years";
	allQuestions[14].possibilities[2] = "c] The ocean absorbs a large of amount of CO2 emitted into the atmopshere";
	allQuestions[14].possibilities[3] = "d] All of the above";
	allQuestions[14].key = 'd';
	allQuestions[14].used = false;

	allQuestions[15].q = "In 2013, how much CO2 did the United States emit?";
	allQuestions[15].possibilities[0] = "a] 6600 metric tons";
	allQuestions[15].possibilities[1] = "b] 5200 metric tons";
	allQuestions[15].possibilities[2] = "c] 4800 metric tons";
	allQuestions[15].possibilities[3] = "d] 3300 tons";
	allQuestions[15].key = 'a';
	allQuestions[15].used = false;

	allQuestions[16].q = "Which is true about carbon emissions and climate change?";
	allQuestions[16].possibilities[0] = "a] Gas imoact on the atmosphere can only be measured in potential because there's little science connecting the two";
	allQuestions[16].possibilities[1] = "b] Carbon emissions have been increasing side by side with global temperatures";
	allQuestions[16].possibilities[2] = "c] Carbon emissions are negligible when considering climate change";
	allQuestions[16].possibilities[3] = "d] All of the above";
	allQuestions[16].key = 'a';
	allQuestions[16].used = false;

	allQuestions[17].q = "For the average person, what is the leading source of greenhouse gas emissions?";
	allQuestions[17].possibilities[0] = "a] Electricity use";
	allQuestions[17].possibilities[1] = "b] Waste";
	allQuestions[17].possibilities[2] = "c] Commuting";
	allQuestions[17].possibilities[3] = "d] Farting";
	allQuestions[17].key = 'c';
	allQuestions[17].used = false;

	allQuestions[18].q = "Which is true about China's carbon emissions?";
	allQuestions[18].possibilities[0] = "a] In 2015, there's going to be a significant rise because of their economy";
	allQuestions[18].possibilities[1] = "b] Their emissions have been and will continue to steadily increase ";
	allQuestions[18].possibilities[2] = "c] In 2015, there's going to be a significant dip because of their economy";
	allQuestions[18].possibilities[3] = "d] In 2015, their emissions will remain the same as last year due to government regulations";
	allQuestions[18].key = 'c';
	allQuestions[18].used = false;

	allQuestions[19].q = "As more CO2 enters the atmosphere, which is true?";
	allQuestions[19].possibilities[0] = "a] More CO2 gets absorbed by forests and the ocean";
	allQuestions[19].possibilities[1] = "b] More CO2 remains in the atmosphere";
	allQuestions[19].possibilities[2] = "c] It becomes harder to breathe";
	allQuestions[19].possibilities[3] = "d] Plants grow taller";
	allQuestions[19].key = 'b';
	allQuestions[19].used = false;

	allQuestions[20].q = "How closesly related are the holes in the ozone related to carbon emissions?";
	allQuestions[20].possibilities[0] = "a] Most gasses which tear holes into the ozone also have a high global warming potential (GWP)";
	allQuestions[20].possibilities[1] = "b] Not related at all";
	allQuestions[20].possibilities[2] = "c] CO2 closes holes in the atmosphere by providing their oxygen atoms";
	allQuestions[20].possibilities[3] = "d] Very loosely related by CFC'sm which both have a high GWP and tears holes in the ozone";
	allQuestions[20].key = 'd';
	allQuestions[20].used = false;

	allQuestions[21].q = "What is the US government aiming for in reducing their carbon emissions?";
	allQuestions[21].possibilities[0] = "a] 50% reduction of 2005 levels in 2050";
	allQuestions[21].possibilities[1] = "b] 40% of the reduction of 2005 levels in 2050";
	allQuestions[21].possibilities[2] = "c] 60% reduction of 2005 levels in 2050";
	allQuestions[21].possibilities[3] = "d] 80% reduction of 2005 levels in 2050";
	allQuestions[21].key = 'd';
	allQuestions[21].used = false;

	allQuestions[22].q = "Which of the follwing is true about the US's efforts to reduce carbon emissions?";
	allQuestions[22].possibilities[0] = "a] With their plan, it will reduce business costs by $465 billion by 2030 in comparison to today";
	allQuestions[22].possibilities[1] = "b] US will save a net $1.7 trillion between 2010 and 2030 in comparison to today";
	allQuestions[22].possibilities[2] = "c] Households will have an annual savings of $255 billion by 2030";
	allQuestions[22].possibilities[3] = "d] all of the above";
	allQuestions[22].key = 'd';
	allQuestions[22].used = false;

	allQuestions[23].q = "With the US goal in carbon emission reductions, how much do they plan for each household to save per year?";
	allQuestions[23].possibilities[0] = "a] $300";
	allQuestions[23].possibilities[1] = "b] $250";
	allQuestions[23].possibilities[2] = "c] $400";
	allQuestions[23].possibilities[3] = "d] $900";
	allQuestions[23].key = 'd';
	allQuestions[23].used = false;

	allQuestions[24].q = "Which country, is current trends continue, will become the largest contributer CO2 emissions";
	allQuestions[24].possibilities[0] = "a] Canada";
	allQuestions[24].possibilities[1] = "b] India";
	allQuestions[24].possibilities[2] = "c] Russia";
	allQuestions[24].possibilities[3] = "d] Japan";
	allQuestions[24].key = 'b';
	allQuestions[24].used = false;

	allQuestions[25].q = "In 2005, who was the largest emitter of CO2?";
	allQuestions[25].possibilities[0] = "a] US";
	allQuestions[25].possibilities[1] = "b] China";
	allQuestions[25].possibilities[2] = "c] India";
	allQuestions[25].possibilities[3] = "d] Japan";
	allQuestions[25].key = 'a';
	allQuestions[25].used = false;

	allQuestions[26].q = "Who passed the US in CO2 emissions in 2006?";
	allQuestions[26].possibilities[0] = "a] Japan";
	allQuestions[26].possibilities[1] = "b] Russia";
	allQuestions[26].possibilities[2] = "c] China";
	allQuestions[26].possibilities[3] = "d] India";
	allQuestions[26].key = 'c';
	allQuestions[26].used = false;

	allQuestions[27].q = "Globally, how much CO2 are we releasing into the atmosphere each year?";
	allQuestions[27].possibilities[0] = "a] 5000 million metric tons";
	allQuestions[27].possibilities[1] = "b] 3000 million metric tons";
	allQuestions[27].possibilities[2] = "c] 4500 million metric tons";
	allQuestions[27].possibilities[3] = "d] 9500 million metric tons";
	allQuestions[27].key = 'd';
	allQuestions[27].used = false;

	allQuestions[28].q = "How much of the US carbon emissions are not related to fossil fuel combustion?";
	allQuestions[28].possibilities[0] = "a] 20 %";
	allQuestions[28].possibilities[1] = "b] 6 %";
	allQuestions[28].possibilities[2] = "c] 12 %";
	allQuestions[28].possibilities[3] = "d] 33%";
	allQuestions[28].key = 'b';
	allQuestions[28].used = false;

	allQuestions[29].q = "Since 1854, Chevon, Exxon Mobile, Shell, British Petroleum and ConocoPhillips can be traced back to what percent of all carbon emissions?";
	allQuestions[29].possibilities[0] = "a] 5 %";
	allQuestions[29].possibilities[1] = "b] 7 %";
	allQuestions[29].possibilities[2] = "c] 13 %";
	allQuestions[29].possibilities[3] = "d] 10 %";
	allQuestions[29].key = 'c';
	allQuestions[29].used = false;

	allQuestions[30].q = "Globally, what are the top 4 sources of carbon emissions from greatest to least?";
	allQuestions[30].possibilities[0] = "a] Electricity production -> Agriculture -> Industry -> Transporation ";
	allQuestions[30].possibilities[1] = "b] Electricity production -> Agriculture -> Transportation -> Industry ";
	allQuestions[30].possibilities[2] = "c] Transportation -> Electricity production -> Industry -> Agriculture ";
	allQuestions[30].possibilities[3] = "d] Transportation -> Industry -> Electricity production -> Agriculture ";
	allQuestions[30].key = 'b';
	allQuestions[30].used = false;

	allQuestions[31].q = "In the United States, what are the top sources of carbon emission from greatest to lest?";
	allQuestions[31].possibilities[0] = "a] Electricity production -> Transporation -> Industry -> Commercial and Residential ";
	allQuestions[31].possibilities[1] = "b] Electricity production -> Commercial and Residential -> Transportation -> Industry";
	allQuestions[31].possibilities[2] = "c] Transportation -> Electricity production -> Industry -> Agriculture ";
	allQuestions[31].possibilities[3] = "d] Transportation -> Industry -> Electricity production -> Commercial and Residential ";
	allQuestions[31].key = 'a';
	allQuestions[31].used = false;

	allQuestions[32].q = "In the energy sector, which is true about corporate carbon emissions";
	allQuestions[32].possibilities[0] = "a] Between 2009 and 2013, carbon emissions rose by 53 % ";
	allQuestions[32].possibilities[1] = "b] Between 2009 and 2013, carbon emissions rose by 27 %";
	allQuestions[32].possibilities[2] = "c] Between 2009 and 2013, carbon emission fell by 53% ";
	allQuestions[32].possibilities[3] = "d] Between 2009 and 2013, carbon emissions fell by 27% ";
	allQuestions[32].key = 'a';
	allQuestions[32].used = false;

	allQuestions[33].q = "Out of the top 4 most carbon emittinv companies, which has the highest carbon emissions?";
	allQuestions[33].possibilities[0] = "a] Shell ";
	allQuestions[33].possibilities[1] = "b] Exxon Mobil";
	allQuestions[33].possibilities[2] = "c] British Petroleum ";
	allQuestions[33].possibilities[3] = "d] Chevron ";
	allQuestions[33].key = 'b';
	allQuestions[33].used = false;

	allQuestions[34].q = "In the United States, what are the top sources of carbon emission from greatest to lest?";
	allQuestions[34].possibilities[0] = "a] Electricity production -> Transporation -> Industry -> Commercial and Residential ";
	allQuestions[34].possibilities[1] = "b] Electricity production -> Commercial and Residential -> Transportation -> Industry";
	allQuestions[34].possibilities[2] = "c] Transportation -> Electricity production -> Industry -> Agriculture ";
	allQuestions[34].possibilities[3] = "d]Transportation -> Industry -> Electricity production -> Commercial and Residential ";
	allQuestions[34].key = 'b';
	allQuestions[34].used = false;

	allQuestions[35].q = "How much CO2 does Exxon Mobile emit per year?";
	allQuestions[35].possibilities[0] = "a] 100k tons ";
	allQuestions[35].possibilities[1] = "b] 130k tons";
	allQuestions[35].possibilities[2] = "c] 150k tons ";
	allQuestions[35].possibilities[3] = "d] 90k tons";
	allQuestions[35].key = 'c';
	allQuestions[35].used = false;

	allQuestions[36].q = "What percent of companies in the energy sector don't even have plans for carbon emission reduction";
	allQuestions[36].possibilities[0] = "a] 25%";
	allQuestions[36].possibilities[1] = "b] 5%";
	allQuestions[36].possibilities[2] = "c] 10% ";
	allQuestions[36].possibilities[3] = "d] 9%";
	allQuestions[36].key = 'a';
	allQuestions[36].used = false;
}


