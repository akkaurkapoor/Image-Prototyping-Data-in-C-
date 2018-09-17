/**
 * Point.cpp
 *
 * EECS 183, Winter 2018
 * Project 4: CoolPics
 *
 * Abpreet Kaur
 * abpreetk
 *
 * Implemented point class functions for CoolPics below.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// Default constructor sets (x,y) to origin
Point::Point() {
    x = 0;
    y = 0;
}

// Overloaded constructor sets (x,y) coordinates
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// Set and return x coordinate
void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return x;
}

// Set and return y coordinate
void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return y;
}

// Read point in coordinate form
void Point::read(istream &ins) {
    char temp;
    ins >> temp >> x >> temp >> y >> temp;
    
    setX(x);
    setY(y);
}

// Write point in coordinate form
void Point::write(ostream &outs) {
    
    outs << "(" << x << "," << y << ")";
}

// Check range and returns proper val
int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    else if (val < 0) {
        return 0;
    }
    else {
        return DIMENSION - 1;
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



