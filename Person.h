/****************************************************************
File: Person Class
Description: Calculate Carbon Omissions

Author:Perry Barker
Class: CSCI 120
Date:12/3/15

I hereby certify that this program is entirely my own work.
*****************************************************************/
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


using namespace std;

/*Person class is used to keep track of user inputed data. 
The getter functions are mostly needed for debugging purposes
Average person with a household size of one 
and carpool size of 1 emittes 19702 lbs of CO2 a year*/	

	class Person{
	public:

		Person();
		//~Person();
		Person(string name);
		void setUserName(string);
		double getCarbonFootprint();
		string getUserName();
		/*calls Energy,Transportation, and Waste functions
		  to calculate and set users Carbon Footprint*/
		double calcCarbonFootprint();
		void   setCarbonFootprint(double);

		//  HOUSE ENERGY FUNCTIONS

		void   setGasUsage(double gasUsed);
		void   setElectricUsage(double electricUsed);
		double getGasUsage();
		double getElectricUsage();
		/*calculates users HouseEnergy emmissions*/
		double calcHouseEnergy();
		void   setHouseholdSize(int size);

		//  TRANSPORTATION FUNCTIONS

		void   setCarPoolSize(int carPool);
		void   setCarMPG(double mpg, int carPool);
		void   setDailyMiles(double miles);
		int	   getCarPoolSize();
		double getCarMPG();
		/*calculates users Transportation emmissions*/
		double calcTransportation();
		//  WASTE FUNCTIONS

		/*following bool statements are set true
		  if respective checkboxes are checked*/
		bool   recyMetal(bool check);
		bool   recyPlastic(bool check);
		bool   recyGlass(bool check);
		bool   recyNewspaper(bool check);
		bool   recyMagazines(bool check);
		/*calculates users Waste emmissions*/
		double calcWaste();



	private:

		string userName;
		int    householdSize;
		double carbonFootprint;
		int    carpoolSize;
		double    electricUsage;
		double    gasUsage;
		double carMPG;
		double dailyMiles;
		bool checkMag;
		bool checkPlast;
		bool checkNwsPap;
		bool checkMetal;
		bool checkGlass;

	};
#endif
