#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime) {
    //if time is divisible by ticks per elevator move and is servicing,
    //then send the elevator closer to it's destination

    if (currentTime % TICKS_PER_ELEVATOR_MOVE == 0) {
        if (servicing) {
            if (currentFloor > targetFloor) {
                currentFloor--;
            }
            else if (currentFloor < targetFloor) {
                currentFloor++;
            }
                
        }
    }

    //if it reached the destination, then it's no longer servicing
    if (currentFloor == targetFloor) {
        servicing = false;
    }

}


void Elevator::serviceRequest(int floorNum) {
    targetFloor = floorNum;
    servicing = true;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream &outs) {
    outs << currentFloor;
    if (!servicing){
        outs << "w";
    } else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
	targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
	return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
