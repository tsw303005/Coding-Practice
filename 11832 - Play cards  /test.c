#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  struct _Node* next;
  int label;
}Node;

Node* head;
int size;

void init(int n);
void pushNode(int index, int n);
void cutNode(int start, int end);
void Print();

int main() {
  int n, m, index, t, a, b;
  char operation[5];
  
  scanf("%d%d", &n , &m);
  head = NULL;
  size = n;
  init(n);

  for (int i = 0; i < m; i++) {
    scanf(" %s", operation);

    if (strcmp(operation, "ADD") == 0) {
      scanf("%d%d", &index, &t);
      pushNode(index, t);
    } else {
      scanf("%d%d", &a, &b);
      if (a+b-1 < a || a == 0) continue;
      else {
        cutNode(a, a+b-1);
      }
    }
  }
  Print();
  return 0;
}

void init(int n) {
  int t;
  Node* cur;

  for (int i = 0; i < n; i++) {
    scanf("%d", &t);

    if (i == 0) {
      head = malloc(sizeof(Node));
      head->label = t;
      head->next = NULL;
      cur = head;
    } else {
      cur->next = malloc(sizeof(Node));
      cur->next->label = t;
      cur->next->next = NULL;
      cur = cur->next;
    }
  }

  return ;
}

void pushNode(int index, int n) {
  Node* cur = NULL;

  if (index > size || index < 0) {
    return ;
  } else {
    if (index == 0) {
      cur = malloc(sizeof(Node));
      cur->label = n;
      cur->next = head;
      head = cur;
      size += 1;
    } else {
      cur = head;
      for (int i = 0; i < index - 1; i++) {
        cur = cur->next;
      }
      Node* temp = malloc(sizeof(Node));
      temp->label = n;
      temp->next = cur->next;
      cur->next = temp;
    }
  }

  return ;
}

void cutNode(int start, int end) {
  Node* cur = head;
  Node* findHeadPrev = head;
  Node* findHead;
  Node* findTail = head;
  Node* findTailNext;

  for (int i = 0; i < start-1; i++) {
    findHeadPrev = findHeadPrev->next;
  }
  findHead = findHeadPrev->next;

  for (int i = 0; i < end; i++) {
    findTail = findTail->next;
  }
  findTailNext = findTail->next;

  findHeadPrev->next = findTailNext;
  findTail->next = head;
  head = findHead;

  return ;
}

void Print() {
  Node* cur = head;

  while (cur != NULL) {
    printf("%d\n", cur->label);
    cur = cur->next;
  }

  return ;
}