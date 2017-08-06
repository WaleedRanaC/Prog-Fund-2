//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : November 12 2016
// Status    : Complete
//
// This program will be used to do assignment 7
//******************************************************************
/* PROMPT*/
#include <iostream>				// for cin, cout, endl
#include<cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
struct Student
{
	string name;
	int test[3];
	string letterGrade;
};
//prototypes
void input(Student [], int);
void output(Student [], int);
double average(Student [], int);
void letterGrade(Student [], int);
void bubbleSort(Student[], int);

int main()						
{ 
	//variables
	int numStudents=0;
	cout<<"Enter the number of students ";
	cin>>numStudents;
	
	Student stu [numStudents];
	
	//processing
	input(stu, numStudents);
	bubbleSort(stu, numStudents);
	output(stu, numStudents);
	
	//output
	cout<<"******************************"<<endl;
	cout<<"Average: "<<average(stu, numStudents)<<endl;
	
 return 0;
}   // end of main function

void input(Student stu[], int numStudents)
{
	for (int i=0; i<numStudents; i++)
	{
		cout<<"Student "<<i<<endl;
		cout<<"Enter the student's name: ";
		cin>>stu[i].name;
		for (int j=0; j<3; j++)
		{
			cout<<"Enter test "<<j<<": ";
			cin>>stu[i].test[j];
			while (stu[i].test[j]<0||stu[i].test[j]>105)
			{
				cout<<"Enter scores between 0-105 for test "<<i<<": ";
				cin>>stu[i].test[j];
			}
		}
		cout<<"____________"<<endl;
	}
}//end of input

void output(Student stu[], int numStudents)
{
	int *testPtr;
	for (int i=0; i<numStudents; i++)
	{
		cout<<"Name: "<<stu[i].name<<endl;
		testPtr=(stu[i].test);
		cout<<"Test: "<<*testPtr<<", "<<*(testPtr+1)<<", "<<*(testPtr+2)<<endl;
		letterGrade(stu, numStudents);
		cout<<"Letter Grade: "<<stu[i].letterGrade<<endl;
		cout<<"________________________"<<endl;
		
	}
}//end of output

double average(Student stu[], int numStudents)
{
	int sum=0;
	int count=0;
	double avg=0;
	for (int i=0; i<numStudents; i++)
	{
		for (int j=0; j<3; j++)
		{
			sum+=stu[i].test[j];
			count++;
		}
	}
	avg=sum/count;
	return avg;
}//end of average

void letterGrade(Student stu[], int numStudents)
{
	int sum=0;
	double avg=0;
	for (int i=0; i<numStudents; i++)
	{
		sum=stu[i].test[0]+stu[i].test[1]+stu[i].test[2];
		avg=sum/3;
		if (avg>=90)
		{
			stu[i].letterGrade="A";
		}
		else if (avg>=80&&avg<=89)
		{
			stu[i].letterGrade="B";
		}
		else if (avg>=70&&avg<=79)
		{
			stu[i].letterGrade="C";
		}
		else if (avg>=60&&avg<=69)
		{
			stu[i].letterGrade="D";
		}
		else
		{
			stu[i].letterGrade="F";
		}
	}
}//end of letterGrade

void bubbleSort(Student stu[], int numStudents)
{
	int temp=0;
	for (int i=0; i<numStudents; i++)
	{
		for (int k=0; k<2; k++)
		{
			for (int j=0; j<2; j++)
			{
				if (stu[i].test[j]>stu[i].test[j+1])
				{
					temp=stu[i].test[j];
					stu[i].test[j]=stu[i].test[j+1];
					stu[i].test[j+1]=temp;
				}	
			}
		}
	}
}//end of bubbleSort
