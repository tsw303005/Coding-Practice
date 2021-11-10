#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[1005][1005] = {0};
int times[1005][1005] = {0};
char str[1005];

int judge(int left, int right, int m) {
  if (m < 0) return 0;
  else if (left >= right) return 1;

  if ((map[left][right] != -1 && times[left][right] >= m) || map[left][right] == 1) return map[left][right];
  else {
    int leftRun, rightRun;
    if (str[left] == str[right]) {
      map[left+1][right-1] = judge(left+1, right-1, m);
      times[left+1][right-1] = m;
      return map[left+1][right-1];
    } else {
      leftRun = map[left+1][right] = judge(left+1, right, m-1);
      times[left+1][right] = m-1;
      rightRun = map[left][right-1] = judge(left, right-1, m-1);
      times[left][right-1] = m-1;
      return (leftRun || rightRun);
    }
  }
}

void init(int n, int k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      map[i][j] = -1;
      times[i][j] = -1;
    }
  }
}

int main() {
  int n, k;

  scanf("%d%d", &n, &k);
  scanf(" %s", str);

  init(n, k);

  map[0][n-1] = judge(0, n-1, k);

  if (map[0][n-1] == 1 || n - 1 == k || n == k) printf("Yes\n");
  else printf("No\n");
  return 0;
}