#include "Customer.h"

Customer::Customer(int i, int t) {
  id = i;
  time = t;
}

int Customer::getId() {
  return id;
}

int Customer::getTime() {
  return time;
}

