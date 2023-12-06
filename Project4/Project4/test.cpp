/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Ishika Majumder
 * ishika@umich.edu
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Graphics();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Graphics();
    test_Line();
    test_Triangle();
    test_Circle();
    test_Rectangle();    
    return;
}

void test_Point() {
    cout << " Now testing: Point" << endl;

    // test of default constructor
    Point p1;
    cout << "Expected: (0, 0) , Actual: " << p1 << endl;
    Point p2;
    cout << "Expected: (0, 0) , Actual: " << p2 << endl << endl;
    
    
    // test of the non-default constructor
    Point p6(3, 9);
    cout << "Expected: (3, 9) , Actual: " << p6 << endl;
    Point p7(82, 91);
    cout << "Expected: (82, 91) , Actual: " << p7 << endl << endl;


    // test of member function: setX()
    p1.setX(5);
    p2.setX(83);

    // test of member function: setY()
    p1.setY(3);
    p2.setY(63);


    // test of member functions getX() and getY()
    cout << "Expected: (5, 3) , Actual: " <<  "(" << p1.getX() << ", " << p1.getY() << ")" << endl;

    cout << "Expected: (83 63) , Actual: " << "(" << p2.getX() << ", " << p2.getY() << ")" << endl << endl;

    
    // you can also do cin >> p1;
    cout << "Input (7, 80)\t";
    p1.read(cin);
    cout << "Expected: (7,80) , Actual: " << p1 << endl;

    cout << "Input (130, -72)\t";
    p2.read(cin);
    cout << "Expected: (99, 0) , Actual: " << p2 << endl << endl;
 }

void test_Color() {
    cout << " Now testing: Color" << endl;
    // test of default constructor
    Color c1;
    cout << "Expected: 0 0 0 , Actual: " << c1 << endl;
    Color c2;
    cout << "Expected: 0 0 0 , Actual: " << c2 << endl << endl;

    // test of the non-default constructor
    Color c6(136, -98, 240);
    cout << "Expected: 136 0 240 , Actual: " << c6 << endl;
    Color c7(182, 260, 7);
    cout << "Expected: 182 255 7 , Actual: " << c7 << endl << endl;

    // test of member function: setRed()
    c1.setRed(65);
    c2.setRed(250);

    // test of member function: setGreen()
    c1.setGreen(187);
    c2.setGreen(-51);

    // test of member function: setBlue()
    c1.setBlue(200);
    c2.setBlue(293);


    // test of member functions getRed() and getGreen() and getBlue()
    cout << "Expected: 65 187 200 , Actual: " << 
        c1.getRed() << " " << c1.getGreen() << " " << c1.getBlue() << endl;

    cout << "Expected: 250 0 255 , Actual: " << 
        c2.getRed() << " " << c2.getGreen() << " " << c2.getBlue() << endl;

    // you can also do cin >> p1;
    cout << "Input 40 29 832\t";
    c1.read(cin);
    cout << "Expected: 40 29 255 , Actual: " << c1 << endl;

    cout << "Input -29 -38 23\t";
    c2.read(cin);
    cout << "Expected: 0 0 23 , Actual: " << c2 << endl;

}

void test_Graphics() {
    cout << "Now testing: Graphics" << endl;

    Color red(255, 0, 0);
    Color green(0, 255, 0);


    //test of default constructor
    Graphics a;
    Graphics b;

    //test of setPixel()
    a.setPixel(3, 5, red);
    b.setPixel(69, 61, green);


    //test of clear()
    a.clear();
    b.clear();


}

void test_Line() {
    cout << "Now testing: Line" << endl;

    //testing default constructor
    Line l1;
    cout << "Expected: (0, 0) (0, 0) 0 0 0 , Actual: " << l1 << endl;
    Line l2;
    cout << "Expected: (0, 0) (0, 0) 0 0 0 , Actual: " 
        << l2 << endl << endl;

    Color red(255, 0, 0);
    Color green(0, 255, 0);
    Point p1(3, 9);
    Point p2(82, 91);
    Point p3(39, 45);
    Point p4(-92, 838);

    //testing non-default constructor
    Line l3(p1, p4, red);
    cout << "Expected: (3, 9) (0, 99) 255 0 0 , Actual: " << l3 << endl;
    Line l4(p3, p1, green);
    cout << "Expected: (39, 45) (3, 9) 0 255 0 , Actual: " 
        << l4 << endl << endl;

    //testing setStart
    l1.setStart(p2);
    l2.setStart(p3);

    //testing setEnd
    l1.setEnd(p1);
    l2.setEnd(p2);

    //testing setColor
    l1.setColor(red);
    l2.setColor(green);
    
    //testing getter
    cout << "Expected: (82, 91) (3, 9) 255 0 0 , Actual: " << 
        l1.getStart() << " " << l1.getEnd() << " " << l1.getColor() << endl;

    cout << "Expected: (39, 45) (82, 91) 0 255 0 , Actual: " 
        << l2.getStart() << " " << l2.getEnd() << " " << l2.getColor() 
        << endl << endl;


    cout << "Input (19, 75) (13, 89) 12 297 -86\t";
    l1.read(cin);
    cout << "Expected: (19, 75) (13, 89) 12 255 0 , Actual: " << l1 << endl;

    cout << "Input (135, -92) (1, 99) 13 74 71\t";
    l2.read(cin);
    cout << "Expected: (99, 0) (1, 99) 13 74 71 , Actual: " << l2 << endl;

}

void test_Triangle() {
    cout << "Now testing: Triangle" << endl;

    //testing default constructor
    Triangle t1;
    cout << "Expected: (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0 , Actual: " 
        << t1 << endl;
    Triangle t2;
    cout << "Expected: (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0 , Actual: " 
        << t2 << endl;

    Point p1(90, 73);
    Point p2(82, 61);
    Point p3(13, 8);
    Point p4(18, 92);
    Color c1(75, 98, 217);
    Color c2(18, 183, 215);
    Color c3(0, 255, 0);
    Color c4(250, 209, 0);

    //testing non-default constructor
    Triangle t3(p1, p2, p3, c1);
    cout << "Expected: (90, 73) 75 98 217 (82, 61) " <<
        "75 98 217 (13, 8) 75 98 217 , Actual: " << t3 << endl;
    Triangle t4(p4, p3, p1, c2);
    cout << "Expected: (18, 92) 18 183 215 (13, 8) "
        "18 183 215 (90, 73) 18 183 215 , Actual: " << t4 << endl << endl;

 
    Triangle t5(p1, c2, p3, c1, p2, c3);
    cout << "Expected: (90, 73) 18 183 215 (13, 8) " <<
        "75 98 217 (82, 61) 0 255 0 , Actual: " << t5 << endl << endl;
    Triangle t6(p3, c4, p1, c2, p2, c3);
    cout << "Expected: (13, 8) 250 209 0 (90, 73) " <<
        "18 183 215 (82, 61) 0 255 0 , Actual: " << t6 << endl << endl;

    //testing setColor
    t1.setColor(c1);
    t2.setColor(c4);

    //testing vertex setters
    t1.setVertexOne(p2);
    t2.setVertexOne(p3);

    t1.setVertexTwo(p4);
    t2.setVertexTwo(p1);

    t1.setVertexThree(p3);
    t2.setVertexThree(p2);

    //testing vertex color setters
    t1.setVertexOneColor(c2);
    t2.setVertexOneColor(c3);

    t1.setVertexTwoColor(c3);
    t2.setVertexTwoColor(c2);

    t1.setVertexThreeColor(c4);
    t2.setVertexThreeColor(c1);

    //testing getters
    cout << "Expected: (82, 61) 18 183 215 (18, 92) " <<
        "0 255 0 (13, 8) 250 209 0 , Actual: " << 
        t1.getVertexOne() << " " << t1.getVertexOneColor() << " " << 
        t1.getVertexTwo() << " " << t1.getVertexTwoColor() << " " << 
        t1.getVertexThree() << " " << t1.getVertexThreeColor() << endl;

    cout << "Expected: (13, 8) 0 255 0 (90, 73) " <<
        "18 183 215 (82, 61) 75 98 217 , Actual: " <<
        t2.getVertexOne() << " " << t2.getVertexOneColor() << " " << 
        t2.getVertexTwo() << " " << t2.getVertexTwoColor() << " " << 
        t2.getVertexThree() << " " << t2.getVertexThreeColor() << endl;

    //testing read
    Triangle tri1;

    cout << "Input (-1, 12) 0 255 0 (23, 34) 255 50 50 (45, 560) 78 89 99\t";
    tri1.read(cin);
    cout << "Expected: (0, 12) 0 255 0 (23, 34) 255 50 50 " <<
        "(45, 99) 78 89 99 , Actual: " << tri1 << endl;

    cout << "Input (91, -812) 0 -98 0 (82, 30) 0 0 30 (15, 92) -172 917 99\t";
    t2.read(cin);
    cout << "Expected: (91, 0) 0 0 0 (82, 30) 0 0 30 " << 
        "(15, 92) 0 255 99 , Actual: " << t2 << endl;

}

void test_Circle() {
    cout << "Now testing: Circle" << endl;

    //testing default constructor;
    Circle c1;
    cout << "Expected: (0, 0) 0 0 0 0 , Actual: " << c1 << endl;
    Circle c2;
    cout << "Expected: (0, 0) 0 0 0 0 , Actual: " << c2 << endl;


    Point p1(70, 41);
    Point p2(50, 50);

    int rad1 = 12;
    int rad2 = 21;
    int rad3 = -72;

    Color col1(0, 200, 200);
    Color col2(0, 0, 90);

    //testing non-default constructors
    Circle c3(p1, rad1, col1);
    Circle c4(p2, rad2, col2);

    //testing setters
    c1.setCenter(p1);
    c2.setCenter(p2);

    c1.setRadius(rad3);
    c2.setRadius(rad1);

    c1.setColor(col1);
    c2.setColor(col2);

    //testing getters
    cout << "Expected: (70, 41) 72 0 200 200 , Actual: " << 
        c1.getCenter() << " " << c1.getRadius() << " " << 
        c1.getColor() << endl;
    cout << "Expected: (50, 50) 12 0 0 90 , Actual: " << 
        c2.getCenter() << " " << c2.getRadius() << " " << 
        c2.getColor() << endl;

    //testing read
    cout << "Input (-1, 12) -8 78 89 99\t";
    c1.read(cin);
    cout << "Expected: (0, 12) 8 78 89 99 , Actual: " << c1 << endl;

    cout << "Input (91, -812) 9 -172 917 99\t";
    c2.read(cin);
    cout << "Expected: (91, 0) 9 0 255 99 , Actual: " << c2 << endl << endl;
}

void test_Rectangle() {
    cout << "Now testing: Rectangle" << endl;

    //testing default constructor
    Rectangle r1;
    cout << "Expected: (0, 0) (0, 0) 0 0 0 0 0 0 0 0 0 0 0 0 , Actual: " << r1;
    Rectangle r2;
    cout << "Expected: (0, 0) (0, 0) 0 0 0 0 0 0 0 0 0 0 0 0 , Actual: " << r2;

    Point p1(20, 20);
    Point p2(40, 40);
    Point p3(50, 40);
    Point p4(60, 60);
    Color c1(0, 90, 90);
    Color c2(90, 90, 0);
    Color c3(200, 200, 200);
    Color c4(90, 90, 90);
    Color c5(80, 80, 80);

    //testing non-default constructors
    Rectangle r3(p1, p2, c1);
    cout << "Expected: (20, 20) (40, 40) 0 90 90 0 90 90 0 90 90 " <<
        "0 90 90 , Actual:  " << r3;
    Rectangle r4(p3, p1, c2);
    cout << "Expected: (50, 40) (20, 20) 90 90 0 90 90 0 90 90 0 " << 
        "90 90 0 , Actual:  " << r4;

    Rectangle r5(p1, p4, c1, c2, c3, c4);
    cout << "Expected: (20, 20) (60, 60) 0 90 90 90 90 0 200 200 200 " <<
        "90 90 90 , Actual:  " << r5;
    Rectangle r6(p2, p4, c2, c2, c3, c3);
    cout << "Expected: (40, 40) (60, 60) 90 90 0 90 90 0 200 200 200 " <<
        "200 200 200 , Actual:  " << r6;

    //testing setters
    r1.setStart(p3);
    r2.setStart(p4);

    r1.setEnd(p4);
    r2.setEnd(p2);

    r1.setColor(c3);
    r2.setColor(c5);

    r1.setColorBottomLeft(c2);
    r2.setColorBottomLeft(c3);

    r1.setColorBottomRight(c3);
    r2.setColorBottomRight(c4);

    r1.setColorTopLeft(c4);
    r2.setColorTopLeft(c5);
    
    r1.setColorTopRight(c5);
    r2.setColorTopRight(c1);

    //testing getters
    cout << "Expected: (50, 40) (60, 60) 90 90 90 80 80 80 90 90 0 " <<
        "200 200 200 Actual: " <<
        r1.getStart() << " " << r1.getEnd() << " " << 
        r1.getColorTopLeft() << " " << r1.getColorTopRight() << 
        r1.getColorBottomLeft() << " " << r1.getColorBottomRight() 
        << " " <<  endl;

    cout << "Expected: (60, 60) (40, 40) 80 80 80 0 90 90 200 200 200 " <<
        "90 90 90 , Actual: " <<
        r2.getStart() << " " << r2.getEnd() << " " << 
        r2.getColorTopLeft() << " " << r2.getColorTopRight() << 
        r2.getColorBottomLeft() << " " << r2.getColorBottomRight() 
        << " " <<  endl;

    //testing read
    cout << "Input (-1, 12) (90, 99) -86 0 0 90 90 90 80 80 80 70 70 70 " <<
        "90 90 280 \t";
    r1.read(cin);
    cout << "Expected: (0, 12) (90, 99) 0 0 0 90 90 90 80 80 80 70 70 70 " <<
        "90 90 255 , Actual: " << r1 << endl;

    cout << "Input (-1, 90) (70, 99) -86 0 0 12 12 12 80 80 80 34 34 34 " <<
        "90 90 280 \t";
    r2.read(cin);
    cout << "Expected: (0, 90) (70, 99) 0 0 0 12 12 12 80 80 80 34 34 34 " <<
        "90 90 255 , Actual: " << r2 << endl;
}


