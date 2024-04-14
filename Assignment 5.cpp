/******************************************
* Edgardo Richard Ventura                 *
* Week 11                                 *
* Assignment 5                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
******************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <direct.h> // Include for _getcwd on Windows
using namespace std;


/***************************************************
*             ~ Table of Etymology ~               *
*             ln = Last name of the student        *
*             sc = Student code ('I' or 'O')       *
*             ch = Credits taken                   *
*             tu = Tuition owed                    *
*             cf = Course fees                     *
*          total = Total tuition owed              *
*  studentCount = Number of students processed    *
* averageTuition = Average tuition per student     *
***************************************************/


// Function prototypes
float calculateTuition(float credits, char code);
float calculateCourseFees(float tuition);


int main() {
    /* CURRENT FILE DIRECTORY */
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");


    /* VALUES */
    string ln;
    char sc;
    float ch, tu, cf;
    float total = 0;
    int studentCount = 0;


    /* FILE DIRECTORY */
    ifstream infile;  // Defines a file stream object
    infile.open("student.txt"); // Connect to the file


    /* PROCESS INPUT */
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    cout << "File opened successfully!" << endl;
    cout << setprecision(2) << fixed;


    /* PROCESS CALCULATION */
    while (infile >> ln >> sc >> ch) {
        tu = calculateTuition(ch, sc);
        cf = calculateCourseFees(tu);
        total += tu;
        studentCount++;


        /* INDIVIDUAL OUTPUTS */
        cout << endl;
        cout << "         Last Name: " << ln << endl;
        cout << "      Student Code: " << sc << endl;
        cout << "     Credits Taken:  " << setw(10) << ch << endl;
        cout << "      Tuition Owed: $" << setw(10) << tu << endl;
        cout << "       Course Fees: $" << setw(10) << cf << endl;
    }


    /* ACCUMULATIVE OUTPUTS */
    float averageTuition = (studentCount > 0) ? total / studentCount : 0;

    cout << endl;
    cout << "-------- Tuition Summary --------" << endl;
    cout << "     Student Count: " << setw(8) << studentCount << endl;
    cout << "Total Tuition Owed: $" << setw(10) << total << endl;
    cout << "   Average Tuition: $" << setw(10) << averageTuition << endl;

    infile.close(); // Close the file

    return 0;
}


/* FUNCTION DEFINITIONS */
float calculateTuition(float credits, char code) {
    const float IN_DISTRICT_RATE = 250.0;
    const float OUT_DISTRICT_RATE = 500.0;
    return credits * (code == 'I' ? IN_DISTRICT_RATE : OUT_DISTRICT_RATE);
}

float calculateCourseFees(float tuition) {
    return tuition * 0.1;  // Compute course fees as 10% of tuition
}
