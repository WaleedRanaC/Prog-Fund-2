//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 5 2016
// Status    : Complete
//
// This program will be used to start my project
//******************************************************************
/* PROMPT*/
#include <iostream>				// for cin, cout, endl
#include<cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
struct Employee
{
	int iD;//input
	string name;//input
	double basePay;//input
	int type;//input union, management
	double hoursWorked;//input
	
	double grossPay;// basePay * hours worked 
	double tax; //15% of gross pay
	double netPay;//grossPay - tax
};

//prototypes
void input(Employee[]);
void calcGrossPay(Employee[]);
void calcTax(Employee []);
void calcNetPay(Employee []);
void determineBasePay(Employee []);
void output(Employee[]);
void finalCalc(Employee []);

int main()						
{ 
	//variables
	Employee guy[4];

	input(guy);
	output(guy);
	finalCalc(guy);
	
 return 0;
}   // end of main function

void input(Employee guy[])
{
	for (int i=0; i<4; i++)
	{
		cout<<"Enter ID number for employee "<<i<<": ";
		cin>>guy[i].iD;
		while (guy[i].iD<0)
		{
			cout<<"ENTER POSITIVE ID"<<endl;
			cin>>guy[i].iD;
		}
		
		cout<<"Enter name for employee "<<i<<": ";
		cin>>guy[i].name;
		
		cout<<"Enter base pay for employee "<<i<<": ";
		cin>>guy[i].basePay;
		while (guy[i].basePay<0)
		{
			cout<<"ENTER POSITIVE PAY ";
			cin>>guy[i].basePay;
		}
		
		cout<<"Enter type for employee "<<i<<": ";
		cin>>guy[i].type;
		while (guy[i].type<0||guy[i].type>1)
		{
			cout<<"ENTER 0 OR 1 ";
			cin>>guy[i].type;
		}
		
		cout<<"Enter hours worked for employee "<<i<<": ";
		cin>>guy[i].hoursWorked;
		while (guy[i].hoursWorked<0)
		{
			cout<<"ENTER POSITIVE HOURS WORKED ";
			cin>>guy[i].hoursWorked;
		}
		
		cout<<" "<<endl;
	}
}//end of input

void calcGrossPay(Employee guy[])
{
	for (int i=0; i<4; i++)
	{
		guy[i].grossPay=guy[i].hoursWorked*guy[i].basePay;	
	}
	
}//end of calcGrossPay

void calcTax(Employee guy[])
{
	for (int i=0; i<4; i++)
	{
		guy[i].tax=guy[i].grossPay*.15;
	}
}//end of calcTax

void calcNetPay(Employee guy[])
{
	for (int i=0; i<4; i++)
	{
		guy[i].netPay=guy[i].grossPay-guy[i].tax;
	}
}//end of calcNetPay

void determineBasePay(Employee guy[])
{
	for (int i=0; i<4; i++)
	{
		double x=0;
		if (guy[i].type==0&& guy[i].hoursWorked>40)
		{
			x=guy[i].basePay*1.5;
			guy[i].basePay=x;
		}
		else
		{
			x=guy[i].basePay;
			guy[i].basePay=x;	
		}

	}
}//end of determineOvertime

void output(Employee guy[])
{
	for (int i=0; i<4; i++)
	{
		cout<<"______________________________________"<<endl;
		cout<<"Employee "<<i<<endl;
		cout<<"ID "<<guy[i].iD<<endl;
		cout<<"Name: "<<guy[i].name<<endl;
		cout<<"Hours Worked: "<<guy[i].hoursWorked<<endl;
		//__________________________________________________
		determineBasePay(guy);
		cout<<"Base Pay: $"<<guy[i].basePay<<endl;
		calcGrossPay(guy);
		cout<<"Gross Pay: $"<<guy[i].grossPay<<endl;
		calcTax(guy);
		cout<<"Tax: $"<<guy[i].tax<<endl;
		calcNetPay(guy);
		cout<<"Net Pay: $"<<guy[i].netPay<<endl;
	}
}//end of output

void finalCalc(Employee guy[])
{
	double grossPaySum=0;
	double netPaySum=0;
	for (int i=0; i<4; i++)
	{
		grossPaySum+=guy[i].grossPay;
	}
	
	for (int i=0; i<4; i++)
	{
		netPaySum+=guy[i].netPay;
	}
	cout<<"____________________________"<<endl;
	cout<<"Total Gross Pay: $"<<grossPaySum<<endl;
	cout<<"Total Net Pay: $"<<netPaySum<<endl;
}//end of finalCalc
