#ifndef SAVIGS_H
#define SAVINGS_H

#include "Account.h"

class Savings: public Account
{
public:
  Savings();
  Savings(double b);
  void daily_interest();
private:
};

#endif
