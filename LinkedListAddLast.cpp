//
//  main.cpp
//  LinkedList - addLast
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

// a pointer is passed to this function and this function will print the
// attributes of each node that the pointer being passed to the function
// is pointing to when it is called.
void displayEntry(Entry *e)
{
    cout << e->name << " " << e->age << endl;
}

bool addFirst(Entry *newEntry, Entry* &head)
{
    /* this function takes in a pointer to a node of type Entry
     and the function will point newEntry->next to the address of 
     the node that that the pointer called head is currently being 
     pointed to. Basically, The pointer of type Entry being passed
     to the function will first be added as the new head of the linked list.
     It will be pointed to the head instead of its default NULL value.
     The pointer designated to head from the old node will then be reassigned and it
     will now point to the node passed as newEntry. So now we know
     that the head node's pointer points to the head, and the old head
     node and its next pointer will now point to the new node which is the
     new head of the linked list.
    */
    
    if (newEntry == NULL)//a node was not passed into the function
        return false;//therefore head points to the last node entered as the head of the list
    
    newEntry->next = head;
    head = newEntry;
    return true;
}

bool addLast(Entry *newEntry, Entry* &head)
{
    if(newEntry == NULL)
        return false;
    else
    {
        /*
            This creates a pointer to the current node which will traverse each node
            until it gets to the end of the list where it will add the new node called
            newEntry. 
         
            the pointer current will be set equal to the pointer that was passed to the 
            function which is keeping track of the head of our list.
         */
        
        Entry *current;
        current = head;
        
        if(head == NULL)
        {
            head = newEntry;
        }
        else
        {
            /*
                this while loop checks to see if the next pointer in each node points to another node
                the head is the start of the list and it points to another node. the last node points 
                to NULL and this will be where the newEntry node will be added by pointing the current
                node's next pointer to the newEntry node
             */
            
            //traverse the list to get to the end
            while(current->next != NULL)
            {
                current = current->next;
            }
            
            //Set the current's *next to the new Entry
            current->next = newEntry;//the current node's next pointer is now set to point at the newEntry node passed to function
        }
    }
    return true; //this return tells the buildList function to keep creating nodes.
}

Entry* buildList()
{
    Entry *listHead = NULL; //start of the list
    
    while(true)
    {
        Entry *newOne = getNewEntry();//creates a new node every time a user enters data for the new node
        
        //add to end
        if(!addLast(newOne, listHead))
            break;
    }
    return listHead;
}

void displayList(Entry *list)
{
    //a pointer to a list of type Entry is passed into this function and it iterates
    // over the list using a new pointer called current which begins its search at
    // list. current will continue to iterate over the list until it reaches a NULL
    // or a node of nothing. on each iteration current will be passed to the displayEntry
    // function and be printed to the screen and it will then point to the next node
    // using the nodes pointer to repeat the process until the loop reaches NULL
    
    for (Entry *current = list; current != NULL; current = current->next)
        displayEntry(current);
}

int main() {
    
    // new pointer of type Entry that points to the data in a
    // new node whose pointer points to null
    
    Entry *listHead = buildList();
    displayList(listHead);
    
    return EXIT_SUCCESS;
    
}


