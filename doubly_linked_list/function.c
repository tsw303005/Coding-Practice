#include "function.h"

Node *createList()
{
  int num = 0;
  Node *head = NULL;
  Node *cur = NULL;

  while (1) {
    scanf("%d", &num);
    if (num == -1) {
      return head;
    } else {
      Node *tmp = malloc(sizeof(Node));
      tmp->data = num;
      tmp->next = NULL;
      if (head == NULL) {
        head = tmp;
        cur = head;
      } else {
        cur->next = tmp;
        cur = cur->next;
      }
    }
  }
}

void deleteNode(Node ** nd, int data) {
  Node *head = *nd;
  Node *cur = head;
  Node *prev = NULL;

  if (data == 1) {
    head = head->next;
    *nd = head;
    free(cur);
    return ;
  }

  for (int i = 0; i < data-1; i++) {
    if (cur->next != NULL) {
      prev = cur;
      cur = cur->next;
    } else {
      return ;
    }
  }
  prev->next = cur->next;
  free(cur);
}