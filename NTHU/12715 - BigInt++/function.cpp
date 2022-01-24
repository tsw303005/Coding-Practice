#include "function.h"
#include <string.h>

namespace oj {
    BigInt::BigInt(char *c) {
        this->_val = new char[2000];
        strcpy(this->_val, c);
    }

    BigInt::~BigInt() {
        delete this->_val;
    }

    BigInt& BigInt::operator++() {
    }
}