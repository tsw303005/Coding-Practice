#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%2d", arr[(i+(n-1)*j) % n]);
    }
    printf("\n");
  }

  return 0;
}