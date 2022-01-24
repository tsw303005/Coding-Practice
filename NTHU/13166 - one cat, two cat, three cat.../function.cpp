#include <iostream>
#include "function.h"

using namespace std;

big_number::big_number(string num) {
  this->num = num;
}

bool big_number::multiple_of_two() {
  int x = num[num.length()-1] - '0';
  if (x % 2 == 0) return true;
  else return false;
}

bool big_number::multiple_of_three() {
  int x = 0;
  for (auto i : num) x += i - '0';
  if (x % 3 == 0) return true;
  else return false;
}

bool big_number::multiple_of_four() {
  int x = 0;
  if (num.length() >= 2) x = num[num.length()-1] - '0' + 10* (num[num.length()-2] - '0');
  else x = num[num.length()-1] - '0';
  if (x % 4 == 0) return true;
  else return false;
}

bool big_number::multiple_of_five() {
  if (num[num.length()-1] == '0' || num[num.length()-1] == '5') return true;
  else return false;
}

bool big_number::multiple_of_six() {
  if (multiple_of_two() && multiple_of_three()) return true;
  else return false;
}

bool big_number::multiple_of_eight() {
  int x = 0;
  if (num.length() >= 3) x = num[num.length()-1] - '0' + 10* (num[num.length()-2] - '0') + 100 * (num[num.length()-3] - '0');
  else if (num.length() == 2) x = num[num.length()-1] - '0' + 10* (num[num.length()-2] - '0');
  else x = num[num.length()-1] - '0';
  if (x % 8 == 0) return true;
  else return false;
}

bool big_number::multiple_of_nine() {
  int x = 0;
  for (auto i : num) {
    x += i - '0';
  }
  if (x % 9 == 0) return true;
  else return false;
}

bool big_number::multiple_of_ten() {
  if (num[num.length()-1] == '0') return true;
  else return false;
}

bool big_number::multiple_of_eleven() {
  int len = num.length() - 1;
  int odd = 0;
  int even = 0;
  for (int i = 0; i <= len; i += 2) odd += num[i]-'0';
  for (int i = 1; i <= len; i += 2) even += num[i]-'0';
  if (abs(odd-even) % 11 == 0) return true;
  else return false;
}