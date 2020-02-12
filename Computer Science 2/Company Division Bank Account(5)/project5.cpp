//************************  PROGRAM IDENTIFICATION ****************************
//*                                                                           *
//*   PROGRAM FILE NAME:  program5.cpp   ASSIGNMENT #:  5   Grade: _______    *
//*                                                                           *
//*                                                                           *
//*   PROGRAM AUTHOR:                                    					  *
//*                   ___________________________________________________     *
//*                                      Greyson Monjay                       *
//*                                                                           *
//*   COURSE #:  CSC 24400 11                  DUE DATE: November 20th, 2019  *
//*                                                                           *
//*****************************************************************************

//*************************** PROGRAM DESCRIPTION *****************************
//*																			  *
//*		This program interprets budget data for five divisions of a company.  *
//*		It reads an input file which gives it initial values for the 		  *
//*		divisions alongside actions to take regarding their budgets.	      *
//*		This program also prints out division and company data in the format  *
//*		of a formatted list.												  *
//*																			  *
//*		USER DEFINED CLASSES												  *
//*			Division - Company division with financial data.				  *
//*		USER DEFINED FUNCTIONS												  *
//*			Division.GetID - Returns the Division's 4 digit ID number.		  *
//*			Division.GetBalance - Returns the Division's balance.			  *
//*			Division.GetCredit - Returns the Division's credit value (income) *
//*			Division.GetDebit - Returns the Division's debit value (spending) *
//*			Division.Initialize - Sets inital values for division variables.  *
//*			Division.Income - Adds income to the division.					  *
//*			Division.Outflow - Applys spending to the division.				  *
//*			Division.PrintData - Prints Division data w/ formatted spacing	  *
//*			ReadData - reads a line of input from a file and does various	  *
//					   things depending on the data read.					  *
//*																			  *
//*****************************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

//*****************************************************************************

class Division
{
	public:
		Division(int);
		int GetID();
		float GetBalance();
		float GetCredit();
		float GetDebit();
		void Initialize(float, float, float);
		void Income(float);
		void Outflow(float);
		void PrintData(ofstream &);
	private:
		int ID;
		float balance;
		float credit;
		float debit;
};

//*****************************************************************************

bool ReadData(ifstream &,ofstream &, Division &, Division &, Division &, Division &, Division &, Division &);
void Header(ofstream &);
void Footer(ofstream &);

//*****************************************************************************

int main()
{

	ifstream InFile("DATA5.TXT",ios::in);
	ofstream OutFile("output.txt",ios::out);
	Header(OutFile);
	bool sentinel = true;

	Division d1(2017);
	Division d2(3026);
	Division d3(4039);
	Division d4(6049);
	Division d5(7052);
	Division corp(9999);

	while(sentinel)
	{
		sentinel = ReadData(InFile,OutFile,d1,d2,d3,d4,d5,corp);
	}
	Footer(OutFile);
}

//*****************************************************************************

bool ReadData(ifstream &InFile, ofstream &OutFile, Division &d1,  Division &d2, Division &d3, Division &d4, Division &d5, Division &corp)
{
	//GIVEN - 	Input File, Output File, and all Division objects.
	//TASK -	Reads input file, and does different tasks depending on the 
	//			character that was read.
	//				I - Takes in 4 values, and initializes a Division using 
	//					these values.
	//				C - Takes in 2 values, and adds credit to the given
	//					Division.
	//				D - Takes in 2 values, and adds debit to the given
	//					Division.
	//				P - Given either E or S afterwards
	//					E - Every Division's data is printed in a formatted
	//						list, alongside the companies overall data.
	//					S - A specific division's data is printed.
	//				Q - Sentinel.
	//
	//RETURN - 	Boolean value for sentinel detection.

	char op;
	int IDBuffer;
	float CreditBuffer;
	float DebitBuffer;
	float BalanceBuffer;

	InFile >> op;

	switch(op)
	{

		case 'I':
			InFile >> IDBuffer;
			InFile >> CreditBuffer;
			InFile >> DebitBuffer;
			InFile >> BalanceBuffer;
			switch(IDBuffer)
			{

				case 2017:
					d1.Initialize(CreditBuffer,DebitBuffer,BalanceBuffer);
					corp.Initialize(corp.GetCredit() + CreditBuffer,corp.GetDebit() + DebitBuffer,corp.GetBalance() + BalanceBuffer);
					break;
				case 3026:
					d2.Initialize(CreditBuffer,DebitBuffer,BalanceBuffer);
					corp.Initialize(corp.GetCredit() + CreditBuffer,corp.GetDebit() + DebitBuffer,corp.GetBalance() + BalanceBuffer);
					break;
				case 4039:
					d3.Initialize(CreditBuffer,DebitBuffer,BalanceBuffer);
					corp.Initialize(corp.GetCredit() + CreditBuffer,corp.GetDebit() + DebitBuffer,corp.GetBalance() + BalanceBuffer);
					break;
				case 6049:
					d4.Initialize(CreditBuffer,DebitBuffer,BalanceBuffer);
					corp.Initialize(corp.GetCredit() + CreditBuffer,corp.GetDebit() + DebitBuffer,corp.GetBalance() + BalanceBuffer);
					break;
				case 7052:
					d5.Initialize(CreditBuffer,DebitBuffer,BalanceBuffer);
					corp.Initialize(corp.GetCredit() + CreditBuffer,corp.GetDebit() + DebitBuffer,corp.GetBalance() + BalanceBuffer);
					break;

			}
			return true;
			break;
		case 'C':
			InFile >> IDBuffer;
			InFile >> CreditBuffer;
			switch(IDBuffer)
			{

				case 2017:
					d1.Income(CreditBuffer);
					corp.Income(CreditBuffer);
					break;
				case 3026:
					d2.Income(CreditBuffer);
					corp.Income(CreditBuffer);
					break;
				case 4039:
					d3.Income(CreditBuffer);
					corp.Income(CreditBuffer);
					break;
				case 6049:
					d4.Income(CreditBuffer);
					corp.Income(CreditBuffer);
					break;
				case 7052:
					d5.Income(CreditBuffer);
					corp.Income(CreditBuffer);
					break;

			}
			return true;
			break;
		case 'D':
			InFile >> IDBuffer;
			InFile >> DebitBuffer;
			switch(IDBuffer)
			{

				case 2017:
					d1.Outflow(DebitBuffer);
					corp.Outflow(DebitBuffer);
					break;
				case 3026:
					d2.Outflow(DebitBuffer);
					corp.Outflow(DebitBuffer);
					break;
				case 4039:
					d3.Outflow(DebitBuffer);
					corp.Outflow(DebitBuffer);
					break;
				case 6049:
					d4.Outflow(DebitBuffer);
					corp.Outflow(DebitBuffer);
					break;
				case 7052:
					d5.Outflow(DebitBuffer);
					corp.Outflow(DebitBuffer);
					break;

			}
			return true;
			break;
		case 'P':
			InFile >> op;

			switch(op)
			{

				case 'E':

					OutFile.setf(ios::right) ;
					OutFile.setf(ios::fixed) ;   
					OutFile.precision(2);

					OutFile << "               Amount of     Amount of      Account" << endl;
					OutFile << "Division ID    Credits       Debits         Balance" << endl;
					OutFile << "---------------------------------------------------" << endl;
					d1.PrintData(OutFile);
					d2.PrintData(OutFile);
					d3.PrintData(OutFile);
					d4.PrintData(OutFile);
					d5.PrintData(OutFile);
					OutFile << "---------------------------------------------------" << endl;
					OutFile << "Corporation                                        " << endl;
					OutFile << "Totals" << setw(16) << corp.GetCredit();
					OutFile << setw(14) << corp.GetDebit();
					OutFile << setw(15) << corp.GetBalance();
					OutFile << endl << endl;
					OutFile << "***************************************************" << endl << endl;

					break;

				case 'S':

					OutFile.setf(ios::right) ;
					OutFile.setf(ios::fixed) ;   
					OutFile.precision(2);

					OutFile << "               Amount of     Amount of      Account" << endl;
					OutFile << "Division ID    Credits       Debits         Balance" << endl;
					OutFile << "---------------------------------------------------" << endl;
					switch(IDBuffer)
					{

						case 2017:
							d1.PrintData(OutFile);
							break;
						case 3026:
							d2.PrintData(OutFile);
							break;
						case 4039:
							d3.PrintData(OutFile);
							break;
						case 6049:
							d4.PrintData(OutFile);
							break;
						case 7052:
							d5.PrintData(OutFile);
							break;

					}
					OutFile << endl;
					OutFile << "***************************************************" << endl << endl;

					break;



			}
			return true;
			break;

		case 'Q':
			return false;
			break;


	}
}

//*****************************************************************************

Division::Division(int inputID)

{
	//GIVEN - 	integer ID value
	//TASK -	Constructs a new Division object.
	//RETURN - 	N/A

	ID = inputID;
	balance = 0.0;
	credit = 0.0;
	debit = 0.0;

}

//*****************************************************************************

void Division::Initialize(float cdt, float dbt, float bal)
{
	//GIVEN - 	Credit, Debit, and Balance values
	//TASK -	Sets the object's variables to these values.
	//RETURN - 	N/A

	balance = bal;
	credit = cdt;
	debit = dbt;

}

//*****************************************************************************

float Division::GetBalance()
{
	//GIVEN - 	N/A
	//TASK -	N/A
	//RETURN - 	Division Balance

	return balance;

}

//*****************************************************************************

float Division::GetCredit()
{
	//GIVEN - 	N/A
	//TASK -	N/A
	//RETURN - 	Division Credit


	return credit;

}

//*****************************************************************************

float Division::GetDebit()
{
	//GIVEN - 	N/A
	//TASK -	N/A
	//RETURN - 	Division Debit


	return debit;

}

//*****************************************************************************

int Division::GetID()
{
	//GIVEN - 	N/A
	//TASK -	N/A
	//RETURN - 	Division ID


	return ID;

}

//*****************************************************************************

void Division::Income(float cdt)
{
	//GIVEN - 	Float Credit Value
	//TASK -	Adds the given credit value to the Division's balance and
	//			credit values.
	//RETURN - 	N/A


	credit += cdt;

	balance += cdt;

}

//*****************************************************************************

void Division::Outflow(float dbt)
{
	//GIVEN - 	Float Debit Value
	//TASK -	Adds the given debit value to the Division's debit and
	//			subtracts it from the Division's balance.
	//RETURN - 	N/A

	debit += dbt;

	balance -= dbt;

}

//*****************************************************************************

void Division::PrintData(ofstream &OutFile)
{
	//GIVEN - 	Output file
	//TASK -	Prints Division Data with formatted spacing
	//RETURN - 	N/A

	OutFile << setw(7) << ID;
	OutFile << setw(15) << credit;
	OutFile << setw(14) << debit;
	OutFile << setw(15) << balance << endl;

}

//****************************  FUNCTION HEADER  ******************************
void Header( ofstream &Outfile) 
{              // Receives – the output file
               // Task - Prints the output preamble
               // Returns - Nothing
   Outfile << setw(30) << "Greyson Monjay ";
   Outfile << setw(17) << "CSC 24400"; 
   Outfile << setw(15) << "Section 11" << endl;
   Outfile << setw(30) << "Fall 2019";
   Outfile << setw(20) << "Assignment #1" << endl;
   Outfile << setw(35) << "-----------------------------------";
   Outfile << setw(35) << "-----------------------------------" << endl << endl;
   return;
  }
//********************** END OF FUNCTION HEADER  ************************

//*************************  FUNCTION FOOTER  ***************************
void Footer (ofstream &Outfile) 
{
               // Receives – the output file
               // Task - Prints the output salutation
               // Returns - Nothing
   Outfile << endl;
   Outfile << setw(35) << " --------------------------------- " << endl;
   Outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;
   Outfile << setw(35) << " --------------------------------- " << endl;

   return;
  }
//********************* END OF FUNCTION FOOTER  ***********************