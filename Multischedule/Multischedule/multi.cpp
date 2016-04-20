#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <queue>

using namespace std;

struct Process{
	int process_number;
	int total_time;
	int priority;
	int ttf;
	int slicesRemaining;
};

bool getState(bool empty[]){
	for (int i = 0; i < 16; i++){
		if (empty[i] == 0)
			return false;
	}
	return true;
}

int main(){
	
	int process_number[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int total_time_required[16] = { 6, 4, 8, 3, 8, 2, 4, 8, 7, 6, 3, 7, 3, 4, 7 };
	int priority[16] = { 1, 3, 1, 2, 4, 3, 5, 4, 1, 4, 1, 3, 2, 4, 1 };
	int time_to_finish[16];
	int slices_remaining[16];
	int running[16];
	bool empty[16];
	queue<Process> processes;
	queue<Process> running;


	cout << "Priority 1 " << endl;
	cout << "process  " << "total  " << "time to  " << "slices    " << "priority " << endl;
	cout << "number   " << "time   " << "finish   " << "remaining" << endl;
	
	for (int i = 0; i < 16; i++){
		if (priority[i] == 1) {
			time_to_finish[i] = total_time_required[i];
			slices_remaining[i] = time_to_finish[i];
			cout << setw(3) << process_number[i] << setw(8) << total_time_required[i] << setw(8)
				<< time_to_finish[i] << setw(10) << slices_remaining[i] << setw(10) << priority[i] << endl;
		}
	}
	
	cout << " " << endl;
	//printing out queue 2 at the start
	cout << "Priority 2 " << endl;
	cout << "process  " << "total  " << "time to  " << "slices    " << "priority " << endl;
	cout << "number   " << "time   " << "finish   " << "remaining" << endl;
	for (int i = 0; i < 16; i++){
		if (priority[i] == 2) {
			time_to_finish[i] = total_time_required[i];
			slices_remaining[i] = time_to_finish[i];
			cout << setw(3) << process_number[i] << setw(8) << total_time_required[i] << setw(8)
				 << time_to_finish[i] << setw(10) << slices_remaining[i] << setw(10) << priority[i] << endl;
		}
	}
	//printing out queue 3 at the start
	cout << " " << endl;
	cout << "Priority 3 " << endl;
	cout << "process  " << "total  " << "time to  " << "slices    " << "priority " << endl;
	cout << "number   " << "time   " << "finish   " << "remaining" << endl;
	for (int i = 0; i < 16; i++){
		if (priority[i] == 3) {
			time_to_finish[i] = total_time_required[i];
			slices_remaining[i] = time_to_finish[i];
			cout << setw(3) << process_number[i] << setw(8) << total_time_required[i] << setw(8)
				<< time_to_finish[i] << setw(10) << slices_remaining[i] << setw(10) << priority[i] << endl;
		}
	}
	//printing out queue 4 at the start
	cout << " " << endl;
	cout << "Priority 4 " << endl;
	cout << "process  " << "total  " << "time to  " << "slices    " << "priority " << endl;
	cout << "number   " << "time   " << "finish   " << "remaining" << endl;
	for (int i = 0; i < 16; i++){
		if (priority[i] == 4) {
			time_to_finish[i] = total_time_required[i];
			slices_remaining[i] = time_to_finish[i];
			cout << setw(3) << process_number[i] << setw(8) << total_time_required[i] << setw(8)
				<< time_to_finish[i] << setw(10) << slices_remaining[i] << setw(10) << priority[i] << endl;
		}
	}
	//printing out queue 5 at the start
	cout << " " << endl;
	cout << "Priority 5 " << endl;
	cout << "process  " << "total  " << "time to  " << "slices    " << "priority " << endl;
	cout << "number   " << "time   " << "finish   " << "remaining" << endl;
	for (int i = 0; i < 16; i++){
		if (priority[i] == 5) {
			time_to_finish[i] = total_time_required[i];
			slices_remaining[i] = time_to_finish[i];
			cout << setw(3) << process_number[i] << setw(8) << total_time_required[i] << setw(8)
				<< time_to_finish[i] << setw(10) << slices_remaining[i] << setw(10) << priority[i] << endl;
		}
	}
	//priting out queue 6 at the start
	cout << " " << endl;
	cout << "Priority 6 " << endl;
	cout << "process  " << "total  " << "time to  " << "slices    " << "priority " << endl;
	cout << "number   " << "time   " << "finish   " << "remaining" << endl;
	for (int i = 0; i < 16; i++){
		if (priority[i] == 6) {
			time_to_finish[i] = total_time_required[i];
			slices_remaining[i] = time_to_finish[i];
			cout << setw(3) << process_number[i] << setw(8) << total_time_required[i] << setw(8)
				<< time_to_finish[i] << setw(10) << slices_remaining[i] << setw(10) << priority[i] << endl;
		}
	}
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "====================================================================" << endl;
	cout << " " << endl;
	cout << " " << endl;

	//implement running process running
	while (!getState(empty)){
		for (int i = 0; i < 16; i++){
			if (priority[i] == 1){
				running[i] = 1;
			}
		}
		cout << "process running" << endl
			<< "  #   ps  tot  fin  slices     " << endl
			<< "               ish  remaining" << endl;

	}

	system("pause");
}