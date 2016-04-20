#include <iostream>
#include <string>
using namespace std;

int main(){
	string username;
	int age;
	cout << "Please enter the username:";
	cin >> username;
	cout << "Please enter your age:";
	cin >> age;



	if (username=="smumallah"){
		if (age == 22){
			cout << "Welcome back Sana!" << endl;
		}
		else{
			cout << "You are not the real Sana." << endl;
		}
	}
	else if (username=="ralhamami"){
		if (age == 27){
			cout << "Welcome back Rayan!" << endl;
		}
		else{
			cout << "You are not the real Rayan." << endl;
		}
	}
	else
	{
		cout << "Go to hell. You are not Sana or Rayan!" << endl;
	}
	system("PAUSE");
	return 0;
}