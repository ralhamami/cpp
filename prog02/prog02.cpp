#include <iostream>
using namespace std;

//Reverse fucntion
void reverse(double arr[], int size)
   {double temp, *p1 = arr, *p2 = &(arr[size-1]);
    for (int i=0; i < size/2; i++)
       {temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
       }
   }

//Main function for testing with 7, and then 10 elements
int main()
   {double array[] = {1,2,3,4,5,6,7};
    for (int i=0; i<sizeof(array)/sizeof(double); i++)
       {cout << array[i] << " ";
       }
    reverse(array, sizeof(array)/sizeof(double));
    cout << endl;
    for (int i=0; i<sizeof(array)/sizeof(double); i++)
       {cout << array[i] << " ";
       }
    cout << endl << endl;
    double array2[] = {10,9,8,7,6,5,4,3,2,1};
    for (int i=0; i<sizeof(array2)/sizeof(double); i++)
       {cout << array2[i] << " ";
       }
    reverse(array2, sizeof(array2)/sizeof(double));
    cout << endl;
    for (int i=0; i<sizeof(array2)/sizeof(double); i++)
       {cout << array2[i] << " ";
       }
    cout << endl;
   }


