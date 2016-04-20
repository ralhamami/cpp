#include <iostream>
using namespace std;

int main(){
	int grade;
	cout << "Please enter your whole number grade:";
	cin >> grade;

	if (grade <= 100 && grade >= 90){
		cout << "Grade: A" << endl;
	}
	else if (grade < 90 && grade >= 80){
		cout << "Grade: B" << endl;
	}
	else if (grade < 80 && grade >= 70){
		cout << "Grade: C" << endl;
	}
	else if (grade < 70 && grade >= 60){
		cout << "Grade: D" << endl;
	}
	else if (grade < 60 && agrade >= 0){
		cout << "Grade: F" << endl;
	}
	else{
		cout << "That was an invalid grade entry. Rerun the program"
			"and enter a number between 0 and 100" << endl;
	}

	system("PAUSE");
	return 0;
}