#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
private:
  int id;
  int time;
public:
  Customer(int i, int t);
  int getId();
  int getTime();
};

#endif 
