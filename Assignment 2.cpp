/******************************************
* Edgardo Richard Ventura                 *
* Week 11                                 *
* Assignment 2                            *
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
*      qty = Quantity of grocery items             *
*      cpi = Cost Per Item                         *
*       ep = Extended Price                        *
*  totalEP = Total Extended Price                  *
*      tax = Sales Tax on total extended price     *
* totalRec = Total Receipt including sales tax     *
***************************************************/


// Function prototype
float calculateExtendedPrice(int qty, float cpi);


int main() {
    /* CURRENT FILE DIRECTORY */
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");


    /* VALUES */
    string item;
    int qty;
    float cpi, ep, totalEP = 0, tax, totalRec;


    /* FILE DIRECTORY */
    ifstream infile;  // Defines a file stream object
    infile.open("grocery.txt"); // Connect to the file


    /* PROCESS INPUT */
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    // Continue with your file processing
    cout << "File opened successfully!" << endl;
    cout << setprecision(2) << fixed;


    /* CALCULATION PROCESS */
    while (infile >> item >> qty >> cpi) {
        // Calculate extended price
        ep = calculateExtendedPrice(qty, cpi);
        totalEP += ep; // Accumulate total extended price


        /* INDIVIDUAL OUTPUTS */
        cout << endl;
        cout << "           Item: #" << item << endl;
        cout << "       Quantity: " << qty << "q" << endl;
        cout << "  Cost per Item: $" << setw(6) << cpi << endl;
        cout << "      Ext.Price: $" << setw(6) << ep << endl;
    }


    /* ACCUMULATIVE OUTPUTS CALCULATION */
    tax = totalEP * 0.07; // Calculate sales tax
    totalRec = totalEP + tax; // Calculate total receipt

    cout << endl;
    cout << "-------- Your Total Is --------" << endl;
    cout << "Total Ext.Price: $" << setw(7) << totalEP << endl;
    cout << "      Sales Tax: $" << setw(7) << tax << endl;
    cout << "  Total Receipt: $" << setw(7) << totalRec << endl;

    infile.close(); // Close the file
    return 0;
}

/* FUNCTION DEFINITIONS */
float calculateExtendedPrice(int qty, float cpi) {
    return qty * cpi;  // Compute extended price
}