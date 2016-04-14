#include "Daily.h"

Daily::Daily()
{
}

Daily::Daily(string desc, Time s, Time e) 
   : Appointment(desc, s, e)
{
}

/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/
bool Daily::occurs_on(int year, int month, int day) const
{
   return true;
}