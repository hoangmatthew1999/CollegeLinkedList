//
//  CollegeList.cpp
//  22C_HW_1
//
//  Created by home on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//
#include <iostream>         // For cout  and NULL
#include <fstream>
#include <iomanip>
#include "CollegeList.h"
using namespace std;


//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
CollegeList::CollegeList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
    count = 0;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void CollegeList::insertNode(College dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode -> col = dataIn;
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    // Find location: skip all nodes whose name is less than dataIn's name.
    while(pCur != NULL && pCur -> col.getName() < dataIn.getName())
    {
        pPre = pCur;
        pCur = pCur -> next;
    }
    
    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode -> next = pCur;
    
    //Update the counter
    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with num as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool CollegeList::deleteNode(string target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;        // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    
    // Find node containing the target: Skip all nodes whose name is less than the target
    while (pCur != NULL && pCur->col.getName() < target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delete the node
    if (pCur != NULL && pCur -> col.getName() == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        //Update counter
        count--;
    }
    return deleted;
    
}

//**************************************************
// Search function shows if the college name is match with what the user enters
//**************************************************
bool CollegeList::searchList(string target, College &dataOut)
{
    ListNode *pCur;
    pCur = head -> next;
    bool found = false;
    
    while(pCur != NULL && pCur->col.getName() < target)
        pCur = pCur -> next;
    
    if(pCur != NULL && pCur->col.getName() == target){
        found = true;
        dataOut = pCur->col;
    }
    return found;
    
}

//**************************************************
// Display function shows every college name with their rank and cost.
//**************************************************

void CollegeList::displayList() const
{
    ListNode *pCur;  // To move through the list
    
    // print header
    cout << endl
    << "==== ============================= ========= ==========" << endl
    << "Rank          Name                    Cost      NoStu  " << endl
    << "==== ============================= ========= ==========" << endl;
    
    //pCur = head->next;          // Position pCur: skip the head of the list.
    while(pCur != NULL)
    {
        pCur -> col.display();  //Display the value in the node.
        //pCur = pCur -> next;    //Move to the next node.
        
    }
    cout<< "==== ============================= ========= ==========" << endl;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
CollegeList::~CollegeList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    pCur = head->next;
    
    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur -> next;
        
        // Delete the current node.
        cout << "DEBUG - Destructor: Now deleting " << pCur->col.getName() << endl;
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node rank " << head -> col.getRank() << endl;
    delete head; // delete the sentinel node
}
/*
int main(){
    return 0;
}
*/

