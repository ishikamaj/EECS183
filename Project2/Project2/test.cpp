/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Ishika Majumder
 * ishika@umich.edu
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,

    test_getMenuChoice();
    test_isGregorianDate();
    
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears(); 

}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "\nNow testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    cout << "Please enter 7 then 10 then 2:";
    int choice3 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then \"Invalid menu choice\" then 2." << endl;
    cout << "Actual: " << choice3 << endl;

    cout << "\nNow testing funtion getMenuChoice()\n";
    cout << "Please enter 2:" << endl;
    int choice4 = getMenuChoice();
    cout << "Test result: expected: 2, actual: " << choice4 << endl;

    cout << "\nNow testing funtion getMenuChoice()\n";
    cout << "Please enter 1:" << endl;
    int choice5 = getMenuChoice();
    cout << "Test result: expected: 1, actual: " << choice5 << endl;
}

void test_isGregorianDate()
{
    // isGregorianDate does not read from cin, so
    // all its tests can be run automatically

    cout << "\nNow testing function isGregorianDate()\n";

    cout << "9 / 14 / 1752:  Expected: 1, Actual: " << isGregorianDate(9, 2, 2019) << endl;
    cout << "9 / 14 / 1752: Expected: 1, Actual: " << isGregorianDate(9, 14, 1752) << endl;
    cout << "9 / 13 / 1752: Expected: 0, Actual: " << isGregorianDate(9, 13, 1752) << endl;
    cout << "9 / 15 / 1752: Expected: 1, Actual: " << isGregorianDate(9, 15, 1752) << endl;
    cout << "1 / 14 / 1752: Expected: 0, Actual: " << isGregorianDate(1, 14, 1752) << endl;
    cout << "1 / 13 / 1752: Expected: 0, Actual: " << isGregorianDate(1, 13, 1752) << endl;
    cout << "1 / 15 / 1752: Expected: 0, Actual: " << isGregorianDate(1, 15, 1752) << endl;
    cout << "10 / 14 / 1752: Expected: 1, Actual: " << isGregorianDate(10, 14, 1752) << endl;
    cout << "10 / 13 / 1752: Expected: 1, Actual: " << isGregorianDate(10, 13, 1752) << endl;
    cout << "10 / 15 / 1752: Expected: 1, Actual: " << isGregorianDate(10, 15, 1752) << endl;
}

void test_isLeapYear()
{
    cout << "\nNow testing function isLeapYear()\n";
    cout << "2016:  Expected: 1, Actual: " << isLeapYear(2016) << endl;
    cout << "2007: Expected: 0, Actual: " << isLeapYear(2007) << endl;
    cout << "1900: Expected: 0, Actual: " << isLeapYear(1900) << endl;
    cout << "2000:  Expected: 1, Actual: " << isLeapYear(2000) << endl;
    cout << "1811:  Expected: 0, Actual: " << isLeapYear(1811) << endl;
    cout << "2040:  Expected: 1, Actual: " << isLeapYear(2040) << endl;


}

void test_isValidDate()
{
    cout << "\nNow testing function isValidDate()\n";
    cout << "1/31/2019:  Expected: 1, Actual: " << isValidDate(1, 31, 2019) << endl;
    cout << "2/31/1901: Expected: 0, Actual: " << isValidDate(2, 31, 1901) << endl;
    cout << "2/29/2008: Expected: 1, Actual: " << isValidDate(2, 29, 2008) << endl;
    cout << "2/29/2011: Expected: 0, Actual: " << isValidDate(2, 29, 2011) << endl;
    cout << "83/31/1901: Expected: 0, Actual: " << isValidDate(83, 31, 1901) << endl;


}

void test_determineDay()
{
    cout << "\nNow testing function determineDay()\n";
    cout << "1/31/2019: Expected: 5, Actual: " << determineDay(1, 31, 2019) << endl;
    cout << "2/29/2008: Expected: 6, Actual: " << determineDay(2, 29, 2008) << endl;
    cout << "10/5/1937: Expected: 3, Actual: " << determineDay(10, 5, 1937) << endl;
    cout << "2/29/2000: Expected: 3, Actual: " << determineDay(2, 21, 2000) << endl;
    cout << "9/27/2020: Expected: 1, Actual: " << determineDay(9, 27, 2020) << endl;


}

void test_printDayOfBirth()
{
    // printDayOfBirth prints to cout rather than
    // returning a value.
    cout << "\nNow testing function printDayOfBirth()\n";
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);

    cout << "3: Expected: Tuesday, Actual: ";
    printDayOfBirth(3);

    cout << "6: Expected: Friday, Actual: ";
    printDayOfBirth(6);

    cout << "4: Expected: Wednesday, Actual: ";
    printDayOfBirth(4);

    cout << "0: Expected: Saturday, Actual: ";
    printDayOfBirth(0);
    cout << endl;
}

void test_determineDayOfBirth()
{
    cout << "\nNow testing funtion determineDayOfBirth()\n";
    cout << "Please enter 09 / 27 / 2020:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"Sunday \" : ";
    cout << "Actual: ";
    determineDayOfBirth();

    cout << "Please enter 2 / 29 / 2000:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"Tuesday \" : ";
    cout << "Actual: ";
    determineDayOfBirth();

    cout << "Please enter 1 / 31 / 2019:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"Thursday \" : ";
    cout << "Actual: ";
    determineDayOfBirth();
    
    cout << "Please enter 10 / 05 / 2002:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"Saturday \" : ";
    cout << "Actual: ";
    determineDayOfBirth();

    cout << "\nPlease enter 19 / 09 / 1893:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid date\" " << endl;
    cout << "Actual: ";
    determineDayOfBirth();
}

void test_print10LeapYears()
{
    cout << "\nNow testing function print10LeapYears()\n";
    cout << "Please enter 1981:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020 \" " << endl;
    cout << "Actual: ";
    print10LeapYears();

    cout << "\nPlease enter 1804:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"1808, 1812, 1816, 1820, 1824, 1828, 1832, 1836, 1840, 1844 \" " << endl;
    cout << "Actual: ";
    print10LeapYears();

    cout << "\nPlease enter 1913:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"1916, 1920, 1924, 1928, 1932, 1936, 1940, 1944, 1948, 1952 \" " << endl;
    cout << "Actual: ";
    print10LeapYears();

    cout << "\nPlease enter 1960:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000 \" " << endl;
    cout << "Actual: ";
    print10LeapYears();

    cout << "\nPlease enter 1855:" << endl;
    cout << "Test result: " << endl;
    cout << "Expected: \"1856, 1860, 1864, 1868, 1872, 1876, 1880, 1884, 1888, 1892 \" " << endl;
    cout << "Actual: ";
    print10LeapYears();
}