/****************************************************************
File: Person Class
Description: Calculate Carbon Omissions

Author:Perry Barker
Class: CSCI 120
Date:12/3/15

I hereby certify that this program is entirely my own work.
*****************************************************************/
#include <iostream>
#include "Person.h"

/*Person class is used to keep track of user inputed data.
The getter functions are mostly needed for debugging purposes
Average person with a household size of one
and carpool size of 1 emittes 19702 lbs of CO2 a year*/
Person::Person(){
	userName = "NAME";
	householdSize = 1;
	carbonFootprint = 0.0;
	carpoolSize = 1;
	electricUsage = 0.0;
	gasUsage = 0.0;
	carMPG = 0.0;
	dailyMiles = 0.0;
	checkMag, checkPlast, checkNwsPap, checkMetal, checkGlass = 0;
};

Person::Person(string name){
	userName = name;
	householdSize = 1;
	carbonFootprint = 0.0;
	carpoolSize = 1;
	electricUsage = 0.0;
	gasUsage = 0.0;
	carMPG = 0.0;
	dailyMiles = 0.0;
	checkMag, checkPlast, checkNwsPap, checkMetal, checkGlass = 0;
};

void Person::setUserName(string name){
	userName = name;
}
double Person::getCarbonFootprint(){
	return carbonFootprint;
};
string Person::getUserName(){
	return userName;
};
/*calls Energy,Transportation, and Waste functions
to calculate and set users Carbon Footprint*/
double Person::calcCarbonFootprint(){

	carbonFootprint = calcHouseEnergy() + calcTransportation() + calcWaste();

	return carbonFootprint;

};
void Person::setCarbonFootprint(double footprint){
	carbonFootprint = footprint;
}
//  HOUSE ENERGY FUNCTIONS
void Person::setGasUsage(double gasUsed){

	gasUsage = gasUsed / householdSize;
};
void Person::setElectricUsage(double electricUsed){

	electricUsage = electricUsed / householdSize;
};
double Person::getGasUsage(){
	return gasUsage;
};
double Person::getElectricUsage(){
	return electricUsage;
};
/*calculates users HouseEnergy emmissions*/
double Person::calcHouseEnergy(){

	double gasEmmissions = (
		gasUsage / 10.68)      // monthly user bill divided by price of gas per 1000 cubic ft
		* 119.58	           // lbs of CO2 emmitted per 1000 cubic ft
		* 12;				   // twelve months in a year
	double electricEmmissions = (
		electricUsage / 0.12)  // monthly user bill divided by price of electric per kWh
		* 1.24				   // lbs of CO2 emmitted per kWh
		* 12;				   // twelve months in a year
	return gasEmmissions + electricEmmissions;
};
void  Person::setHouseholdSize(int size){

	householdSize = size;
};
//  TRANSPORTATION FUNCTIONS
void  Person::setCarPoolSize(int carPool){

	carpoolSize = carPool;
};
void  Person::setCarMPG(double mpg, int carPool){

	carMPG = mpg / carPool;
};
void   Person::setDailyMiles(double miles){

	dailyMiles = miles;
};
int    Person::getCarPoolSize(){
	return carpoolSize;
};
double Person::getCarMPG(){
	return carMPG;
};
/*calculates users Transportation emmissions*/
double Person::calcTransportation(){

	double gallonsUsed = dailyMiles / carMPG; // amount of gallons of gas used in dailytravel
	
	return gallonsUsed * 20.61 * 365; // 20.61 is total amount of greenhouse gases emitted per gallon of gas for a year
};
//  WASTE FUNCTIONS
/*following bool statements are set true
if respective checkboxes are checked*/
//PENDING WXWIDGETS
bool   Person::recyMetal(bool check){
	if (!check){
		checkMetal = false;
	return false;
	}
	else{
		checkMetal = true;
	return true;
	}
};

//PENDING WXWIDGETS
bool   Person::recyPlastic(bool check){
	if (!check){
		checkPlast = false;
		return false;
	}
	else{
		checkPlast = true;
		return true;
	}
};

//PENDING WXWIDGETS
bool   Person::recyGlass(bool check){
	if (!check){
		checkGlass = false;
		return false;
	}
	else{
		checkGlass = true;
		return true;
	}
};

//PENDING WXWIDGETS
bool   Person::recyNewspaper(bool check){
	if (!check){
		checkNwsPap = false;
		return false;
	}
	else{
		checkNwsPap = true;
		return true;
	}
};

//PENDING WXWIDGETS
bool   Person::recyMagazines(bool check){
	if (!check){
		checkMag = false;
		return false;
	}
	else{
		checkMag = true;
		return true;
	}
};

/*calculates users Waste emmissions*/

double Person::calcWaste(){

	double wasteOmissions = 692.0; //lbs of waste per person in a year
	if (recyGlass(checkGlass)){
		wasteOmissions -= 25.39; //amount reduced from recycling glass
	}
	if (recyMagazines(checkMag)){
		wasteOmissions -= 27.46; //amount reduced from recycling magazines
	}
	if (recyMetal(checkMetal)){
		wasteOmissions -= 89.38; //amount reduced from recycling metal(aluminum & cans)

	}
	if (recyPlastic(checkPlast)){
		wasteOmissions -= 35.56; //amount reduced from recycling plastic
	}
	if (recyNewspaper(checkNwsPap)){
		wasteOmissions -= 113.14; //amount reduced from recycling newspapers
	}
	return wasteOmissions;
};
/*
//BELOW CODE WAS USED FOR DEBUGGING OF PERSON CLASS

int main(){
	
	Person Perry("Perry");
	//TEST TRANSPORTATION FUNCTIONS
	cout << "USER NAME " << Perry.getUserName() << endl;
	Perry.setCarPoolSize(1);
	Perry.setDailyMiles(20);
	Perry.setCarMPG(35, Perry.getCarPoolSize());
	cout << "USER MPG " << Perry.getCarMPG() << endl;
	cout << "TOTAL TRANSPORTATION EMMISSIONS " << Perry.calcTransportation() << endl;
	//TEST HOUSE ENERGY FUNCTIONS
	Perry.setHouseholdSize(3);
	Perry.setElectricUsage(50.59);
	Perry.setGasUsage(22.57);
	cout << "ELECTRIC BILL " << Perry.getElectricUsage() << endl;
	cout << "GAS BILL " << Perry.getGasUsage() << endl;
	cout << "HOUSE ENERGY EMISSIONS " << Perry.calcHouseEnergy() << endl;
	//TEST WASTE FUNCTIONS
	cout << "RECYCLE METAL "         << Perry.recyMetal(    0)     << endl;
	cout << "RECYCLE NEWSPAPER "     << Perry.recyNewspaper(0) << endl;
	cout << "RECYCLE GLASS "         << Perry.recyGlass(    0)     << endl;
	cout << "RECYCLE PLASTIC "       << Perry.recyPlastic(  0)   << endl;
	cout << "RECYCLE MAGAZINES "     << Perry.recyMagazines(0) << endl;
	cout << "TOTAL WASTE EMISSIONS " << Perry.calcWaste()      << endl;
	//TEST FOOTPRINT
	cout << "CARBON FOOTPRINT " << Perry.calcCarbonFootprint() << endl;
	cout << Perry.getCarbonFootprint() << endl;
	

	system("PAUSE");
	
	return 0;
}
*/