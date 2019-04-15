//
//  College.h
//  22C_HW_1
//
//  Created by home on 4/11/19.
//  Copyright © 2019 home. All rights reserved.
//



#ifndef COLLEGE_H
#define COLLEGE_H
#include <string>
using std::string;
using namespace std;

class College
{
private:
    int rank;
    int year;
    int cost;
    int noStu;
    double transfer;
    double retention;
    string name;
    string website;
public:
    // Constructors
    College();
    College(int r, string n, int y, string w, double t, double re,int co, int no);
    
    // Setters
    void setRank(int r) { rank = r; }
    void setYear(int y) { year = y; }
    void setCost(int c) {cost = c; }
    void setNoStu(int no) {noStu = no; }
    void setTran(double tran) { transfer = tran; }
    void setReten(double reten) {retention = reten; }
    void setName(string n) { name = n; }
    void setWeb(string web) { website = web; }
    
    // Getters
    int getRank() const { return rank; }
    int getYear() const { return year; }
    int getCost() const { return cost; }
    int getNoStu() const { return noStu; }
    double getTran() const { return transfer; }
    double getReten() const { return retention; }
    string getName() const { return name; }
    string getWeb() const { return website; }
    
    // Other functions
    void display();
    void displayAll();
    void insertManager();
};


#endif /* College_h */
