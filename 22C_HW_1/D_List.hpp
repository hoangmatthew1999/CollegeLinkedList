//
//  D_List.hpp
//  22C_HW_1
//
//  Created by home on 4/24/19.
//  Copyright © 2019 home. All rights reserved.
//

#ifndef D_List_hpp
#define D_List_hpp
#include "College.h"
#include "CollegeList.h"
#include <stdio.h>
#include <string>
class DList: public CollegeList{
public:
    struct double_link{
        College col;
        double_link *next;
        double_link *previous;
};
    //int count;
    DList();
    void insertNode(College & dataIn);
    bool deleteNode(string);
    bool searchList(string,College & );
    void traverseForward();
    void traverseBackward();
    //void getCount();
    bool isEmpty();
    void displayList() const;
    ~DList();
    
    

};
#endif /* D_List_hpp */
