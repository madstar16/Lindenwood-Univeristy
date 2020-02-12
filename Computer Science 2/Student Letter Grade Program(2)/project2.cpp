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
//*   PROCESS: This program is meant to read the data of the student IDs and their test scores. It    *
//*            prints the list of each student ID and test score. It then prints the ID numbers of    *
//*            the students that have the letter grade of A, B, C, D, and F. It also prints the ID    *
//*            number and test score of the lowest scoring student, the highest scoring student, and  *
//*            the average test score for the group.                                                  *
//*                                                                                                   *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     :        Header - prints the class header in the output                            *
//*                         Footer - prints the end of program output                                 *
//*                         readArr -  reads in the data from the input txt file                      * 
//*                         printArr - prints the data that was read in into the output txt file      *
//*                         sortArr - sorts the array from the highest test score to the lowest test  *
//*                                   score                                                           *  
//*                         printLetterA - prints all of the student ID's with scores 90.00 and above *
//*                         printLetterB - prints all of the student ID's with scores 80.00 through   *
//*                                        89.99                                                      *
//*                         printLetterC - prints all fo the student ID's with scores 70.00 through   *
//*                                        79.99                                                      *
//*                         printLetterD - prints all fo the student ID's with scores 60.00 through   *
//*                                        69.99                                                      *
//*                         printLetterF - prints all fo the student ID's with scores 00.00 through   *
//*                                        59.99                                                      *
//*                         findLow - finds the lowest test score from the group                      *
//*                         findHigh - finds the highest test score from the group                    *
//*                         getAverage - finds the average test grade from the group                  *
//*                         printOutput - prints out all of the info into the output file             *
//*****************************************************************************************************                                                                        *

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void Header(ofstream &);
void Footer(ofstream &);  
void readArr(ifstream &, int[], float[], int &);
void printArr(ofstream &, int[], float[], int);
void sortArr(int[], float[], float[], int[], int);
void printLetterA(ofstream &, int[], float[], int);
void printLetterB(ofstream &, int[], float[], int);
void printLetterC(ofstream &, int[], float[], int);
void printLetterD(ofstream &, int[], float[], int);
void printLetterF(ofstream &, int[], float[], int);
void findLow(int[], float[], int &, float &, int);
void findHigh(int[], float[], int &, float &, int);
void getAverage(ofstream &, float[], int);
void printOutput(ifstream &, ofstream &, int[], float[], int, int, int, float, float);

//*************************************  FUNCTION MAIN  **********************************************
int main()
{
    //Recieves - nothing
    //Task - sets up the entire program
    //Return - nothing
    
            //finds the data2.txt file 
    ifstream input("DATA2.txt", ios::in);  
            //creates an output file for all of the data     
    ofstream output("output.txt", ios::out);    

    int ID[50];
    float score[50];
    int counter;
    int lowestID;
    int highestID;
    float lowestScore;
    float highestScore;
            //puts the header in the output file
    Header(output);
            //puts all of the test scores and ID numbers into the output file
    printOutput(input, output, ID, score, counter, lowestID, highestID, lowestScore, highestScore);
            //puts the footer int the output file
    Footer(output);

    return 0;
}
//*************************************  END OF FUNCTION MAIN  ***************************************

//*************************************  FUNCTION READARR  **********************************************
void readArr(ifstream &infile, int ID[], float score[], int &counter)
{
    //Recieves - a reference to an input file, all of the student ID's, all of thes students scores,
    //           and how many students there are 
    //Task - reads in all of the data from the input file and stores it into arrays
    //Return - nothing

     int IDnum; 
     float scoreNum;                                  
     counter = 0; 
            //sets the first line in the input file equal to IDnum
     infile >> IDnum; 
            //sets the second life in the input file equal to scoreNum
     infile >> scoreNum;
            //goes through all of the input data and stores them in the arrays
     while (IDnum > 0)                           
     {     
                //sets IDnum to the first slot of the array ID                        
         ID[counter] = IDnum; 
                //sets scoreNum to the first slot of the array score
         score[counter] = scoreNum;
                //checks to see if the score was over 100.00
                //if it is then it will be set to 100.00
        if (score[counter] > 100.00)
        {
            score[counter] = 100.00;
        } 
                //adds one to the amount of students 
         counter++;

                //reads in the next two numbers to set up the array                            
         infile >> IDnum;
         infile >> scoreNum;
     }
}
//*************************************  END OF FUNCTION READARR  ***************************************

//*************************************  FUNCTION PRINTARR  **********************************************
void printArr(ofstream &outfile, int ID[], float score[], int counter)
{
    //Recieves - a refernce to an output file, all of the students ID numbers, all of the students
    //           score, and how many students there are.
    //Task -    prints both arrays into the ouput file accordingly
    //Return -  changes outputfile accordingly
    outfile.setf(ios::fixed);
    outfile.unsetf(ios::right); 
    for (int i = 0; i < counter; i++) 
    {
        outfile << setw(5) << ID[i] << setw(16) << setprecision(2) << score[i] << endl;
    }
}
//*************************************  END OF FUNCTION PRINTARR  ***************************************

//*************************************  FUNCTION PRINTLETTERA  **********************************************
void printLetterA(ofstream &output, int ID[], float score[], int counter)
{
    //Recieves - a reference to an output file, all of the students ID numbers, all of thes students
    //           scores, and the amount of students
    //Task - finds all of the scores that are from 90.00 - 100.00 and then prints the ID numbers
    //Return - changes output file accordingly
            //loops thorugh the students scores and prints the ID numbers of the students who scored
            // from 90.00 to 100.00
    for (int i = 0; i < counter; i++)
    {
            //checks if the score is from 90.00 to 100.00
        if (score[i] <= 100.0 && score[i] >= 90.0)
        {
            //prints the ID number to the outfile
            output << ID[i] << " ";
        }
    }
}
//*************************************  END OF FUNCTION PRINTLETTERA  ***************************************

//*************************************  FUNCTION PRINTLETTERB  **********************************************
void printLetterB(ofstream &output, int ID[], float score[], int counter)
{
    //Recieves - a reference to an output file, all of the students ID numbers, all of thes students
    //           scores, and the amount of students
    //Task - finds all of the scores that are from 80.00 - 89.99 and then prints the ID numbers
    //Return - changes output file accordingly
            //loops thorugh the students scores and prints the ID numbers of the students who scored
            // from 80.00 to 89.99
    for (int i = 0; i < counter; i++)
    {
            //checks if the score is from 80.00 to 89.99
        if (score[i] <= 89.99 && score[i] >= 80.0)
        {
            //prints the ID number to the outfile
            output << ID[i] << " ";
        }
    }
}
//*************************************  END OF FUNCTION PRINTLETTERB  ***************************************

//*************************************  FUNCTION PRINTLETTERC  **********************************************
void printLetterC(ofstream &output, int ID[], float score[], int counter)
{
    //Recieves - a reference to an output file, all of the students ID numbers, all of thes students
    //           scores, and the amount of students
    //Task - finds all of the scores that are from 70.00 - 79.99 and then prints the ID numbers
    //Return - changes output file accordingly
            //loops thorugh the students scores and prints the ID numbers of the students who scored
            // from 70.00 to 79.99
    for (int i = 0; i < counter; i++)
    {
        //checks to see if the scores are from 70.00 to 79.99
        if (score[i] <= 79.99 && score[i] >= 70.0)
        {
            //prints the ID numbers to the outfile 
            output << ID[i] << " ";
        }
    }
}
//*************************************  END OF FUNCTION PRINTLETTERC  ***************************************

//*************************************  FUNCTION PRINTLETTERD  **********************************************
void printLetterD(ofstream &output, int ID[], float score[], int counter)
{
    //Recieves - a reference to an output file, all of the students ID numbers, all of thes students
    //           scores, and the amount of students
    //Task - finds all of the scores that are from 60.00 - 69.99 and then prints the ID numbers
    //Return - changes output file accordingly
            //loops thorugh the students scores and prints the ID numbers of the students who scored
            // from 60.00 to 69.99
    for (int i = 0; i < counter; i++)
    {
        if (score[i] <= 69.99 && score[i] >= 60.0)
        {
            output << ID[i] << " ";
        }
    }
}
//*************************************  END OF FUNCTION PRINTLETTERD  ***************************************

//*************************************  FUNCTION PRINTLETTERF  **********************************************
void printLetterF(ofstream &output, int ID[], float score[], int counter)
{
    //Recieves - a reference to an output file, all of the students ID numbers, all of thes students
    //           scores, and the amount of students
    //Task - finds all of the scores that are from 00.00 - 59.99 and then prints the ID numbers
    //Return - changes output file accordingly
            //loops thorugh the students scores and prints the ID numbers of the students who scored
            // from 00.00 to 59.99
    for (int i = 0; i < counter; i++)
    {
            //checks to see if the score is from 0.0 to 60.0
        if (score[i] < 60.0  && score[i] >= 0)
        {
            //prints the ID to the outfile
            output << ID[i] << " ";
        }
    }
}
//*************************************  END OF FUNCTION PRINTLETTERF  ***************************************

//*************************************  FUNCTION FINDLOW  **********************************************
void findLow(int ID[], float score[], int &lowID, float &lowScore, int counter)
{
    //Recieves - all of the students IDs, all of the students scores, the lowest scoring student's
    //           ID, the lowest score, and the number of all students
    //Task - finds the lowest score of all of the students and thier ID number
    //Return - outifle changes accordingly

            //sets lowID and lowScore to the first in both arrays
    lowID = ID[0];
    lowScore = score[0];
            //loops through the arrays based on how many students there are 
    for (int i = 1; i < counter; i++)
    {
            // checks to see if lowScore is greater than the element we are checking in the array
        if (lowScore > score[i])
        {
            //changes the new lowest score
            lowScore = score[i];
            lowID = ID[i];
        }
    }
}
//*************************************  END OF FUNCTION FINDLOW  ***************************************

//*************************************  FUNCTION FINDHIGH  **********************************************
void findHigh(int ID[], float score[], int &highID, float &highScore, int counter)
{
    //Recieves - all of the students IDs, all of the students scores, the highest scoring student's
    //           ID, the highest score, and the number of all students
    //Task - finds the highest score of all of the students and thier ID number
    //Return - outifle changes accordingly

            //sets highID and highScore to the first in both arrays
    highID = ID[0];
    highScore = score[0];
            //loops through the arrays based on how many students there are
    for (int i = 1; i < counter; i++)
    {
            // checks to see if highScore is greater than the element we are checking in the array
        if (highScore < score[i])
        {
            //changes the new highest score
            highScore = score[i];
            highID = ID[i];
        }
    }
}
//*************************************  END OF FUNCTION FINDHIGH  ***************************************

//*************************************  FUNCTION GETAVERAGE  **********************************************
void getAverage(ofstream &outfile, float score[], int counter)
{
    //Recieves - a refernce to an outfile, all of the students score, and the amount of students
    //Task - finds the average score of all of the students scores
    //Return - changes the outfile accordingly
    float total = 0;
    float average;
    for (int i = 0; i < counter; i++)
    {
        total += score[i];
    }
    average = total/counter;
    outfile << average << endl;
}
//*************************************  END OF FUNCTION GETAVERAGE  ***************************************

//*************************************  FUNCTION PRINTOUTPUT  **********************************************
void printOutput(ifstream &input, ofstream &output, int ID[], float score[], 
int counter, int lowestID, int highestID, float lowestScore, float highestScore)
{
    //Recieves - a reference to an input file, a references to an output file, all of the 
    //           students ID numbers, all of the students scores, the amount of all the students,
    //           the lowest scoring student's ID number, the higest score student's ID number, the
    //           lowest score, and the highest score
    //Task - takes all of the functions above and prints everything to the output file accordingly
    //Return - nothing

            //prints all of the functions and all of the labels that are needed
    readArr(input, ID, score, counter); 
    output << "The original list of test scores is:" << endl;
    output << "Student ID#   Test Score" << endl;
    printArr(output, ID, score, counter);
    output << endl << endl;
    output << "Students receiving a grade of A are: ";
    printLetterA(output, ID, score, counter);
    output << endl;
    output << "Students receiving a grade of B are: ";
    printLetterB(output, ID, score, counter);
    output << endl;
    output << "Students receiving a grade of C are: ";
    printLetterC(output, ID, score, counter);
    output << endl;
    output << "Students receiving a grade of D are: " ;
    printLetterD(output, ID, score, counter);
    output << endl;
    output << "Students receiving a grade of F are: " ;
    printLetterF(output, ID, score, counter);
    output << endl << endl;;
    findLow(ID, score, lowestID, lowestScore, counter);
    findHigh(ID, score, highestID, highestScore, counter);
    output << "The lowest test score was " << lowestScore << " achieved by student #" << lowestID << endl << endl;
    output << "The highest test score was " << highestScore << " achieved by student #" << highestID << endl << endl;
    output << "The average test score for the group is ";
    getAverage(output, score, counter);
}
//*************************************  END OF FUNCTION PRINTOUTPUT  ***************************************

//*************************************  FUNCTION HEADER  **********************************************
void Header(ofstream &outfile) 
{              
    // Receives – the output file               
    // Task - Prints the output preamble               
    // Returns - Nothing   
    outfile << setw(30) << "Maddie Talley";   
    outfile << setw(17) << "CSC 24400";    
    outfile << setw(15) << "Section 11" << endl;   
    outfile << setw(30) << "Fall 2019";   
    outfile << setw(20) << "Assignment #2" << endl;   
    outfile << setw(35) << "-----------------------------------";   
    outfile << setw(35) << "-----------------------------------" << endl << endl;  
    return; 
}
//*************************************  END OF FUNCTION HEADER  ***************************************

//*************************************  FUNCTION FOOTER  **********************************************
void Footer(ofstream &outfile) 
{               
    // Receives – the output file               
    // Task - Prints the output salutation               
    // Returns - Nothing   
    outfile << endl;   
    outfile << setw(35) << " --------------------------------- " << endl;   
    outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;   
    outfile << setw(35) << " --------------------------------- " << endl;  
    return; 
}
//*************************************  END OF FUNCTION FOOTER  ***************************************