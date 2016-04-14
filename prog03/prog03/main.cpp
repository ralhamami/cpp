#include <iostream>
#include "Checking.h"
#include "Savings.h"

using namespace std;

int main()
{
   Checking c = Checking(1000.0);
   Savings s = Savings(1000.0);
   for (int i = 1; i <= DAYS_PER_MONTH; i++)
   {
      c.deposit(i * 5);
      c.withdraw(i * 2);
      s.deposit(i * 5);
      s.withdraw(i * 2);
      c.daily_interest();
      s.daily_interest();
      if (i % 10 == 0)
      {
         cout << "day " << i << "\n";
         cout << "Checking balance: " << c.get_balance() << "\n";
         cout << "Savings balance: " << s.get_balance() << "\n";
      }
   }
   return 0;
}
