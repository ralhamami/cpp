
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Heap.h"
#include "Car.h"

int main() {
    
   {cout << "\n****HEAP TEST DOUBLE****\n" << endl;
    
    //TEST CONSTRUCTOR
    Heap<double> tasks;
    
    //TEST PUSH()
    tasks.push(2.1);
    tasks.push(3.1);
    tasks.push(2.2);
    tasks.push(1.1);
    tasks.push(4.1);
    tasks.push(9.1);
    tasks.push(1.2);
    tasks.push(5.1);
    
    //TEST SIZE() "SHOULD RETURN 8"
    while (tasks.size() > 0) {
        //TEST TOP() "SHOULD BE LARGEST AND ON TOP" 
        double task = tasks.top();
        //TEST POP() "SHOULD POP TOP, AND REPLACE WITH NEXT LARGEST" 
        tasks.pop();
        cout << task << endl;
       }
    //TEST DESTRUCTOR
    cout << "Expecting Destructor: ";
   }

   {cout << "\n****HEAP TEST CAR****\n" << endl; 
    
    //TEST CONSTRUCTOR
    Heap<Car> tasks1;

    //TEST PUSH()
    tasks1.push(Car("Hyundai",2012,11000));
    tasks1.push(Car("Toyota",2013,25000));
    tasks1.push(Car("Kia",2011,14000));
    tasks1.push(Car("BMW",2008,16000));
    tasks1.push(Car("Mercedes",2007,23000));
    tasks1.push(Car("Nissan",2010,10700));
    
    //TEST SIZE() "SHOULD RETURN 6"
    while (tasks1.size() > 0) {
        //TEST TOP() "SHOULD BE LARGEST AND ON TOP"
        Car task1 = tasks1.top();
        //TEST POP() "SHOULD POP TOP, AND REPLACE WITH NEXT LARGEST"
        tasks1.pop();
        //TEST FOR << OPERATOR OVERLOAD FOR CLASS CAR
        cout << task1 << endl;
    }
    //TEST DESTRUCTOR
    cout << "Expecting Destructor: ";
   }

   {cout << "\n****HEAP TEST STRING****\n" << endl; 
    
    //TEST CONSTRUCTOR
    Heap<string> tasks2;

    //TEST PUSH()
    tasks2.push("Hillary");
    tasks2.push("Bob");
    tasks2.push("Kyle");
    tasks2.push("Billy");
    tasks2.push("Timothy");
    tasks2.push("Alex");
    tasks2.push("George");
    tasks2.push("Jacob");
    tasks2.push("Rayan");
    
    //TEST SIZE() "SHOULD RETURN 9"
    while (tasks2.size() > 0) {
        //TEST TOP() "SHOULD BE LARGEST AND ON TOP"
        string task2 = tasks2.top();
        //TEST POP() "SHOULD POP TOP, AND REPLACE WITH NEXT LARGEST"
        tasks2.pop();
        cout << task2 << endl;
    }
    //TEST DESTRUCTOR
    cout << "Expecting Destructor: ";
   }
    return 0;
}

