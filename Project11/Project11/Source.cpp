#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getNumAccidents(string regionName){
	int num;
	cout << "How many auto accidents were reported"
		 << " in the " << regionName << " region in the"
		 << " last year?" << endl;
	if (cin >> num){
		return num;
	}
	else{
		return -1;
	}
}

void findLowest(int reg1, int reg2, int reg3, int reg4, int reg5){
	string lowest;

	if (reg1 < reg2 && reg1 < reg3 && reg1 < reg4 && reg1 < reg5){
		cout << "The lowest value is " << reg1 << " in the North region.\n";
	}
	else if (reg2 < reg1 && reg2 < reg3 && reg2 < reg4 && reg2 < reg5){
		cout << "The lowest value is " << reg2 << " in the South region.\n";
	}
	else if (reg3 < reg1 && reg3 < reg2 && reg3 < reg4 && reg3 < reg5){
		cout << "The lowest value is " << reg3 << " in the East region.\n";
	}
	else if (reg4 < reg1 && reg4 < reg2 && reg4 < reg3 && reg4 < reg5){
		cout << "The lowest value is " << reg4 << " in the West region.\n";
	}
	else{
		cout << "The lowest value is " << reg5 << " in the Central region.\n";
	}
}

int main(){
	int north = getNumAccidents("North");
	int south = getNumAccidents("South");
	int east = getNumAccidents("East");
	int west = getNumAccidents("West");
	int central = getNumAccidents("Central");

	findLowest(north, south, east, west, central);

	system("pause");
	return 0;
}