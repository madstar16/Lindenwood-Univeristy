//*****************************  PROGRAM IDENTIFICATION  *****************************
//*                                                                                  *
//*  PROGRAM FILE NAME:  project6.cpp    ASSIGNMENT #:  6       Grade: _________     *
//*                                                                                  *
//*   PROGRAM AUTHOR:                                                                *
//*                   ___________________________________________________            *
//*                                     Maddie Talley                                *
//*                                                                                  *
//*   COURSE #:  CSC 24400 11                           DUE DATE: November 25, 2019  *
//*                                                                                  *
//************************************************************************************
//*******************************  PROGRAM DESCRIPTION  ******************************
//*                                                                                  *
//*   PROCESS:  This program reads the data from the input file and creates an array *
//*             of objects that hold the information of employees. It also prints out*
//*             the data from the input file for each and every employee as well as  *
//*             individual employees.                                                *
//*   USER DEFINED                                                                   *
//*    MODULES     :        Header - prints the class header in the output           *
//*                         Footer - prints the end of program output                *
//*                         readData -  reads in the data from the input txt file    *
//*                         printData - prints the data read in to the output file   *
//*                         lastAtoZ - prints the last names in alhpabetical order   *
//*                         testAverage - prints the test averages and letter grade  *
//*                         sortedTestAverage - prints the test averages sorted from *
//*                                             high to low                          *
//************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//******************************  STUCTURE EMPLOYEETYPE  *****************************
struct EmployeeType
{
    int ID;
    string first;
    string last;
    string dep;
    string title;
    float pay;
};
//***************************  END OF STRUCTURE EMPLOYEETYPE  ************************

//*********************************  CLASS ITEMPLOYEE  *******************************
class ITEmployee
{
public:
    ITEmployee();
    void initial(ifstream &, ITEmployee[], int &, int, string , string , string , string , float);
    void update(ifstream &, ITEmployee[], int, int);
    void deleteRec(ifstream &, ITEmployee[], int &, int);
    void printRec(ifstream &, ITEmployee[], int &, char);
    int getID();
    string getFirst();
    string getLast();
    string getDep();
    string getTitle();
    float getPay();
    float getPayRoll(); 
    void setID(int);
    void setFirst(string);
    void setLast(string);
    void setDep(string);
    void setTitle(string);
    void setPay(float); 
    void setPayRoll(float);
private:
    EmployeeType Employee;
    static float TotalPayRoll;
};
//******************************  END OF CLASS ITEMPLOYEE  ***************************

float ITEmployee::TotalPayRoll;
void Header(ofstream &);
void Footer(ofstream &);
void readData(ifstream &, ofstream &, ITEmployee[], int);

//*********************************  FUNCTION MAIN  **********************************
int main()
{
        //create an ITEmployee called Employee, an array of 50 Employees, and an int
        //called count and set it to 0
    ITEmployee Employee;
    ITEmployee EmployeeList[50] = {Employee};
    int count = 0;

        //create an input file and an output file
    ifstream input("data6.txt", ios::in);
    ofstream output("output.txt", ios::out);

        //call the readData function and all of this parameters
    readData(input, output, EmployeeList, count);

    return 0;
}
//******************************  END OF FUNCTION MAIN  ******************************

//*****************************  CONSTRUCTOR ITEMPLOYEE  *****************************
ITEmployee::ITEmployee()
{
        //set the ID, first name, last name, department name, title name, pay, and
        //total pay roll equal to 0 or null
    Employee.ID = 0; 
    Employee.first = " ";
    Employee.last = " ";
    Employee.dep = " ";
    Employee.title = " ";
    Employee.pay = 0.0;
    TotalPayRoll = 0.0;
}
//**************************  END OF CONSTRUCTOR ITEMPLOYEE  **************************

//*********************************  FUNCTION GETID  *********************************
int ITEmployee::getID()
{
    // Receives – nothing           
    // Task -  obatins the employee ID              
    // Returns - the employee ID
    return Employee.ID;
}
//*****************************  END OF FUNCION GETID ********************************

//******************************  FUNCTION GETFIRST  *********************************
string ITEmployee::getFirst()
{
    // Receives – nothing            
    // Task -  obtains the employee's first name             
    // Returns - the employee's first name
    return Employee.first;
}
//***************************  END OF FUNCION GETFIRST *******************************

//*******************************  FUNCTION GETLAST  *********************************
string ITEmployee::getLast()
{
    // Receives –  nothing            
    // Task - obtains the last name of the employee           
    // Returns - the employee's last name
    return Employee.last;
}
//****************************  END OF FUNCION GETLAST *******************************

//********************************  FUNCTION GETDEP  *********************************
string ITEmployee::getDep()
{
    // Receives –  nothing            
    // Task -  obtains the department of the employee              
    // Returns - the employee's department
    return Employee.dep;
}
//*****************************  END OF FUNCION GETDEP *******************************

//*******************************  FUNCTION GETTITLE  ********************************
string ITEmployee::getTitle()
{
    // Receives – nothing             
    // Task -  obtains the title of the employee             
    // Returns - the employee's title
    return Employee.title;
}
//****************************  END OF FUNCION GETTITLE ******************************

//********************************  FUNCTION GETPAY  *********************************
float ITEmployee::getPay()
{
    // Receives – nothing           
    // Task - obtains the salary of the employee           
    // Returns - the employee's salary
    return Employee.pay;
}
//*****************************  END OF FUNCION GETPAY *******************************

//******************************  FUNCTION GETPAYROLL  *******************************
float ITEmployee::getPayRoll()
{
    // Receives – nothing             
    // Task - obtains the pay roll of all of the employee's               
    // Returns - the companies total payroll
    return TotalPayRoll;
}
//***************************  END OF FUNCION GETPAYROLL *****************************

//*********************************  FUNCTION SETID  *********************************
void ITEmployee::setID(int ID)
{
    // Receives – an int that is an ID number             
    // Task - sets the ID euqal to the employees ID             
    // Returns - nothing
    Employee.ID = ID;
}
//*****************************  END OF FUNCION SETID ********************************

//******************************  FUNCTION SETFIRST  *********************************
void ITEmployee::setFirst(string first)
{
    // Receives –  a string that is a first name            
    // Task -  sets the name to the employees first name              
    // Returns - nothing
    Employee.first = first;
}
//***************************  END OF FUNCION SETFIRST *******************************

//*******************************  FUNCTION SETLAST  *********************************
void ITEmployee::setLast(string last)
{
    // Receives –  a string that is a last name            
    // Task -  sets the last name to the employees last name              
    // Returns - nothing
    Employee.last = last;
}
//****************************  END OF FUNCION SETLAST *******************************

//********************************  FUNCTION SETDEP  *********************************
void ITEmployee::setDep(string dep)
{
    // Receives –  a string that is a department name            
    // Task - sets the department name to the employee's department name               
    // Returns - nothing
    Employee.dep = dep;
}
//*****************************  END OF FUNCION SETDEP *******************************

//*******************************  FUNCTION SETTITLE  ********************************
void ITEmployee::setTitle(string title)
{
    // Receives – a string that is a title name             
    // Task - sets the title name to the employee's title name              
    // Returns - nothing
    Employee.title = title;
}
//****************************  END OF FUNCION SETTITLE ******************************

//********************************  FUNCTION SETPAY  *********************************
void ITEmployee::setPay(float pay)
{
    // Receives –  a float that is a salary             
    // Task - sets the salary to the employee's salary               
    // Returns - nothing
    Employee.pay = pay;
} 
//*****************************  END OF FUNCION SETPAY *******************************

void ITEmployee::setPayRoll(float payroll)
{
    TotalPayRoll = payroll;
}

//*******************************  FUNCTION INITIAL  *********************************
void initial(ifstream &input, ITEmployee EmployeeList[], int &count, int ID, 
string first, string last, string dep, string title, float pay)
{
    // Receives –  an input file, an array of employees, the number of employees, 
    //             the employee's ID number, first name, last name, department, title,
    //             and salary          
    // Task -  reads in all the data from the input file and stores it into the array
    //         correctly              
    // Returns - the amount of employees

                //create an employee named temp and a boolean called loopover 
                //set to true
    ITEmployee Temp;
    bool loopover = true;

                //set the ID, first name, last name, department, title, and salary
                //equal to the temp employee
    Temp.setID(ID);
    Temp.setFirst(first);
    Temp.setLast(last);
    Temp.setDep(dep);
    Temp.setTitle(title);
    Temp.setPay(pay);

                //loop through the array
    for (int i = 0; i < 50; i++)
    {
                //check if the array  entry is empty and if loopover is true
        if (EmployeeList[i].getID() == 0 && loopover)
        {
                //set the specific employee equal to temp
            EmployeeList[i] = Temp;
                //add one to the employee count
            count++;
                //set loopover to false
            loopover = false;
        }
    }
}
//***************************  END OF FUNCION INITIAL ********************************

//********************************  FUNCTION UPDATE  *********************************
void update(ifstream &input, ITEmployee EmployeeList[], int ID, int option)
{
    // Receives –  an input file, an array of employees, an ID number, and an int 
    //             that ranges from 1 to 5            
    // Task - update the needed information to a specific employee               
    // Returns - nothing

                //create an int, four strings, and a float
    int index;
    string newFirst;
    string newLast;
    string newDep;
    string newTitle;
    float newPay;

                //loop thorugh the array   
    for (int i = 0; i < 50; i++)
    {
                //check if the ID we have is equal to the one in the array
        if(EmployeeList[i].getID() == ID)
        {
                //set index = i
            index = i;
        }
    }

                //check your int from 1 to 5
    switch(option)
    {
                //if int is 1
        case 1:
                //read in ws
            input >> ws;
                //get the next line and store it into a string
            getline(input, newFirst);
                //remove the '\r'
            newFirst.erase(remove(newFirst.begin(), newFirst.end(), '\r'), 
            newFirst.end());
                //set the string equal to teh employee's first name
            EmployeeList[index].setFirst(newFirst);
            break;
                //if int is 2
        case 2:
                //read in ws
            input >> ws;
                //get the next line and store it into a string
            getline(input, newLast);
                //remove the '\r'
            newLast.erase(remove(newLast.begin(), newLast.end(), '\r'), 
            newLast.end());
                //set the string equal the the employee's last name
            EmployeeList[index].setLast(newLast);
            break;
                //if int is 3
        case 3:
                //read in ws
            input >> ws;
                //get the next line and store it into a string
            getline(input, newDep);
                //remove the '\r'
            newDep.erase(remove(newDep.begin(), newDep.end(), '\r'), 
            newDep.end());
                //set the string equal to the employee's department
            EmployeeList[index].setDep(newDep);
            break;
                //in int is 4
        case 4:
                //read in ws
            input >> ws;
                //get the next line and store it into a string
            getline(input, newTitle);
                //remove the '\r'
            newTitle.erase(remove(newTitle.begin(), newTitle.end(), '\r'), 
            newTitle.end());
                //set the string equal to the employee's title
            EmployeeList[index].setTitle(newTitle);
            break;
                //if int is 5
        case 5:
                //read in the next float
            input >> newPay;
                //set the float equal to the employee's pay
            EmployeeList[index].setPay(newPay);
            break;
    }
}
//*****************************  END OF FUNCION UPDATE *******************************

//******************************  FUNCTION DELETEREC  ********************************
void deleteRec(ifstream &input, ITEmployee EmployeeList[], int &count, int ID)
{
    // Receives – an input file, an array of employees, the amount of employees, and
    //            an ID number           
    // Task - deletes a certain employee out of the array based on the ID and shifs
    //        over the rest of the employees in the array to the left               
    // Returns - the amount of employees

                //create an int for an index
    int index;

                //loop thorugh the array
    for (int i = 0; i < 50; i++)
    {
                //check if the ID is equal to the employee in the arrays ID
        if(EmployeeList[i].getID() == ID)
        {
                //shift all of the necessary elements to the left in the array
            for(int j = i; j < 49; j++)
            {
                EmployeeList[j] = EmployeeList[j+1];
            }
        }
    }
                //subtract one from the employee count
    count--;
}
//***************************  END OF FUNCION DELETEREC ******************************

//*******************************  FUNCTION PRINTREC  ********************************
void printRec(ifstream &input, ofstream &output, ITEmployee EmployeeList[], 
int count, char letter)
{
    // Receives – an input file, an output file, an array of employees, the amount of
    //            employees, and a char that is the next letter             
    // Task - prints the data based on what letter is. If letter is an E it will print 
    //        all of the employees data. If letter is an S it will read in the ID
    //        number and print that indiviuals information              
    // Returns - nothing

                //create an int for an ID, an int for an index, and a temp Employee
    int ID;
    int index;
    float payroll;
    ITEmployee temp;
                //check is letter is E or S
    switch(letter)
    {
                //if letter is E
        case 'E':
                //create formatting to set to the right and precisions to 2
            output.setf(ios::fixed);
            output.setf(ios::left);
            output.precision(2);
                //print out formatting
            output << "===============================================================================" << endl;
            output << "ID #           Name                  Department      Position          Pay" << endl;
            output << "-------------------------------------------------------------------------------" << endl;
                //print out all of the employees information
            for (int i = 0; i < count; i++)
            {
                output << setw(5) << EmployeeList[i].getID() << " " << setw(12) << EmployeeList[i].getFirst();
                output << setw(5) << EmployeeList[i].getLast() << setw(8) << EmployeeList[i].getDep();
                output << setw(5) << EmployeeList[i].getTitle() << setw(8) << EmployeeList[i].getPay();
                output << endl;
            }
                //add up the payroll
            for (int i = 0; i < count; i++)
            {
                payroll += EmployeeList[i].getPay();
            }
            EmployeeList[0].setPayRoll(payroll);
                //print out the payroll
            output << "-------------------------------------------------------------------------------" << endl;
            output << "          Total Amount of Payroll        " << setw(14) << EmployeeList[0].getPayRoll();
            output << "*******************************************************************************" << endl << endl;
            break;
                //if letter is S
        case 'S':
                //create formatting to set to the right and precisions to 2
            output.setf(ios::fixed);
            output.setf(ios::left);
            output.precision(2);
                //read in the ID number
            input >> ID;
                //check the array for the specific employee
            for (int i = 0; i < 50; i++)
            {
                if(EmployeeList[i].getID() == ID)
                {
                    //set index equal to i
                    index = i;
                }
            }
                //print out formatting and the specific employees information
            output << "===============================================================================" << endl;
            output << "ID #           Name                  Department      Position          Pay" << endl;
            output << "-------------------------------------------------------------------------------" << endl;
            output << setw(5) << EmployeeList[index].getID() << setw(8) << EmployeeList[index].getFirst();
            output << setw(8) << EmployeeList[index].getLast() << setw(8) << EmployeeList[index].getDep();
            output << setw(8) << EmployeeList[index].getTitle() << setw(8) << EmployeeList[index].getPay();
            output << endl;           
            break;
    }
}
//****************************  END OF FUNCION PRINTREC ******************************

//*******************************  FUNCTION READDATA  ********************************
void readData(ifstream &input, ofstream &output, ITEmployee EmployeeList[], int count)
{
    // Receives – an input, output, an array of employees, and the amount of employees             
    // Task - reads in all of the data and calls the needed functions for the specific
    //        letter that was read in               
    // Returns - nothing

                    //create 2 ints called ID and option, 5 strings, a float, 2 chars
                    //and a boolean that is equal to true
    int ID;
    int option;
    string first;
    string last;
    string dep;
    string title;
    string letter1;
    float pay;
    char action;
    char letter;
    bool loopover = true;

                    //read int the first char
    input >> action;

                    //loop while your boolean is true
    while(loopover)
    {
                    //checks is the char is an I, D, C, P, or Q
        switch(action)
        {
                    //if case I
            case 'I':
                    //read in the ID number
                input >> ID;
                    //read in the ws
                input >> ws;
                    //get the next line and store it into a string
                getline(input, first);
                    //remove the '\r'
                first.erase(remove(first.begin(), first.end(), '\r'), first.end());
                    //get the next line and store it into a string
                getline(input, last);
                    //remove the '\r'
                last.erase(remove(last.begin(), last.end(), '\r'), last.end());
                    //get the next line and store it into a string
                getline(input, dep);
                    //remove the '\r'
                dep.erase(remove(dep.begin(), dep.end(), '\r'), dep.end());
                    //get the next line and store it into a string
                getline(input, title);
                    //remove the '\r'
                title.erase(remove(title.begin(), title.end(), '\r'), title.end());
                    //read in the floar
                input >> pay;
                    //call the inital function with the correct parameters
                initial(input, EmployeeList, count, ID, first, last, dep, title, 
                pay);
                    //read in the next char
                input >> action;
                break;
                    //if case D
            case 'D':
                    //read in the ID
                input >> ID;
                    //call the deleteRec function with the correct parameters
                deleteRec(input, EmployeeList, count, ID);
                    //read in the next char
                input >> action;
                break;
                    //if case C
            case 'C':
                input >> ID;
                input >> option;
                update(input, EmployeeList, ID, option);
                input >> action;
                break;
                    //if case P
            case 'P':
                    //read in ws
                input >> ws;
                    //get the next line and store it into a string
                getline(input, letter1);
                    //remove the '\r'
                letter1.erase(remove(letter1.begin(), letter1.end(), '\r'), 
                letter1.end());
                    //store the first letter of the string into a char
                letter = letter1.at(0);
                    //call the printRec function with the correct parameters
                printRec(input, output, EmployeeList, count, letter);
                    //read in the next char
                input >> action;
                break;
                    //if case Q
            case 'Q':
                    //set the boolean to false and the while loop will ned
                loopover = false;
                break;
        }
    }
}
//****************************  END OF FUNCION READDATA ******************************

//*********************************  FUNCTION HEADER  ********************************
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

