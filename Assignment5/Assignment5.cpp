//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : October 13 2016
// Status    : Complete
//
// This program will be used to do project 5
//******************************************************************
/* PROMPT*/
const int sC= 15;
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
struct Box
{
	int side1;
	int side2;
	int side3;
	double weight;	
};
//prototypes
void menu();
void input(Box &, int &, double &, int&, int &, int[], double[]);
void boxInput(Box&);
void output(Box&, int &, double &, int&, int&, int [], double[]);
void transaction(int&);
void status(Box&, int&, int&, double&);
void dimensions(Box&);
double girth(Box&);
double determineCost(Box&, double &, int [], double[]);

template<typename dataType>
void debug(dataType x)
{
	cout<<"******Debug Start******"<<endl;
	cout<<"Value is "<<x<<endl;
	cout<<"******End Debug******"<<endl;
}

int main()						
{ 
	//variables
	Box junk;
	double charge=0;
	int transactionCount=0;
	int accepted=0;
	int rejected=0;
	int outStateCharge=25;
	int outCountryCharge=30;
	
	//arrays
	int weight[sC]={1,2,3,5,7,10,13,16,20,25,30,35,40,45,50};
	double shippingCharge[sC]={ 1.5, 2.1, 4, 6.75, 9.9, 14.95, 19.4, 24.2, 27.3, 31.9, 38.5, 43.5, 44.8, 47.4, 55.2};

	//processing	 
	input(junk, transactionCount, charge, accepted, rejected, weight, shippingCharge);
	
	
  
 return 0;
}   // end of main function

void menu()
{
	cout<<"Enter the location"<<endl;
	cout<<"T for TX shipping"<<endl;
	cout<<"O for Out of state shipping"<<endl;
	cout<<"F for Foriegn shipping"<<endl;
	cout<<"X for exit"<<endl;
}//end of menu

void input(Box & junk, int & trans, double & charge, int &accept, int &reject, int weight[], double shippingCharge[])
{
	//variables
	string choice;
	
	while (choice!="x")
{
		menu();
		cin>>choice;
		
		if (choice=="t")//texas
		{
			charge+=0;
			boxInput(junk);
			transaction(trans);
			
			cout<<"Location: TX"<<endl;
			status(junk, accept, reject, charge);
			dimensions(junk);
			cout<<"Shipping Charge: $"<<determineCost(junk, charge,  weight, shippingCharge)<<endl;
		}
		else if (choice=="o")//out of state
		{
			charge+=25;
			boxInput(junk);
			transaction(trans);
			cout<<"Location: Out of State"<<endl;
			status(junk, accept, reject, charge);
			dimensions(junk);
			cout<<"Shipping Charge: $"<<determineCost(junk, charge,  weight, shippingCharge)<<endl;
		}
		else if (choice=="f")//forigen
		{
			charge+=30;
			boxInput(junk);
			transaction(trans);
			cout<<"Location: Foriegn"<<endl;
			status(junk, accept, reject, charge);
			dimensions(junk);
			cout<<"Shipping Charge: $"<<determineCost(junk, charge,  weight, shippingCharge)<<endl;
		}
		else
		{
			output(junk, trans, charge, accept, reject, weight, shippingCharge);
			cout<<endl;
			exit(0);
		}	
	}
	
}//end of input

void boxInput(Box& junk)
{
	cout<<"Enter package weight";
	cin>>junk.weight;
	cout<<"Enter side 1: ";
	cin>>junk.side1;
	cout<<"Enter side 2: ";
	cin>>junk.side2;
	cout<<"Enter side 3: ";
	cin>>junk.side3;
	cout<<"_______________________"<<endl;
}//end of boxInput

void output(Box &junk, int & trans, double & charge, int &accept, int &reject, int weight[], double shippingCharge[])
{
	cout<<"Transactions Made: "<<trans<<endl;
	cout<<"Packages Accepted: "<<accept<<endl;
	cout<<"Packages Rejected: "<<reject<<endl;
	cout<<"Total Cost: $"<<charge+determineCost( junk, charge,  weight, shippingCharge)<<endl;
	
}//end of output

void status(Box & junk, int &accept, int &reject, double & charge)
{
	if ((junk.weight<=40 &&junk.side1<=6&&junk.side2<=6&&junk.side1<=6)&&(junk.weight>0 &&junk.side1>0&&junk.side2>0&&junk.side1>0)&& (girth(junk)<=10))
	{
		cout<<"Status: ACCEPTED"<<endl;
		accept++;
		//cout<<"Packages Accepted: "<<accept<<endl;
	}
	else
	{
		cout<<"Status: REJECTED"<<endl;
		reject++;
		charge=0;
		//cout<<"Packages Rejected: "<<reject<<endl;
	}	
}//end of status

void transaction(int &trans)
{
	cout<<"Transaction "<<trans<<endl;
	trans++;
}//end of transaction 

void dimensions(Box& junk)
{
	cout<<"Weight: "<<junk.weight<<" lbs"<<endl;
	cout<<"Side 1: "<<junk.side1<<"'"<<endl;
	cout<<"Side 2: "<<junk.side2<<"'"<<endl;
	cout<<"Side 3: "<<junk.side3<<"'"<<endl;
	cout<<"Girth: "<<girth(junk)<<"'"<<endl;
}//end of dimensions 

double girth(Box& junk)
{
	double largest=0;
	double finalGirth=0;
	if ((junk.side1>=junk.side2)&&(junk.side1>=junk.side3))
	{
		largest=junk.side1;
	}
	else if ((junk.side2>=junk.side1)&&(junk.side2>=junk.side3))
	{
		largest=junk.side2;
	}
	else if ((junk.side3>=junk.side1)&&(junk.side3>=junk.side2))
	{
		largest=junk.side3;
	}
	else
	{
		largest=-1;
	}
	finalGirth=2*(junk.side1+junk.side2+junk.side3-largest);
	
	return finalGirth;
}//end of girth


double determineCost(Box& junk, double &charge, int weight[], double shippingCharge[])
{
	double cost=0;
	bool found=false;
	for (int i=0; i<15&&!found; i++)
	{
		if (junk.weight<=weight[i])
		{
			cost=shippingCharge[i];
			found=true;
		}	
	}
	return cost;
}//end of determineCost function
