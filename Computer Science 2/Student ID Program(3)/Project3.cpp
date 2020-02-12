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
using namespace std;

void Header(ofstream &);
void Footer(ofstream &); 
void readData(ifstream &, int[], float[][4], int &);
void printData(ofstream &, int[], float[][4], int);
void hightolow(ofstream &, int[], float[][4], int);
void testAverage(ofstream &, int[], float[][4], float[], char[], int);
void sortedTestAverage(ofstream &, int[], float[][4], float[], char[], int);
void printOutput(ofstream &, ifstream &, int[], float[][4], float[], char[], int);


//*************************************  FUNCTION MAIN  **********************************************
int main()
{
    //Recieves - nothing
    //Task - sets up the entire program
    //Return - nothing

    ifstream input("data3.txt", ios::in);
    ofstream output("output.txt", ios::out);

    int ID[50];
    float scores[50][4];
    float average[50];
    char grade[50];
    int counter;

    Header(output);
    printOutput(output, input, ID, scores, average, grade, counter);
    Footer(output);

    return 0;
}
//*********************************  END OF FUNCTION MAIN  *******************************************


//*************************************  FUNCTION READDATA  ******************************************
void readData(ifstream &input, int ID[], float scores[][4], int &counter)
{
    //Recieves - an input file, an array of IDs, a multidimensional array of scores, and a counter
    //Task - reads the data from the input file and changes the arrays accordingly
    //Return - nothing

    int IDnum;
    float score1;
    float score2;
    float score3;
    float score4;
    counter = 0;
                //sets all the data equal to the correct variable
    input >> IDnum;
    input >> score1;
    input >> score2;
    input >> score3;
    input >> score4;
                //Reads through all the data and stores them in the correct arrays
    while (IDnum > 0)
    {
        ID[counter] = IDnum;
        scores[counter][0] = score1;
        scores[counter][1] = score2;
        scores[counter][2] = score3;
        scores[counter][3] = score4;
                //adds one to the amount of students
        counter++;
                //reads in the next 5 numbers
        input >> IDnum;
        input >> score1;
        input >> score2;
        input >> score3;
        input >> score4;
    }
}
//*********************************  END OF FUNCTION READDATA  ****************************************


//*********************************  FUNCTION PRINTDATA  **********************************************
void printData(ofstream &output, int ID[], float scores[][4], int counter)
{
    //Recieves - an output file, an array of IDs, a multidimensional array of scores, and a counter
    //Task - prints all of the original data to the output file
    //Return - changes output file accordingly

    output << "The original student data is:" <<endl;
    output << "Student ID     Test 1   Test 2   Test 3   Test 4" << endl;
    output << "------------   ------   ------   ------   ------" << endl;

                //prints output to file
    output.setf(ios::fixed);
    output.unsetf(ios::right);

    for (int i = 0; i < counter; i++)
    {
        output << setw(8) << setprecision(1) << ID[i];
        output << setw(12) << setprecision(1) << scores[i][0];
        output << setw(9) << setprecision(1) << scores[i][1];
        output << setw(9) << setprecision(1) << scores[i][2];
        output << setw(9) << setprecision(1) << scores[i][3] << endl;
    }
}
//******************************  END OF FUNCTION PRINTDATA  ******************************************


//*************************************  FUNCTION HIGHTOLOW  ******************************************
void hightolow(ofstream &output, int ID[], float scores[][4], int counter)
{
    //Recieves - an output file, an array of ints, a multidimensional array of scores, and a counter
    //Task - sorts the student ID's from high to low and prints to the output
    //Return - changes output accordingly

                //sorts the array from highest to lowest ID
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter; j++)
        {
                //checks if the ID is greater
            if(ID[i] > ID[j])
            {
                //changes arrays accordingly
                int highest = ID[j];
                int temp = ID[i];
                ID[i] = highest;
                ID[j] = temp;

                float highscore1 = scores[j][0];
                float highscore2 = scores[j][1];
                float highscore3 = scores[j][2];
                float highscore4 = scores[j][3];
                float temp1 = scores[i][0];
                float temp2 = scores[i][1];
                float temp3 = scores[i][2];
                float temp4 = scores[i][3];

                scores[i][0] = highscore1;
                scores[i][1] = highscore2;
                scores[i][2] = highscore3;
                scores[i][3] = highscore4;
                scores[j][0] = temp1;
                scores[j][1] = temp2;
                scores[j][2] = temp3;
                scores[j][3] = temp4;
            }
        }
    }
                //prints output to file
    output << "The list of students sorted by ID number high to low is:" <<endl;
    output << "Student ID     Test 1   Test 2   Test 3   Test 4" << endl;
    output << "------------   ------   ------   ------   ------" << endl;

    output.setf(ios::fixed);
    output.unsetf(ios::right);

    for (int i = 0; i < counter; i++)
    {
        output << setw(8) << setprecision(1) << ID[i];
        output << setw(12) << setprecision(1) << scores[i][0];
        output << setw(9) << setprecision(1) << scores[i][1];
        output << setw(9) << setprecision(1) << scores[i][2];
        output << setw(9) << setprecision(1) << scores[i][3] << endl;
    }
}
//********************************** END OF FUNCTION HIGHTOLOW  ***************************************


//*********************************** FUNCTION TESTAVERAGE  *******************************************
void testAverage(ofstream &output, int ID[], float scores[][4], float average[], char grade[], int counter)
{
    //Recieves - an output file, an array of ints, a multidimensional array of scores, and a counter
    //Task - gets teh test avergaes of all the students
    //Return - changes output accordingly

                //gets the averages of 4 tests for each student
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            average[i] += scores[i][j];
        }
        average[i] = average[i]/4;
    }
                //checks the test average to get the right letter grade
    for (int i = 0; i < counter; i++)
    {
        int aver = average[i]/10;
        switch (aver)
        {
            case 1: case 2: case 3:
            case 4: case 5:
                grade[i] = 'F';
                break;
            case 6:
                grade[i] = 'D';
                break;
            case 7:
                grade[i] = 'C';
                break;
            case 8:
                grade[i] = 'B';
                break;
            case 9: case 10:
                grade[i] = 'A';
                break;
            default:
                grade[i] = '!';
        }
    }
                //prints output to file
    output << "The list of students with their test average and course grade is:" <<endl;
    output << "                                                   Test      Course" << endl;
    output << "Student ID     Test 1   Test 2   Test 3   Test 4   Average   Grade " << endl;
    output << "------------   ------   ------   ------   ------   -------   ------" << endl;

    output.setf(ios::fixed);
    output.unsetf(ios::right);

    for (int i = 0; i < counter; i++)
    {
        output << setw(8) << setprecision(1) << ID[i];
        output << setw(12) << setprecision(1) << scores[i][0];
        output << setw(9) << setprecision(1) << scores[i][1];
        output << setw(9) << setprecision(1) << scores[i][2];
        output << setw(9) << setprecision(1) << scores[i][3];
        output << setw(10) << setprecision(2) << average[i];
        output << setw(7) << grade[i] << endl; 
    }
}
//******************************** END OF FUNCTION TESTAVERAGE  ***************************************

//******************************** FUNCTION SORTEDTESTAVERAGE  ****************************************
void sortedTestAverage(ofstream &output, int ID[], float scores[][4], float average[], char grade[], int counter)
{
    //Recieves - an output file, an array of ints, a multidimensional array of scores, an array of averages, an array of letter grades, and a counter
    //Task - sorts the student test averages from high to low and prints to the output
    //Return - changes output accordingly

                //checks the array to sort
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter; j++)
        {
                //checks the average is greater than another students average
            if (average[i] > average[j])
            {
                //changes arrays accordingly
                float highest = average[j];
                float temp = average[i];
                average[i] = highest;
                average[j] = temp;

                int highID = ID[j];
                int tempID = ID[i];
                ID[i] = highID;
                ID[j] = tempID;

                float highscore1 = scores[j][0];
                float highscore2 = scores[j][1];
                float highscore3 = scores[j][2];
                float highscore4 = scores[j][3];
                float temp1 = scores[i][0];
                float temp2 = scores[i][1];
                float temp3 = scores[i][2];
                float temp4 = scores[i][3];

                scores[i][0] = highscore1;
                scores[i][1] = highscore2;
                scores[i][2] = highscore3;
                scores[i][3] = highscore4;
                scores[j][0] = temp1;
                scores[j][1] = temp2;
                scores[j][2] = temp3;
                scores[j][3] = temp4;

                char letter = grade[i];
                char highLetter = grade[j];
                grade[i] = highLetter;
                grade[j] = letter;
            }
        }
    }

                //prints output to file
    output << "The list of students with their test average high to low is:" <<endl;
    output << "                                                   Test      Course" << endl;
    output << "Student ID     Test 1   Test 2   Test 3   Test 4   Average   Grade" << endl;
    output << "------------   ------   ------   ------   ------   -------   ------" << endl;

    output.setf(ios::fixed);
    output.unsetf(ios::right);

    for (int i = 0; i < counter; i++)
    {
        output << setw(8) << setprecision(1) << ID[i];
        output << setw(12) << setprecision(1) << scores[i][0];
        output << setw(9) << setprecision(1) << scores[i][1];
        output << setw(9) << setprecision(1) << scores[i][2];
        output << setw(9) << setprecision(1) << scores[i][3];
        output << setw(10) << setprecision(2) << average[i];
        output << setw(7) << grade[i] << endl; 
    }
}
//***************************** END OF FUNCTION SORTEDTESTAVERAGE  ************************************


//***************************** END OF FUNCTION SORTEDTESTAVERAGE  ************************************
void printOutput(ofstream &output, ifstream &input, int ID[], float scores[][4], float average[], char grade[], int counter)
{
    //Recieves - an output file, an input file, an array of ID numbers, a multidimensional array of scores, an array of averages, an array of letter grades, and a counter
    //Task - prints everything to the output file
    //Return - changes output accordingly
    readData(input, ID, scores, counter);
    printData(output, ID, scores, counter);
    output << endl;
    hightolow(output, ID, scores, counter);
    output << endl;
    testAverage(output, ID, scores, average, grade, counter);
    output << endl;
    sortedTestAverage(output, ID, scores, average, grade, counter);
    output << endl;
}
//***************************** END OF FUNCTION SORTEDTESTAVERAGE  ************************************


//*************************************** FUNCTION HEADER *********************************************
void Header(ofstream &Outfile)
{
    // Receives – the output file               
    // Task - Prints the output preamble               
    // Returns - Nothing   
    Outfile << setw(30) << "Maddie Talley ";   
    Outfile << setw(17) << "CSC 24400";   
    Outfile << setw(15) << "Section 11" << endl;  
    Outfile << setw(30) << "Fall 2019";   
    Outfile << setw(20) << "Assignment #4" << endl;   
    Outfile << setw(35) << "-----------------------------------";   
    Outfile << setw(35) << "-----------------------------------" << endl << endl;   
    return;
}
//*********************************** END OF FUNCTION HEADER ******************************************


//*************************************** FUNCTION FOOTER *********************************************
void Footer(ofstream &Outfile)
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
//********************************** END OF FUNCTION FOOTER *******************************************