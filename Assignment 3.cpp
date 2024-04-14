/******************************************
* Edgardo Richard Ventura                 *
* Week 11                                 *
* Assignment 3                            *
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
*      gal = Gallons used on the trip              *
*       mi = Miles traveled on the trip            *
*      mpg = Miles Per Gallon                      *
* totalGal = Total Gallons used                    *
*  totalMi = Total Miles traveled                  *
* totalMpg = Total Miles Per Gallon                *
***************************************************/

// Function prototypes
float calculateMPG(float mi, float gal);
float calculatetotalMPG(float totalMi, float totalGal);

int main() {
    /* CURRENT FILE DIRECTORY */
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");

    /* VALUES */
    float gal, mpg, mi, totalMpg;
    float totalMi = 0, totalGal = 0;

    /* FILE DIRECTORY */
    ifstream infile;  // Defines a file stream object
    infile.open("trips.txt"); // Connect to the file

    /* PROCESS INPUT */
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    cout << "File opened successfully!" << endl;
    cout << setprecision(2) << fixed;

    /* PROCESS CALCULATION */
    while (infile >> gal >> mi) {
        mpg = calculateMPG(mi, gal);
        totalMi += mi;
        totalGal += gal;

        /* INDIVIDUAL OUTPUTS */
        cout << endl;
        cout << "      Gallons Used: " << setw(7) << gal << endl;
        cout << "    Miles Traveled: " << setw(7) << mi << endl;
        cout << "  Miles Per Gallon: " << setw(7) << mpg << endl;
    }

    totalMpg = calculatetotalMPG(totalMi, totalGal);  // Ensure to end function call with a semicolon

    /* ACCUMULATIVE OUTPUTS */
    cout << endl;
    cout << "-------- Travel Summary --------" << endl;
    cout << "     Total Gallons: " << setw(7) << totalGal << endl;
    cout << "       Total Miles: " << setw(7) << totalMi << endl;
    cout << "Total Miles/Gallon: " << setw(7) << totalMpg << endl;

    infile.close(); // Close the file

    return 0;
}

/* FUNCTION DEFINITIONS */
float calculateMPG(float mi, float gal) {
    return mi / gal;  // Compute miles per gallon
}

float calculatetotalMPG(float totalMi, float totalGal) {
    if (totalGal == 0) return 0;  // Prevent division by zero
    return totalMi / totalGal;  // Compute total miles per gallon
}
