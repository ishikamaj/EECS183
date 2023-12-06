#include "Floor.h"

using namespace std;

int Floor::tick(int currentTime) {
	int numExploded = 0;
	int exploded[MAX_PEOPLE_PER_FLOOR];
	int index = 0;
	//ticking each person which increases the angerLevel
	//if anger is max, then they exploded so keep track
	for (int i = 0; i < numPeople; i++) {
		if (people[i].tick(currentTime)) {
			numExploded++;
			exploded[index] = i;
			index++;
		}
	}
	//remove those that exploded and return how many were removed
	removePeople(exploded, numExploded);
	return numExploded;
}

void Floor::addPerson(Person p, int request) {
	//can only add if there is room
	if (numPeople < MAX_PEOPLE_PER_FLOOR) {
		people[numPeople] = p;
		numPeople++;
		//see if going up or down depending on the sign of request
		//which is targetFloor - currentFloor
		if (request < 0) {
			hasDownRequest = true;
		}
		else if (request > 0) {
			hasUpRequest = true;
		}
	}
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], 
	int numPeopleToRemove) {
	Person empty;
	bool equal = false;
	int num = 0;
	//this array will keep track of the people that stay
	Person newArray[MAX_PEOPLE_PER_FLOOR];

	//go through all the people and see 
	//if anything indicesToRemove match the indices of people
	for (int i = 0; i < numPeople; i++) {
		for (int j = 0; j < numPeopleToRemove; j++) {
			if (i == indicesToRemove[j]) {
				equal = true;
			}
		}

		//if they don't match, add to the new array
		if (!equal) {
			newArray[num] = people[i];
			num++;
		}
		//resets
		equal = false;
	}

	numPeople -= numPeopleToRemove;
	//copy newArray to people
	for (int k = 0; k < MAX_PEOPLE_PER_FLOOR; k++) {
		if (k < numPeople) {
			people[k] = newArray[k];
		}
		else {
			people[k] = empty;
		}
	}	

	resetRequests();
}

void Floor::resetRequests() {
	int upNum = 0;
	int downNum = 0;
	//counts the number of up requests and down requests
	for (int i = 0; i < numPeople; i++) {
		if (people[i].getCurrentFloor() - people[i].getTargetFloor() > 0) {
			downNum++;
		}
		else if (people[i].getCurrentFloor() - people[i].getTargetFloor() < 0) {
			upNum++;
		}
	}

	hasUpRequest = false;
	hasDownRequest = false; 

	if (upNum >= 1) {
		hasUpRequest = true;
	}

	if (downNum >= 1) {
		hasDownRequest = true;
	}
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i){
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " O   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "-|-  ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " |   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "/ \\  ";
	}
	outs << endl << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << i << "   ";
	}
	outs << endl << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
	return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
