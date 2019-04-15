//
//  CollegeList.h
//  22C_HW_1
//
//  Created by home on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//

#ifndef COLLEGE_LIST_H
#define COLLEGE_LIST_H
#include "College.h"
#include <string>

using std::string;
class CollegeList
{
private:
    struct ListNode{
        College col;
        ListNode *next;
    };
    ListNode *head;
    int count;
    
public:
    //Constructor
    CollegeList();
    
    // Linked list operations
    void insertNode(College);
    bool deleteNode(string);
    bool searchList(string, College &);
    void displayList() const;
    int getCount() {return count;}
    
    //Destructor
    ~CollegeList();
};

#endif /* CollegeList_h */
