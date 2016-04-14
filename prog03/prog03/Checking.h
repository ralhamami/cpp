#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Checking: public Account
{
public:
  Checking();
  Checking(double b);
  void daily_interest();
private:
    double Balance;
};

#endif
