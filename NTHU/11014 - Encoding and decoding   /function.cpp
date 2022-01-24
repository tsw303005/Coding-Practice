#include "function.h"
#include <cstring>

using namespace std;
string tmp;
void RleCodec::encode()
{
    // Your code here
    string decode_str = "";
    tmp = this->code_str;
    int count = 1;
    for (int i = 1; i < this->code_str.length(); i++) {
        if (this->code_str[i] == this->code_str[i-1]) count += 1;
        else {
            if (count > 2) {
                decode_str += to_string(count);
                decode_str += this->code_str[i-1];
            } else if (count == 2) {
                decode_str += this->code_str[i-1];
                decode_str += this->code_str[i-1];
            } else {
                decode_str += this->code_str[i-1];
            }
            count = 1;
        }
        if (i == this->code_str.length()-1) {
            if (count > 2) decode_str += to_string(count);
            else if (count == 2) decode_str += this->code_str[this->code_str.length()-1];
            decode_str += this->code_str[this->code_str.length()-1];
        }
    }
    encoded = true;
    this->code_str = decode_str;
}

void RleCodec::decode()
{
   //No cheating : )
   this->encoded = false;
   this->code_str = tmp;
}