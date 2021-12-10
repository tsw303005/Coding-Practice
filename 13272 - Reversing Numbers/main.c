#include <stdio.h>

int main() {
  unsigned int a, b;
  scanf("%d", &a);
  unsigned int tmp = a;
  b = 0;
  while (tmp > 0) b *= 10, b += tmp % 10, tmp /= 10;

  printf("%d\n", a + b);
  return 0;
}