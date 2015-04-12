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
    cin.ignore(1024,'\n');
    
    newOne->next = NULL;
    
    return newOne;
}

void displayEntry(Entry *e)
{
    cout << e->name << " " << e->age << endl;
}

bool addFirst(Entry *newEntry, Entry* &head)
{
    if (newEntry == NULL)
        return false;
    
    newEntry->next = head;
    head = newEntry;
    return true;
}

Entry* buildList()
{
    Entry *listHead = NULL; //start of the list
    
    while(true)
    {
        Entry *newOne = getNewEntry();
        
        // add to the begining
        if(!addFirst(newOne, listHead))
            break;
    }
    return listHead;
}

void displayList(Entry *list)
{
    for (Entry *current = list; current != NULL; current = current->next)
        displayEntry(current);
}

int main() {
    
    // insert code here...
    Entry *listHead = buildList();
    displayList(listHead);
    
    return EXIT_SUCCESS;
    
}
