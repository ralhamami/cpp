#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;

#include "Memo.h"

class Money
{
public:
   Money();			   // 0 dollars 0 cents
   Money(int dollars); // 0 cents
   Money(int dollars, int cents);
   Money(int dollars, int cents, string memo);
   int getDollars() const;
   int getCents() const;
   Memo* getPmemo() const;
   virtual ~Money(); // always declare destructor as VIRTUAL

   Money(const Money& right); // copy constructor, Memo object is copied

// overloaded operators using member functions
// implement the following ones by uncommenting them

   Money& operator=(const Money& right); // Memo object is copied
   Money& operator+=(const Money& right); // messages in Memo are concatenated if not NULL
   Money& operator-=(const Money& right); // no change in Memo
   Money& operator++(); // prefix increment cents, no change in Memo
   Money operator++(int unused); // postfix increment cents, no change in Memo

private:
   int dollars;
   int cents;
   Memo* pmemo; // a pointer to a Memo object
};

// overloaded operators using non-member functions
// implement the following ones by uncommenting them

ostream& operator<<(ostream& out, const Money& value); // print $ddd.cc[memo]
Money operator+(const Money& left, const Money& right); // messages in Memo are concatenated
Money operator-(const Money& left, const Money& right); // message of left is copied
bool operator<(const Money& left, const Money& right); // compares value only
bool operator>(const Money& left, const Money& right); // compares value only
bool operator==(const Money& left, const Money& right); // compares value && memo
istream& operator>>(istream& in, Money& r); // read dollars cents memo

#endif
