#include "Appointment.h"

#include <iostream>
using namespace std;

Appointment::Appointment()
{
}

Appointment::Appointment(string desc, Time s, Time e)
{
   description = desc;
   start = s;
   end = e;
}

void Appointment::print() const
{
   cout << " " << start.get_hours() << ":";
   if (start.get_minutes() < 10) cout << "0";
   cout << start.get_minutes()
      << " - " << end.get_hours() << ":";
   if (end.get_minutes() < 10) cout << "0";
   cout << end.get_minutes() << " " << description << "\n";
}
