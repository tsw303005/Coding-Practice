/*
每個數字對應到一個英文字母
1 -> A, 2 -> B, 3 -> C, 4 -> D, ..., 25->Y, 26 -> Z
input 是一串數字 ex: 1234
output: ABCD, LCD, AWD (3種可能)

給定一串 input, output 出有幾種可能
*/

#include <iostream>

using namespace std;

int main() {
  int arr[3] = {0};
  int num;
  bool flag = true;

  string str;
  string str_aft;
  cin >> str;

  // check this string is valid
  for (int i = 0; i < str.length() && flag; i++) {
    if (str[i] == '0' && i == 0) flag = false;
    else if (str[i] == '0' && (str[i-1] != '1' && str[i-1] != '2')) flag = false;
    else if (str[i] == '0' && (str[i-1] == '1' || str[i-1] == '2')) str_aft.pop_back(), str_aft.push_back('@');
    else str_aft.push_back(str[i]);
  }

  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 1;
  cout << str_aft << endl;
  for (int i = 1; i < str_aft.length() && flag; i++) {
    if (str_aft[i] != '@' && str_aft[i-1] != '@') {
      num = str_aft[i] - '0' + (str[i-1] - '0') * 10;
      if (num <= 26) arr[2] += arr[0];
    }
    arr[0] = arr[1];
    arr[1] = arr[2];
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
  }
  if (flag) cout << arr[2] << endl;
  else cout << "No Answer" << endl;
  return 0;
}
