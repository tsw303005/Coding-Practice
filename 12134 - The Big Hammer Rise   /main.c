#include <stdio.h>

int main() {
  int a, b, c, d;
  scanf("%d.%d %d.%d", &a, &b, &c, &d);
  
  int ans = (a * 100 + b) * (c * 100 + d);
  printf("%d.%.04d\n", ans / 10000, ans % 10000);

  return 0;
}