//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used...
//******************************************************************
/* PROMPT*/
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
#include "Employee.h"
using namespace std;
//constructor
Employee::Employee()
{
	id=0;
	name="";
	hourlyPay=0;
	numDeps=0;
	type=0;
	hours=0;
//	gender='m';
}//end of constructotr

//get
int Employee::getID()
{
	return id;
}

string Employee::getName()
{
	return name;
}

double Employee::getHourlyPay()
{
	return hourlyPay;
}

int Employee::getNumDeps()
{
	return numDeps;
}

string Employee::getType()
{
	if (type==0)
	{
		return "Union";
	}
	else if (type==1)
	{
		return "Management";
	}
	else
	{
		return "NULL";
	}
}

float Employee::getHours()
{
	return hours;
}

char Employee::getGender()
{
	return gender;
}

//set
void Employee::setID(int i)
{
	id=i;
}

void Employee::setName(string n)
{
	name=n;
}

void Employee::setHourlyPay(double h)
{
	hourlyPay=h;
}

void Employee::setNumDeps(int n)
{
	numDeps=n;
}

void Employee::setType(int t)
{
	type=t;
}

void Employee::setHours(int h)
{
	hours=h;
}

/*char Employee::setGender(char g)
{
	gender=g;
}*/

//other functions	
double Employee::calcGrossPay()
{
	if (type==0 && hours > 40)
	{
		return hours * hourlyPay * 1.5;
	}
	else
	{
		return hours*hourlyPay;
	}	
}

double Employee::calcTax()
{
	return calcGrossPay()*.15;
}

double Employee::calcInsurance()
{
	return 30*numDeps;	
}

double Employee::calcNetPay()
{
	return calcGrossPay() - calcTax() - calcInsurance();
}

