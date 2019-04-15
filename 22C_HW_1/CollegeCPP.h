//
//  College.cpp
//  22C_HW_1
//
//  Created by home on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//
#include <iostream>         // For cout  and NULL
#include <fstream>
#include <iomanip>
#include <string>
#include "College.h"
using namespace std;

// Default Constructor
College::College()
{
    rank = -1;
    name = "";
    year = -1;
    website = "";
    transfer = 0.0;
    retention = 0.0;
    cost = -1;
    noStu = -1;
}

// Overloaded Constructor
College::College(int r, string n, int y, string w, double t, double re,int co, int no)
{
    rank = r;
    name = n;
    year = y;
    website = w;
    transfer = t;
    retention = re;
    cost = co;
    noStu = no;
}

// Display rank, name, cost, and number of students

void College::display()
{
    cout << setw(4) << rank << " "
    << left << setw(30) << name
    << right << setw(7) << cost
    << right << setw(11) << noStu << endl;
}

// Display all data

void College::displayAll()
{
    cout
    << "                        Rank: " << rank<< endl
    << "                        Name: " << name << endl
    << "                     Founded: " << year << endl
    << "                     Website: " << website << endl
    << "Graduation and Transfer Rate: " << transfer << "%" << endl
    << "   First Year Retention Rate: " << retention <<"%" << endl
    << "          Cost of Attendance: $" << cost << endl
    << "          Number of Students: " << noStu << endl;
}

int main(){
    return 0;
}

