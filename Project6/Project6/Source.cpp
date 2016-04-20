#include <iostream>
using namespace std;

int main(){
	/*This is demonstrating logical operators.
	A logical operator is just AND, OR, or NOT.
	This is what they look like:
	AND: &&
	OR: ||
	NOT: !
	These are useful when you are using an if statement
	and the condition depends on multiple things, or
	if you want the opposite of the condition. For example,
	An "A" grade on a test would be between 90 and 100, so
	in other words you want to check if grade is less than or equal
	to 100 AND also greater than or equal to 90.
	*/

	//Declare an integer variable called grade
	int grade;

	cout << "Please enter your whole number grade:";
	cin >> grade;

	if (grade <= 100 && grade >= 90){
		cout << "Grade: A" << endl;
	}
	else if (grade >= 80){
		cout << "Grade: B" << endl;
	}
	else if (grade >= 70){
		cout << "Grade: C" << endl;
	}
	else if (grade >= 60){
		cout << "Grade: D" << endl;
	}
	else{
		cout << "Grade: F" << endl;
	}

	system("PAUSE");
	return 0;
}