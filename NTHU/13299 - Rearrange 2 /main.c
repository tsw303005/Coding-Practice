#include <stdio.h>
#include <stdlib.h>
#define Q 100001
int place[Q];
int ans[Q];

int main() {
  int n, m, q, t;
  int a, b;
  for (int i = 0; i < Q; i++) place[i] = i, ans[i] = i;
  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    ans[place[a]] = b;
    ans[place[b]] = a;
    int tmp = place[a];
    place[a] = place[b];
    place[b] = tmp;
  }
  for (int i = 1; i <= q; i++) {
    if (i != 1) printf(" ");
    scanf("%d", &t);
    printf("%d", ans[t]);
  }
  printf("\n");
  return 0;
}