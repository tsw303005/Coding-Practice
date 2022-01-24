#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long arr[1000005];

int main() {
  memset(arr, 0, sizeof(arr));
  unsigned long long n;
  unsigned long long left, right;
  unsigned long long t;
  scanf("%llu", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%llu", &t);
    arr[i] = arr[i-1] + t;
  }
  scanf("%llu", &t);
  for (long long i = 0; i < t; i++) {
    scanf("%llu %llu", &left, &right);
    printf("%llu\n", arr[right] - arr[left-1]);
  }
  return 0;
}