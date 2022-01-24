#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100005];
int num_to_char[100005];
int buffer[100005];

void init();

int main() {
  int n, l, r, k, middle, count;
  int str_length;
  scanf("%s", str);
  scanf("%d", &n);
  str_length = strlen(str);
  
  init();

  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &r, &k);
    if (l == r) continue;
    count = 0;
    l--;
    r--;
    k %= (r-l+1);

    middle = r - k + 1;
    for(int j = middle; j <= r; j++) {
      buffer[count] = num_to_char[j];
      count += 1;
    }
    for(int j = l; j < middle; j++) {
      buffer[count] = num_to_char[j];
      count += 1;
    }
    count = 0;
    for (int j = l; j <= r; j++) {
      num_to_char[j] = buffer[count];
      count += 1;
    }
  }

  for (int i = 0; i < str_length; i++) {
    printf("%c", str[num_to_char[i]]);
  }
  printf("\n");
  return 0;
}

void init() {
  int length = strlen(str);

  for (int i = 0; i < length; i++) {
    num_to_char[i] = i;
  }
}