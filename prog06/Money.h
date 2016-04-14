#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <iomanip>

using namespace std;

class Money
{
public:
   Money(int dollars, int cents);
   Money operator+(const Money& b) const;
   Money operator-(const Money& b) const;
   Money operator*(double m) const;
   Money operator/(double d) const;

   void print() const;

private:
   int dollars;
   int cents;
};

#endif
