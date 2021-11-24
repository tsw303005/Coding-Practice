#include <stdio.h>

int main() {
  int d;
  float a, b, c, e;
  float ans;
  scanf("%f%f%f%d%f", &a, &b, &c, &d, &e);
  if (d == 0) ans = a / b * e + c;
  else ans = (ans - c) * b / a;
  printf("%.3f\n", ans);
  return 0;
}