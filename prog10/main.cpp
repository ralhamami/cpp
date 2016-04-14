
#include <iostream>
using namespace std;

#include "Queue.h"

void test_double();
void test_int();
void test_string();

int main() {

    test_double();
    test_int();
    test_string();
    return 0;
}

void test_double() {
    // Test Constructor
    Queue<double> q1;
    cout << ">>>TESTING DOUBLE<<<" << endl;
    
    // isEmpty() Test
    if (q1.isEmpty()) {
        cout << "q1 is empty at the beginning." << endl;
    } else {
        cout << "q1 must be empty. Something's wrong!" << endl;
    }

    // push() Test
    q1.push_back(1.1);
    q1.push_back(2.2);
    q1.push_back(3.3);
    q1.push_back(4.4);
    q1.push_back(5.5);

    //back() Test
    cout << "Expecting 5.5: " << q1.back() << endl;

    // front() and pop_front() Test
    cout << "Expecting 1.1 2.2 3.3 4.4 5.5: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << q1.front() << endl;
        q1.pop_front();
    }

    // isFull() Test
    if (!q1.isFull())
        cout << "q1 is not full." << endl;
    else
        cout << "q1 is full" << endl;    

    // isEmpty() Test
    if (q1.isEmpty()) {
        cout << "q1 is empty after five pop_front() calls." << endl;
    } else {
        cout << "q1 must be full. Something's wrong!" << endl;
    }

    // QueueEmptyException test
    cout << "Expecting QueueEmptyException: ";
    try {
        q1.pop_front();
    } catch (Queue<double>::QueueEmptyException) {
        cout << "Exception: cannot pop_front, queue is empty" << endl;
    }

    // ~Queue Test
    cout << "Expecting Destructor: ";
}

void test_int() {
    // Test Constructor
    Queue<int> q1;
    cout << ">>>TESTING INT<<<" << endl;
    
    // isEmpty() Test
    if (q1.isEmpty()) {
        cout << "q1 is empty at the beginning." << endl;
    } else {
        cout << "q1 must be empty. Something's wrong!" << endl;
    }

    // push() Test
    q1.push_back(5);
    q1.push_back(4);
    q1.push_back(3);
    q1.push_back(2);
    q1.push_back(1);

    //back() Test
    cout << "Expecting 1: " << q1.back() << endl;

    // pop_front() Test
    cout << "Expecting 5 4 3 2 1: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << q1.front() << endl;
        q1.pop_front();
    }

    // isFull() Test
    if (!q1.isFull())
        cout << "q1 is not full." << endl;
    else
        cout << "q1 is full" << endl;    

    // isEmpty() Test
    if (q1.isEmpty()) {
        cout << "q1 is empty after five pop_front() calls." << endl;
    } else {
        cout << "q1 must be full. Something's wrong!" << endl;
    }

    // QueueEmptyException test
    cout << "Expecting QueueEmptyException: ";
    try {
        q1.pop_front();
    } catch (Queue<int>::QueueEmptyException) {
        cout << "Exception: cannot pop_front, queue is empty" << endl;
    }

    // ~Queue Test
    cout << "Expecting Destructor: ";
}

void test_string() {
    // Test Constructor
    Queue<string> q1;
    cout << ">>>TESTING STRING<<<" << endl;
    
    // isEmpty() Test
    if (q1.isEmpty()) {
        cout << "q1 is empty at the beginning." << endl;
    } else {
        cout << "q1 must be empty. Something's wrong!" << endl;
    }

    // push() Test
    q1.push_back("This");
    q1.push_back("is");
    q1.push_back("a");
    q1.push_back("working");
    q1.push_back("program");

    //back() Test
    cout << "Expecting program: " << q1.back() << endl;

    // pop_front() Test
    cout << "Expecting This is a working program: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << q1.front() << endl;
        q1.pop_front();
    }

    // isFull() Test
    if (!q1.isFull())
        cout << "q1 is not full." << endl;
    else
        cout << "q1 is full" << endl;    

    // isEmpty() Test
    if (q1.isEmpty()) {
        cout << "q1 is empty after five pop_front() calls." << endl;
    } else {
        cout << "q1 must be full. Something's wrong!" << endl;
    }

    // QueueEmptyException test
    cout << "Expecting QueueEmptyException: ";
    try {
        q1.pop_front();
    } catch (Queue<string>::QueueEmptyException) {
        cout << "Exception: cannot pop_front, queue is empty" << endl;
    }

    // ~Queue Test
    cout << "Expecting Destructor: ";
}