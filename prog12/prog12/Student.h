#ifndef STUDENT_H
#define STUDENT_H

class Student
   {private:
    string name;
    int id;
    public:
    Student();
    Student(string a, int b);
    bool operator!=(Student right);
    friend ostream& operator<<(ostream& out, const Student& value);
   };    

#endif
