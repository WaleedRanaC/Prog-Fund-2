//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : Oct 18,2016
// Status    : Complete
//
// Assignment 4: This program will allow the user to enter the number pounds of food
//for each monkey in an array, then display them. It will calculate
//avg, min and max through functions.
//******************************************************************

#include <iostream>				// for cin, cout, endl
#include<cmath>
#include <iomanip>
using namespace std;
//prototypes
void input(double [][7]);
void output(double [][7]);
double average(double [][7]);
double minimum(double[][7]);
double maximum(double[][7]);
int main()						
{ 
  //variables
  double pounds[3][7];
  int count=0;

  	 input(pounds);
  	 cout<<"    S     M     T     W     Th    F    Sa"<<endl;
 	 output(pounds);
 	// cout<<endl;
	 cout<< "The average food eaten per day by all monkeys: "<<average(pounds)<<" pounds"<<endl;
	 cout<<"The minimum is:  "<<minimum(pounds)<<endl;
	 cout<<"The maximum is:  "<<maximum(pounds)<<endl;
 return 0;
}   // end of main function

void input(double pounds[][7])
{
	int flag=0;
	
for (int i=0; i<3; i++)
  {
  	for (int j=0; j<7; j++)
  	{
  		cout<<"Enter the pounds of food eaten by monkey "<<(i+1)<<" on day "<<(j+1)<<endl;
  		cin>>pounds[i][j];
  		
		while (pounds[i][j]<flag)
  		{
  		cout<<"Enter the POSITIVE pounds of food eaten by monkey "<<(i+1)<<" on day "<<(j+1)<<endl;
  		cin>>pounds[i][j];	
		}
	}
  }	
}//end of input function

void output(double pounds[][7])
{
for (int i=0; i<3; i++)
  {
  	for (int j=0; j<7; j++)
  	{
  		//cout<<"Monkey: "<<(i+1)<<" Day "<<(j+1)<<endl;
		//cout<<pounds[i][j]<<" pounds"<<endl;
		cout<<setw(5)<<pounds[i][j]<<" ";
	}
	  cout<<endl;
  }	

}

double average(double pounds[][7])
{
  double sum=0;
  double avg=0;
  int count=0;	
  for (int i=0; i<3; i++)
  {
  	for (int j=0; j<7; j++)
  	{
  	sum=sum+pounds[i][j];  
	 count++;	
	}
  }	
  	avg=sum/double(count);
  	return avg;
}//end of average function

double minimum(double pounds[][7])
{
 double min=pounds[0][0];
   for (int i=0; i<3; i++)
  {
  	for (int j=0; j<7; j++)
  	{
		if (pounds[i][j]<min)
		{
		min=pounds[i][j];
		}
	}
  }	
  return min;	
}//end of min function

double maximum(double pounds[][7])
{
 double max=pounds[0][0];
   for (int i=0; i<3; i++)
  {
  	for (int j=0; j<7; j++)
  	{
		if (pounds[i][j]>max)
		{
			max=pounds[i][j];
		}
	}
  }	
  return max;	
}//end of max function
