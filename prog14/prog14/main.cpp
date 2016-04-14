#include <iostream>
#include "BST.h"
#include "Student.h"
using namespace std;

template <class T>
void visit(T data);

int main() {

  {cout << "\n*** Binary Search Tree Test DOUBLE ***" << endl;
  
  //TEST CONSTRUCTOR
  BST<double> tree1;
  
  //TEST INSERT()
  tree1.insert(20.2);
  tree1.insert(30.1);
  tree1.insert(25);
  tree1.insert(10.9);
  tree1.insert(5);
  tree1.insert(15);
  tree1.insert(12);
  tree1.insert(25.3);

  //TEST INORDER()
  tree1.inOrder(visit);

  //TEST FINDMIN() "SHOULD RETURN 5"
  cout << "min= " << tree1.findMin() << endl;

  //TEST GETNODECOUNT() "SHOULD RETURN 8"
  cout << "# of nodes = " << tree1.getNodeCount() << endl;
  
  //TEST GETLEAFCOUNT() "SHOULD RETURN 3 (5, 12, 25.3)"
  cout << "# of leaves = " << tree1.getLeafCount() << endl;
   
  //TEST GETHEIGHT() "SHOULD RETURN 4"
  cout << "height = " << tree1.getHeight() << endl;

  //TEST SEARCH()
  if (tree1.search(10)) cout << "found 10" << endl;
  else cout << "10 not found" << endl;

  if (tree1.search(12)) cout << "found 12" << endl;
  else cout << "12 not found" << endl;

  //TEST REMOVE()
  tree1.remove(5);
  cout << "\nafter deleting 5" << endl;
  tree1.inOrder(visit);

  tree1.remove(15);
  cout << "\nafter deleting 15" << endl;
  tree1.inOrder(visit);

  tree1.remove(25);
  cout << "\nafter deleting 25" << endl;
  tree1.inOrder(visit);

  tree1.remove(12);
  cout << "\nafter deleting 12" << endl;
  tree1.inOrder(visit);

  //TEST GETNODECOUNT() "SHOULD RETURN 4"
  cout << "# of nodes = " << tree1.getNodeCount() << endl;
  
  //TEST GETLEAFCOUNT() "SHOULD RETURN 2 (10.9, 25.3)"
  cout << "# of leaves = " << tree1.getLeafCount() << endl;

  //TEST GETHEIGHT() "SHOULD RETURN 3"
  cout << "height = " << tree1.getHeight() << endl;

  //TEST DESTRUCTOR
  cout << "Expecting Destructor: ";
  }

  {cout << "\n*** Binary Search Tree Test STRING ***" << endl;
  
  //TEST CONSTRUCTOR
  BST<string> tree11;

  //TEST INSERT()
  tree11.insert("fgh");
  tree11.insert("abc");
  tree11.insert("bcd");
  tree11.insert("ghi");
  tree11.insert("cde");
  tree11.insert("def");
  tree11.insert("ijk");
  tree11.insert("efg");
  tree11.insert("hij");

  //TEST INORDER()
  tree11.inOrder(visit);

  //TEST FINDMIN() "SHOULD RETURN ABC"
  cout << "min= " << tree11.findMin() << endl;

  //TEST GETNODECOUNT() "SHOULD RETURN 9"
  cout << "# of nodes = " << tree11.getNodeCount() << endl;
  
  //TEST GETLEAFCOUNT() "SHOULD RETURN 2 (EFG, HIJ)"
  cout << "# of leaves = " << tree11.getLeafCount() << endl;
  
  //TEST GETHEIGHT() "SHOULD RETURN 6"
  cout << "height = " << tree11.getHeight() << endl;

  //TEST SEARCH()
  if (tree11.search("abc")) cout << "found abc" << endl;
  else cout << "abc not found" << endl;

  if (tree11.search("bcd")) cout << "found bcd" << endl;
  else cout << "bcd not found" << endl;


  //TEST REMOVE()
  tree11.remove("cde");
  cout << "\nafter deleting cde" << endl;
  tree11.inOrder(visit);

  tree11.remove("def");
  cout << "\nafter deleting def" << endl;
  tree11.inOrder(visit);

  tree11.remove("efg");
  cout << "\nafter deleting efg" << endl;
  tree11.inOrder(visit);

  tree11.remove("hij");
  cout << "\nafter deleting hij" << endl;
  tree11.inOrder(visit);

  //TEST GETNODECOUNT() "SHOULD RETURN 5"
  cout << "# of nodes = " << tree11.getNodeCount() << endl;
  
  //TEST GETLEAFCOUNT() "SHOULD RETURN 2 (ABC, HIJ)"
  cout << "# of leaves = " << tree11.getLeafCount() << endl;

  //TEST GETHEIGHT() "SHOULD RETURN 3"
  cout << "height = " << tree11.getHeight() << endl;

  //TEST DESTRUCTOR
  cout << "Expecting Destructor: ";
 }


  {cout << "\n*** Binary Search Tree Test STUDENT ***" << endl;
  
  //TEST CONSTRUCTOR
  BST<Student> tree;

  //TEST INSERT()
  tree.insert(Student("Rayan",123,3.8));
  tree.insert(Student("Sana",234,4.0));
  tree.insert(Student("Sabiel",345,3.7));
  tree.insert(Student("Samer",456,3.5));
  tree.insert(Student("Jackie",567,3.4));
  tree.insert(Student("Zee",678,3.3));
  tree.insert(Student("Erin",789,3.2));
  tree.insert(Student("Pepper",890,3.1));

  
  //TEST INORDER()
  tree.inOrder(visit);

  //TEST FINDMIN()
  cout << "min= " << tree.findMin() << endl;

  //TEST GETNODECOUNT() "SHOULD RETURN 8"
  cout << "# of nodes = " << tree.getNodeCount() << endl;

  //TEST GETLEAFCOUNT() "SHOULD RETURN 2 (3.1, 4.0)"
  cout << "# of leaves = " << tree.getLeafCount() << endl;

  //TEST GETHEIGHT() "SHOULD RETURN 7"
  cout << "height = " << tree.getHeight() << endl;

  //TEST SEARCH()
  if (tree.search(Student("Rayan",123,3.8))) cout << "found Rayan" << endl;
  else cout << "Rayan not found" << endl;
  if (tree.search(Student("Sana",234,4.0))) cout << "found Sana" << endl;
  else cout << "Sana not found" << endl;

  //TEST REMOVE()
  tree.remove(Student("Rayan",123,3.8));
  cout << "\nafter deleting Rayan" << endl;
  tree.inOrder(visit);

  tree.remove(Student("Sana",234,4.0));
  cout << "\nafter deleting Sana" << endl;
  tree.inOrder(visit);

  tree.remove(Student("Sabiel",345,3.7));
  cout << "\nafter deleting Sabiel" << endl;
  tree.inOrder(visit);

  tree.remove(Student("Samer",456,3.5));
  cout << "\nafter deleting Samer" << endl;
  tree.inOrder(visit);

  //TEST GETNODECOUNT() "SHOULD RETURN 4"
  cout << "# of nodes = " << tree.getNodeCount() << endl;
  
  //TEST GETLEAFCOUNT() "SHOULD RETURN 1 (3.1)"
  cout << "# of leaves = " << tree.getLeafCount() << endl;

  //TEST GETHEIGHT() "SHOULD RETURN 4"
  cout << "height = " << tree.getHeight() << endl;

  //TEST DESTRUCTOR
  cout << "Expecting Destructor: ";
 }
  
  return 0;
}

template <class T>
void visit(T data) {
  cout << data << endl;
}
