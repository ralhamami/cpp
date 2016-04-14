#ifndef DATE_H
#define DATE_H

class Date
{
public:
   Date();
   Date(int y, int m, int d);
   void print() const;
   bool equals(Date other) const;
private:
   int day;
   int month;
   int year;
};

#endif