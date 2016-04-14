#include <iostream>
#include "Money.h"
using namespace std;

int main()
   {Money a(7, 50);
    Money b(2, 75);
    Money d(3, 45);
    Money e(1, 25);
    cout << "TEST OUTPUT 1" << endl;
    Money c = a + b + b - a; //RESULT: $5.50
    cout << "7.50 + 2.75 + 2.75 - 7.50 = ";
    c.print();
    c = a - b - d; //RESULT: $1.30
    cout << "7.50 - 2.75 - 3.45 = ";
    c.print();
    c = a * 2.5; //RESULT: $18.75
    cout << "7.50 x 2.5 = ";
    c.print();
    c = a / 1.5; //RESULT: $5.00
    cout << "7.50 / 1.5 = ";
    c.print();
    //END TEST
    cout << "TEST OUTPUT 2" << endl;
    c = a + b + a - a + b; //RESULT: $13.00
    cout << "7.50 + 2.75 + 7.50 - 7.50 + 2.75 = ";
    c.print();
    c = a - b - d + a - b; //RESULT: $6.05
    cout << "7.50 - 2.75 - 3.45 + 7.50 - 2.75 = ";
    c.print();
    c = a * 2.5 * 2; //RESULT: $37.50
    cout << "7.50 x 2.5 x 2 = ";
    c.print();
    c = a / 3 / 1.25; //RESULT: $2.00
    cout << "7.50 / 3 / 1.25 = ";
    c.print();
    //END TEST
    cout << "TEST OUTPUT 3" << endl;
    c = (a + b) + (a + b); //RESULT: $20.50 
    cout << "(7.50 + 2.75) + (7.50 + 2.75) = ";
    c.print();
    c = (a - e) - (d + b); //RESULT: $0.05
    cout << "(7.50 - 1.25) - (3.45 + 2.75) = ";
    c.print();
    c = (a * 3) * 2.5; //RESULT: $56.25.00
    cout << "(7.50 x 3) x 2.5 = ";
    c.print();
    c = (a / 3) + (b / 1.25); //RESULT: $0.03
    cout << "(7.50 / 3) + (2.75 / 1.25) = ";
    c.print();
    //END TEST

   }

