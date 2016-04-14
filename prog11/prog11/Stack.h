#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* top_node;
public:

    class StackEmptyException {
    }; // empty inner typename for exception handling

    Stack();
    virtual ~Stack();
    void push(T);
    void pop();
    T top();
    bool isEmpty();
    bool isFull();
};
// constructor: new stack is created. top_node is null.
template <class T>
Stack<T>::Stack() {
    top_node = NULL;
}

// destructor: free all the memory allocated for the stack
template <class T>
Stack<T>::~Stack() {
    while (!isEmpty())
        pop();
}

// push a data onto the stack
template <class T>
void Stack<T>::push(T data) {
    try {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = top_node;
        top_node = newNode;
    } catch (bad_alloc &e) {
        cout << "memory allocation exception: " << e.what() << endl;
        exit(1);
    }
}

// pop the data from the stack
template <class T>
void Stack<T>::pop() {
    if (isEmpty())
        throw StackEmptyException();

    Node<T>* discard = top_node;
    top_node = top_node->next;
    delete discard;
}

// read the data on the top of the stack
template <class T>
T Stack<T>::top() {
    if (isEmpty())
        throw StackEmptyException();

    return top_node->data;

}

// is stack empty?
template <class T>
bool Stack<T>::isEmpty() {
    if (top_node == NULL) return true;
    else return false;
}

// is stack full? 
template <class T>
bool Stack<T>::isFull() {
    return false; // never, unless memory is full
}
#endif
