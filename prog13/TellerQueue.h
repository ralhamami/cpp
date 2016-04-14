#ifndef TELLERQUEUE_H
#define TELLERQUEUE_H

#include <queue>
using namespace std;
#include "Customer.h"

class TellerQueue : public queue<Customer> {
public:
    TellerQueue(int maxCapacity);
    bool full();
private:
    int maxCapacity;
};

#endif

