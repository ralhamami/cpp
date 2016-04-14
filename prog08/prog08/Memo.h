#ifndef MEMO_H
#define MEMO_H

#include <string>
using namespace std;

class Memo {
public:
	Memo();
    Memo(string message);
    string getMessage() const;
private:
    string message;
};

#endif
