
#include <iostream>
#include <iomanip>
using namespace std;

#include "Money.h"

//***********************************
// implementation of member functions
//***********************************

Money::Money() {
    this->dollars = 0;
    this->cents = 0;
    this->pmemo = NULL;
}

Money::Money(int dollars) {
    this->dollars = dollars;
    this->cents = 0;
    this->pmemo = NULL;
}

Money::Money(int dollars, int cents) {
    // if cents exceed 99, adjust dollars
    this->cents = cents % 100;
    this->dollars = dollars + cents / 100;
    this->pmemo = NULL;
}

Money::Money(int dollars, int cents, string message) {
    this->cents = cents % 100;
    this->dollars = dollars + cents / 100;
    this->pmemo = new Memo(message);
}

Money::~Money() {
    if (pmemo != NULL) delete pmemo;
}

Money::Money(const Money& right)
   {Money *temp = new Money(right.dollars,right.cents,(right.pmemo)->getMessage());
    *this = *temp;
   }

int Money::getDollars() const {
    return dollars;
}

int Money::getCents() const {
    return cents;
}

Memo* Money::getPmemo() const {
    return pmemo;
}

Money& Money::operator=(const Money& right)
   {Money *temp  = new Money(right.dollars,right.cents,(right.pmemo)->getMessage());
    this->dollars = temp->dollars;
    this->cents = temp->cents;
    this->pmemo = temp->pmemo;
    return *this;
   }

Money& Money::operator+=(const Money& right)
   {if (getPmemo() != NULL || right.getPmemo() != NULL)
       pmemo = new Memo(getPmemo()->getMessage()+(right.getPmemo())->getMessage());
    Money temp(dollars+right.dollars,cents+right.cents);
    dollars = temp.dollars;
    cents = temp.cents;	
    return *this;
   }

Money& Money::operator++()
   {Money *temp = new Money(this->dollars,++this->cents,(this->pmemo)->getMessage());
    *this = *temp;
    return *this;
   }

Money Money::operator++(int unused)
   {Money *temp = new Money(this->dollars,this->cents,(this->pmemo)->getMessage());
    Money *temp2 = new Money(this->dollars,++this->cents,(this->pmemo)->getMessage());
    *this = *temp2;
    return *temp;
   }

//****************************************
// implementation of non-member functions
//****************************************

ostream& operator<<(ostream& out, const Money& value) {
    out << "$" << value.getDollars() << "." 
    	<< setfill('0') << setw(2) << value.getCents();
    if (value.getPmemo() != NULL)
    	out << "[" << (value.getPmemo())->getMessage() << "]";
    return out;
}

Money operator+(const Money& left, const Money& right)
   {string mtemp = "", mtemp2 = "";
    if (left.getPmemo() != NULL)
       mtemp = (left.getPmemo())->getMessage();
    if (right.getPmemo() != NULL)
       {mtemp2 = (right.getPmemo())->getMessage();
        mtemp += mtemp2;
       }
    Money temp(left.getDollars()+right.getDollars(), left.getCents()+right.getCents(), mtemp);
    return temp;
   }

Money operator-(const Money& left, const Money& right)
   {int dollars=left.getDollars()-right.getDollars(), cents=left.getCents()-right.getCents();
    if (cents < 0)
       {dollars--;
        cents+=100;
       }
    Money temp(dollars,cents,(left.getPmemo())->getMessage());
    return temp;
   }

bool operator<(const Money& left, const Money& right)
   {if((left.getCents()+(left.getDollars()*100))<(right.getCents()+(right.getDollars()*100)))
       return true;
    return false;
   }

bool operator>(const Money& left, const Money& right)
   {if((left.getCents()+(left.getDollars()*100))>(right.getCents()+(right.getDollars()*100)))
       return true;
    return false;
   }

bool operator==(const Money& left, const Money& right)
   {if((left.getCents()+(left.getDollars()*100))==(right.getCents()+(right.getDollars()*100)))
       {string temp1 = (left.getPmemo())->getMessage();
        string temp2 = (right.getPmemo())->getMessage();
        if (temp1 == temp2)
           return true;
       }
    return false;
   }

istream& operator>>(istream& in, Money& r)
   {int dollars=0,cents=0;
    string message="";
    in >> dollars >> cents >> message;
    Money *temp = new Money(dollars,cents,message);
    r = *temp;
    return in;
   }
