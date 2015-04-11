//
//  main.cpp
//  LinkedList
//
//  Created by David P. Lopez on 4/10/15.
//  Copyright (c) 2015 David P. Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

const int SIZE = 35;

struct Entry
{
    char name[SIZE];
    int age;
    Entry *next;
};


Entry* getNewEntry()
{
    char name[SIZE];
    
    cout << "Enter a new name or press ENTER to quit.";
    cin.getline(name,SIZE);
    
    if(strlen(name) == 0)
    {
        cout << "You pressed ENTER" << endl;
        return NULL;
    }
    
    Entry *newOne = new Entry;
    strcpy(newOne->name, name);
    
    cout << "Age: ";
    cin >> newOne->age;
    
    
    
    
    
    
    return newOne;
    
    
}





int main() {
    
    // insert code here...
    
    
}


