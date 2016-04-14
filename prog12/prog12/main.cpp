#include <iostream>
#include "List.h"
#include "Student.h"
using namespace std;

int main() {

  cout << "\n*** String List Test ***" << endl;

  List<string> list;
  list.push_back("zero");
  list.push_back("one");
  list.push_back("two");
  list.push_back("three");
  list.push_back("four");
  list.push_back("five");
  list.print();
  
  list.insert(1, "inserted at position 1");
  list.insert(0, "inserted at position 0");
  list.insert(4, "inserted at position 4");
  list.print();

  cout << "removing at indexes 3, 0" << endl;
  list.remove(3);
  list.remove(0);
  list.print();

  list.insert(2, "inserted at position 2");
  list.print();

  cout << "five is at index " << list.indexOf("five") << endl;
  cout << "two is at index " << list.indexOf("two") << endl;

  cout << "\n*** Double List Test ***" << endl;

  List<double> list3;
  list3.push_back(0.1);
  list3.push_back(1.2);
  list3.push_back(2.3);
  list3.push_back(3.4);
  list3.push_back(4.5);
  list3.push_back(5.6);
  //Testing push_back()
  list3.print();
  //Testing insert()
  list3.insert(1, 6.7);
  list3.insert(0, 7.8);
  list3.insert(4, 8.9);
  list3.print();
  //Testing remove()
  cout << "removing at indexes 3, 0" << endl;
  list3.remove(3);
  list3.remove(0);
  list3.print();

  list3.insert(2, 9.1);
  list3.print();
  //Testing indexOf()
  cout << "5.6 is at index " << list3.indexOf(5.6) << endl;
  cout << "2.3 is at index " << list3.indexOf(2.3) << endl;
  //Routinely Testing get(), isEmpty(), size() 
  //to have fully tested all class functions
  cout << list3.get(2) << " is at index 2" << endl;
  cout << "Student List is Empty (0=False, 1=True)? : " << list3.isEmpty() << endl;
  cout << "Student List Size is: " << list3.size() << endl;
   
  cout << "\n*** Student List Test ***" << endl;

  List<Student> list2;
  //Testing push_back()
  list2.push_back(Student("Rayan",123));
  list2.push_back(Student("Sana",456));
  list2.push_back(Student("Jack",567));
  list2.push_back(Student("David",678));
  list2.push_back(Student("George",789));
  list2.push_back(Student("Harry",890));
  //Testing print()
  list2.print();
  //Testing insert()
  list2.insert(1,Student("Timothy",321));
  list2.insert(0,Student("Alex",543));
  list2.insert(4,Student("Dan",654));
  list2.print();
  //Testing remove()
  cout << "Removing at indexes 3, 0" << endl;
  list2.remove(3);
  list2.remove(0);
  list2.print();

  list2.insert(2, Student("Jacob",765));
  list2.print();
  //Testing indexOf()
  cout << "Harry is at index " << list2.indexOf(Student("Harry",890)) << endl;
  cout << "Jack is at index " << list2.indexOf(Student("Jack",567)) << endl;
  //Routinely Testing get(), isEmpty(), size() 
  //to have fully tested all class functions
  cout << list2.get(2) << " is at index 2" << endl;
  cout << "Student List is Empty (0=False, 1=True)? : " << list2.isEmpty() << endl;
  cout << "Student List Size is: " << list2.size() << endl;
return 0;
}
