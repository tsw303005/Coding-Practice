#include <stdio.h>
#include <stdlib.h>
int place[1005];
int ans[1005];

int main() {
  int n, m;
  int a, b;
  for (int i = 0; i < 1005; i++) place[i] = i, ans[i] = i;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    ans[place[a]] = b;
    ans[place[b]] = a;
    int tmp = place[a];
    place[a] = place[b];
    place[b] = tmp;
  } 
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}