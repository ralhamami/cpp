#include <iostream>
using namespace std;

#include "Appointment.h"
#include "Daily.h"
#include "Onetime.h"
#include "Monthly.h"

const int SCHEDULE_SIZE = 7;

int main()
{
   Appointment* schedule[SCHEDULE_SIZE];
   schedule[0]= new Onetime("see the dentist", Date(2013, 9, 4), Time(11, 30, 0), Time(12, 30, 0));
   schedule[1]= new Daily("brush my teeth", Time(8,0,0), Time(8, 5, 0));
   schedule[2]= new Monthly("clean the house", 30, Time(14,0,0), Time(16, 0, 0));
   schedule[3] = new Onetime("program04 due", Date(2013, 6, 15), Time(15, 0, 0), Time(15, 10, 0));
   schedule[4] = new Monthly("pay electric bill", 15, Time(14,0,0), Time(16, 0, 0));
   schedule[5] = new Monthly("pay credit card", 30, Time(17,0,0), Time(18, 0, 0));
   schedule[6] = new Onetime("program05 due", Date(2013, 6, 20), Time(15, 0, 0), Time(15, 10, 0));


   cout << "Enter year month day: ";
   int year;
   int month;
   int day;
   cin >> year >> month >> day;

   cout << "You have these appointments: " << "\n";
   bool no_appointments = true;
   for (int i = 0; i < SCHEDULE_SIZE; i++)
   {
      if (schedule[i]->occurs_on(year, month, day)) // polymorphism is used !!!
      {
         schedule[i]->print();
         no_appointments = false;
      }
   }
   
   if (no_appointments) {
         cout << "You have no appointments on " << year << " " << month << " " << day << "." << endl;
   }
   return 0;
}
