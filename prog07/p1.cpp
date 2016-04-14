#include <iostream>
using namespace std;

void sort(int *, int);
int smallest(int *, int);
void swap(int &, int &);
void print(int *, int);
int main() {

  int a[] = {5, 4, 1, 9, 8, 3, 11, 2, 7, 6, 4};
  int b[] = {46, 10, 68, 57, 20, 31};
  sort(a, 11);
  sort(b, 6);
  print(a, 11);
  print(b, 6);
  return 0;
}

void sort(int *p, int arrSize) {
  if (arrSize == 0 || arrSize == 1)
    return;
  int i = smallest(p, arrSize);
  swap(p[0], p[i]);
  ++p;
  sort(p, arrSize-1);
   }
int smallest(int* p, int j)
   {int index=0, smallest=p[0];
    for(int i=0; i<j; i++)
       {if (smallest>p[i])
           {smallest = p[i];
            index = i;
           }
       }
    return index;
   }

void swap(int& a, int &b)
   {int temp = a;
    a = b;
    b = temp;
   }

void print(int *p, int arrSize)
   {for (int i = 0; i < arrSize; i++)
    cout << p[i] << " ";
    cout << endl;
   }
