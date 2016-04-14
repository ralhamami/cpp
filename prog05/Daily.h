#ifndef DAILY_H
#define DAILY_H

#include "Time.h"
#include "Appointment.h"

class Daily : public Appointment
{
public:
   Daily();
   Daily(string desc, Time s, Time e);
   virtual bool occurs_on(int year, int month, int day) const;
};

#endif