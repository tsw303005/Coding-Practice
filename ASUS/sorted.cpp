/* 
n 個選民, m 個候選人
候選人得到超過 n/2 的票數當選
input 是 sorted 的 array 代表 n 個選民分別投過誰
請問誰當選
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int a) {
  if (a == -1) cout << "No winner\n";
  else cout << "The winner is: " << a << endl;
}

void call(int n, int m, vector<int> vec) {
  if (n == 1) {
    print(vec[0]);
    return;
  }
  int middle = n / 2;
  int num;
  if (n % 2) num = middle - 1;
  else num = middle;
  int left = lower_bound(vec.begin(), vec.end(), vec[num]) - vec.begin();
  int right = upper_bound(vec.begin(), vec.end(), vec[num]) - vec.begin();
  if (right == n) right -= 1;
  if (right - left + 1 > middle) print(vec[num]);
  else print(-1);
}

int main() {
  int n, m;
  n = 6;
  m = 5;
  call(n, m, vector<int>{1, 1, 1, 3, 3, 3}); // no
  call(n, m, vector<int>{1, 2, 4, 4, 4, 4}); // 4
  call(n, m, vector<int>{1, 1, 1, 1, 1, 1}); // 1
  call(n, m, vector<int>{1, 2, 3, 4, 5, 6}); // no
  call(n, m, vector<int>{1, 1, 1, 1, 2, 3}); // 1

  return 0;
}