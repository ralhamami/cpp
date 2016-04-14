#ifndef CAR_H
#define CAR_H

class Car
  {private:
   string model;
   int year;
   int price;
   public:
   Car();
   Car(string a, int b, int c);
   bool operator<(Car right);
   bool operator>(Car right);
   bool operator==(Car right);
   bool operator!=(Car right);
   bool operator<=(Car right);
   bool operator>=(Car right);
   friend ostream& operator<<(ostream& out, const Car& value);
  };
#endif
