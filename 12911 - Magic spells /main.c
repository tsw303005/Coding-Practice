#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char A[1001], B[1001];
  int t, len_a, len_b, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", A, B);
    len_a = strlen(A);
    len_b = strlen(B);
    
    for (i = (len_b > len_a) ? len_a - 1 : len_b - 1; i >= 0 && strncmp(&A[len_a-1-i], B, i + 1) != 0; i--);
    printf("%s%s\n", A, &B[i+1]);
  }
  return 0;
}