//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : Sept 20,2016
// Status    : Complete
//
// This program will be used to get the sum, product, average, quotient, and remainder of 2 numbers
//******************************************************************

#include <iostream>				// for cin, cout, endl
using namespace std;

//prototypes
int sum(int, int);
int product(int, int);
int average (int, int);
int quotient(int, int);
int remainder(int, int);
//main
int main()						
{ 
//declarations
 int num1;
 int num2;

//input
 cout<<"Enter the first number";
 cin>>num1;

 cout<<"Enter the second number";
 cin>>num2;

//output
cout<<"Sum: "<<sum(num1, num2)<<endl;
cout<<"Product: "<<product(num1, num2)<<endl;
cout<<"Average: "<<average(num1, num2)<<endl;
cout<<"Quotient: "<<quotient(num1, num2)<<endl;
cout<<"Modulus: "<<remainder(num1, num2)<<endl;

 return 0;
} // end of main function

//functions
int sum(int a, int b)//sum
{
 int total;
 total= a+b;
 return total;
}//end of sum

int product(int a, int b)//product
{
 int prod;
 prod= a*b;
 return prod;
}//end of product

int average(int a, int b)//avg
{
 int avg;
 avg=(a+b)/2;
 return avg;
}//end of average

int quotient(int a, int b)//quotient
{
 int quot;
 quot= a/b;
 return quot;
}//end of quotient

int remainder(int a, int b)//remainder
{
 int mod;
 mod=a%b;
 return mod;
}//end of modulus
