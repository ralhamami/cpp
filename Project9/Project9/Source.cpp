#include <iostream>
using namespace std;

int main(){
	int choice;
	cout << "Enter a choice between 1 and 3" << endl;
	cin >> choice;

	switch(choice){
	case 1: cout << "You entered 1" << endl;
			break;
	case 2: cout << "You entered 2" << endl;
			break;
	case 3: cout << "You entered 3" << endl;
			break;
	default:cout << "You entered an invalid choice. Rerun and try again." << endl;
	}

	cout << endl << endl << "Here is an example of the conditional operator." << endl;
	cout << "Is 1 greater than 3?" << endl;
	// (condition) ? if true : if false;
	(1 > 3) ? cout << "true" << endl : cout << "false" << endl;

	system("PAUSE");
	return 0;
}