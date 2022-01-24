#include <iostream>
#include <string>

using namespace std;


int main() {
  string str;
  cin >> str;
  int len = str.length();
  int prev, next, ans;
  prev = 0;
  next = 1;
  ans = 0;
  for (int i = 1; next < len; i++) {
    //cout << i << endl;
    if (isalpha(str[prev]) && str[prev] == str[next]) {
      str[next] = '^';
      ans += 1;
    }
    if (i % 2 == 1) next += 1;
    if (i % 2 == 0) prev += 1;
  }
  cout << ans << endl;
  return 0;
}