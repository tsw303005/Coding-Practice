#include <stdio.h>

int main() {
  int n, k;
  unsigned long ans = 0, run = 0;

  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; i++) {
    run *= 10;
    run += n;
    ans += run;
  }
  printf("%lu\n", ans);

  return 0;
}