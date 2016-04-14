#ifndef ONETIME_H
#define ONETIME_H

#include "Appointment.h"
#include "Date.h"

class Onetime : public Appointment
{
public:
   Onetime();
   Onetime(string desc, Date d, Time s, Time e);
   virtual bool occurs_on(int year, int month, int day) const;
private:
   Date when;
};

#endif