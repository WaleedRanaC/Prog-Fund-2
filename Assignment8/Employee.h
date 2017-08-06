#ifndef Employee_H
#define Employee_H
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Employee 
{
  private:
    int id;             // employee ID
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    float hours;		//hours
    char gender; 		//gender
    
  public:
//constructor
	Employee();

//accessors
	int getID();
	string getName();
	double getHourlyPay();
	int getNumDeps();
	string getType();
	float getHours();
	char getGender();
	
//setFields
	void setID(int i);
	void setName(string n);
	void setHourlyPay(double h);
	void setNumDeps(int n);
	void setType(int t);
	void setHours(int h);
	void setGender(char g);


	//other functions
	double calcGrossPay();
	double calcTax();
	double calcInsurance();
	double calcNetPay();

};//end of class
#include "Employee.cpp"
#endif 
