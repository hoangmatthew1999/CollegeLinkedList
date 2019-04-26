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
    /****************************
     this is the cout operator overloading
     *****************************/
    strm<<"Rank: "<<object.rank<<" "<<endl;
    strm<<"Name: "<<object.name<<" "<<endl;
    strm<<"Year School Founded: "<<object.year<<" "<<endl;
    strm<<"Website URL"<<object.website<<" "<<endl;
    strm<<"Transfer Rate"<<object.transfer<<" "<<endl;
    strm<<"Retention Rate"<<object.retention<<" "<<endl;
    strm<<"Cost to attend"<<object.cost<<" "<<endl;
    strm<<"number of students"<<object.noStu<<" "<<endl;
    return strm;
}
istream &operator >> (istream &strm,College &object){
    /****************************************
     This is the cin operator overloader function
     ***************************************/
    cout<<"What is the school's name"<<endl;
    strm>>object.name;
    
    cout<<"What is the school's rank"<<endl;
    strm>>object.rank;
    
    while(!cin){//for non string input, used to make sure does not crash
        cout<<"there is a character in your input. Ranks can only be numbers "<<endl;
        cin.clear();//clears the cin input; Without it, the cout statement will go forever
        cin.ignore(100,'\n');//used to allow for spaces
        cin>>object.rank;
    }
    
    cout<<"When was the school found"<<endl;
    strm>>object.year;
    while(object.year > 2020){
        cout<<"The school can not be created in the future"<<endl;
        cin>>object.year;
    }
    while(!cin){
        cout<<"there is a character in your input. Years can only be numbers "<<endl;
        cin.clear();//clears the cin input; Without it, the cout statement will go forever
        cin.ignore(100,'\n');//used to allow for spaces
        cin>>object.year;
    }
    
    cout<<"What is the url of the college";
    strm>>object.website;
    
    cout<<"What is the transfer rate of the college"<<endl;
    strm>>object.transfer;
    while(object.transfer > 100 | object.transfer < 0){
        cout<<"A transfer rate must be a positive number and it can not be larger than 100";
        cin>>object.transfer;
    }
    while(!cin){
        cout<<"there is a character in your input. Percents can only be numbers "<<endl;
        cin.clear();//clears the cin input; Without it, the cout statement will go forever
        cin.ignore(100,'\n');//used to allow for spaces
        cin>>object.transfer;
    }
    
    cout<<"How many students does the school have"<<endl;
    strm>>object.noStu;
    
    while(object.noStu < 0){
        cout<<"The number of students can not be a negative value"<<endl;
        cin>>object.noStu;
    }
    while(!cin){
        cout<<"there is a character in your input. Populations can only be numbers "<<endl;
        cin.clear();//clears the cin input; Without it, the cout statement will go forever
        cin.ignore(100,'\n');//used to allow for spaces
        cin>>object.noStu;
    }
    
    cout<<"What is the cost to attend this school"<<endl;
    strm>>object.cost;//technically a cost can be a negative number if financial aid and scholarships outweight the cost to attend as school
    while(!cin){
        cout<<"there is a character in your input. Costs can only be numbers "<<endl;
        cin.clear();//clears the cin input; Without it, the cout statement will go forever
        cin.ignore(100,'\n');//used to allow for spaces
        cin>>object.cost;
    }
    
    cout<<"What is the first year retention rate of the school"<<endl;
    strm>>object.retention;//also retention rate can be negative; This would mean the school losing students each year
    while(!cin){
        cout<<"there is a character in your input. Percents can only be numbers "<<endl;
        cin.clear();//clears the cin input; Without it, the cout statement will go forever
        cin.ignore(100,'\n');//used to allow for spaces
        cin>>object.retention;
    }
    
    return strm;
}


