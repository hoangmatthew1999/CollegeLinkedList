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
ostream &operator << (ostream &strm,const College &object){
    strm<<"Rank: "<<object.rank<<" "
        <<"Name: "<<object.name<<" "
        <<" Year School Founded: "<<object.year<<" "
        <<"Website URL"<<object.website<<" "
        <<"Transfer Rate"<<object.transfer<<" "
        <<"Retention Rate"<<object.retention<<" "
        <<"Cost to attend"<<object.cost<<" "
        <<"noStu"<<object.noStu<<" ";
    return strm;
}
istream &operator >> (istream &strm,College &object){
    cout<<"What is the school's name"<<endl;
    strm>>object.name;
    
    cout<<"What is the school's rank"<<endl;
    strm>>object.rank;
    while(!cin){
        cout<<"ther is a character in your input. Ranks can only be numbers "<<endl;
        cin>>object.rank;
    }
    
    cout<<"When was the school found"<<endl;
    strm>>object.year;
    while(object.year > 2020){
        cout<<"The school can not be created in the future"<<endl;
        cin>>object.year;
    }
    
    cout<<"What is the url of the college";
    strm>>object.website;
    
    cout<<"What is the transfer rate of the colelge"<<endl;
    strm>>object.transfer;
    while(object.transfer > 100 | object.transfer < 0){
        cout<<"A transfer rate must be a t"
    }
    
    cout<<"How many students does the school have"<<endl;
    strm>>object.noStu;
    
    cout<<"What is the cost to attend this school"<<endl;
    strm>>object.cost;
    
    cout<<"What is the first year retention rate of the school"<<endl;
    strm>>object.retention;
    
    return strm;
}
/*

 int year;
 int cost;
 int noStu;
 double transfer;
 double retention;
 string name;
 string website;
 */
