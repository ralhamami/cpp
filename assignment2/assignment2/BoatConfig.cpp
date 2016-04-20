#include "Boatconfig.h"

Boatconfig::Boatconfig(int n){
	this->n = n;
	//wt = new int[n];
	//val = new int[n];
}

const int Boatconfig::get_n(){
	return n;
}

void Boatconfig::set_n(int n){
	this->n = n;
}

int Boatconfig::getW(){
	return W;
}

void Boatconfig::setW(int W){
	this->W = W;
}

int* Boatconfig::getWt(){
	return wt;
}

void Boatconfig::setWt(int index, int wt){
	this->wt[index] = wt;
}

int* Boatconfig::getVal(){
	return val;
}

void Boatconfig::setVal(int index, int val){
	this->val[index] = val;
}