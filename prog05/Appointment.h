#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Time.h"
#include <string>
using namespace std;

class Appointment
{
public:
   Appointment();
   Appointment(string desc, Time s, Time e);
   void print() const;

   /** pure virtual function
      Determines if the appointment occurs on the given date.
      @param year a year value
      @param month a month value of 1 for Jan, to 12 for Dec
      @param day a day value
      @return true if the appointment occurs on the given date
   */
   virtual bool occurs_on(int year, int month, int day) const = 0;

private:
   string description;
   Time start;
   Time end;
};

#endif
