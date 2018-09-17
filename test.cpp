/**
 * test.cpp
 *
 * EECS 183, Winter 2018
 * Project 4: CoolPics
 *
 * Abpreet Kaur
 * abpreetk
 *
 * Created test cases and edge cases to test CoolPics Classes.
 */

#include <iostream>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

#include "Point.h"
#include "utility.h"
#include "Color.h"
#include "bmp.h"
#include "Shape.h"

int main () {
    
    // test of default constructor point
    Point p1;
    // test of the other constructor
    Point p2(3, 9);
    Point p3(-2,-2);
    Point p4(4,5);
    
    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);
    
    // test of member functions getX() and getY()
    cout << "( " << p1.getX()
    << ", " << p1.getY()
    << " )" << endl;
    
    // you can also do cin >> p1;
    p1.read(cin);
    cout << p1 << endl;
    cout << p2 << endl;
    
    //test of constructor color
    
    //test case 1
    Color col1;
    Color col2(100,155,50);
    cout << col2.getBlue();
    cout << col2.getGreen();
    cout << col2.getRed();
    col2.setBlue(100);
    
    //test case 2
    Color col3(0,0,0);
    cout << col3.getBlue();
    cout << col3.getGreen();
    cout << col3.getRed();
    col3.setBlue(0);
    
    //test case 3
    Color col4(255,255,255);
    cout << col4.getBlue();
    cout << col4.getGreen();
    cout << col4.getRed();
    col4.setBlue(255);
    
    //test case 4
    Color col5(0,255,0);
    cout << col5.getBlue();
    cout << col5.getGreen();
    cout << col5.getRed();
    col5.setBlue(0);
    
    //test case 5
    Color col6(0,-255,0);
    cout << col6.getBlue();
    cout << col6.getGreen();
    cout << col6.getRed();
    col6.setBlue(-255);
    
    //test case 6
    Color col7(-255,-255,-255);
    cout << col7.getBlue();
    cout << col7.getGreen();
    cout << col7.getRed();
    col7.setBlue(-255);
    
    //test case 7
    Color col8(-255,-255,-255);
    cout << col8.getBlue();
    cout << col8.getGreen();
    cout << col8.getRed();
    col8.setBlue(0);
    
    
    //test of constructor circle
    
    Circle c1;
    c1.setCenter(Point(-10, -10));
    c1.setRadius(-1000);

    Circle c2(Point(-99999, 99999), -5, col2);
    c2.setCenter(Point(0, 99999));
    c2.setRadius(-5);
    
    Circle c3(Point(0, 0), 0, col2);
    c3.setCenter(Point(0, 0));
    c3.setRadius(0);
    
    Circle c4(Point(-99999, 99999), 1000, col3);
    c4.setCenter(Point(99999, 0));
    c4.setRadius(1000);
    
    Circle c5(Point(-99999, 0), 5, col4);
    c5.setCenter(Point(0, 99999));
    c5.setRadius(5);
    
    Circle c6(Point(-99999, 99999),-1000, col5);
    c6.setCenter(Point(0, 99999));
    c6.setRadius(-1000);
    
    Circle c7(Point(-99999, 99999), 500, col6);
    c7.setCenter(Point(0, 99999));
    c7.setRadius(500);
    
    Circle c8(Point(-99999, 99999), 1000, col8);
    c8.setCenter(Point(0, 99999));
    c8.setRadius(1000);
    
    Circle c9(Point(-99999, -99999), -10, Color(-10, -10, -300));
    c9.setCenter(Point(-10, -10));
    c9.setRadius(-1000);
    cout<<c9.getRadius();
    cout<<c9.getCenter();
    
    Circle c10(Point(99999, 99999), -10, Color(-10, -10, -300));
    c10.setCenter(Point(100000, 1000000));
    c10.setRadius(1000000);
    cout<<c10.getRadius();
    cout<<c10.getCenter();
    
    Point pt11(202, -10);
    Point pt22(0, 105);
    Point pt55(100, 2);
    Point pt66(-10, 200);
    Point pt77(100, 0);
    Point pt88(2, 102);
    
    Color col22(-10, 260, 180);
    Color col33(0, 255, -1);
    
    Circle c11;
    c11.setCenter(pt22);
    c11.setRadius(-10);
    c11.setColor(col33);
    
    Circle c12;
    c12.setCenter(pt22);
    c12.setRadius(-3);
    c12.setColor(col33);
    
    cout << c11.getColor() << endl;
    cout << c11.getCenter() << " " << c11.getRadius() << " ";
    cout << c12.getCenter() << " " << c12.getRadius() << " ";
    cout << c12.getColor() << endl;
    
    Circle c13(pt55, -3, col22);
    cout << c13 << endl;
    
    
    //test of constructor line
    
    Line(Point(-1,6),Point(1,1), Color(0, 5, 255)).getStart();
    Line(Point(-1,6),Point(1,1), Color(0, 0, 258)).getColor();
    Line(Point(-1,6),Point(1,1), Color(0, -100, 258)).getColor();
    Line(Point(-1,6),Point(1,1), Color(-100, -100, -100)).getColor();
    
    Line(Point(0,0),Point(4,4),Color(255,0,255)).setEnd(Point(-1,5));
    Line(Point(0,0),Point(4,4),Color(255,0,255)).setEnd(Point(1,5));
    Line(Point(0,0),Point(4,4),Color(255,0,255)).setEnd(Point(0,0));
    
    Line l1(p1, p4, col1);
    cout << l1;
    cout << l1.getStart();
    l1.setEnd(p4);
    cout << l1.getColor();
    
    Line l2(p1, p1, col1);
    cout << l2;
    cout << l2.getStart();
    l2.setEnd(p2);
    cout << l2.getColor();
    
    Line l3(p1, p2, col1);
    cout << l3;
    cout << l3.getStart();
    l3.setEnd(p2);
    cout << l3.getColor();
    
    Line l4(p1, p3, col1);
    cout << l4;
    cout << l4.getStart();
    l4.setEnd(p3);
    cout << l4.getColor();
    
    Line l5(p2, p3, col1);
    cout << l5;
    cout << l5.getStart();
    l5.setEnd(p3);
    cout << l5.getColor();
    
    Line l6(Point(-7,-5),Point(-7,-5), Color(-1, 257, 6));
    l6.setEnd(Point(-1,-1));
    cout<<l6.getEnd();
    l6.setEnd(Point(-1000000,0));
    cout<<l6.getEnd();
    l6.setEnd(Point(0,-100000000));
    cout<<l6.getEnd();
    l6.setEnd(Point(99999999,99999999));
    cout<<l6.getEnd();
    cout<<l6;
    
    Line l7;
    Point pt111(102, -10);
    Point pt222(0, 101);
    Color col44(6, 29, 89);
    
    l7.setStart(pt222);
    l7.setEnd(pt111);
    l7.setColor(col44);
    
    cout << l7.getStart() << " " << l7.getEnd() << " ";
    cout << l7.getColor() << endl;
    
    Line l8(pt111, pt222, col44);
    cout << l8 << endl;
    
    //test of constructor rectangle
    Rectangle r1(p1, p2, col1);
    cout << r1.getEnd();
    r1.setStart(p1);
    r1.setColor(col1);
    cout<< r1;
    
    Rectangle r2(p1, p4, col1, col1, col1, col1);
    cout << r2.getEnd();
    r2.setStart(p1);
    r2.setColor(col1);
    cout << r2;
    
    Rectangle r3(p2, p3, col1, col1, col1, col1);
    cout << r3.getEnd();
    r3.setStart(p2);
    r3.setColor(col1);
    cout << r3;
    
    Rectangle r4(p1, p3, col1, col1, col1, col1);
    cout << r4.getEnd();
    r4.setStart(p1);
    r4.setColor(col1);
    cout << r4;
    
    
    Rectangle r5(Point(99999999,99999999), Point(-1,-1), Color(-10,-10,-10), Color(300,0,-1), Color(-1,0,400), Color(400,400,400));
    cout << r5.getEnd();
    r5.setStart(p1);
    r5.setColor(Color(99999999,99999999,-99999999));
    
    cout << r5;
    cout << r5.getColorBottomLeft();
    cout << r5.getColorBottomRight();
    cout << r5.getColorTopLeft();
    cout << r5.getColorTopRight();
    
    Color cl1(0, 0, 0);
    Color cl2(-12, 290, 170);
    Color cl3(0, 255, -10);
    Color cl4(5, 254, 265);
    
    Point p41;
    Point p44;
    Point p42(90, -5);
    Point p43(0, 32);
    Point p45(98, 1);
    Point p46(-5, 200);
    Point p47(109, 0);
    Point p48(56, 108);
    
    Rectangle r6;
    r6.setStart(p42);
    r6.setEnd(p43);
    r6.setColor(cl2);
    cout << r6.getStart() << " " << r6.getEnd() << " ";
    cout << r6.getColorBottomRight() << endl;
    
    Rectangle r7;
    r7.setStart(p44);
    r7.setEnd(p45);
    r7.setColorTopLeft(cl2);
    r7.setColorTopRight(cl3);
    r7.setColorBottomRight(cl4);
    r7.setColorBottomLeft(cl3);
    
    cout << r7.getStart() << " ";
    cout << r7.getEnd() << " ";
    cout << r7.getColorTopLeft() << " " << r7.getColorTopRight() << " ";
    cout << r7.getColorBottomRight() << " " << r7.getColorBottomLeft();
    cout << endl;
    
    Rectangle r8(Point(12, 32), Point(43, 90), Color(70, 130, 195));
    Rectangle r9(Point(10, 65), Point(-3, 15), Color(14, 110, 33), Color(65, 172, 92), Color(90, 68, 16), Color(90, 35, 295));
    cout << r8 << endl << r9 << endl;
    
    Rectangle r10(p44, p43, cl2);
    Rectangle r11(p45, p46, cl1, cl2, cl3, cl4);

    
    //test of constructor triangle
    
    Triangle t;
    cout << t;
    
    Triangle t1(p1, p2, p3, col1);
    cout << t1;
    cout << t1.getVertexOne();
    cout << t1.getVertexThreeColor();
    t1.setVertexThree(p1);
    
    Triangle t2(p1, col1, p2, col1, p3, col1);
    cout << t2;
    cout << t2.getVertexOne();
    cout << t2.getVertexThreeColor();
    t2.setVertexThree(p1);
    
    Triangle t3(Point(-10, -10), Point(10000,100000), Point(0, 1000000), Color(-10,-10,-10));
    cout << t3;
    cout << t3.getVertexOne();
    cout << t3.getVertexThreeColor();
    t3.setVertexThree(Point(-10,-10));
    cout<< t3.getVertexThree();
    
    Triangle t4(Point(-10, -10), Point(10000,99999999), Point(-99999999, 1000000), Color(-10,-10,-10));
    cout << t4;
    cout << t4.getVertexOne();
    cout << t4.getVertexThreeColor();
    t4.setVertexThree(Point(1000000,100000000));
    cout<<t4.getVertexThree();
    
    Triangle t5(Point(-99999999, -10), Point(99999999,100000), Point(0, 1000000), Color(-99999999,99999999,-10));
    cout << t5;
    cout << t5.getVertexOne();
    t5.setVertexThreeColor(Color(99999999, -99999999, 99999999));
    cout<<t5;
    cout << t5.getVertexThreeColor();
    t5.setVertexThree(Point(-10,-10));
    cout<< t5.getVertexThree();
    
    Point pt31(189, -1);
    Point pt32(0, 199);
    Point p33;
    Point p34;
    Point p35;
    
    Color clr2(-19, 390, 150);
    Color clr3(0, 255, -9);
    Color clr4(1, 254, 278);
    
    Triangle t6(p33, pt32, p34, clr4);
    Triangle t7(p35, clr2, p33, clr3, p34, clr4);
    
    cout << t6 << endl << t7 << endl;
    
    Triangle t8(Point(15, 90), Point(10, 40), Point(55, 85), Color(15, 45, 65));
    Triangle t9(Point(35, 80), Color(6, 0, 0), Point(15, 200), Color(255, 60, 198), Point(50, 15), Color(70, 19, 119));
    
    t8.setVertexOne(pt31); t8.setVertexOneColor(clr2);
    t8.setVertexTwo(pt32); t8.setVertexTwoColor(clr3);
    t8.setVertexThree(p33); t8.setVertexThreeColor(clr4);
    
    cout << t8.getVertexOne() << " " << t8.getVertexOneColor() << " ";
    cout << t8.getVertexTwo() << " " << t8.getVertexTwoColor() << " ";
    cout << t8.getVertexThree() << " " << t8.getVertexThreeColor() << endl;
    
    return 0;
    
}
