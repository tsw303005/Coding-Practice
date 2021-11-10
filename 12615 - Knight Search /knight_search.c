#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define I 0
#define C 1
#define P 2
#define A 3
#define S 4
#define G 5

const char words[11] = "ICPCASIASG\0";

int row[6][10000];
int col[6][10000];
int num[6] = {0};
int flag = 0;

void init() {
  flag = 0;
  for (int i = 0; i < 6; i++) {
    num[i] = 0;
    for (int j = 0; j < 10000; j++) {
      row[i][j] = -1;
      col[i][j] = -1; 
    }
  }
}

int judge_which_letter(int a) {
  if (words[a] == 'I') {
    return I;
  } else if (words[a] == 'C') {
    return C;
  } else if (words[a] == 'P') {
    return P;
  } else if (words[a] == 'A') {
    return A;
  } else if (words[a] == 'S') {
    return S;
  } else {
    return G;
  }
}

void judge(int which, int a, int b) {
  if (which >= strlen(words)) {
    flag = 1;
    return ;
  };
  int c, d;
  int which_letter = judge_which_letter(which);
  for (int i = 0; i < num[which_letter]; i++) {
    if (flag) {
      return ;
    }
    c = row[which_letter][i];
    d = col[which_letter][i];

    int square1 = pow(a-c, 2);
    int square2 = pow(b-d, 2);

    if ((square1 + square2) == 5) {
      judge(which+1, c, d);
    }
  }
}

int main() {
  int n;
  char c;

  init();
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &c);
      if (c == 'I') {
        row[I][num[I]] = i;
        col[I][num[I]] = j;
        num[I]++;
      } else if (c == 'C') {
        row[C][num[C]] = i;
        col[C][num[C]] = j;
        num[C]++;
      } else if (c == 'P') {
        row[P][num[P]] = i;
        col[P][num[P]] = j;
        num[P]++;
      } else if (c == 'A') {
        row[A][num[A]] = i;
        col[A][num[A]] = j;
        num[A]++;
      } else if (c == 'S') {
        row[S][num[S]] = i;
        col[S][num[S]] = j;
        num[S]++;
      } else if (c == 'G') {
        row[G][num[G]] = i;
        col[G][num[G]] = j;
        num[G]++;
      }
    }
  }

  for (int i = 0; i < num[I]; i++) {
    if (flag) {
      break;
    }
    judge(1, row[I][i], col[I][i]);
  }

  if (flag) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}