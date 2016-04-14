#include <iostream>
#include <iomanip>
#include "Money.h"
using namespace std;

   Money::Money(int d, int c)
      {dollars = d;
       if (c > 99)
          {dollars += c/100;
           cents = c%100;
          }
       else cents = c;
      }
   
   Money Money::operator+(const Money& b) const
      {Money temp(this->dollars,this->cents);
       temp.dollars = dollars + b.dollars;
       if((temp.cents + b.cents) > 99){temp.dollars += (temp.cents+b.cents)/100; temp.cents = (temp.cents+b.cents)%100;}
       else {temp.cents += b.cents;}
       return temp;
      }
   
   Money Money::operator-(const Money& b) const
      {Money temp(this->dollars,this->cents); 
       temp.dollars -= b.dollars;
       if((temp.cents-b.cents) < 0){temp.dollars--; temp.cents = (temp.cents-b.cents)+100;}
       else {temp.cents -= b.cents;}
       return temp;
      }
   
   Money Money::operator*(double m) const
      {Money temp(0,0);
       double whole = this->dollars + (double(this->cents%100)/100);
       whole *= m;
       temp.dollars = (int)whole;
       temp.cents = (whole-(temp.dollars))*100;
       return temp;
      }
   
   Money Money::operator/(double d) const
      {Money temp(0,0);
       double whole = this->dollars + (double(this->cents%100)/100);
       whole /= d;
       temp.dollars = (int)whole;
       temp.cents = (whole-(temp.dollars))*100;
       return temp;
      }

   void Money::print() const
      {cout << "$" << dollars << "." << setfill('0') << setw(2) << cents << endl;
      } 
