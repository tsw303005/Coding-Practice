#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  struct _Node *next;
  int position;
}Node;

Node *node[55];
Node *head[55];
char alph[55] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main() {
  int len;
  int flag;
  char str[1000002];
  char c;
  Node *cur = NULL;

  for (int i = 0; i < 55; i++) node[i] = NULL;
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len; i++) {
    c = str[i];
    flag = (c >= 'a' && c <= 'z') ? 26 + c - 'a' : c - 'A';
    cur = (Node*)malloc(sizeof(Node));
    cur->next = NULL;
    cur->position = i;
    if (node[flag] == NULL) node[flag] = cur, head[flag] = cur;
    else head[flag]->next = cur, head[flag] = head[flag]->next;
  }
  for (int i = 0; i < 52; i++) {
    if (node[i] != NULL) {
      printf("%c:", alph[i]);
      cur = node[i];
      while (cur != NULL) {
        printf(" %d", cur->position);
        cur = cur->next;
      }
      printf("\n");
    }
  }
  return 0;
}