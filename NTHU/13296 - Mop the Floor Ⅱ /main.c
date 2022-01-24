#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int row[4] = {1, 0, -1, 0};
int col[4] = {0, -1, 0, 1};
int map[2501][2501] = {0};

int main() {
  int n, m;
  int r;
  int c;
  int time;
  int run = 0;
  int flag;
  int now = 0;

  scanf("%d %d", &n, &m);
  time = (n * m + 1) / 2;
  flag = (n * m) % 2;
  r = 0;
  c = m - 1;
  map[r][c] = 1;

  for (int i = 0; i < time; i++) {
    printf("%d %d\n", r, c);
    run = 0;
    while (run < 2 && i != time-1) {
      if (r + row[now] >= 0 && r + row[now] < n && c + col[now] >= 0 && c + col[now] < m && !map[r+row[now]][c+col[now]]) {
        run += 1;
        r = row[now] + r;
        c = col[now] + c;
        map[r][c] = 1;
      } else {
        now += 1;
        now %= 4;
      }
    }
  }
  
  return 0;
}