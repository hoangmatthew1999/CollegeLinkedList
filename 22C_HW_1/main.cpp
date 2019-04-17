//
//  main.cpp
//  22C_HW_1
//
//  Created by Matthew Hoang on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//Complied in XCode 10.2

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
    string collegeName;
    string rank;//is a string to allow for the isalpha function to test if there are letters in the rank which should be a number
    int found_date;
    double transfer_rate;
    int cost_of_attendence;
    int number_of_students;
    /*
    cout<<"What is the college's name"<<endl;
    cin>>collegeName;
    
    cout<<"What is the college's rank"<<endl;
    cin>>rank;
    for(int i = 0; i < rank.length();i++){
        if(isalpha(rank[i]) != 0){
            cout<<"There is a letter in the rank variable"<<endl;
            cin>>rank;
            i = 0;//resets the loop to check again if there is a letter in the string
        }
    }
    
    cout<<"when was the school found"<<endl;
    cin>>found_date;
    while(found_date > 2019){
        cout<<"The school can not be found in the future"<<endl;
        cin>>found_date;
    }
    
    string website;
    cout<<"What is the website of the school"<<endl;
    cin>>website;
    
    cout<<"what is the school's transfer_rate"<<endl;
    cin>>transfer_rate;
    while(transfer_rate < 0 | transfer_rate > 100){//a percentage can not be less than 0 or greater than 100
        cout<<"the graduation and transfer rate can not be less than 0 or greater than 100"<<endl;
        cin>>transfer_rate;
    }
    
    double retention_rate;
    cout<<"what is the school's retention rate"<<endl;
    cin>>retention_rate;
    while(retention_rate < 0 | retention_rate > 100){//a percentage can not be less than 0 or greater than 100
        cout<<"the graduation and transfer rate can not be less than 0 or greater than 100"<<endl;
        cin>>retention_rate;
    }
    
    cout<<"How much does it cost to go to the school"<<endl;
    cin>>cost_of_attendence;
    while(cost_of_attendence < 0){
        cout<<"Cost of attendence can not be negative"<<endl;
        cin>>cost_of_attendence;
    }
    
    cout<<"What is the school's population"<<endl;
    cin>>number_of_students;
    while(number_of_students < 0){
        cout<<"the number of students must be positive"<<endl;
        cin>>number_of_students;
    }
     */
    College cin_operator_overload;//starts with the default constructor and adds the elements in the cin
    cin>>cin_operator_overload;
    cout<<cin_operator_overload;//showing the use of overloading << operator
    list.insertNode(cin_operator_overload);

    /*
    int rank_;// the constructor will not accept the rank variable because it is not a int so it needs to be changed into an int
    rank_ = stoi(rank);//stoi changes the value of something to an int
    
    College add(rank_, collegeName, found_date, website, transfer_rate, retention_rate, cost_of_attendence, number_of_students);
    list.insertNode(add);
    cout<<add;//showing the use of overloading << operator
     */
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


