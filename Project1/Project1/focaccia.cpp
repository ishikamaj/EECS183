/**
 * focaccia.cpp
 *
 * Ishika Majumder
 * ishika@umich.edu
 *
 * EECS 183: Project 1
 * Fall 2020
 * 
 * Project UID: 302fa9f14bd8266589c43c3129048565d11aa124
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);

int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    //calculate loaves and print
    const double PEOPLE_PER_LOAF = 4.0;
    int loaves = ceil(people / PEOPLE_PER_LOAF);
    cout << "You need to make: " << loaves  << " " 
         << pluralize("loaf", "loaves", loaves) 
         << " of focaccia" << endl << endl;

    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    
    //calculate flour and print
    const double FLOUR_CUPS_PER_LOAF = 5.0;
    const double FLOUR_CUPS_PER_BAG = 20.0;
    int flourBags = ceil((loaves * FLOUR_CUPS_PER_LOAF)/ FLOUR_CUPS_PER_BAG);
    const double PRICE_PER_FLOUR_BAG = 2.69;
    double flourCost = flourBags * PRICE_PER_FLOUR_BAG;
    cout << flourBags << " " 
         << pluralize("bag", "bags", flourBags) << " of flour" << endl;
 

    //calculate yeast and print
    const double YEAST_TSP_PER_LOAF = 1.75;
    const double YEAST_TSP_PER_PACK = 2.25;
    int yeastPacks = ceil((loaves * YEAST_TSP_PER_LOAF) / YEAST_TSP_PER_PACK);
    const double PRICE_PER_YEAST_PACK = 0.40;
    double yeastCost = yeastPacks * PRICE_PER_YEAST_PACK;
    cout << yeastPacks << " " 
         << pluralize("package", "packages", yeastPacks) << " of yeast" << endl;

    //calculate salt and print
    const double SALT_TSP_PER_LOAF = 1.875;
    const double SALT_TSP_PER_CAN = 6.0;
    int saltCans = ceil((loaves * SALT_TSP_PER_LOAF) / SALT_TSP_PER_CAN);
    const double PRICE_PER_SALT_CAN = 0.49;
    double saltCost = saltCans * PRICE_PER_SALT_CAN;
    cout << saltCans << " " 
         << pluralize("canister", "canisters", saltCans) << " of salt" << endl;

    //calculate olive oil and print
    const double OIL_TBSP_PER_LOAF = 2.0;
    const double OIL_TBSP_PER_BOTTLE = 500/14.8;
    int oilBottles = ceil((loaves * OIL_TBSP_PER_LOAF) / OIL_TBSP_PER_BOTTLE);
    const double PRICE_PER_OIL_BOTTLE = 6.39;
    double oilCost = oilBottles * PRICE_PER_OIL_BOTTLE;
    cout << oilBottles << " " 
         << pluralize("bottle", "bottles", oilBottles) 
         << " of olive oil" << endl << endl;

    //calculate total and print
    double totalCost = flourCost + yeastCost + saltCost + oilCost;
    cout << "Total expected cost of ingredients: $" << totalCost << endl << endl;
    cout << "Have a great socially-distanced party!" << endl;

    return 0;
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
