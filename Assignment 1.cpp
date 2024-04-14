/******************************************
* Edgardo Richard Ventura                 *
* Week 11                                 *
* Assignment 1                            *
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
* msp = Manufacturer Suggested Retail Price (MSRP) *
*  sp = Sales Price                                *
*  sv = Savings from MSRP                          *
*  st = Sales Tax on sales price                   *
*  ts = Total Savings across all entries           *
***************************************************/


// Function prototype
float computeSavings(float msp, float sp);


int main() {
    /* CURRENT FILE DIRECTORY */
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");


    /* VALUES */
    string make, model;
    float msp, sp, sv, st, ts = 0;


    /* FILE DIRECTORY */
    ifstream infile;  // Defines a file stream object
    infile.open("auto.txt"); // Connect to the file


    /* PROCESS INPUT */
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    // Continue with your file processing
    cout << "File opened successfully!" << endl;
    cout << setprecision(2) << fixed;


    /* CALCULATION PROCESS */
    while (infile >> make >> model >> msp >> sp) {
        // Calculate savings
        sv = computeSavings(msp, sp);
        st = sp * 0.07; // Compute sales tax at 7%
        ts += sv; // Accumulate total savings

        /* INDIVIDUAL OUTPUTS */
        cout << endl;
        cout << "         Make:  " << setw(10) << make << endl;
        cout << "        Model:  " << setw(10) << model << endl;
        cout << "         MSRP: $" << setw(10) << msp << endl;
        cout << "  Sales Price: $" << setw(10) << sp << endl;
        cout << "      Savings: $" << setw(10) << sv << endl;
        cout << "    Sales Tax: $" << setw(10) << st << endl;
    }


    /* ACCUMULATIVE OUTPUTS */
    cout << endl;
    cout << "-------- Total Savings --------" << endl;
    cout << "Total Savings: $" << setw(10) << ts << endl;

    infile.close(); // Close the file

    return 0;
}


/* FUNCTION DEFINITIONS */
float computeSavings(float msp, float sp) {
    return msp - sp;  // Compute savings
}
