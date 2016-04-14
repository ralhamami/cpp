#include "Date.h"

#include <iostream>
using namespace std;

Date::Date()
{
   day = 1;
   month = 1;
   year = 1;
}

Date::Date(int y, int m, int d)
{
   day = d;
   month = m;
   year = y;
}

void Date::print() const
{
   cout << year << "/" << month << "/" << day;
}

bool Date::equals(Date other) const
{
   return day == other.day && month == other.month 
      && year == other.year;
}
