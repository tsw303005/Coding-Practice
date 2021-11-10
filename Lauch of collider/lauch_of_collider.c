#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Max 2147483647

int particle[200005] = {0};

int main() {
  int n, t, ans, last, collision_point, distance;
  t = last = 0;
  ans = Max;
  char c;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &c);
    if (c == 'L') {
      particle[i] = 0;
    } else {
      particle[i] = 1;
    }
  }

  scanf("%d", &last);
  for (int i = 1; i < n; i++) {
    scanf("%d", &t);
    if ((particle[i] == 0 && particle[i-1] == 1)) {
      collision_point = (last + t) / 2;
      distance = abs(t - collision_point);
      if (distance < ans) {
        ans = distance;
      }
    }
    last = t;
  }

  if (ans != Max) {
    printf("%d\n", ans);
  } else {
    printf("-1\n");
  }

  return 0;
}