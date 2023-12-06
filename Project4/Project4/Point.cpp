/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Ishika Majumder
 * ishika@umich.edu
 *
 * Functions for Point class
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point() {
    x = 0;
    y = 0;
}
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
}
int Point::getX() {
    return x;
}
void Point::setY(int yVal) {
    y = checkRange(yVal);
}
int Point::getY() {
    return y;
}

void Point::read(istream& ins) {
    char bracket1;
    char bracket2;
    char comma;
    ins >> bracket1 >> x >> comma >> y >> bracket2;
}
void Point::write(ostream& outs) {
    outs << "(" << checkRange(x) << ", " << checkRange(y) << ")";
}

int Point::checkRange(int val) {
    //makes sure number is within the bounds
    if (val >= 0 && val < DIMENSION){
        return val;
    }
    //if not in bounds, it returns 0 or DIMENSION - 1
    //depends on which is closer to the value
    else {
        if (val >= DIMENSION) {
            return DIMENSION - 1;
        }
        else {
            return 0;
        }
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
