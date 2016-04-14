#include <iostream>
using namespace std;

#include "BST.h"

int main()
  {int input = 1;
   BST<int> tree;
   while (input>0)
     {cout << "Enter a positive integer (0 or negative to quit) : ";
      cin >> input;
      if (input>0) tree.insert(input);
     }
   tree.traverseLevel();
   return 0;
  } 
