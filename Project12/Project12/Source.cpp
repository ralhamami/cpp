#include <iostream>
//Found a solution online for calculating the minimum with <algorithm>
#include <algorithm>
using namespace std;

//getScore function
void getScore(double& score){
	//Start a static index number as a nice way to state which test 
	//score to enter between function calls
	static int index = 1;
	//Keep track of the number of passes the loop makes
	//in order to know when to print error
	int pass = 0;
	//do-While score entered is less than 0 or greater than 100
	do
	{
	//If the number of loop passes is greater than 0, 
	//that means the user entered an invalid number, so print error message
	//Post-increments pass in the first loop
	if (pass++ > 0)
		cout << "Error. Please enter a score between 0 and 100" << endl;
	//Ask to enter test score plust the current index
	cout << "Please enter score for test #"
		 << index << ": ";
	//Store it in reference variable score
	cin >> score;
	}while (score < 0 || score > 100);
	//Increment index
	index++;
}

//findLowest() function
double findLowest(double s1, double s2, double s3, double s4, double s5){
	//Uses min function in <algorithm>, but each call
	//returns another call to the function to eventually
	//find the smallest
	return min(min(s1,s2),min(min(s3,s4),s5));
}

//calcAverage() function
void calcAverage(double s1, double s2, double s3, double s4, double s5){
	//Create a variable to store the value returned by findLowest(), which will
	//be the lowest test score
	double lowest = findLowest(s1,s2,s3,s4,s5);
	//Print a statement stating lowest test score will be dropped
	cout << "Dropping lowest score, which is: " << lowest << "..." << endl;
	//Calculate average by adding all test scores, then subtracting the lowest
	//, then dividing that whole thing by 4 (not 5 since we dropped one)
	double average = (s1+s2+s3+s4+s5-lowest)/4;
	//Print out a statement of the average
	cout << "The test score average for the highest four exams is " 
		 << average << "%" << endl;
}

int main(){
	//Declare local variables for each test score
	double score1,score2,score3,score4,score5;

	//Call getScore() function for each test score
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	//Call calcAverage() function and pass it all 5 test scores
	//to return the correct average
	calcAverage(score1,score2,score3,score4,score5);

	system("pause");
}