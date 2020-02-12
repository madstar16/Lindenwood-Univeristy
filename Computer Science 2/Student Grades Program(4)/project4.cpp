//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  project4.cpp          ASSIGNMENT #:  4            Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:                                                                                 *
//*                   ___________________________________________________                             *
//*                                     Maddie Talley                                                 *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11                              DUE DATE: November 6, 2019                 *
//*                                                                                                   *
//*****************************************************************************************************
//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS:  This program reads the data from the input file and creates two arrays with the       *
//*             students name and a multidimensional array that corresponds with the ID array. The    *
//*             program then prints the original data, the last names alphabetized, calculates the    *
//*             average and gets the course grade, and sorts the test averages from high to low       *
//*                                                                                                   *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     :        Header - prints the class header in the output                            *
//*                         Footer - prints the end of program output                                 *
//*                         readData -  reads in the data from the input txt file                     * 
//*                         printData - prints the data read in to the output file                    *
//*                         lastAtoZ - prints the last names in alhpabetical order                    *
//*                         testAverage - prints the test averages and letter grade                   *
//*                         sortedTestAverage - prints the test averages sorted from high to low      *
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void Header(ofstream &);
void Footer(ofstream &); 
void readData(ifstream &, string[], string[], float[][4], int &);
void printData(ofstream &, string[], string[], float[][4], int);
void lastAtoZ(ofstream &, string[], string[], float[][4], int);
void testAverage(ofstream &, string[], string[], float[][4], float[], char[], int);
void sortedTestAverage(ofstream &, string[], string[], float[][4], float[], char[], int);

//************************************  FUNCTION MAIN  *************************************************
int main()
{
    //Recieves - nothing
    //Task - sets up the entire program
    //Return - nothing

            //create an input file and an ouput file
    ifstream input("data4.txt", ios::in);
    ofstream output("output.txt", ios::out);

            //create two string arrays, two float arrays with [50] and [50][4], a char array, and an int
    string First[50];
    string Last[50];
    float scores[50][4];
    float average[50];
    char grade[50];
    int counter = 0;
    
            //call all functions with the proper parameters
    Header(output);
    readData(input, First, Last, scores, counter);
    printData(output, First, Last, scores, counter);
    lastAtoZ(output, First, Last, scores, counter);
    testAverage(output, First, Last, scores, average, grade, counter);
    sortedTestAverage(output, First, Last, scores, average, grade, counter);
    Footer(output);

    return 0;
}
//***********************************  END OF FUNCTION MAIN  *******************************************

//************************************  FUNCTION READDATA  *********************************************
void readData(ifstream &input, string First[], string Last[], float scores[][4], int &counter)
{
    //Recieves - an input file, an array of first names, an array of 
    //           last names, an array of scores, and the amount of students
    //Task - reads in all of the data from the input file and stores its accordingly 
    //Return - an array of first names, an array of last names, an 
    //         array of test scores, and the amount of students

            //create a string eof
    string sentinel = "No";
            //create two strings
    string first;
    string last;
            //create four floats
    float score1;
    float score2;
    float score3;
    float score4;

            //set counter to 0
    counter = 0;  
    
            //get the first line of input and store it in a string
    getline(input, first);
            //get the second line of input and store it in a string
    getline(input, last);

             //erase the new line on both strings
    first.erase(remove(first.begin(), first.end(), '\r'), first.end());
    last.erase(remove(last.begin(), last.end(), '\r'), last.end());

            //read the next four numbers in the input and store it into the four floats
    input >> score1;
    input >> score2;
    input >> score3;
    input >> score4;

            //create a while loop to compare the first name to the eof
    while (first.compare(sentinel) != 0)
    {
            //store the two strings into the first name array and the last name array
        First[counter] = first;
        Last[counter] = last;

            //store the four floats into the corresponding row for the specific student
        scores[counter][0] = score1;
        scores[counter][1] = score2;
        scores[counter][2] = score3;
        scores[counter][3] = score4;

            //read in the whitespace
        input >> ws;

            //get the next line of input and store it in a string
        getline(input, first);
            //get the first line of input and store it in a string
        getline(input, last);

            //erase the new line on both strings
        first.erase(remove(first.begin(), first.end(), '\r'), first.end());
        last.erase(remove(last.begin(), last.end(), '\r'), last.end());

            //read the next four numbers in the input and store it into the four floats
        input >> score1;
        input >> score2;
        input >> score3;
        input >> score4;

            //add one to the number of students
        counter++;
    }
}
//*********************************  END OF FUNCTION READDATA  *****************************************

//*********************************  END OF FUNCTION READDATA  *****************************************
void printData(ofstream &output, string first[], string last[], float scores[][4], int counter)
{
    //Recieves - an output file, an array of first names, an array of 
    //           last names, an array of scores, and the amount of students
    //Task - prints all of the data to the output file
    //Return - changes output, an array of first names, an array of last names, and an 
    //         array of test scores


            //print grade heading to the screen
    output << " The original student data is:" << endl;
    output << "     Student Name" << endl;
    output << "  First       Last          Test 1   Test 2   Test 3   Test 4" << endl;
    output << "----------    ----------    ------   ------   ------   ------" << endl;

            //fix the printed data to the left side
    output.setf(ios::fixed);
    output.unsetf(ios::left);

            //loop through all of the students
    for (int i = 0; i < counter; i++)
    {
            //print the students first and last name and their 4 test scores
        output << setw(14) << first[i];
        output << setw(14) << last[i];
        output << setw(6) << setprecision(2) << scores[i][0];
        output << setw(9) << setprecision(2) << scores[i][1];
        output << setw(9) << setprecision(2) << scores[i][2];
        output << setw(9) << setprecision(2) << scores[i][3];
        output << endl;
    }
    output << endl;
}
//*********************************  END OF FUNCTION READDATA  *****************************************

//************************************  FUNCTION LASTATOZ  *********************************************
void lastAtoZ(ofstream &output, string first[], string last[], float scores[][4], int counter)
{
    //Recieves - an output file, an array of first names, an array of 
    //           last names, an array of scores, and the amount of students
    //Task - sorts the last names from A to Z
    //Return - changes output file, an array of first names, an array of last names, and an 
    //         array of test scores

                    //create two temp strings
    string ftemp;
    string ltemp;
    
                    //loop through all of the students
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter; j++)
        {
                    //check if the last name is of lesser value than the other
            if (last[i] < last[j])
            {
                    //change last name postion in the array
                ltemp = last[i];
                last[i] = last[j];
                last[j] = ltemp;

                    //change first name position in the array
                ftemp = first[i];
                first[i] = first[j];
                first[j] = ftemp;

                    //change score positions in the array
                float temp1 = scores[i][0];
                float temp2 = scores[i][1];
                float temp3 = scores[i][2];
                float temp4 = scores[i][3];
                scores[i][0] = scores[j][0];
                scores[i][1] = scores[j][1];
                scores[i][2] = scores[j][2];
                scores[i][3] = scores[j][3];
                scores[j][0] = temp1;
                scores[j][1] = temp2;
                scores[j][2] = temp3;
                scores[j][3] = temp4;
            }
        }
    }

                        //print grade heading to screen
    output << " The list of students sorted A thru Z by Last Name is:" << endl;
    output << "     Student Name" << endl;
    output << "  First       Last          Test 1   Test 2   Test 3   Test 4" << endl;
    output << "----------    ----------    ------   ------   ------   ------" << endl;

                        //fix the printed data to the left
    output.setf(ios::fixed);
    output.unsetf(ios::left);

                        //looop through all the stuents
    for (int i = 0; i < counter; i++)
    {
                        //print all of the student's data
        output << setw(14) << first[i];
        output << setw(14) << last[i];
        output << setw(6) << setprecision(2) << scores[i][0];
        output << setw(9) << setprecision(2) << scores[i][1];
        output << setw(9) << setprecision(2) << scores[i][2];
        output << setw(9) << setprecision(2) << scores[i][3];
        output << endl;
    }
    output << endl;
}
//*********************************  END OF FUNCTION LASTATOZ  *****************************************

//***********************************  FUNCTION TESTAVERAGE  *******************************************
void testAverage(ofstream &output, string first[], string last[], float scores[][4], float averg[], 
char grade[], int counter)
{ 
    //Recieves - an output file, an array of first names, an array of 
    //           last names, an array of scores, an array of test averages
    //           an array of letter grades, and the amount of students
    //Task - gets the student's test average and prints it to the output file
    //Return - an array of first names, an array of last names, an array 
    //         of test scores, an array of test averages, and an array of 
    //         letter grades

                //loop through all of the students
    for (int i = 0; i < counter; i++)
    {
                //create a float and set equal to 0
        float avg = 0.0;
                //loop through all of the grades
        for (int j = 0; j < 4; j++)
        {
                //add each score into the average
            avg += scores[i][j];
        }
                //divide the average by 4
        avg /= 4;
                //store average into the corresponding array spot
        averg[i] = avg;
    }

                //loop through all of the students
    for (int i = 0; i < counter; i++)
    {
                //create an int and set it equal to the corresponding 
                //average from the array and divide it by ten
        int aver = averg[i] / 10;
                //create a switch case checking the average
        switch (aver)
        {
                //if the grade is 50 or lower set the corresponding 
                //letter grade to F
            case 1: case 2: case 3:
            case 4: case 5:
                grade[i] = 'F';
                break;
                //if the grade is from 60 - 69.99 set the corresponding
                //letter grade to D
            case 6:
                grade[i] = 'D';
                break;
                //if the grade is from 70 - 79.99 set the corresponding
                //letter grade to C
            case 7:
                grade[i] = 'C';
                break;
                //if the grade is from 80 - 89.99 set the correspodning 
                //letter grade to B
            case 8:
                grade[i] = 'B';
                break;
                //if the grade is from 90 - 1000 set the corresponding
                //letter grade to A
            case 9: case 10:
                grade[i] = 'A';
                break;
                //if the grade does not fall within set the corresponding
                //letter grade to !
            default:
                grade[i] = '!';
        }
    }

                //print grade heading to screen
    output << "The list of students with their test average and course grade is:" << endl;
    output << "     Student Name" << endl;
    output << "  First       Last          Test 1   Test 2   Test 3   Test 4   Average   Grade" << endl;
    output << "----------    ----------    ------   ------   ------   ------   -------   ------" << endl;


                //fix the printed data to the left
    output.setf(ios::fixed);
    output.unsetf(ios::left);

                //loop through all of the students
    for (int i = 0; i < counter; i++)
    {
                //print all of the student's data
        output << setw(14) << first[i];
        output << setw(14) << last[i];
        output << setw(6) << setprecision(2) << scores[i][0];
        output << setw(9) << setprecision(2) << scores[i][1];
        output << setw(9) << setprecision(2) << scores[i][2];
        output << setw(9) << setprecision(2) << scores[i][3];
        output << setw(9) << setprecision(2) << averg[i];
        output << setw(6) << setprecision(2) << grade[i];
        output << endl;
    }
    output << endl;
}
//*******************************  END OF FUNCTION TESTAVERAGE  ****************************************

//********************************  FUNCTION SORTEDTESTAVERAGE  ****************************************
void sortedTestAverage(ofstream &output, string first[], string last[], float scores[][4], 
float average[], char grade[], int counter)
{
    //Recieves - an output file, an array of first names, an array of 
    //           last names, an array of scores, an array of test averages
    //           an array of letter grades, and the amount of students
    //Task - sorts the students test averages from highest to lowest
    //Return - an array of first names, an array of last names, an array 
    //         of test scores, an array of test averages, and an array of 
    //         letter grades

                    //loop through all students
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter; j++)
        {
                    //check if the grade is lower than the other grade
            if (grade[i] < grade[j])
            {
                    //change last name postion in array
                string ltemp = last[i];
                last[i] = last[j];
                last[j] = ltemp;

                    //change first name position in array
                string ftemp = first[i];
                first[i] = first[j];
                first[j] = ftemp;

                    //change score postions in array
                float temp1 = scores[i][0];
                float temp2 = scores[i][1];
                float temp3 = scores[i][2];
                float temp4 = scores[i][3];
                scores[i][0] = scores[j][0];
                scores[i][1] = scores[j][1];
                scores[i][2] = scores[j][2];
                scores[i][3] = scores[j][3];
                scores[j][0] = temp1;
                scores[j][1] = temp2;
                scores[j][2] = temp3;
                scores[j][3] = temp4;

                    //change letter grade postion in array
                char letter = grade[i];
                char highLetter = grade[j];
                grade[i] = highLetter;
                grade[j] = letter;
            }
        }
    }

                    //print grade heading to screen
    output << "The list of students with their test average and course grade is:" << endl;
    output << "     Student Name" << endl;
    output << "  First       Last          Test 1   Test 2   Test 3   Test 4   Average   Grade" << endl;
    output << "----------    ----------    ------   ------   ------   ------   -------   ------" << endl;

                    //fix the printed data to the left
    output.setf(ios::fixed);
    output.unsetf(ios::left);

                    //loop through all of the students
    for (int i = 0; i < counter; i++)
    {
                    //print all of the students data
        output << setw(14) << first[i];
        output << setw(14) << last[i];
        output << setw(6) << setprecision(2) << scores[i][0];
        output << setw(9) << setprecision(2) << scores[i][1];
        output << setw(9) << setprecision(2) << scores[i][2];
        output << setw(9) << setprecision(2) << scores[i][3];
        output << setw(9) << setprecision(2) << average[i];
        output << setw(6) << setprecision(2) << grade[i];
        output << endl;
    }
    output << endl;
}
//******************************  END OF FUNCTION SORTEDTESTAVERAGE  ***********************************

//*************************************  FUNCTION HEADER  **********************************************
void Header( ofstream &Outfile) 
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
//**********************************  END OF FUNCTION HEADER  ******************************************

//*************************************  FUNCTION FOOTER  **********************************************
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
//**********************************  END OF FUNCTION FOOTER  ******************************************