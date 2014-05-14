//
//  main.cpp
//  Study
//
//  Created by Robert Mancuso on 5/14/14.
//  Copyright (c) 2014 Robert Mancuso. All rights reserved.
//

#include <iostream>
using namespace std;

class LiveStock
{
    
public:
    double cost;
    int amount;
    string name;
    
    LiveStock(string n)
    {
        name = n;
        cost = 0.0;
        amount = 0;
    }
    
    LiveStock(string n, int amt, double cst)
    {
        name = n;
        amount = amt;
        cost = cst;
    }
    void AddInt(int i)
    {
        amount += i;
    }
    int getAmt()
    {
        return amount;
    }
};









int main(int argc, const char * argv[])
{
    LiveStock *test1 = new LiveStock("test1", 1, 2);
    LiveStock *test2 = new LiveStock("test2", 2, 3);
    LiveStock *test3 = new LiveStock("test3", 44, 45);
    LiveStock *ls[3] = {test1, test2, test3};
    e
    for(int i = 0; i < 3; i++)
    {
        cout << ls[i]->getAmt() << endl;
        cout << ls[i]->cost << endl;
        cout << ls[i]->name << endl;
        
    }ge
    
    return 0;
}

