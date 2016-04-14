#include <iostream>
using namespace std;

#include "Stack.h"

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
    //Test constructor
    cout << ">>>TESTING DOUBLE<<<" << endl;
    Stack<double> s1;

    // isEmpty() Test
    if (s1.isEmpty()) {
        cout << "s1 is empty at the beginning." << endl;
    } else {
        cout << "s1 must be empty. Something's wrong!" << endl;
    }

    // push() Test
    s1.push(1.1);
    s1.push(2.2);
    s1.push(3.3);
    s1.push(4.4);
    s1.push(5.5);

    // pop() Test
    cout << "Expecting 5.5 4.4 3.3 2.2 1.1: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << s1.top() << endl;
        s1.pop();
    }

    // isFull() Test
    if (!s1.isFull())
        cout << "s1 is not full." << endl;
    else
        cout << "s1 is full." << endl;

    // isEmpty() Test
    if (s1.isEmpty()) {
        cout << "s1 is empty after five pop() calls." << endl;
    } else {
        cout << "s1 must be full. Something's wrong!" << endl;
    }

    // StackEmptyException test
    cout << "Expecting StackEmptyException: ";
    try {
        s1.pop();
    } catch (Stack<double>::StackEmptyException) {
        cout << "Exception: cannot pop, stack is empty" << endl;
    }
    
    // ~Stack() Test
    cout << "Expecting Destructor: ";
}

void test_int() {
    cout << ">>>TESTING INT<<<" << endl;
    // Test Constructor
    Stack<int> s1;

    // isEmpty() Test
    if (s1.isEmpty()) {
        cout << "s1 is empty at the beginning." << endl;
    } else {
        cout << "s1 must be empty. Something's wrong!" << endl;
    }

    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    // pop() Test
    cout << "Expected: 1 2 3 4 5 -->" << endl;
    for (int i = 0; i < 5; i++) {
        cout << s1.top() << endl;
        s1.pop();
    }

    // isFull() Test
    if (!s1.isFull())
        cout << "s1 is not full." << endl;
    else
        cout << "s1 is full." << endl;

    // isEmpty() Test
    if (s1.isEmpty()) {
        cout << "s1 is empty after five pop() calls." << endl;
    } else {
        cout << "s1 must be full. Something's wrong!" << endl;
    }

    // StackEmptyException test
    cout << "Expecting StackEmptyException: ";
    try {
        s1.pop();
    } catch (Stack<int>::StackEmptyException) {
        cout << "Exception: cannot pop, stack is empty" << endl;
    }

    // ~Stack() Test
    cout << "Expecting Destructor: ";
}

void test_string() {
    cout << ">>>TESTING STRING<<<" << endl;
    // Test Constructor
    Stack<string> s1;

    // isEmpty() Test
    if (s1.isEmpty()) {
        cout << "s1 is empty at the beginning." << endl;
    } else {
        cout << "s1 must be empty. Something's wrong!" << endl;
    }

    s1.push("This");
    s1.push("is");
    s1.push("a");
    s1.push("working");
    s1.push("program");

    // pop() Test
    cout << "Expected: program working a is This -->" << endl;
    for (int i = 0; i < 5; i++) {
        cout << s1.top() << endl;
        s1.pop();
    }

    // isFull() Test
    if (!s1.isFull())
        cout << "s1 is not full." << endl;
    else
        cout << "s1 is full." << endl;

    // isEmpty() Test
    if (s1.isEmpty()) {
        cout << "s1 is empty after five pop() calls." << endl;
    } else {
        cout << "s1 must be full. Something's wrong!" << endl;
    }

    // StackEmptyException test
    cout << "Expecting StackEmptyException: ";
    try {
        s1.pop();
    } catch (Stack<string>::StackEmptyException) {
        cout << "Exception: cannot pop, stack is empty" << endl;
    }

    // ~Stack() Test
    cout << "Expecting Destructor: ";
}

