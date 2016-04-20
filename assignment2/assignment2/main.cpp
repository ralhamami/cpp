#include <iostream>
#include "Boatconfig.h"
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int solve_from(Boatconfig config)
{
	const int n = config.get_n() + 1;
	const int W = config.getW() + 1;
	int i, w;
	int** K = new int*[n];
	for (int i = 0; i < n; i++)
		K[i] = new int[W];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (config.getWt[i - 1] <= w){
				int index1 = i - 1;
				int index2 = w - config.getWt()[i - 1];
				int value1 = (config.getVal()[index1]) + (K[index1][index2]);
				K[i][w]
					= max(value1 , K[index1][w]);
			}
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	cout << "Enter the number of items in a Knapsack:";
	int n;
	//int W;
	cin >> n;
	//int *val = new int[n];
    //int *wt = new int[n];
	Boatconfig boatconfig(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter value and weight for item " << i << ":";
		cin >> boatconfig.getVal[i];
		cin >> boatconfig.getWt[i];
	}



	//    int val[] = { 60, 100, 120 };
	//    int wt[] = { 10, 20, 30 };
	//    int W = 50;
	cout << "Enter the capacity of knapsack";
	cin >> boatconfig.getW;
	cout << solve_from(boatconfig);

	return 0;
}