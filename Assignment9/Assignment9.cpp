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
#include<cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
class Date
{
	private:
	int months;
	int days;
	int years;
	
	//constructor
	public:
	Date()
	{
		months=1;
		days=1;
		years=2020;
	}
	
	//accessors
	int getMonth()
	{
		return months;
	}
	
	int getDay()
	{
		return days;
	}
	
	int getYear()
	{
		return years;
	}
	
	//modifyers
	void setData()
	{
		cout<<"Enter Month between 1-12: ";
		cin>>months;
		//month
		while (months>12||months<1)
		{
			cout<<"Enter a VALID MONTH NUMBER! ";
			cin>>months;
		}
		//day
		cout<<"Enter Day between 1-31: ";
		cin>>days;
		while (days>31||days<1)
		{
			cout<<"Enter a VALID DAY NUMBER! ";
			cin>>days;	
		}
		//year
		cout<<"Enter Year between 1950-2020: ";
		cin>>years;
		while (years>2020||years<1950)
		{
			cout<<"Enter a YEAR BETWEEN 1950 and 2020! ";
			cin>>years;	
		}
	}
	
	void set(int m, int d, int y)
	{
		months=m;
		days=d;
		years=y;
	}
	
	//other functions
	void printInNumbers()
	{
		cout<<months<<"/"<<days<<"/"<<years<<endl;
	}
	
	void printMDY()
	{
		cout<<monthName()<<" "<<days<<", "<<years<<endl;
	}
	
	void printDMY()
	{
		cout<<days<<" "<<monthName()<<" "<<years<<endl;
	}
	
	string monthName()
	{
		string mon[12]={"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		string name="";
		bool found=false;
		for (int i=0;i<12&&!found; i++)
		{
			if (months==(i+1))
			{
				name=mon[i];
				found=true;
			}
		}
		return name;	
	}
};
//prototypes
void output(Date&);

int main()						
{ 
	Date date;

	//processing
	date.setData();
	output(date);
 return 0;
}   // end of main function


void output(Date& date)
{
	cout<<"*************************************"<<endl;
	date.printInNumbers();
	date.printMDY();
	date.printDMY();
}//end of output

