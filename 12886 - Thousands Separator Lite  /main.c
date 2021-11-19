#include <stdio.h>

int main() {
  int a, b, c, d, e, f;
  int ans;
  scanf("%d,%d,%d", &a, &b, &c);
  scanf("%d,%d,%d", &d, &e, &f);

  ans = (a + d) * 1000000 + (b + e) * 1000 + c + f;
  printf("%d\n", ans);

  return 0;
}