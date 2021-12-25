#include <stdio.h>

int main() {
  int k, n, m, t;

  scanf("%d", &k);

  for (int i = 0; i < k; i++) {
    scanf("%d %d %d", &n, &m, &t);
    for (int j = 1; j <= n; j++) {
      if (j <= t && j + m > t) printf("^");
      else printf("-");
    }
    printf("\n");
  }

  return 0;
}