#include <iostream>
#include <iomanip>
using namespace std;

#include "Student.h"

Student::Student()
   {name = "empty";
    id = 111;
    gpa = 0.0;
   }

Student::Student(string a, int b, double c)
   {name = a;
    id = b;
    gpa = c;
   }

bool Student::operator!=(Student right)
   {if (this->gpa == right.gpa)
       return false;
    return true;
   }

bool Student::operator==(Student right)
   {if (this->gpa==right.gpa)
       return true;
    return false;
   }
    
bool Student::operator>(Student right)
   {if (this->gpa > right.gpa)
       return true;
    return false;
   } 
bool Student::operator<(Student right)
   {if (this->gpa < right.gpa)
       return true;
    return false;
   }

ostream& operator<<(ostream& out, const Student& value)
   {out << "Name: " << setw(10) << left << value.name << setw(2) << right
        << "ID: " << value.id << fixed << setprecision(2) << setw(8) << "GPA: " << value.gpa;
    return out;
   }
