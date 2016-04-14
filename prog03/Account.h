#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

const int DAYS_PER_MONTH = 30;

class Account
{
public:
   Account();
   Account(double b);
   void deposit(double amount);
   void withdraw(double amount);
   double get_balance() const;
   void adjust(double r, int yield);
private:
   double balance;
};

#endif
