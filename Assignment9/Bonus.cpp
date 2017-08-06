//******************************************************************
// Template Program
// Programmer: Alan Ngo, Cameron Tindal, Chris Carnicle, Naseem Raad, Joe Ho
// Completed : November 22 2016
// Status    : Complete
//
// This program will be used to create a cash register
//******************************************************************
/*Write an application for a fast food restaurant.
"	It will as a point of sale system at a rodeo snack bar. 
"	Create your own menu of items that are sold
"	All items are subject to an 8.25% sales tax. 
"	The program will repeatedly display the following menu until the shift is closed - E is entered. 
"	The program should keep a running total of the amount of the sale and the end of day total sales will be displayed when E is entered. 
"	If the sale is cancelled - X is entered, clear the running total and display the menu again. 
"	When the sale is totaled - T is entered, calculate the sales tax due and OUTPUT the number of all the items ordered (not the totals of each type of item), 
the total before the tax,  the tax and the final total including the tax. Use a sentinel loop.
"	Use functions with value and reference parameters where appropriate.
"	Your numeric output must be formatted to show two places after the decimal even if the value after the decimal is 0. An output of 10 should display as 10.00.
"	All output must have the appropriate labels.

*/
#include <iostream>				// for cin, cout, endl
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Transaction
{
	//Private Fields of the Class Transaction
	private:
		int numBurgers;//$5
		int numHotDogs;//$3
		int numCandy;//$1.50
		int numSoda;//$1
	
	//Public Functions in the Class Transaction			
	public:
		
	//Constructor
	Transaction()
	{
		numBurgers=0;
	 	numHotDogs=0;
		numCandy=0;
		numSoda=0;	
	}
	
	//Modifiers
	void addBurgers(int num)
	{
		numBurgers+=num;
		cout << "Added " << num << " burgers to the order." << endl;
	}
	
	void addHotDogs(int num)
	{
		numHotDogs+=num;
		cout << "Added " << num << " hot dogs to the order." << endl;
	}
	
	void addCandy(int num)
	{
		numCandy+=num;
		cout << "Added " << num << " candies to the order." << endl;
	}
	
	void addSoda(int num)
	{
		numSoda+=num;
		cout << "Added " << num << " sodas to the order." << endl;
	}
	
	//Calculation Functions
	int numItems() 
	{
		return numBurgers + numHotDogs + numCandy + numSoda;
	}
	
	double getSubTotal()
	{
		return (numBurgers*5)+(numHotDogs*3)+(numCandy*1.5)+(numSoda*1);//prices implementation
	}
	
	double getTax()	
	{
		return getSubTotal()*0.0825;//8.25% sales tax
	}
	
	double getTotal()
	{
		return getSubTotal()+getTax();
	}
	
	void completeTransaction()
	{
		showTotal();
	}
	
	void zero() 
	{
		numBurgers=0;
	 	numHotDogs=0;
		numCandy=0;
		numSoda=0;
	}
	
	void showTotal() 
	{
		cout << "Here's the final total for your order:" << endl << endl;
		
		cout<<"Number of Burgers: "<<numBurgers<<endl;
		cout<<"Number of HotDogs: "<<numHotDogs<<endl;
		cout<<"Number of Candy: "<<numCandy<<endl;
		cout<<"Number of Sodas: "<<numSoda<<endl;
		cout<<"SubToal: $"<<getSubTotal()<<endl;
		cout<<"Tax: $"<<getTax()<<endl;
		cout<<"Total: $"<<getTotal()<<endl;
	}
	
	void showSubTotal() 
	{
		
		cout << endl << "Here's the order so far:" << endl;
		
		cout<<"Number of Burgers: "<<numBurgers<<endl;
		cout<<"Number of HotDogs: "<<numHotDogs<<endl;
		cout<<"Number of Candy: "<<numCandy<<endl;
		cout<<"Number of Sodas: "<<numSoda<<endl;
		cout<<"SubTotal: $"<<getSubTotal()<<endl;
	}
}; //end of Class Transaction

//This functions shows the menu choices.
void showMenu()
{
	cout<<"******************RODEO MENU******************"<<endl;
	cout<<"Enter your choice: "<<endl;
	cout<<"(B)urgers $5.00"<<endl;
	cout<<"(H)otDogs $3.00"<<endl;
	cout<<"(C)andy $1.50"<<endl;
	cout<<"(S)oda $1.00"<<endl;
	cout<<"(T)otal"<<endl;
	cout<<"(X)Cancel Order"<<endl;
	cout<<"(E)xit"<<endl;
	cout<<"**********************************************"<<endl;	
}//end of showMenu

//This function obtains the character for the menu choice
char getChar()
{
	char choice;
	cin >> choice;
	return tolower(choice);
}

//This takes the menu character and verifies it
char getChoice()
{
	
	char choice = getChar();
	
		while (choice != 'e' && choice != 'b' && choice != 'h' && choice != 'c' && choice != 's' && choice != 'x' && choice != 't') 
			{
				cout << "Please select a valid choice." << endl;
				choice = getChoice();
			}
			
	return choice;
}

//This function calculates the Daily Total of the User
void showDayTotals(double& totalSales, double& totalTax)
{
	cout << "You have done $" << totalSales << " in sales today" << endl;
	cout << "...and $" << totalTax << " in taxes" << endl << endl;
}

//This allows the user to input more than one item at a time and makes it not possible to add a negative number
int getQuantity(string message)
{
	int quantity=0;
	cout<<"Enter how many "<<message<<"s: ";
	cin>>quantity;
	
	while(quantity < 0)
	{
		cout << "You can't buy a negative number of " << message << "s. Please enter a positive number or 0." << endl;
		cin >> quantity;
	}
	return quantity;
}

//This function runs the menu
void runMenu(Transaction& transaction, double& totalSales, double& totalTax, int& totalItems) {
	char choice;

	showMenu();
	choice = getChoice();
	
	while(choice != 'e' )
	{	
		showMenu();
		
		//Checks the Cases of the input per menu request
		switch (choice) 
		{
			case 'x':
				cout << "Transaction cancelled." << endl << endl;
				transaction.zero();
				transaction.showSubTotal();
				break;
				
			case 't':
				transaction.showTotal();
	
				totalSales += transaction.getSubTotal();
				totalTax += transaction.getTax();
				totalItems += transaction.numItems();

				transaction.zero();
	
				showDayTotals(totalSales, totalTax);
	
				cout << "New transaction:" <<endl;
	
				transaction.showSubTotal();
	
				break;
				
			case 'b':
				transaction.addBurgers(getQuantity("burger"));
				transaction.showSubTotal();
				break;
				
			case 'h':
				transaction.addHotDogs(getQuantity("hotdog"));
				transaction.showSubTotal();
				break;
				
			case 'c':
				transaction.addCandy(getQuantity("candie"));
				transaction.showSubTotal();
				break;
				
			case 's':
				transaction.addSoda(getQuantity("soda"));
				transaction.showSubTotal();
				break;
			
		}

		choice = getChoice();
	}
}

//Main Function Start
int main()						
{ 
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2); // set fixed floating format cout.precision(2)
	
	//Variables
	double totalSales=0;
	double totalTax=0;
	int totalItems=0;
	Transaction transaction;
	

	runMenu(transaction, totalSales, totalTax, totalItems);
	
	//Outputs Daily Total per User
	cout << "Here are your daily totals: " << endl;
	cout << totalItems << " items sold." << endl;
	cout << "$" << totalSales << " in sales." << endl;
	cout << "$" << totalTax << " in sales taxes." << endl;
	
	
 	return 0;
}   // end of main function
