#include <iostream>
using namespace std;

int main(){
	int choice;
	cout << "Please Enter Menu Number:\n"
		  << "1. Print Rayan\n"
		  << "2. Print Sana\n"
		  << "3. Add 2 Numbers\n";
	cin >> choice;

	if (choice == 1){
		cout << "Rayan" << endl;
	}
	else if (choice == 2){
		cout << "Sana" << endl;
	}
	else if (choice == 3){
		int num1, num2;
		cout << "Enter the 2 numbers you wish to add:";
		cin >> num1 >> num2;
		cout << "Sum is " << num1+num2 << endl;
	}

	system("PAUSE");
	return 0;
}