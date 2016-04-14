//Added member function "adjust" to apply daily interest. 
//Fucntion takes 2 parameters, "r" and "yield".  "r" is the
//interest rate, while "yield" is simply whether or not interest
//is accrued on amounts over 1000 or the entire amount.
#include <iostream>
#include <string>
using namespace std;

#include "Account.h"

Account::Account()
{}

Account::Account(double b)
{balance = b;}

void Account::deposit(double amount)
{balance += amount;}

void Account::withdraw(double amount)
{balance -= amount;}

double Account::get_balance() const
{return balance;}

void Account::adjust(double r, int yield)
{balance += (balance-yield) * r;}
