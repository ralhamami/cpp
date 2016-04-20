//This program uses backtracking recursion to find the best
//combination of items weights/values
#include <iostream>
using namespace std;

//Calculate the number of occurrences for each weight class, and print the solution
void printSolution(int items[], int weights[], int values[], int capacity, int size) {
	int k = capacity;
	int *instances;
	instances = new int[size];
	//Declare int counter to use throughout
	int i;
	//Initialize all values in the instances array to 0
	for (i = 0; i<size; i++)
		instances[i] = 0;
	//
	while (k >= 0) {
		int x = items[k];
		if (x == -1)
			break;
		instances[x] += 1;
		k -= weights[items[k]];
	}
	//Declare variables to store total value and weight for printing the solution
	int totWeight = 0, totValue = 0;
	for (i = 0; i < size; i++){
		totWeight += weights[i] * instances[i];
		totValue += values[i] * instances[i];
	}
	cout << "\nThe solution contains:\n";
	//Loop through to print the solution based on number of instances
	//of each item
	for (i = 0; i < size; i++)
		if (instances[i] > 0)
			cout << instances[i] << " Item " << i + 1 << endl;
	cout << "\nTotal Weight: ";
	//Loop through to print out the weight for each instances
	//except for those with 0 instances.
	for (i = 0; i < size; i++){
		if (instances[i] > 0){
			cout << instances[i] << " * " << weights[i] << " ";
			//To comply with assignment specified formatting
			if (i != size - 1)
				cout << "+ ";
			else
				cout << "= ";
		}
	}
	cout << totWeight << "\nTotal Value: ";
	//Loop through to print out the value for each instances
	//except for those with 0 instances.
	for (i = 0; i < size; i++){
		if (instances[i] > 0){
			cout << instances[i] << " * " << values[i] << " ";
			if (i != size - 1)
				cout << "+ ";
			else
				cout << "= ";
		}
	}
	cout << totValue << endl;
}

int solve_from(int weight[], int values[], int items[], int n, int capacity) {
	//Dynamically allocate space in memory for the boat variable based on boat cap + 1
	int *boat;
	boat = new int[capacity + 1];
	boat[0] = 0;
	items[0] = -1;
	int i, j;
	for (j = 1; j <= capacity; j++) {
		items[j] = items[j - 1];
		int max = boat[j - 1];
		for (i = 0; i<n; i++) {
			int x = j - weight[i];
			if (x >= 0 && (boat[x] + values[i]) > max) {
				max = boat[x] + values[i];
				items[j] = i;
			}
			boat[j] = max;
		}
	}
	return boat[capacity];
}