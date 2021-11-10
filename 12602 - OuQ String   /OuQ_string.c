#include <stdio.h>
#include <string.h>

char word[] = "OuQ";
long long int num_str[55];

void recur(int num, int k) {
  long long int count = num_str[k];
  long long int middle = 0;

  middle = count / 2;
  
  if (num == 0) {
    printf("O");
  } else if (num == middle) {
    printf("u");
  } else if (num == count-1) {
    printf("Q");
  } else {
    if (num < middle) {
      recur(num-1, k-1);
    } else {
      recur(num-middle-1, k-1);
    }
  }
}

void init() {
  long long int count = 0;
  for (int i = 1; i <= 50; i++) {
    count = 0;
    for (int j = 0; j < i; j++) {
      count *= 2;
      count += 3;
    }
    num_str[i] = count;
  }
}

int main() {
  int k, l, r;
  init();
  while (scanf("%d%d%d", &k, &l, &r) != EOF) {
    for (int i = l; i <= r; i++) {
      recur(i, k);
    }
    printf("\n");
  }
  return 0;
}