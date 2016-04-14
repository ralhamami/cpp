#include "Time.h"

/**
   Computes the correct remainder for negative dividend
   @param a - an integer
   @param n - an integer > 0
   @return the mathematically correct remainder r such that
   a - r is divisible by n and 0 <= r and r < n
*/
int remainder(int a, int n)
{  
   if (a >= 0)
   {
      return a % n;
   }
   else
   {
      return n - 1 - (-a - 1) % n;
   }
}

Time::Time(int hour, int min, int sec)
{
   time_in_secs = 60L * 60 * hour + 60 * min + sec;
}

Time::Time()
{  
   time_in_secs = 0;
}

int Time::get_hours() const
{  
   return time_in_secs / (60 * 60);
}

int Time::get_minutes() const
{  
   return (time_in_secs / 60) % 60;
}

int Time::get_seconds() const
{  
   return time_in_secs % 60;
}

int Time::seconds_from(Time t) const
{  
   return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s)
{  
   const int SECONDS_PER_DAY = 60 * 60 * 24;
   time_in_secs = remainder(time_in_secs + s, SECONDS_PER_DAY);
}