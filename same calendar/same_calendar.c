#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge_leap_year(int year);
int calculate(int year);

int main() {
  int n, t, ans;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    printf("%d\n", calculate(t));
  }

  return 0;
}

int judge_leap_year(int year) {
  if (year % 400 == 0) {
    return 1;
  } else if (year % 100 == 0) {
    return 0;
  } else if (year % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int calculate(int year) {
  int ans = year;
  int count = 0;
  if (judge_leap_year(year)) {
    while (count % 7 != 0 || year == ans) {
      if (judge_leap_year(ans+4)) {
        count += 5;
        ans += 4;
      } else {
        count += 9;
        ans += 8;
      }
    }
  } else {
    while (count % 7 != 0 || year == ans) {
      if (judge_leap_year(ans+1)) {
        ans += 2;
        count += 3;
      } else {
        ans += 1;
        count += 1;
      }
    }
  }

  return ans;
}