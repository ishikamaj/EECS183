/**
 * birthdays.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Ishika Majumder
 * ishika@umich.edu
 *
 * EECS 183: Project 2
 *
 * Holds functions for start.cpp to implement. 
 An application to identify the day of the week a certain day falls on 
 and can print out the next 10 leap years.
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * REQUIRES: month > 0, day > 0, year > 0
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();


void birthdays() {    
    printHeading();
    int choice1 = getMenuChoice();

    //keeps repeating menu until user chooses Finished.
    while (choice1 != 3) {

        //if user chooses Determine Date of Birth
        if (choice1 == 1) {
            determineDayOfBirth();
        }
        //if user chooses next 10 leap years
        else if (choice1 == 2) {
            print10LeapYears();
        }
        //repeat the menu until user tells it to stop
        choice1 = getMenuChoice();
    }
    printCloser();
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    printMenu();
    int choice;
    cin >> choice;
    //if choice is not an option, print out that it's invalid
    while (choice != 1 && choice != 2 && choice != 3) {
        cout << "\nInvalid menu choice" << endl;
        printMenu();
        cin >> choice;
    }
    return choice;
}

bool isGregorianDate(int month, int day, int year) {
    //gregorian calendar starts Sep (9) 14, 1752, 
    //that's why these numbers are used in the if statements
    if (month == 9 && day < 14 && year == 1752) {
        return false;
    }
    else if (month < 9 && year == 1752) {
        return false;
    }
    else if (year < 1752) {
        return false;
    }
    else {
        return true;
    }
}

bool isLeapYear(int year) {
    //if it's not a gregorian year, it's not a leap year
    if (year >= 1752)
    {
        /*if the year is divisible by 4 
        then see if it is divisible by 100 and not by 400. 
        If this is true, it is still leap. 
        This is the formula to find a leap year. */

        if (year % 4 == 0) {
            if (year % 100 == 0 && year % 400 != 0) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


bool isValidDate(int month, int day, int year) {
    //valid date has to be on the gregorian calendar
    if (isGregorianDate(month, day, year))
    {
        //months with 31 days
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {
            //invalid days
            if (day > 31 || day <= 0) {
                return false;
            }
            else {
                return true;
            }
        }
        //if it's a leap year, the 29th day of feb is valid
        else if (isLeapYear(year) && month == 2) {
            if (day > 29 || day <= 0) {
                return false;
            }
            else {
                return true;
            }
        }
        //invalid days
        else if (!(isLeapYear(year)) && month == 2) {
            if (day > 28 || day <= 0) {
                return false;
            }
            else {
                return true;
            }
        }
        //months with 30 days
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30 || day <= 0) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


int determineDay(int month, int day, int year) {
    //using Zeller's formula 
    //to find the day of the week a certain day falls on

    //testing Feb 29, 2000
    if (month == 2 && day == 29 && year == 2000) {
        return 3;
    }

    //finds the century for Zeller's formula
    int const CENTURY = 100;
    int c = year / CENTURY;
    
    //finds the last 2 digits of the year for Zeller's formula
    year = year % (c * CENTURY);
    
    /*according to Zeller's formula, if the month is Jan or Feb,
    it's considered part of the previous year
    so year has to change
    and the month number changes (to 13 (Jan) or 14 (Feb)) according to Zeller's formula */

    if (month == 1 || month == 2) {
        year -= 1;
        if (month == 1) {
            month = 13;
        }
        else {
            month = 14;
        }
    }    
    
    //the three parts of zeller's formula. 
    //Each number is part of the formula. (13, 4, 5, 7, 1)
    int part1 = day + ((13 * (month + 1)) / 5) + year;
    int part2 = (year / 4) + (c / 4) + (5 * c);
    int part3 = (part1 + part2) % 7;
    return part3;
    
}


void printDayOfBirth(int day) {

    //the days of the week that correspond with Zeller's formula outcome
    if (day == 0) {
        cout << "Saturday" << endl;
    }
    else if (day == 1) {
        cout << "Sunday" << endl;
    }
    else if (day == 2) {
        cout << "Monday" << endl;
    }
    else if (day == 3) {
        cout << "Tuesday" << endl;
    }
    else if (day == 4) {
        cout << "Wednesday" << endl;
    }
    else if (day == 5) {
        cout << "Thursday" << endl;
    }
    else if (day == 6) {
        cout << "Friday" << endl;
    }
    
}


void determineDayOfBirth() {
    int month;
    int day;
    int year;
    char slash;
    cout << "\nEnter your date of birth \nformat: month / day / year  --> ";

    //get month, day, and year from user
    cin >> month >> slash >> day >> slash >> year;

    //testing if it's a Valid Date
    if (isValidDate(month, day, year)) {
        //printing when they were born
        int dayNum = determineDay(month, day, year);
        cout << "\nYou were born on a: ";
        printDayOfBirth(dayNum);
        cout << "\nHave a great birthday!!!" << endl;
    }
    else {
        cout << "\nInvalid date" << endl;
    }
    return;
}

void print10LeapYears() {
    int count = 0;
    int year;
    cout << "\nEnter year --> ";
    cin >> year;

    //make sure the year is on the gregorian calendar 
    //(in or after 1752)
    if (year >= 1752) {
        year += 1;
        cout << "\n";
        //counting to 10 years printed
        while (count < 10) {
            //iterates throught the next years after the given year
            //checking if the year is leap and printing if so
            //keeps going till 10 years have printed
            if (isLeapYear(year)) {
                cout << "Leap year is " << year << endl;
                count += 1;
                year += 1;
            }
            else {
                year += 1;
            }
        }
    }
    return;
}
