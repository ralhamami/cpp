#ifndef BOATCONFIG_H
#define BOATCONFIG_H

class Boatconfig{
	const int n;
	const int W;
	//Array size will be changed dynamically
	int* wt = new int[3];
	int* val = new int[3];

	public:
	Boatconfig(int n);
	const int get_n();
	void set_n(int n);
	int getW();
	void setW(int W);
	int* getWt();
	void setWt(int index, int Wt);
	int* getVal();
	void setVal(int index, int val);
};

#endif