//From my understanding in class lecture, a mergesort generally 
//requires the following operations be done recursively:
//*Divide the unsorted list into n sublists.
//*Compare the sublists
//*Merge the sublists
//4 fucntions were added to achieve this here.
//The first is the public member mergesort()
//and the other 3 functions carry out each of the 3 operations
//mentioned above.

#ifndef List_H
#define List_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Node.h"
using namespace std;

// Singly linked list
template <class T>
class List {
  private:
    Node<T>* head; // pointer to the first node
    Node<T>* tail; // pointer to the last node
    int count;  // number of nodes in the list
    
    //Private Member Functions Needed for mergesort()
    //Added to provide recursive backbone needed for mergesort
    void recursiveMerge(Node<T>* &sub);
   
    //Added to carry out division of entries in list
    //This is used in the recursive function above
    Node<T>* divide(Node<T>* sub);

    //Added to compare entries and merge the divided lists
    //in a sorted fashion
    Node<T>* merge(Node<T>* first, Node<T>* second);
  public:
    class OutOfRangeException{ }; // empty inner class for exception handling
    List();
    virtual ~List();
    void push_back(T item);
    void insert(int index, T item);
    void remove(int index);
    int indexOf(T item);
    T get(int position); // OutOfRangeException is generated
    bool isEmpty();
    int size();
    void print();
    void mergesort();//Public member function
};

template <class T>
List<T>::List() {
  head = tail = NULL;
  count = 0;
}

template <class T>
List<T>::~List() {
  Node<T>* discard;
  while (head != 0) {
    discard = head;
    head = head->next;
    delete discard;
  }
}

// append an item at the end of the List
template <class T>
void List<T>::push_back(T item) {
  try {
    Node<T>* newNode = new Node<T>(item);
    if (head == 0) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    ++count;
  } catch (bad_alloc &e) {
    cout << "memory allocation exception: " << e.what() << endl;
    //exit(1);
  }
}

// insert an item at the specified index
template <class T>
void List<T>::insert(int index, T item) {
  try {
    if (index < 0 || index > count) // push_back() if index == count
      throw OutOfRangeException();

    Node<T>* newNode = new Node<T>(item);
    if (head == 0) { // empty
      head = tail = newNode;
    } else if (index == 0) { // at the start
      newNode->next = head;
      head = newNode;
    } else if (index == count) { // at the end
      tail->next = newNode;
      tail = newNode;
    } else { // insert in the middle
      Node<T>* prevNode;
      Node<T>* currNode = head;
      for (int i = 0; i < index; i++) {
        prevNode = currNode;
        currNode = currNode->next;
      }
      // insert between 'prevNode' and 'currNode'
      prevNode->next = newNode;
      newNode->next = currNode;
    }
    ++count;

  } catch (bad_alloc &e) {
    cout << "memory allocation exception: " << e.what() << endl;
    exit(1);
  }
}

// is the List empty?
template <class T>
bool List<T>::isEmpty() {
  return count == 0;
}

// remove the item at specified index
template <class T>
void List<T>::remove(int index) {
  if (index < 0 || index >= count)
    throw OutOfRangeException();

  if (index == 0) { // at the start
    Node<T>* discard = head;
    head = head->next;
    delete discard;
  } else {
    Node<T>* prevNode;
    Node<T>* currNode = head;
    for (int i = 0; i < index; i++) {
      prevNode = currNode;
      currNode = currNode->next;
    }
    // remove 'currNode'
    prevNode->next = currNode->next; // bypass
    delete currNode;

    if (index == count - 1) // last node was removed. Update 'tail'
      tail = prevNode;
  }
  --count;
  if (count == 0)
    tail = NULL;
}

// retrieve the item at the given position of the List. position starts from 0.
// throws OutOfRangeException if invalid position value is given.
template <class T>
T List<T>::get(int position) {
  if (position < 0 || position >= count)
    throw OutOfRangeException();

  int loc = 0;
  Node<T>* curr = head;
  while (loc < position) {
    ++loc;
    curr = curr->next;
  }
  return curr->data;
}

// Requirement:
//   != operator of <class T>  is used
template <class T>
int List<T>::indexOf(T item) {
  if (head == 0) {
    return -1; // not found
  } else {
    int index = 0;
    Node<T>* currNode = head;
    while (currNode->data != item && currNode != NULL) {
      currNode = currNode->next;
      ++index;
    }
    if (currNode == NULL) // not found thru the end
      return -1;
    else
      return index;
  }
}

// number of nodes in the List
template <class T>
int List<T>::size() {
  return count;
}

// Requirement:
//   << operator for <class T> is used.
template <class T>
void List<T>::print() {
  for (int i = 0; i < count; i++) {
    cout << setw(3) << left << i << ": " << get(i) << endl;
  }
}

//Public mergesort function for list
template <class T>
void List<T>::mergesort()
  {recursiveMerge(head);
  }

//Recursive Backbone
template <class T>
void List<T>::recursiveMerge(Node<T>* &sub)
  {if (sub != NULL && sub->next != NULL)
     {Node<T>* secondHalf = divide(sub);//List is divided
      recursiveMerge(sub);//Recursive call 1st half
      recursiveMerge(secondHalf);//Recursive call 2nd half
      sub = merge(sub,secondHalf);//Sort and merge 1st and 2nd
     }
  }

//Division of List
template <class T>
Node<T>* List<T>::divide(Node<T>* sub)
  {Node<T>* position;
   Node<T>* midpoint;
   Node<T>* secondHalf;
   if ((midpoint = sub) == NULL) return NULL;
   position = midpoint->next;
   while(position != NULL)
     {position = position->next;
      if (position != NULL)
        {midpoint = midpoint->next;
         position = position->next;
        }
     }
   secondHalf = midpoint->next;
   midpoint->next = NULL;
   return secondHalf;
  }

//Comparing and Merging of list
template <class T>
Node<T>* List<T>::merge(Node<T>* first, Node<T>* second)
  {Node<T>* lastSort;
   Node<T> merged((T()));
   lastSort = &merged;
   while (first != NULL && second != NULL)
     {if (first->data <= second->data)//If data is <=
        {lastSort->next = first; //Change linkage of list entries
         lastSort = first;
         first = first->next;
        }
      else
        {lastSort->next = second;
         lastSort = second;
         second = second->next;
        }
     }
   if (first == NULL)
     lastSort->next = second;
   else
     lastSort->next = first;
   return merged.next; //Return a pointer to the newly merged list
  }

#endif
