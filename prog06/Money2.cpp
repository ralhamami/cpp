#include <iostream>
#include <iomanip>
#include "Money.h"
using namespace std;

#define above99 (temp.cents > 99){temp.dollars += (temp.cents/100);}
#define below0 (temp.cents < 0){temp.dollars--; temp.cents += 100;}

   Money::Money(int d, int c)
      {dollars = d;
       if (c > 99)
          {dollars += c/100;
           cents = c%100;
          }
       else cents = c;
      }
   
   Money &Money::operator+(const Money& b) const
      {Money temp = *this;
       temp.dollars += b.dollars;
       if(temp.cents > 99){temp.dollars += (temp.cents/100);}
       else if(temp.cents < 0){temp.dollars--; temp.cents += 100;}
       else {temp.cents += b.cents;}
       return temp;
      }
   
   Money &Money::operator-(const Money& b) const
      {Money temp = *this;
       
       temp.dollars -= b.dollars;
       if(temp.cents > 99){temp.dollars += (temp.cents/100);}
       else if(temp.cents < 0){temp.dollars--; temp.cents += 100;}
       else {temp.cents -= b.cents;}
       return temp;
      }
   
   Money Money::operator*(double m) const{}
   
   Money Money::operator/(double d) const{}

   void Money::print() const
      {cout << "$" << dollars << "." << cents << endl;}

int main()
   {Money *a = new Money(0, 675);
    Money *b = new Money(6, 0);
    Money *c = new Money(0, 0);
    *c = *a + *b + *a;
   c->print();
   } 
