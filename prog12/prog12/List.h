#ifndef List_H
#define List_H
#include <iostream>
#include <cstdlib>
#include "Node.h"
using namespace std;

// Singly linked list
template <class T>
class List {
  private:
    Node<T>* head; // pointer to the first node
    Node<T>* tail; // pointer to the last node
    int count;  // number of nodes in the list
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
  cout << "*** List contents ***" << endl;
  for (int i = 0; i < count; i++) {
    cout << i << ": " << get(i) << endl;
  }
}

#endif
