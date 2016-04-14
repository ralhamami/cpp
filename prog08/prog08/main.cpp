#include <iostream>
using namespace std;

#include "Money.h"

int main()
{
   // testing the constructor in case 'cents' exceeds 99
   // testing << output operator
   Money m1(0, 351, "money1");
   cout << "Expected: 3 dollars 51 cents ... " << m1 << endl;


   // testing overloaded + operator
   Money m2(2, 45), m3(3, 57);
   Money m4 = m2 + m3;
   cout << "Expected: 6 dollars 02 cents ... " << m4 << endl;

   // testing overloaded - operator
   Money m5(3, 15, "money5"), m6(1, 99, "money6");
   Money m7 = m5 - m6;
   cout << "Expected: 1 dollar 16 cents ... " << m7 << endl;

   // testing += operator
   m7 += m6;
   cout << "Expected: 3 dollars 15 cents ... " << m7 << endl;

   // testing + operator with an integer
   Money m8 = 2 + m7; // implicit conversion from int (2) to Money m(2)
   cout << "Expected 5 dollars 15 cents ... " << m8 << endl;

   // testing >> input operator
   cout << "TYPE: 7 45 money9 ";
   Money m9;
   cin >> m9;
   cout << "Expected 7 dollars 45 cents[money9] ... " << m9 << endl;

   // testing ++ prefix operator
   for (int i = 0; i < 99; i++) // 99 times
   		++m9;
   cout << "Expected 8 dollars 44 cents[money9] ... " << m9 << endl;

   // testing ++ postfix operator
   Money m10 = m9++; // copy constructor is called!
   cout << "m10 Expected 8 dollars 44 cents[money9] ... " << m10 << endl;
   cout << "m9 Expected 8 dollars 45 cents[money9] ... " << m9 << endl;

   // testing > < == boolean operators
   if (m9 > m10) {
       cout << "m9 is greater than m10." << endl;
    }

    if (m10 < m9) {
        cout << "m10 is less than m9." << endl;
    }
   
    if (m9 == m10)
        cout << "m9 == m10" << endl;
    else
        cout << "m9 is not equal to m10." << endl;

    Money m11(8, 45, "money11");
    cout << "m9 = " << m9 << "  m11 = " << m11 << endl;
    if (m11 == m9)
       cout << "m11 == m9" << endl;
    else
       cout << "m11 != m9 because of difference in Memo." << endl;

/*Uncomment down to here *****/

//****************************************
//**** Add your own test code below ******
//****************************************
    //Testing Copy Constructor and Assignment Operator
    Money temp1(3,15,"money1");
    Money temp2 = temp1;
    temp1 = m9;
    cout << temp2 << endl
         << temp1 << endl
         << m9 << endl;   
   //Testing
   
   return 0;
}
