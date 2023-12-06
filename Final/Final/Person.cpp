#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string input_string) : Person() {
    stringstream ss(input_string);
    //the letters in the string that I don't need
    char f;
    char t;
    char a;

    //collecting information
    ss >> turn;
    ss >> f;
    ss >> currentFloor;
    ss >> t;
    ss >> targetFloor;
    ss >> a;
    ss >> angerLevel;
}

bool Person::tick(int currentTime) {
    //if time is divisible by ticks per anger increase
    if (currentTime % TICKS_PER_ANGER_INCREASE == 0) {
        angerLevel++;
    }

    //if the anger is too high, they explode
    if (angerLevel == MAX_ANGER) {
        return true;
    }
    else {
        return false;
    }
}

void Person::print(ostream& outs) {
    //proper format
    outs << "f" << currentFloor << "t" << targetFloor << "a" 
        << angerLevel << endl;

}


//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person() {
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const {
    return turn;
}

int Person::getCurrentFloor() const {    
    return currentFloor;
}

int Person::getTargetFloor() const {    
    return targetFloor;
}

int Person::getAngerLevel() const {    
    return angerLevel;
}

ostream& operator<< (ostream& outs, Person p)
{
    p.print(outs);
    return outs;
}
