/**
 * pics.cpp
 *
 * EECS 183, Winter 2018
 * Project 4: CoolPics
 *
 * Abpreet Kaur
 * abpreetk
 *
 * After classes have been implemented, this program
 * takes text as input and allows user to create bmp images.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded filename]"
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

int main()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
}

// Reads and writes image to file
void writeFile(const Graphics& drawer) {
    string filename;
    cin >> filename;
    
    filename += ".bmp";
    drawer.writeFile(filename);
    cout << "[Wrote " << filename << "]";
    
}

// Opens file, reads file, draws shape, close file and print
void loadFile(Graphics& drawer) {
    drawer.clear();
    ifstream ins;
    
    char shape;
    
    string lineErr;
    
    // Variables for shapes
    Circle circle;
    Line line;
    Rectangle rect;
    Triangle tri;
    
    string filename;
    filename = openFile(ins);
    
    // Reads in shape and reads and draws
    while (ins >> shape) {
        switch (shape) {
            case 'C':
                circle.read(ins);
                circle.draw(drawer);
                break;
                
            case 'L':
                line.read(ins);
                line.draw(drawer);
                break;
                
            case 'R':
                rect.read(ins);
                rect.draw(drawer);
                break;
                
            case 'T':
                tri.read(ins);
                tri.draw(drawer);
                break;
                
            default:
                getline(ins, lineErr);
                drawer.clear();
                ins.clear();
                cout << "Error in input file: " << shape << lineErr << endl;
                break;
        }
    }
    // Close file and load with filename
    ins.close();
    cout << "[Loaded " << filename << "]" ;
}

// Returns string with lowercase alphabetical characters
string tolower(string str) {
    for (int i = 0; i < (int)str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
    << "--------            ------------" << endl
    << "load filename       Loads data from a txt file" << endl
    << "write filename      Creates a bmp image from data" << endl
    << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
    << "               Welcome to CoolPics" << endl
    << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
    << "            Thanks for using CoolPics!" << endl
    << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;
    
    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }
    
    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);
    
    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
        << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }
    
    return fileName;
}
