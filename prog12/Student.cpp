#include <iostream>
#include <iomanip>
using namespace std;

#include "Student.h"

Student::Student()
   {name = "empty";
    id = 111;
   }

Student::Student(string a, int b)
   {name = a;
    id = b;
   }

bool Student::operator!=(Student right)
   {if (this->name == right.name && this->id == right.id)
       return false;
    return true;
   }

ostream& operator<<(ostream& out, const Student& value)
   {out << "Name: " << setw(10) << left << value.name << setw(2) << right
        << "ID: " << value.id;
    return out;
   }
