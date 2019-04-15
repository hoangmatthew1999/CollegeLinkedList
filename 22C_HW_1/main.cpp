//
//  main.cpp
//  22C_HW_1
//
//  Created by home on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "CollegeList.h"

using namespace std;

//void printWelcome();
//void buildList(string filename, CollegeList &list);
//void deleteManager(CollegeList &list);
//void searchManager(CollegeList &list);
//void printDone(void);

int main()
{
    //const char inputFileName[] = "colleges.txt";
    //CollegeList list;
    //printWelcome();
    //buildList(inputFileName, list);
    //list.displayList();
    //cout <<  "\t\tThere are " << list.getCount() << " college(s) in your list.\n\n";
    //searchManager(list);
    //deleteManager(list);
    //cout <<  "\t\tThere are " << list.getCount() << " college(s) in your list.\n\n";
    //printDone();
    
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
/*
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
*/
/**********************************************************************
 Farewell information
 **********************************************************************/
void printDone(void)
{
    cout << "\n\n\t\t *~~*~~* THE END *~~*~~*\n"
    << "\t     Thank you for using my program! \n\n";
}

/***************************************************************
 Save the OUTPUT below
 
 
 
 *~~*~~* WELCOME *~~*~~*
 
 to the College Linked List Project!
 
 
 ==== ============================= ========= ==========
 Rank          Name                    Cost      NoStu
 ==== ============================= ========= ==========
 12 College of the Siskiyous        21936       2473
 10 Cuesta College                  19135       9571
 1 De Anza College                 19302      24187
 4 Diablo Valley College           20579      22000
 6 Foothill College                19302      18362
 9 Irvine Valley College           20577      14384
 7 Napa Valley College             18920       8996
 8 Ohlone College                  15878      18000
 15 Palo Verde College              18266       3898
 5 Pasadena City College           17666      26057
 3 Santa Barbara City College      18524      30687
 ==== ============================= ========= ==========
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
 ABC College
 
 College ABC College was not found in this list.
 Enter a college's name for search (or Q for stop searching):
 Q
 
 
 ___________________END SEARCH SECTION _____
 
 Delete
 =======
 
 Enter a college's name for delete (or Q for stop searching): Q
 ___________________END DELETE SECTION_____
 There are 11 college(s) in your list.
 
 
 
 *~~*~~* THE END *~~*~~*
 Thank you for using my program!
 
 DEBUG - Destructor: Now deleting College of the Siskiyous
 DEBUG - Destructor: Now deleting Cuesta College
 DEBUG - Destructor: Now deleting De Anza College
 DEBUG - Destructor: Now deleting Diablo Valley College
 DEBUG - Destructor: Now deleting Foothill College
 DEBUG - Destructor: Now deleting Irvine Valley College
 DEBUG - Destructor: Now deleting Napa Valley College
 DEBUG - Destructor: Now deleting Ohlone College
 DEBUG - Destructor: Now deleting Palo Verde College
 DEBUG - Destructor: Now deleting Pasadena City College
 DEBUG - Destructor: Now deleting Santa Barbara City College
 DEBUG - Destructor: Now deleting the sentinel node rank -1
 
 */


