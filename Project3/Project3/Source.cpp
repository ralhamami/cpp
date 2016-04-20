#include <iostream>
#include <string>
using namespace std;

int main(){
	string username;
	cout << "Please enter the username:";
	cin >> username;

	if (username=="smumallah"){
		cout << "Welcome back Sana!" << endl;
	}
	else if (username=="ralhamami"){
		cout << "Welcome back Rayan!" << endl;
	}
	else
	{
		cout << "Go to hell. You are not Sana or Rayan!" << endl;
	}

	system("PAUSE");
	return 0;
}