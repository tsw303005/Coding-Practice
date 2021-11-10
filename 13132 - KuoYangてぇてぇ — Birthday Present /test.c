#include <stdio.h>
#include <stdlib.h>


typedef struct _Node {
  struct _Node* next;
  struct _Node* prev;
  int label;
  int record;
} Node;

Node *head;
Node *tail;
Node *mid;
int mid_place, tail_place;
int flag;

void makeNode(int n);
void Print(int k);

int main() {
  int n, q, k, t;
  char operation[20];

  head = tail = mid = NULL;
  mid_place = tail_place = 0;
  scanf("%d%d%d", &n, &k, &q);
  makeNode(n);

  for (int i = 0; i < q; i++) {
    scanf(" %s", operation);
    if (operation[0] == 'p' && operation[1] == 'o') {
      if (tail_place > 1) {
        tail_place -= 1;
        if (mid_place != 1) {
          Node* cur;
          if (tail_place % 2 == 0) {
            mid_place -= 1;
            cur = mid->prev;
          } else {
            cur = mid->next;
          }
          mid->next->prev = mid->prev;
          mid->prev->next = mid->next;
          free(mid);
          mid = cur;
        } else {
          Node* cur = tail;
          tail = mid = head;
          tail_place = mid_place = 1;
          free(cur);
        }
      } else if (tail_place == 1) {
        Node* cur = tail;
        tail = mid = head = NULL;
        tail_place = mid_place = 0;
        free(cur);
      }
    } else if (operation[0] == 'p' && operation[1] == 'u') {
      scanf("%d", &t);
      if (head == NULL) {
        head = malloc(sizeof(Node));
        head->record = flag;
        head->next = NULL;
        head->prev = NULL;
        head->label = t;
        tail = mid = head;
        mid_place = tail_place = 1;
      } else {
        tail->next = malloc(sizeof(Node));
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail->next->record = flag;
        tail->next->label = t;
        tail_place += 1;
        tail = tail->next;
        if (tail_place % 2 == 1) {
          mid_place += 1;
          mid = mid->next;
        }
      }
    } else {
      scanf(" %s", operation);
      flag += 1;
    }
  }


  Print(k);
  return 0;
}

void Print(int k) {
  Node* cur = head;
  while (cur != NULL) {
    if (cur->record < flag) {
      cur->label %= k;
    }
    printf("%d ", cur->label);
    cur = cur->next;
  }
  printf("\n");
}

void makeNode(int n) {
  int t;

  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (i == 0) {
      head = malloc(sizeof(Node));
      head->next = NULL;
      head->prev = NULL;
      head->record = flag;
      head->label = t;
      tail = head;
      mid = head;
      tail_place = mid_place = 1;
    } else {
      tail->next = malloc(sizeof(Node));
      tail->next->record = flag;
      tail->next->next = NULL;
      tail->next->prev = tail;
      tail->next->label = t;
      tail_place += 1;
      tail = tail->next;

      if (tail_place % 2 == 1) {
        mid_place += 1;
        mid = mid->next;
      }
    }
  }
}