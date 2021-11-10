#include <stdio.h>
#include <string.h>

char word[] = "OuQ";
long long int num_str[55];

void find(int k, int l, int r) {
  if (l > r) {
    return ;
  }

  long long int middle = num_str[k] / 2;
  int flag_l, flag_r, type, flag_m;
  flag_l = flag_r = type  = flag_m = 0;

  if (l == r) {
    if (l == 0) {
      printf("O");
    } else if (l == num_str[k]-1) {
      printf("Q");
    } else if (l == middle) {
      printf("u");
    } else {
      if (l > middle) {
        find(k-1, l-middle-1, r-middle-1);
      } else {
        find(k-1, l-1, r-1);
      }
    }
    return ;
  }

  if (l == 0) {
    l += 1;
    flag_l = 1;
  }

  if (r == num_str[k]-1) {
    r -= 1;
    flag_r = 1;
  }

  if (l >= middle) {
    if (l == middle) {
      flag_m = 1;
      l += 1;
    }
    type = 1;
  } else if (r <= middle) {
    if (r == middle) {
      flag_m = 1;
      r -= 1;
    }
    type = 2;
  } else {
    type = 3;
  }

  if (flag_l == 1) {
    printf("O");
  }

  if (type == 1) {
    if (flag_m) {
      printf("u");
    }
    find(k-1, l-middle-1, r-middle-1);
  } else if (type == 2) {
    find(k-1, l-1, r-1);
    if (flag_m) {
      printf("u");
    }
  } else {
    find(k-1, l-1, middle-2);
    printf("u");
    find(k-1, 0, r-middle-1);
  }
  if (flag_r) {
    printf("Q");
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
    find(k, l, r);
    printf("\n");
  }
  return 0;
}