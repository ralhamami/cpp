#include <iostream>
#include <iomanip>
using namespace std;

#include "Car.h"

Car::Car()
  {model = "Empty";
   year = 0;
   price = 0;
  }

Car::Car(string a, int b, int c)
  {model = a;
   year = b;
   price = c;
  }

bool Car::operator!=(Car right)
   {if (this->price == right.price)
       return false;
    return true;
   }

bool Car::operator==(Car right)
   {if (this->price==right.price)
       return true;
    return false;
   }
    
bool Car::operator>(Car right)
   {if (this->price > right.price)
       return true;
    return false;
   } 
bool Car::operator<(Car right)
   {if (this->price < right.price)
       return true;
    return false;
   }

bool Car::operator<=(Car right)
   {if (this->price <= right.price)
       return true;
    return false;
   }

bool Car::operator>=(Car right)
   {if (this->price >= right.price)
       return true;
    return false;
   }


ostream& operator<<(ostream& out, const Car& value)
   {out << "Model: " << setw(10) << left << value.model << setw(2) << right
        << "Year: " << value.year << fixed << setprecision(2) << setw(8) << "Price: " << value.price;
    return out;
   }
