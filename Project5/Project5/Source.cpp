#include <iostream>
using namespace std;

/*This is where we left off
This is an example of flags.
It's basically a boolean value used as
the condiion in the if statement. A great
thing to remember about if statements is
the condition within the parentheses can
be anything that can be evaluated as true/false, anything.
Another thing to remember, is that numbers can be confitions
too. 0 is false and everything else is true.
*/

int main(){
	//Declare the boolean value and name it isValid
	bool isValid = false;
	int number;

	do{
		cout << "Enter a number between 1 and 100:" << endl;

		cin >> number;

		if (number >= 0 && number <= 100){
			isValid = true;
		}
	}while(isValid==false);

	system("PAUSE");
	return 0;
}