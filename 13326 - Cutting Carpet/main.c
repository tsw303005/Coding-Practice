#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
  int n, m, t;
  scanf("%d %d", &n, &m);
  int arr_r[n+1][m+1];
  int arr_c[n+1][m+1];
  int run;
  int ans = INT32_MIN;
  int tmp;
  memset(arr_r, 0, sizeof(arr_r));
  memset(arr_c, 0, sizeof(arr_c));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &t);
      arr_r[i][j] = arr_r[i-1][j] + t;
      arr_c[i][j] = arr_c[i][j-1] + t;
    }
  }

  if (n > m) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= i; j++) {
        run = 0;
        for (int k = 1; k <= n; k++) {
          tmp = arr_c[k][i] - arr_c[k][j-1];
          if (run + tmp < 0) run = tmp;
          else run += tmp;
          if (ans < run) ans = run;
          if (run < 0) run = 0;
        }
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        run = 0;
        for (int k = 1; k <= m; k++) {
          tmp = arr_r[i][k] - arr_r[j-1][k];
          if (run + tmp < 0) run = tmp;
          else run += tmp;
          if (ans < run) ans = run;
          if (run < 0) run = 0;
        }
      }
    }
  }

  printf("%d\n", ans);
  
  return 0;
}