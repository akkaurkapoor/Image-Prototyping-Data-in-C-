/**
 * Rectangle.cpp
 *
 * EECS 183, Winter 2018
 * Project 4: CoolPics
 *
 * Abpreet Kaur
 * abpreetk
 *
 * Implemented rectangle class functions for CoolPics below.
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;


// Default constructor rectangle
Rectangle::Rectangle() {
    
    start.setX(0);start.setY(0);
    end.setX(0);end.setY(0);
    
    setColorBottomLeft(Color());
    setColorBottomRight(Color());
    
    setColorTopLeft(Color());
    setColorTopRight(Color());
}

// Overloaded constructor sets start, end, & single color
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    
    start.setX(pt1.getX());start.setY(pt1.getY());
    end.setX(pt2.getX());end.setY(pt2.getY());
    
    setColorBottomLeft(color);
    setColorBottomRight(color);
    
    setColorTopLeft(color);
    setColorTopRight(color);
}

// Overloaded constructor sets start, end, & four colors
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    
    start.setX(pt1.getX());start.setY(pt1.getY());
    end.setX(pt2.getX());end.setY(pt2.getY());
    
    setColorBottomLeft(cBottomLeft);
    setColorBottomRight(cBottomRight);
    
    setColorTopLeft(cTopLeft);
    setColorTopRight(cTopRight);
}

// Sets and returns start point of rectangle (top left)
void Rectangle::setStart(Point pt) {
    start.setX(pt.getX());
    start.setY(pt.getY());
}

Point Rectangle::getStart(){
    return start;
}

// Sets and returns end point of rectangle (bottom right)
void Rectangle::setEnd(Point pt) {
    end.setX(pt.getX());
    end.setY(pt.getY());
}

Point Rectangle::getEnd() {
    return end;
}

// Sets four parts of rectangles to colors

void Rectangle::setColor(Color color) {
    
    setColorBottomLeft(color);
    setColorBottomRight(color);
    
    setColorTopLeft(color);
    setColorTopRight(color);
}

void Rectangle::setColorBottomLeft(Color c) {
    colorBottomLeft.setBlue(c.getBlue());
    colorBottomLeft.setGreen(c.getGreen());
    colorBottomLeft.setRed(c.getRed());
}

void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight.setBlue(color.getBlue());
    colorBottomRight.setGreen(color.getGreen());
    colorBottomRight.setRed(color.getRed());
}

void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft.setBlue(color.getBlue());
    colorTopLeft.setGreen(color.getGreen());
    colorTopLeft.setRed(color.getRed());
}

void Rectangle::setColorTopRight(Color color) {
    colorTopRight.setBlue(color.getBlue());
    colorTopRight.setGreen(color.getGreen());
    colorTopRight.setRed(color.getRed());
}

// Returns four colors of rectangles

Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

void Rectangle::read(istream& ins) {
    Point newStart;
    Point newEnd;
    Color cTopLeft;
    Color cTopRight;
    Color cBottomRight;
    Color cBottomLeft;
    
     // Reads rectangle  color in proper order
    ins >> newStart >> newEnd >> cTopLeft >> cTopRight;
    
    // Sets rectangle start and end point, color
    setStart(newStart);
    setEnd(newEnd);
    
    // If ins in fail state, clears, sets color
    if (ins.fail()) {
        ins.clear();
        setColor(cTopLeft);
    } else {
    // Otherwise takes in rest colors and sets four colors
        ins >> cBottomRight >> cBottomLeft;
        setColorTopLeft(cTopLeft);
        setColorTopRight(cTopRight);
        setColorBottomLeft(cBottomLeft);
        setColorBottomRight(cBottomRight);
    }
}

// Writes rectangle in proper order
void Rectangle::write(ostream& outs) {
    outs << getStart() << " " << getEnd() << "  "
    << getColorTopLeft() << "  "
    << getColorTopRight() << "  "
    << getColorBottomRight() << "  "
    << getColorBottomLeft();
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());
    
    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);
    
    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
