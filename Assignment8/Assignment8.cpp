//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used to assignment 8
//******************************************************************
/* 
*/
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
#include"Employee.h"
using namespace std;

//determines the number of employees 
int determineNumEmps(int &numLines)
{
	string line;
	ifstream infile;
	infile.open("master10.txt");
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			numLines++;
		}
		infile.close();
	}
	else
	{
		cout<<"File not found";
	}
	return numLines;
}//end of determineIndex

//reads the master file and stores the contents in the employee array
void readFile(Employee employee[])
{
	string line;
	ifstream infile;
	infile.open("master10.txt");
	
	if (infile.is_open())
	{
		int i=0;
		while (getline(infile, line))
		{
			employee[i].setID(atoi(line.substr(0,2).c_str()));
			employee[i].setName((line.substr(3,20).c_str()));
			employee[i].setHourlyPay(strtod(line.substr(23,5).c_str(), NULL));
			employee[i].setNumDeps(atoi(line.substr(29,1).c_str()));
			employee[i].setType(atoi(line.substr(31,1).c_str()));
			i++;
		}
		infile.close();
	}
	else
	{
		cout<<"File Not Found!";
	}
}//end of readFile

//Check for unmatched IDs between employees and trans file
int readTrans(Employee emp[], int &numLines)
{
	string line;
	ifstream infile;
	infile.open("trans10.txt");
	int id=0;
	int error=0;
	bool found=false;//flag
	while (getline(infile, line))
	{
		id=atoi(line.substr(0, 2).c_str());
		for (int k=0; k<numLines; k++)
		{
			if (id == emp[k].getID())
			{
				found=true;//match found
				break;//breaks out of for loop
			}
		}
		if(!found)
		{
			error++;
		}
		found=false;//reset flag
	}
	infile.close();
	return error;
}//end of readTrans

//read trans file and update employee hours based on IDs 
void determineHours(Employee employee[], int &numLines)
{
	string line;
	ifstream infile;
	infile.open("trans10.txt");

		while (getline(infile, line))
		{
			for (int i=0; i<numLines; i++)
			{
				if (employee[i].getID()==atoi(line.substr(0, 2).c_str()))
				{
					employee[i].setHours(atof(line.substr(3, 5).c_str()));
				}
			
			}

		}
	infile.close();	
}//end of checkID

//
void displayError(Employee emp[], int &numLines)
{
	ofstream errorfile;
	errorfile.open("error.txt");
	int correct=0;
	int error=0;
	for (int i =0; i<numLines; i++)
	{
		if (emp[i].getHours()>=0)
		{
			correct++;
		}
		else
		{
			error++;
			emp[i].setHours(0);
			emp[i].setNumDeps(0);
		}

	}
	errorfile<<"****************ERROR REPORT****************"<<endl;
	errorfile<<"Number of correct transactions: "<<correct<<endl;
	errorfile<<"Number of wrong transactions: "<<error<<endl;
	errorfile<<"Number of Umatched IDs: "<<readTrans(emp, numLines)<<endl;
	errorfile.close();
}//end of displayError

double calcFinalGrossPay(Employee emp[], int &numLines)
{
	double sum=0;
	for (int i=0; i<numLines; i++)
	{
		sum+=emp[i].calcGrossPay();
	}
	return sum;
}//end of finalGrossPay

double calcFinalNetPay(Employee emp[], int & numLines)
{
	double sum=0;
	for (int i=0; i<numLines; i++)
	{
		sum+=emp[i].calcNetPay();
	}
	return sum;
}//end of finalNetPay

void displayFinal(Employee emp[], int &numLines)
{
	ofstream outfile;
	outfile.open("payroll10.txt");
	for (int i=0; i<numLines; i++)
	{
		if (emp[i].getHours()>0)
		{
		outfile<<"_____________________________"<<endl;
		outfile<<"Employee "<<i+1<<endl;
		outfile<<"ID: "<<emp[i].getID()<<endl;
		outfile<<"Name: "<<emp[i].getName()<<endl;
		outfile<<"Hourly Pay: $"<<emp[i].getHourlyPay()<<endl;
		outfile<<"Number of Dependents: "<<emp[i].getNumDeps()<<endl;
		outfile<<"Type: "<<emp[i].getType()<<endl;
		outfile<<"Hours Worked: "<<emp[i].getHours()<<endl;
		outfile<<"****************************"<<endl;
		outfile<<"Gross Pay: $"<<emp[i].calcGrossPay()<<endl;
		outfile<<"Tax Owed: $"<<emp[i].calcTax()<<endl;
		outfile<<"Insurance Policy: $"<<emp[i].calcInsurance()<<endl;
		outfile<<"Net Pay: $"<<emp[i].calcNetPay()<<endl;
		outfile<<"_____________________________"<<endl;
		}

	}
		outfile<<"...................................."<<endl;
		outfile<<"Total Gross Pay: $"<<calcFinalGrossPay(emp, numLines)<<endl;
		outfile<<"Total Net Pay: $"<<calcFinalNetPay(emp, numLines)<<endl;
	outfile.close();
}//end of displayFinal

int main()						
{ 
	int numLines=0;
	determineNumEmps(numLines);//determines the index by traversing the master file
	
	Employee employee[numLines];
	
	readFile(employee);
	determineHours(employee, numLines);
	displayError(employee, numLines);
	displayFinal(employee, numLines);	
 return 0;
}   // end of main function
