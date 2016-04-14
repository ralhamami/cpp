#ifndef MONTHLY_H
#define MONTHLY_H

#include "Appointment.h"

class Monthly : public Appointment
{
public:
   Monthly();
   Monthly(string desc, int d, Time s, Time e);
   virtual bool occurs_on(int year, int month, int day) const;
private:
   int day;
};

#endif