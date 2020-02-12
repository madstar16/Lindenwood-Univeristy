//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  project2.cpp          ASSIGNMENT #:  2            Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:                                                                                 *
//*                   ___________________________________________________                             *
//*                                     Maddie Talley                                                 *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11                              DUE DATE: October 9, 2019                  *
//*                                                                                                   *
//*****************************************************************************************************
//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS:  This program reads the data from the input file and creates a regular array with ID   *
//*             numbers and a multidimensional array that corresponds with the ID array. The program  *
//*             then prints the original data, the ID numbers sorted from high to low, calculates the *
//*             average and gets the course grade, and sorts the test averages from high to low       *
//*                                                                                                   *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     :        Header - prints the class header in the output                            *
//*                         Footer - prints the end of program output                                 *
//*                         readData -  reads in the data from the input txt file                     * 
//*                         printData - prints the data read in to the output file                    *
//*                         hightolow - prints the data from the highest ID to the lowest             *
//*                         testAverage - prints the test averages and letter grade                   *
//*                         sortedTestAverage - prints the test averages sorted from high to low      *
//*                         printOutput - uses all of the above function to print in the main function*
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define sentinel "No"
using namespace std;

int main();
void Header(ofstream &);
void Footer(ofstream &); 
void readData(ifstream &, string[], string[], float[][4], int &);
void printData(ofstream &, string[], string[], float[][4], int);
void lastAtoZ(ofstream &, string[], string[], float[][4], int);
void testAverage(ofstream &, string[], string[], float[][4], float[], char[], int);
void sortedTestAverage(ofstream &, string[], string[], float[][4], float[], char[], int);
void printOutput(ofstream &, ifstream &, string[], string[], int[], float[][4], float[], char[], int);

//************************************  FUNCTION MAIN  *************************************************
int main()
{
    ifstream input("data4.txt", ios::in);
    ofstream output("output.txt", ios::out);

    string First[50];
    string Last[50];
    float scores[50][4];
    int counter;
    
    readData(input, First, Last, scores, counter);
    printData(output, First, Last, scores, counter);

    return 0;
}
//***********************************  END OF FUNCTION MAIN  *******************************************

//************************************  FUNCTION READDATA  *********************************************
void readData(ifstream &input, string First[], string Last[], float scores[][4], int &counter)
{
    string first;
    string last;
    int score1;
    int score2;
    int score3;
    int score4;

    counter = 0;    
    getline(input, first);
    getline(input, last);

    input >> score1;
    input >> score2;
    input >> score3;
    input >> score4;


    while (first.compare(sentinel) != 0)
    {
        First[counter] = first;
        Last[counter] = last;

        scores[counter][0] = score1;
        scores[counter][1] = score2;
        scores[counter][2] = score3;
        scores[counter][3] = score4;

        getline(input, first);
        getline(input, last);

        input >> score1;
        input >> score2;
        input >> score3;
        input >> score4;

        counter++;
    }
}
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void printData(ofstream &output, string first[], string last[], float scores[][4], int counter)
{
    output << " The original student data is:" << endl;
    output << "     Student Name" << endl;
    output << "  First       Last          Test 1   Test 2   Test 3   Test 4" << endl;
    output << "----------    ----------    ------   ------   ------   ------" << endl;

    output.setf(ios::fixed);
    output.unsetf(ios::right);

    for (int i = 0; i < counter; i++)
    {
        output << setw(8) << first[i];
        output << setw(8) << last[i];
    }

    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            output << setw(8) << setprecision(2) << scores[i][j];
        }
    }
}
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void lastAtoZ(ofstream &, string[], string[], float[][4], int);
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void testAverage(ofstream &, string[], string[], float[][4], float[], char[], int);
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void sortedTestAverage(ofstream &, string[], string[], float[][4], float[], char[], int);
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void printOutput(ofstream &, ifstream &, string[], string[], int[], float[][4], float[], char[], int);
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void Header(ofstream &);
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void Footer(ofstream &); 
//*********************************  END OF FUNCTION READDATA  *****************************************