#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
  int num;
  struct Word* next;
} word;

word* head = NULL;
char str[10005];

void init();
void Print();
word *get_link(int n);

int main() {
  int n, l, r, k;

  scanf("%s", str);
  scanf("%d", &n);
  init();

  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &r, &k);
    if (l == r) continue;
    l--;
    r--;
    k %= (r-l+1);

    word* r_self = get_link(r);   // r 自己
    word* r_next = r_self->next;  // r 下一個
    word* end = get_link(r-k);    // 取代 r 位置
    word* start = end->next;      // 取代 l 位置
    word* l_last = get_link(l-1); // l 的上一個
    word* l_self = (l_last == NULL) ? head : l_last->next;  // l 自己


    if (l_last == NULL) {
      head = start;
    } else {
      l_last->next = start;
    }
    r_self->next = l_self;
    end->next = r_next;
  }
  Print();
  return 0;
}

void init() {
  word *cur = NULL;
  int length = strlen(str);
  
  for (int i = 0; i < length; i++) {
    if (i == 0) {
      head = malloc(sizeof(word));
      head->num = i;
      head->next = NULL;
      cur = head;
    } else {
      cur->next = malloc(sizeof(word));
      cur->next->num = i;
      cur->next->next = NULL;
      cur = cur->next;
    }
  }
  return ;
}

word* get_link(int n) {
  word *cur = head;

  if (n < 0) return NULL;
  if (n >= strlen(str)) return NULL; 

  for (int i = 0; i < n; i++) {
    cur = cur->next;
  }

  return cur;
}

void Print() {
  word* cur = head;

  while (cur != NULL) {
    printf("%c", str[cur->num]);
    cur = cur->next;
  }
  printf("\n");
  return ;
}