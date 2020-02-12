//*****************************  PROGRAM IDENTIFICATION  *****************************
//*                                                                                  *
//*  PROGRAM FILE NAME:  project1.cpp    ASSIGNMENT #:  1       Grade: _________     *
//*                                                                                  *
//*   PROGRAM AUTHOR:                                                                *
//*                   ___________________________________________________            *
//*                                     Maddie Talley                                *
//*                                                                                  *
//*   COURSE #:  CSC 36000 11                           DUE DATE: February 7, 2020   *
//*                                                                                  *
//************************************************************************************
//*******************************  PROGRAM DESCRIPTION  ******************************
//*                                                                                  *
//*   PROCESS: This program reads in data from passengers who have picked a flight,  *
//*   section, row, and column. The seats are on a first come first serve basis. If  *
//*   a seat is already taken it checks the row. If the row is full, then it checks  *
//*   the selected column. If the column is full then it starts at the top of the    *
//*   selected section and goes down the rows in order. If all seats are taken in    *
//*   the selected section then the passneger is put on the waitlist. Switching      *
//*   sections is not allowed.                                                       *
//*                                                                                  *
//************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//*****************************  STRUCTURE PASSENGERTYPE  ****************************
struct PassengerType
{
    int boardNum;
    int flightNum;
    char section;
    int row;
    char column;
};
//*************************  END OF STRUCTURE PASSENGERTYPE  *************************

void readData(ifstream &, PassengerType[], int &);
int findFlight(int flightNum);
int findColumn(char column);
int checkOccupied(int, int, int, int[8][10][3]);
void assignSpot(int , int, int, int, char, int[8][10][3], int[][50], int[]);
void printData(ofstream &, int[8][10][3], int[][50], int[]);
void initalizeArr(int[8][10][3]);
void Header(ofstream &);
void Footer(ofstream &);

//*********************************  FUNCTION MAIN  **********************************
int main()
{
    //Recieves - nothing
    //Task - sets up the entire program
    //Return - nothing

            //create input file and output file
    ifstream input("data1.txt", ios::in);
    ofstream output("output.txt", ios::out);

            //create an int 3D array, a PassengerType array, a 2D int array, an int
            //array, and an int
    int Flights[8][10][3];
    PassengerType passenger[500];
    int waitList[8][50];
    int size[8];
    int count;

            //call initalize, readdata, assignspot, header, printdata, and footer
            //with the correct parameters
    initalizeArr(Flights);
    readData(input, passenger, count);
    cout << passenger[222].boardNum << endl;
    for (int i = 0; i < count; i++)
    {
        assignSpot(passenger[i].flightNum, passenger[i].column, passenger[i].row, 
        passenger[i].boardNum, passenger[i].section, Flights, waitList, size);
    }
    Header(output);
    printData(output, Flights, waitList, size);
    Footer(output);

    return 0;
}
//******************************  END OF FUCNTION MAIN  ******************************

//********************************  FUCNTION READDATA  *******************************
void readData(ifstream &input, PassengerType passenger[], int &count)
{
    //Recieves - an input stream, a PassengerType array, and an int
    //Task - reads every passengers data into the passenger array
    //Return - array of passengers and an int

            //create a temp passenger
    PassengerType temp;

            //read in the first int into the temp passenger board number
    input >> temp.boardNum;

            //read the data until boardnumber is less than 0
    while(temp.boardNum > 0)
    {
            //read the data into the temp passenger for the flight number, the
            //section, the row, and the column
        input >> temp.flightNum;
        input >> temp.section;
        input >> temp.row;
        input >> temp.column;

            //store the temp passenger into the passenger array
        passenger[count] = temp;
            //add one to the amount of passengers
        count++;

            //read in the next boarding number into temp
        input >> temp.boardNum;
    }
}
//*****************************  END OF FUCNTION READDATA  ***************************

//*******************************  FUCNTION FINDFLIGHT  ******************************
int findFlight(int flightNum)
{
    //Recieves - an int for flight numbers
    //Task - changes the flight number to a number from 0-7 to match the array
    //Return - an int for the new flight number

            //check the flight number for the specific passenger and return a number
            // 0-7 based on the 3D array
    switch (flightNum)
	{
	case 1010: 
		return 0;
		break;
	case 1015: 
		return 1;
		break;
	case 1020: 
		return 2;
		break;
	case 1025: 
		return 3;
		break;
	case 1030: 
		return 4;
		break;
	case 1035: 
		return 5;
		break;
	case 1040: 
		return 6;
		break;
	case 1045: 
		return 7;
		break;
    }
}
//****************************  END OF FUCNTION FINDFLIGHT  **************************

//*******************************  FUCNTION FINDCOLUMN  ******************************
int findColumn(char column)
{
    //Recieves - a char that is a column
    //Task - changes the char into a number from 0-2 to match the array
    //Return - an int for the column

            //check the column for the specific passenger and return a number 0-2 
            //based on the array
    switch (column) {
	case 'L':
		return 0;
		break;
	case 'M':
		return 1;
		break;
	case 'R':
		return 2;
		break;
	}
}
//****************************  END OF FUCNTION FINDCOLUMN  **************************

//******************************  FUCNTION CHECKOCCUPIED  ****************************
int checkOccupied(int flightNum, int row, int column, int Flights[8][10][3])
{
    //Recieves - an int for flight number, an int for a row, and int for a column, and
    //           the flights 3D array
    //Task - checks if the requested seat is taken or not 
    //Return - an int that is a 0 or 1

            //check if the specified spot is taken or not and returns a 0 or 1
    if (Flights[flightNum][row][column] == -999)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//***************************  END OF FUCNTION CHECKOCCUPIED  ************************

//*******************************  FUCNTION ASSIGNSPOT  ******************************
void assignSpot(int flightNum, int column, int row, int boardNum, char section, 
int Flights[8][10][3], int waitList[][50], int size[])
{
    //Recieves - an int that is a flight number, an int that is a column, an int 
    //           that is a row, an int that is a boarding number, a char that is the
    //           section, an int 3D array of all the flights, an int 2D array for
    //           the waitlist, and an int array for the size of the waitlist
    //Task - assigns the specific passenger to a seat on the requested flight and 
    //       section
    //Return - a 3D array fo the Flights, a 2D array of the waitlists, and an array
    //         to get the size of the waitlists

                //create an int
        int isOccupied;
                //find the flight and the column numbers and store them into two ints
        flightNum = findFlight(flightNum);
        column = findColumn(column);
                //subtract the row number by 1
        row = row - 1;
                //check if the specified seat is occupied and store it into an int 
                //isOccupied
        isOccupied = checkOccupied(flightNum, row, column, Flights);

                //if isOccupied is 0 then store the board number into the spot
                //and exit the loop if not continue
        if (isOccupied == 0)
        {
            Flights[flightNum][row][column] = boardNum;
            return;
        }

                //checks if the specified row has any seats if it does store the boarding
                //number into the flight and exit the loop if not conitnue
        for (int c = 0; c < 3; c++)
        {
            isOccupied = checkOccupied(flightNum, row, c, Flights);
            if (isOccupied == 0)
            {
                Flights[flightNum][row][c] = boardNum;
                return;
            }
        }

                //checks is the passenger picked first class or coach. Loops through all
                //seats until an open one is found or you get to the last seat
        if (section == 'F')
        {
            for (int r = 0; r < 3; r++)
            {
                isOccupied = checkOccupied(flightNum, r, column, Flights);
                if (isOccupied == 0)
                {
                    Flights[flightNum][r][column] = boardNum;
                    return;
                }
            }

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    isOccupied = checkOccupied(flightNum, r, c, Flights);
                    if (isOccupied == 0)
                    {
                        Flights[flightNum][r][c] = boardNum;
                        return;
                    }
                }
            }

                //if no spot is found then the passenger gets put on the waitlist
            waitList[flightNum][size[flightNum]] = boardNum;
            size[flightNum]++;
            return;
        }

        else if (section == 'C')
        {
            for (int r = 3; r < 10; r++)
            {
                isOccupied = checkOccupied(flightNum, r, column, Flights);
                if (isOccupied == 0)
                {
                    Flights[flightNum][r][column] = boardNum;
                    return;
                }
            }

            for (int r = 3; r < 10; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    isOccupied = checkOccupied(flightNum, r, c, Flights);
                    if (isOccupied == 0)
                    {
                        Flights[flightNum][r][c] = boardNum;
                        return;
                    }
                }
            }

                //if no spot is found then the passenger gets put on the waitlist
            waitList[flightNum][size[flightNum]] = boardNum;
            size[flightNum]++;
            return;
        }
}
//****************************  END OF FUCNTION ASSIGNSPOT  **************************

//********************************  FUCNTION PRINTDATA  ******************************
void printData(ofstream &output, int Flights[8][10][3], int waitList[][50], 
int size[])
{
    //Recieves - an outout stream, a 3D array of al the flights, a 2D array of the
    //           waitlist, and an int array of the size of the waitlist
    //Task - prints all needed data to the output file
    //Return - an int 3D array of all the flights, an int 2D array of the waitlist,
    //         and an array of the size of the waitlist
                    //loop through all 8 flights
    for (int p = 0; p < 8; p++)
    {
                    //print all flight info
        switch(p)
        {
            case 0:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1010";
                output << setw(59) << "FROM: Jackson, Mississippi" << endl;
                output << setw(65) << "TO: Memphis, Tennesse" << endl;
                output << endl;
                break;
            case 1:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1015";
                output << setw(57) << "FROM: Memphis, Tennessee" << endl;
                output << setw(68) << "TO: Jackson, Mississippi" << endl;
                output << endl;
                break;
            case 2:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << setw(11) << "Flight 1020";
                output << setw(59) << "FROM: Jackson, Mississippi" << endl;
                output << setw(100) << "TO: Little Rock, Arkansas" << endl;
                output << endl;
                break;
            case 3:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1025";
                output << setw(60) << "FROM: Little Rock, Arkansas" << endl;
                output << setw(69) << "TO: Jackson, Mississippi" << endl;
                output << endl;
                break;
            case 4:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1030";
                output << setw(59) << "FROM: Jackson, Mississippi" << endl;
                output << setw(70) << "TO: Shreveport, Louisiana" << endl;
                output << endl;
                break;
            case 5:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1035";
                output << setw(70) << "FROM: Shreveport, Louisiana" << endl;
                output << setw(69) << "TO: Jackson, Mississippi" << endl;
                output << endl;
                break;
            case 6:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1040";
                output << setw(59) << "FROM: Jackson, Mississippi" << endl;
                output << setw(68) << "TO: Huntsville, Alabama" << endl;
                output << endl;
                break;
            case 7:
                output << setw(50) << "Southern Comfort Airlines" << endl;
                output << endl;
                output << setw(11) << "Flight 1045";
                output << setw(58) << "FROM: Huntsville, Alabama" << endl;
                output << setw(69) << "TO: Jackson, Mississippi" << endl;
                output << endl;
                break;
        }

                    //print out all seating charts
        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                output <<  setw(15) << Flights[p][r][c];
            }
            output << endl;
        }

        output << endl;
                    //print out waiting list
        output << "WAITING LIST" << endl;

                    //if the size of the waiting list is 0 print out
                    //There is no waiting list for this flight
        if (size[p] == 0)
        {
            output << "There is no waiting list for this flight." << endl << endl;
        }
                    //print out the waitng list array
        else
        {
            for (int j = 0; j < size[p]; j++)
            {
                output << waitList[p][j] << endl << endl;
            }
        }
        
    }
}
//*****************************  END OF FUCNTION PRINTDATA  **************************

//*******************************  FUCNTION INITALIZEARR  ****************************
void initalizeArr(int Flights[8][10][3])
{
    //Recieves - an int 3D array of all the flights
    //Task - makes every element in the flights arra -99
    //Return - an int 3D array of all the flighs
    
                //make every element in the flights array -999
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                Flights[i][j][k] = -999;
            }
        }
    }
}
//***************************  END OF FUCNTION INITALIZEARR  *************************

//*********************************  FUNCTION HEADER  ********************************
void Header( ofstream &Outfile) 
{             
    // Receives – the output file               
    // Task - Prints the output preamble               
    // Returns - Nothing   
    Outfile << setw(30) << "Maddie Talley ";   
    Outfile << setw(17) << "CSC 36000";    
    Outfile << setw(15) << "Section 11" << endl;   
    Outfile << setw(30) << "Spring 2020";   
    Outfile << setw(20) << "Assignment #1" << endl;   
    Outfile << setw(35) << "-----------------------------------";   
    Outfile << setw(35) << "-----------------------------------" << endl << endl;   
    return;
}
//*******************************  END OF FUNCTION HEADER  ***************************

//***********************************  FUNCTION FOOTER  ******************************
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
//*******************************  END OF FUNCTION FOOTER  ***************************
