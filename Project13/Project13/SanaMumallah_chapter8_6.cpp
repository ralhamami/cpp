#include <iostream>
#include <string>
using namespace std;

//Changed the data type for parameter to string, as well as the minValue variable.
//Also changed the if condition to the compare() function of string < 0, since a value
//less than 0 is what is returned if the left string is "less than" the right string.
void selectionSort(string array[], int size){
	int startScan, minIndex;
	string minValue;
	for (startScan = 0; startScan < (size - 1); startScan++){
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++){
			if (array[index].compare(minValue)<0){
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

int main()
{
const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
"Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
"James, Jean", "Weaver, Jim", "Pore, Bob",
"Rutherford, Greg", "Javens, Renee",
"Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };

// Insert your code to complete this program
selectionSort(names,NUM_NAMES);
for (int i=0; i<NUM_NAMES; i++){
	cout << names[i] << endl;
}
	
system("pause");
return 0;
}