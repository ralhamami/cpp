#include<iostream>
using namespace std;

double power(int x, int n)
   {if (n==0) return 1;
    return power(x, n-1)*x;
   }

int main() 
   {int x, n; 
    cout << "Enter x(Base): "; // base 
    cin >> x; 
    cout << "Enter n(Power): "; // power 
    cin >> n; 
    cout << power(x, n) << endl; // compute xn
return 0; 
}
