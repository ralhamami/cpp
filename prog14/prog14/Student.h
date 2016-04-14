#ifndef STUDENT_H
#define STUDENT_H

class Student
   {private:
    string name;
    int id;
    double gpa;
    public:
    Student();
    Student(string a, int b, double c);
    bool operator!=(Student right);
    bool operator==(Student right);
    bool operator>(Student right);
    bool operator<(Student right);
    friend ostream& operator<<(ostream& out, const Student& value);
   };    

#endif
