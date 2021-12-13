/*
每個數字對應到一個英文字母
1 -> A, 2 -> B, 3 -> C, 4 -> D, ..., 25->Y, 26 -> Z
input 是一串數字 ex: 1234
output: ABCD, LCD, AWD (3種可能)

給定一串 input, output 出有幾種可能
*/

// WA 程式碼

#include <iostream>

using namespace std;

int main() {
  int arr[3] = {0};
  int num[2];
  string str;
  
  cin >> str;
  arr[0] = 1;
  for (int i = 0; i < str.length(); i++) {
    if (i == 0 && arr[i] == '0') break;
    else if (i == 0) arr[2] = 1;
    else { 
      num[0] = str[i] - '0';
      num[1] = (str[i-1] - '0') * 10 + str[i] - '0';
      if (str[i] == '0' && str[i-1] == '0') {
        arr[2] = 0;
        break;
      } else if (str[i] == '0' && num[1] > 26) {
        arr[2] = 0;
        break;
      } else if (str[i] == '0' && num[1] <= 26){
        arr[2] = arr[1];
      } else if (str[i] == '0') {
        arr[2] = arr[0];
      } else if (str[i-1] == '0') {
        arr[2] = 0;
      } else {
        arr[2] = (arr[1] != 0) ? arr[1] : arr[0];
        if (num[1] <= 26) arr[2] += arr[0];
      }
    }
    arr[0] = arr[1];
    arr[1] = arr[2];
    //cout << arr[2] << endl;
  }
  cout << arr[2] << endl;

  return 0;
}