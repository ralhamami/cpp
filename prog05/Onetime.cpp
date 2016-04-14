#include "Onetime.h"

Onetime::Onetime()
{
}

Onetime::Onetime(string desc, Date d, Time s, Time e) 
   : Appointment(desc, s, e)
{
   when = d;
}

/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/
bool Onetime::occurs_on(int year, int month, int day) const
{
   return when.equals(Date(year, month, day));
}