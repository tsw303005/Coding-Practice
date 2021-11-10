#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int games[1005];
int bills;

int main() {
  int n, m, ans, count;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%d", &games[i]);
  }

  ans = 0;
  count = 0;

  for (int i = 0; i < m; i++) {
    scanf("%d", &bills);

    while (bills < games[count] && count < n) {
      count += 1;
    }

    if (count >= n) break;
    count += 1;
    ans += 1;
  }

  printf("%d\n", ans);
  return 0;
}