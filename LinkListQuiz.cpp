//  LinkListQuiz.cpp
//  LinkedList - Linked Lists Quiz
//
//  Created by David P. Lopez on 4/16/15.
//  Copyright (c) 2015 David P. Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

const int SIZE = 5;
    
struct Entry
{
    char number[SIZE];
    Entry *next;
};

Entry* getNewEntry() //creates a new node when called
{
    char number[SIZE];
    
    cout << "Enter a new number or press ENTER to display list and view more Options: ";
    cin.getline(number, SIZE);
    
    if (strlen(number) == 0)
    {
        cout << "You pressed ENTER" << endl;
        return NULL;
    }
    
    Entry *newOne = new Entry;
    strcpy(newOne->number, number);
    
    newOne->next = NULL;
    
    return newOne;
}

// a pointer is passed to this function and this function will print the
// attributes of each node that the pointer being passed to the function
// is pointing to when it is called.
void displayEntry(Entry *e)
{
    cout << e->number << endl;
}

bool addLast(Entry *newEntry, Entry* &head, Entry* &tail)
{
    if (newEntry == NULL)
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
        
        if (head == NULL)
        {
            head = newEntry;
            tail = newEntry;// 1st node created will be both head and tail
        }
        else
        {
            
            tail = newEntry;//this wires the tail pointer to track the newest Entry as soon as it is created
            
            /*
             this while loop checks to see if the next pointer in each node points to another node
             the head is the start of the list and it points to another node. the last node points
             to NULL and this will be where the newEntry node will be added by pointing the current
             node's next pointer to the newEntry node
             */
            
            //traverse the list to get to the end
            while (current->next != NULL)
            {
                current = current->next;
            }
            
            //Set the current's *next to the new Entry
            current->next = newEntry;//the current node's next pointer is now set to point at the newEntry node passed to function
        }
    }
    return true; //this return tells the buildList function to keep creating nodes.
}

Entry* buildList(Entry* &tail)
{
    Entry *listHead = NULL; //start of the list
    
    while (true)
    {
        Entry *newOne = getNewEntry();//creates a new node every time a user enters data for the new node
        //add to end of the list when calling this function
        if (!addLast(newOne, listHead, tail))
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
    {
        displayEntry(current);
    }
}

bool removeLast(Entry* &head, Entry* &tail)
{
    if (tail == NULL)
        return false;
    else
    {
        Entry *toBeDeleted; //creates pointer that will be wired to the last node for deletion
        toBeDeleted = tail; //wires toBeDeleted to the tail that will be deleted
        
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Entry *previous; //pointer to find tail without losing head
            previous = head; //pointer start at head
            
            while (previous->next != tail) //as long as the pointer from the current node does not point to data in the tail
                previous = previous->next; //then the loop will continue to look for tail
            tail = previous; //finds tail
            tail->next = NULL;
        }
        
        delete toBeDeleted; //deletes tail
    }
    return true;
}

Entry* search(int num, Entry* &head)
{
    Entry *current;
    
    current = head;
    
    while(current != NULL)
    {
        if(atoi(current->number) == num)
        {
            return(current); //selected node is found
        }
        current = current->next; //move to next node to check for num
    }
    
    return head;//if not found return head of linked list
}

int main() {
    
    Entry *listTail = NULL;
    int deleteLast, searchNum;
    
    // new pointer of type Entry that points to the data in a
    // new node whose pointer points to null
    Entry *listHead = buildList(listTail);
    
    displayList(listHead);
    
    cout << "Please enter a number to search for inside your List: ";
    cin >> searchNum;
    
    while(atoi(search(searchNum, listHead)->number) != searchNum)
    {
        cout << "The number you entered is not in your List. Please try again: ";
        cin >> searchNum;
        cout << endl;
    }
    
    Entry *found;
    found = search(searchNum, listHead);
    
    cout << "The number you searched for is: " << found->number << endl;
    
    cout << "Please press '1' to delete the last node from the list: ";
    while(true)
    {
        cin >> deleteLast;
        cout << endl;
        if(deleteLast == 1)
        {
            removeLast(listHead, listTail);
            displayList(listHead);
            cout << "Please press '1' to delete or '2' to escape: " << endl;
        }
        else
            break;
    }
    return EXIT_SUCCESS;
}
