/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Ishika Majumder
 * ishika@umich.edu
 *
 * Functions for Colors
 */

#include "Color.h"



Color::Color() {
	green = 0;
	red = 0;
	blue = 0;
}
Color::Color(int redVal, int greenVal, int blueVal) {
	red = checkRange(redVal);
	green = checkRange(greenVal);
	blue = checkRange(blueVal);
}
int Color::checkRange(int val) {
	//make sure it's a valid number
	if (val >= 0 && val <= 255) {
		return val;
	}
	//if it's not, then replace the number with either 0 or 255
	//depends which is closer
	else {
		int dis = 255 - val;
		if (dis > val) {
			return 0;
		}
		else {
			return 255;
		}
	}
}

void Color::setRed(int redVal) {
	red = checkRange(redVal);
}
int Color::getRed() {
	return red;
}
void Color::setGreen(int greenVal) {
	green = checkRange(greenVal);
}
int Color::getGreen() {
	return green;
}
void Color::setBlue(int blueVal) {
	blue = checkRange(blueVal);
}
int Color::getBlue() {
	return blue;
}
void Color::read(istream& ins) {
	int cRed;
	int cBlue;
	int cGreen;
	ins >> cRed >> cGreen >> cBlue;
	setRed(cRed);
	setGreen(cGreen);
	setBlue(cBlue);
}
void Color::write(ostream& outs) {
	outs << red << " " << green << " " << blue;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
