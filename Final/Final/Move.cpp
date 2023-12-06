#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    stringstream ss(commandString);
    //must be pickup is only 3 characters long
    if (commandString.length() == 3) {
        char e;
        ss >> e;
        ss >> elevatorId;
        targetFloor = -1;
        numPeopleToPickup = 0;
        totalSatisfaction = 0;
        isPass = false;
        isPickup = true;
        isSave = false;
        isQuit = false;
    }
    //must be moving to a different floor if 4 characters long
    else if (commandString.length() == 4) {
        char e;
        ss >> e;
        ss >> elevatorId;
        char t;
        ss >> t;
        ss >> targetFloor;
        numPeopleToPickup = 0;
        totalSatisfaction = 0;
        isPass = false;
        isPickup = false;
        isSave = false;
        isQuit = false;
    }
    //pass move
    else if (commandString == "") {
        elevatorId = -1;
        targetFloor = -1;
        numPeopleToPickup = 0;
        totalSatisfaction = 0;
        isPass = true;
        isPickup = false;
        isSave = false;
        isQuit = false;
    }
    //save move
    else if (commandString == "s" || commandString == "S") {
        elevatorId = -1;
        targetFloor = -1;
        numPeopleToPickup = 0;
        totalSatisfaction = 0;
        isPass = false;
        isPickup = false;
        isSave = true;
        isQuit = false;
    }
    //quit move
    else if (commandString == "q" || commandString == "Q") {
        elevatorId = -1;
        targetFloor = -1;
        numPeopleToPickup = 0;
        totalSatisfaction = 0;
        isPass = false;
        isPickup = false;
        isSave = false;
        isQuit = true;
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    if (isPass || isSave || isQuit) {
        return true;
    }

    //not servicing a request and valid elevator
    if (!elevators[elevatorId].isServicing() && 
        elevatorId < NUM_ELEVATORS && elevatorId >= 0) {
        if (isPickup) {
            return true;
        }
        //valid floor and elevator is not already at the floor
        else if (targetFloor >= 0 && targetFloor < NUM_FLOORS && 
            elevators[elevatorId].getCurrentFloor() != targetFloor) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor,
    const Floor& pickupFloor) {

    //setting everything to 0
    totalSatisfaction = 0;
    numPeopleToPickup = 0;
    char first = pickupList[0];
    int firstPerson = first - '0';
    int farthest = abs(pickupFloor.getPersonByIndex(firstPerson)
        .getTargetFloor() - currentFloor);
    int farIndex = firstPerson;
    int distance = 0;
    int personIndex = 0;

    //going through everyone
    //ading to totalSatisfaction
    //adding to peopleToPickup
    for (int i = 0; i < pickupList.length(); i++) {
        char personI = pickupList[i];
        int personIndex = personI - '0';
        peopleToPickup[i] = personIndex; 
        
        Person person = pickupFloor.getPersonByIndex(personIndex);
        int anger = person.getAngerLevel();
        if (anger < MAX_ANGER) {
            totalSatisfaction += (MAX_ANGER - anger);
        }   
        numPeopleToPickup++;
        
        //checking distance
        distance = abs(person.getTargetFloor() - currentFloor);
        if (distance > farthest) {
            farthest = distance;
            farIndex = personIndex;
        }
    }
    //finding the farthest floor
    targetFloor = pickupFloor.getPersonByIndex(farIndex).getTargetFloor();
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
