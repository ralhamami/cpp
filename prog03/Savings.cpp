#include <iostream>
#include <string>
using namespace std;

#include "Savings.h"

Savings::Savings():Account()
   {}

Savings::Savings(double b):Account(b)
   {}

void Savings::daily_interest() 
   {Account::adjust(.002, 0);}
