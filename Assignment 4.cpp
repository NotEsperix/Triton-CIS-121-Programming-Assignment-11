/******************************************
* Edgardo Richard Ventura                 *
* Week 11                                 *
* Assignment 4                            *
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
*            ln = Last name of the employee        *
*          1pay = Annual salary                    *
*         12pay = Monthly salary estimate          *
*         21pay = Bi-weekly salary                 *
*         52pay = Weekly salary estimate           *
*        per/hr = Hourly wage estimate             *
*         total = Total of all annual salaries     *
* employeeCount = Number of employees processed    *
* averageSalary = Average annual salary            *
***************************************************/


// Function prototypes
float calculateBiWeeklyPay(float annualSalary);
float calculateMonthlyPay(float annualSalary);
float calculateWeeklyPay(float annualSalary);
float calculateHourlyWage(float annualSalary);


int main() {
    /* CURRENT FILE DIRECTORY */
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");


    /* VALUES */
    string ln;
    float annualSalary, biWeeklyPay, monthlyPay, weeklyPay, hourlyWage;
    float total = 0;
    int employeeCount = 0;


    /* FILE DIRECTORY */
    ifstream infile;  // Defines a file stream object
    infile.open("empl.txt"); // Connect to the file


    /* PROCESS INPUT */
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    cout << "File opened successfully!" << endl;
    cout << setprecision(2) << fixed;


    /* PROCESS CALCULATION */
    while (infile >> ln >> annualSalary) {
        biWeeklyPay = calculateBiWeeklyPay(annualSalary);
        monthlyPay = calculateMonthlyPay(annualSalary);
        weeklyPay = calculateWeeklyPay(annualSalary);
        hourlyWage = calculateHourlyWage(annualSalary);
        total += annualSalary;
        employeeCount++;


        /* INDIVIDUAL OUTPUTS */
        cout << endl;
        cout << "     Last Name: " << setw(8) << ln << endl;
        cout << " Annual Salary: $" << setw(10) << annualSalary << endl;
        cout << "   Monthly Pay: $" << setw(10) << monthlyPay << endl;
        cout << " Bi-weekly Pay: $" << setw(10) << biWeeklyPay << endl;
        cout << "    Weekly Pay: $" << setw(10) << weeklyPay << endl;
        cout << "   Hourly Wage: $" << setw(10) << hourlyWage << endl;
    }


    /* ACCUMULATIVE OUTPUTS */
    float averageSalary = (employeeCount > 0) ? total / employeeCount : 0;

    cout << endl;
    cout << "-------- Salary Summary --------" << endl;
    cout << "       Employee Count: " << setw(8) << employeeCount << endl;
    cout << "Total Annual Salaries: $" << setw(10) << total << endl;
    cout << "Average Annual Salary: $" << setw(10) << averageSalary << endl;

    infile.close(); // Close the file

    return 0;
}


/* FUNCTION DEFINITIONS */
float calculateBiWeeklyPay(float annualSalary) {
    return annualSalary / 26;  // Compute bi-weekly pay
}

float calculateMonthlyPay(float annualSalary) {
    return annualSalary / 12;  // Compute monthly pay
}

float calculateWeeklyPay(float annualSalary) {
    return annualSalary / 52;  // Compute weekly pay
}

float calculateHourlyWage(float annualSalary) {
    return annualSalary / (52 * 40);  // Assume 40 hours per week
}
