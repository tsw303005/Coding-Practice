/*
給一個 linked list 當作 input
回傳 sorted 過的 linked list
最好的 time complexity 跟 space complexity
*/

#include <iostream>

using namespace std;

typedef struct Node {
  Node *next;
  int value;
} node;

node* Merge(node* left, node* right, int n) {
  node* cur = NULL;
  node* head = NULL;
  for (int i = 0; i < n; i++) {
    if (left != NULL && right != NULL) {
      if (left->value < right->value) {
        if (cur == NULL) head = cur = left;
        else cur->next = left;
        cur = cur->next;
        left = left->next;
      } else {
        if (cur == NULL) head = cur = right;
        else cur->next = right;
        cur = cur->next;
        right = right->next;
      }
    } else if (left != NULL) {
      cur->next = left;
      cur = cur->next;
      left = left->next;
    } else if (right != NULL) {
      cur->next = right;
      cur = cur->next;
      right = right->next;
    }
  }
  return head;
}

node* MergeSort(node* head, int n) {
  int middle = n / 2;
  node* prev = NULL;
  node* cur = NULL;
  node* left = NULL;
  node* right = NULL;
  node* re = head;

  if (n >= 2) {
    cur = head;
    for (int i = 0; i < middle; i++) prev = cur, cur = cur->next;
    prev->next = NULL;
    left = MergeSort(head, middle);
    right = MergeSort(cur, n - middle);
    re = Merge(left, right, n);
    return re;
  } else {
    return head;
  }
}

int arr[5] = {-2, 5, 3, 1, -4};
int Count = 0;

node* build() {
  node* head;
  node* cur;
  head = NULL;
  cur = NULL;

  head = new node();
  head->next = NULL;
  cur = head;
  for (int i = 0; i < 5; i++) {
    cur->value = arr[i];
    cur->next = new node();
    cur = cur->next;
    cur->next = NULL;
    Count += 1;
  }
  return head;
}

void showResult(node* head) {
  while (head != NULL) {
    cout << head->value << ' ';
    head = head->next;
  }
  cout << endl;
}

int main() {
  node* head = build();
  
  head = MergeSort(head, Count);
  showResult(head);
  return 0;
}

// -2->5->3->1->-4