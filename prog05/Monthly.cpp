#include "Monthly.h"

Monthly::Monthly()
{
}

Monthly::Monthly(string desc, int d, Time s, Time e) 
   : Appointment(desc, s, e)
{
   day = d;
}

bool Monthly::occurs_on(int year, int month, int d) const
/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/

{
   return day == d;
}