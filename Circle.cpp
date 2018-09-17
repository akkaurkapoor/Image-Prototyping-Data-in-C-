/**
 * Circle.cpp
 *
 * EECS 183, Winter 2018
 * Project 4: CoolPics
 *
 * Abpreet Kaur
 * abpreetk
 *
 * Implemented circle class functions for CoolPics below.
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;


// Default constructor sets values to 0
Circle::Circle() {
    center.setX(0);
    center.setY(0);
    
    radius = 0;
    
    color.setBlue(0);
    color.setGreen(0);
    color.setRed(0);
}

// Overloaded constructor sets center, radius, & one color
Circle::Circle(Point pt, int r, Color c) {
    center.setX(pt.getX());
    center.setY(pt.getY());
    
    radius = checkRadius(r);
    
    color.setBlue(c.getBlue());
    color.setGreen(c.getGreen());
    color.setRed(c.getRed());
}

// Sets and returns circle center

void Circle::setCenter(Point pt) {
    center.setX(pt.getX());
    center.setY(pt.getY());
}

Point Circle::getCenter() {
    return center;
}

// Sets and returns circle color

void  Circle::setColor(Color c) {
    color.setBlue(c.getBlue());
    color.setGreen(c.getGreen());
    color.setRed(c.getRed());
}

Color Circle::getColor() {
    return color;
}

// Sets and returns positive circle radius after checking

void Circle::setRadius(int r) {
    radius = checkRadius(r);
}

int Circle::getRadius() {
    return radius;
}

// Read and set circle in proper form (center, radius, color)
void Circle::read(istream &ins) {
    Point newCenter;
    int radi;
    Color newColor;
    
    ins >> newCenter >> radi >> newColor;
    
    setCenter(newCenter);
    setRadius(radi);
    setColor(newColor);
}

// Writes circle in proper form
void Circle::write(ostream &outs) {
    outs << center << " " << radius <<  " " << color;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();
    
    while (x >= y)
    {
        plot8points(x, y, c, drawer);
        
        error += y;
        ++y;
        error += y;
        
        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();
    
    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);
    
    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
