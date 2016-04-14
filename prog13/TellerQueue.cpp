#include "TellerQueue.h"

TellerQueue::TellerQueue(int maxCapacity) {
    this->maxCapacity = maxCapacity;
}

bool TellerQueue::full() {
    if (maxCapacity == size()) return true;
    else return false;
}

