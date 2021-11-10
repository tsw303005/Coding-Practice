#include "function.h"
#include <math.h>

long long int const mod = 880301;

special_power::special_power(int n) {
  this->n = n;
}

int special_power::fpow(int x) {
  long long int ans = 1;
  long long int tmp = (long long int)x;
  int run = this->n;
  while (run >= 1) {
    if (run % 2 == 1) {
      ans *= tmp;
      ans %= mod;
    }
    run /= 2;
    tmp = pow(tmp, 2);
    tmp %= mod;
  }
  return ans;
}

int special_power::fpow(int x, int m) {
  long long int ans = 1;
  long long int tmp = (long long int)x;
  int run = this->n;
  while (run >= 1) {
    if (run % 2) {
      ans *= tmp;
      ans %= m;
    }
    run /= 2;
    tmp = pow(tmp, 2);
    tmp %= m;
  }
  return ans;
}

int special_power::fpow() {
  long long int ans = 1;
  long long int tmp = 2;
  int run = this->n;
  while (run >= 1) {
    if (run % 2) {
      ans *= tmp;
      ans %= mod;
    }
    run /= 2;
    tmp = pow(tmp, 2);
    tmp %= mod;
  }
  return ans;
}

string special_power::fpow(string s) {
  string ans = "";
  for (auto p : s) {
    for (int i = 0; i < this->n; i++) ans.push_back(p);
  }
  return ans;
}

string special_power::fpow(string s, int m) {
  int count = 0;
  string ans = "";
  for (auto p : s) {
    for (int i = 0; i < this->n; i++) {
      if (count == m) return ans;
      ans.push_back(p);
      count += 1;
    }
  }
  return ans;
}