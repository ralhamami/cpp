#include <iostream>
#include <string>
using namespace std;

#include "Checking.h"

Checking::Checking():Account()
   {}

Checking::Checking(double b):Account(b)
   {}

void Checking::daily_interest() 
   {if (Account::get_balance() >= 1000)
       Account::adjust(.001, 1000);}
