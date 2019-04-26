//
//  main.cpp
//  22C_HW_1
//
//  Created by Matthew Hoang on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//Complied in XCode 10.2
/*
 CIS 22C: Homework 0 - Extra Credit
 
 This program will:
 Build and procees a sorted linked list of College objects.
 The list is sorted in ascending order by college name
 Assume that the college name is unique.
 - Print the list as a table with the following columns: rank, name, and cost.
 - Print the list as a table with the following columns: year, name, and noStu.
 - Search: prompt the user to enter a college’s name, search for that name: if found, display its’ data (all members), otherwise display some message, such as ... Not found.
 - Show the number of elements in the list before delete.
 - Delete: prompt the user to enter the college’s name to be
 deleted – put this in a loop, to delete more items from the list; to stop the loop enter Q.
 - Show the number of elements in the list after delete.
 - Destroy list //no memory leak.
 -has a function to add a College object into the linked list
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "CollegeList.h"
#include "College.h"

using namespace std;

void printWelcome();
void buildList(string filename, CollegeList &list);
void deleteManager(CollegeList &list);
void searchManager(CollegeList &list);
void printDone(void);
void insertManager(CollegeList &list);

int main()
{
    const char inputFileName[] = "colleges.txt";
    CollegeList list;
    printWelcome();
    buildList(inputFileName, list);
    //list.displayList(); this part of the program broke
    cout <<  "\t\tThere are " << list.getCount() << " college(s) in your list.\n\n";
    searchManager(list);
    deleteManager(list);
    cout <<  "\t\tThere are " << list.getCount() << " college(s) in your list.\n\n";
    printDone();
    insertManager(list);
    return 0;
}
/*********************************************************************
 Welcome function
 *********************************************************************/
void printWelcome()
{
    cout << "\n\n\t\t *~~*~~* WELCOME *~~*~~*\n\n";
    cout << "\tto the College Linked List Project!\n\n";
}

/*****************************************************************************
 This function reads data about colleges from a given file and inserts them
 into a sorted linked list.
 *****************************************************************************/

void buildList(string filename, CollegeList &list)
{
    ifstream infile;
    int rank;
    string name;
    int year;
    string website;
    double transfer;
    double retention;
    int cost;
    int noStu;
    
    infile.open(filename);
    if(!infile){
        cout << "Error happened to open the input file!"<<endl;
        //exit(EXIT_FAILURE);
    }
    while(infile >> rank){
        infile.ignore();
        getline(infile, name, ';');
        
        infile >> year >> website >> transfer >> retention >> cost >> noStu;
        //Use constructor to pass the values to the college object.
        College coll(rank, name, year, website, transfer, retention, cost, noStu);
        list.insertNode(coll);
    }
    infile.close();
}

/*********************************************************************
 Delete manager: delete items from the list until the user enters QUIT
 Input Parameter: list
 **********************************************************************/

void deleteManager(CollegeList &list)
{
    string targetName = "";
    int n = 0;
    
    cout << "\n Delete\n";
    cout << "=======\n";
    
    while(targetName != "Q")
    {
        cout << endl << "Enter a college's name for delete (or Q for stop searching): ";
        getline(cin, targetName);
        
        if(targetName != "Q")
        {
            if(list.deleteNode(targetName))
                cout << "Deleted\n";
            else
                cout << "College " << targetName << " was not found in this list." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/**********************************************************************
 Search manager: search the list until the user enters Q
 Input Parameter: list
 **********************************************************************/

void searchManager(CollegeList &list)
{
    College col;
    string targetName = "";
    int n = 0;
    cout << "\n Search\n";
    cout <<   "=======\n";
    
    while(targetName != "Q")
    {
        cout << "\nEnter a college's name for search (or Q for stop searching): \n";
        getline(cin, targetName);
        cout << endl;
        if(targetName != "Q"){
            if(!list.searchList(targetName, col))
                cout << "College " << targetName << " was not found in this list.";
            else
                col.displayAll();
            
        }
    }
    cout << endl;
    cout << "___________________END SEARCH SECTION _____\n";
}

/**********************************************************************
 Farewell information
 **********************************************************************/
void printDone(void)
{
    cout << "\n\n\t\t *~~*~~* THE END *~~*~~*\n"
    << "\t     Thank you for using my program! \n\n";
}
void insertManager(CollegeList &list){
    /*********************
     insertManager method that adds
     **********************/
    College cin_operator_overload;//starts with the default constructor and adds the elements in the cin
    cin>>cin_operator_overload;
    cout<<cin_operator_overload;//showing the use of overloading << operator
    list.insertNode(cin_operator_overload);

    
}

/***************************************************************
 Save the OUTPUT below
 

 
 *~~*~~* WELCOME *~~*~~*
 
 to the College Linked List Project!
 
 There are 11 college(s) in your list.
 
 
 Search
 =======
 
 Enter a college's name for search (or Q for stop searching):
 De Anza College
 
 Rank: 1
 Name: De Anza College
 Founded: 1967
 Website: https://www.deanza.edu
 Graduation and Transfer Rate: 72.7%
 First Year Retention Rate: 90.7%
 Cost of Attendance: $19302
 Number of Students: 24187
 
 Enter a college's name for search (or Q for stop searching):
 Foothill College
 
 Rank: 6
 Name: Foothill College
 Founded: 1957
 Website: http://www.foothill.edu
 Graduation and Transfer Rate: 68.8%
 First Year Retention Rate: 87.5%
 Cost of Attendance: $19302
 Number of Students: 18362
 
 Enter a college's name for search (or Q for stop searching):
 Q
 
 
 ___________________END SEARCH SECTION _____
 
 Delete
 =======
 
 Enter a college's name for delete (or Q for stop searching): De Anza College
 Deleted
 
 Enter a college's name for delete (or Q for stop searching): Q
 ___________________END DELETE SECTION_____
 There are 10 college(s) in your list.
 
 
 
 *~~*~~* THE END *~~*~~*
 Thank you for using my program!
 
 What is the college's name
 qwe
 What is the college's rank
 123
 when was the school found
 123
 What is the website of the school
 qew
 what is the school's transfer_rate
 12
 what is the school's retention rate
 12
 How much does it cost to go to the school
 12
 What is the school's population
 12
 Rank: 123 Name: qwe  Year School Founded: 123 Website URLqew Transfer Rate12 Retention Rate12 Cost to attend12 noStu12 DEBUG - Destructor: Now deleting College of the Siskiyous
 DEBUG - Destructor: Now deleting Cuesta College
 DEBUG - Destructor: Now deleting Diablo Valley College
 
 */


