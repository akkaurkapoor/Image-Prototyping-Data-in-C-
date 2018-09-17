/**
 * Color.cpp
 *
 * EECS 183, Winter 2018
 * Project 4: CoolPics
 *
 * Abpreet Kaur
 * abpreetk
 *
 * Implemented color class functions for CoolPics below.
 */

#include "Color.h"

// Checks range [0,255] and returns proper value
int Color::checkRange(int val) {
    if (val >= 0 && val <= 255) {
        return val;
    }
    else if (val < 0) {
        return 0;
    }
    else {
        return 255;
    }
}

// Default constructor sets color to black (0,0,0)
Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

// Overloaded constructor sets RGB values using [0,255]
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue  = checkRange(blueVal);
}

// Returns blue, green, & red values

int Color::getBlue() {
    return blue;
}

int Color::getGreen() {
    return green;
}

int Color::getRed() {
    return red;
}

// Sets blue, green, & red values

void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// Reads color in proper red, green, blue form
void Color::read(istream &ins) {
    ins >> red >> green >> blue;
    
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

// Writes color in proper red, green, blue form
void Color::write(ostream &outs) {
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

