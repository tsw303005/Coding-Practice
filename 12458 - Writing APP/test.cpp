#include <iostream>
#include <cstring>

using namespace std;

int flag = 0;
short map[1005][1005][1000] = {0};
string str;

int judge(int left, int right, int m) {
  if (m < 0) return 0;
  else if (left >= right) return 1;

  if (map[left][right][m] != -1) return map[left][right][m];
  else {
    int leftRun, rightRun;
    if (str[left] == str[right]) map[left+1][right-1][m] = judge(left+1, right-1, m);
    leftRun = map[left+1][right][m-1] = judge(left+1, right, m-1);
    rightRun = map[left][right-1][m-1] = judge(left, right-1, m-1);
    return (leftRun || rightRun || map[left+1][right-1][m]);
  }
}

void init(int n, int k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int l = 1; l <= k; l++) {
        map[i][j][l] = -1;
      }
    }
  }
}

int main() {

  int n, k;

  cin >> n >> k;
  cin >> str;
  init(n, k);

  map[0][n-1][k] = judge(0, n-1, k);

  if (map[0][n-1][k] == 1) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}