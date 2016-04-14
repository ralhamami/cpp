#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* front_node;
    Node<T>* rear_node;
public:

    class QueueEmptyException {
    }; // empty inner typename for exception handling

    Queue<T>();
    virtual ~Queue();
    void push_back(T data); // aka 'enqueue'
    void pop_front();       // aka 'dequeue'
    T front();  // read the data at 'front'
    T back();   // read the dat at 'end'
    bool isEmpty();
    bool isFull();
};
// constructor
template <class T>
Queue<T>::Queue() {
    front_node = rear_node = NULL;
}

// destructor: free all the memory allocated for this queue
template <class T>
Queue<T>::~Queue() {
    while (!isEmpty())
        pop_front();
    cout << "Q1 DESTRUCTOR CALLED!" << endl;
}

// append an item to the queue
template <class T>
void Queue<T>::push_back(T item) {
    try {
        Node<T>* newNode = new Node<T>(item);
        if (isEmpty()) {
            front_node = rear_node = newNode;
        } else {
            rear_node->next = newNode;
            rear_node = newNode;
        }
    } catch (bad_alloc &e) {
        cout << "memory allocation exception: " << e.what() << endl;
        exit(1);
    }
}

// serve an item from the queue
template <class T>
void Queue<T>::pop_front() {
    if (isEmpty())
        throw QueueEmptyException();

    Node<T>* discard = front_node;
    front_node = front_node->next; // advance to the next link
    delete discard;
    if (isEmpty()) rear_node = NULL;
}

// read the data at 'front_node'
template <class T>
T Queue<T>::front() {
    if (isEmpty())
        throw QueueEmptyException();

    return front_node->data;
}

// read the data at 'rear'
template <class T>
T Queue<T>::back() {
    if (isEmpty())
        throw QueueEmptyException();

    return rear_node->data;
}

// is the queue empty?
template <class T>
bool Queue<T>::isEmpty() {
    return front_node == NULL;
}

// is the queue full?
template <class T>
bool Queue<T>::isFull() {
    return false; // never
}
#endif
