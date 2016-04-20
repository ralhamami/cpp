#include <iostream>
#include <string>
using namespace std;

int main(){
	string username;
	cout << "Please enter the username:";
	cin >> username;

	//If the username equals smumallah,
	if (username=="smumallah"){
		//do this
		cout << "Welcome back Sana!" << endl;
	}
	//Otherwise,
	else
	{
		//do this
		cout << "Go to hell. You are not Sana!" << endl;
	}

	system("PAUSE");
	return 0;
}