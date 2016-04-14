#include "Memo.h"

Memo::Memo() {
    message = "";
}

Memo::Memo(string message) {
    this->message = message;
}

string Memo::getMessage() const {
    return message;
}
