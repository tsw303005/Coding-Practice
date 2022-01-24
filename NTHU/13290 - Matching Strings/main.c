#include <stdio.h>
#include <string.h>

char arr[100][1001];

int main() {
  int n, m;
  char query[1001];

  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }

  for (int i = 0; i < m; i++) {
    scanf("%s", query);
    for (int j = 0; j < n; j++) {
      if (strcmp(arr[j], query) == 0) {
        printf("Yes\n");
        break;
      } else if (j == n-1) {
        printf("No\n");
      }
    }
  }
  return 0;
}