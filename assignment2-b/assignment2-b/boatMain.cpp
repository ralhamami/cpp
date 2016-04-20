#include "utility.h"
using namespace std;

int main() {
	int capacity;
	//Collect boat cap data
	cout << "Enter the boat's capacity: ";
	cin >> capacity;
	int size;
	//Collect num of items data
	cout << "Enter the number of items: ";
	cin >> size;
	//Dynamically allocate the space in memory for weight based on size
	int *weight;
	weight = new int[size];
	//Dynamically allocate the space in memory for values based on size.
	int *values;
	values = new int[size];

	//Loop to collect all necessary data
	for (int i = 0; i < size; i++){
		cout << "Enter the weight for item #" << i + 1 << ": ";
		cin >> weight[i];
		cout << "Enter the value for item #" << i + 1 << ": ";
		cin >> values[i];
	}
	//Dynamically allocate the space in memory for items based on the boats capacity + 1
	int *items;
	items = new int[capacity + 1];

	//Set the max value variable to the result of solve_from
	int val = solve_from(weight, values, items, size, capacity);
	//Call the print solution function to get the formatted output
	printSolution(items, weight, values, capacity, size);

	cout << endl;

	system("pause");
	return 0;
}