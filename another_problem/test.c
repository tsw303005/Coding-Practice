#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int A, B;

int main() {
  int n;
  long long int count, ans;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    ans = 0;
    count = 9;
    scanf("%lld%lld", &A, &B);

    while (B >= count) {
      count *= 10;
      count += 9;
      ans += A;
    }

    printf("%lld\n", ans);
  }
  return 0;
}