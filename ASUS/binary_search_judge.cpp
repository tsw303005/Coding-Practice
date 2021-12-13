/*
input 是一棵樹
output 判斷這是不是合法的 binary search tree
*/

#include <iostream>
using namespace std;

typedef struct Node {
  Node *left;
  Node *right;
  int value;
}node;

bool result = true;

int check(node* cur);

int check(node* cur, int type) {
  if (!result) return 0;
  int right, left, ans;
  if (cur->right != NULL) right = check(cur->right, 1), result = (right > cur->value && result == true) ? true : false;
  if (cur->left != NULL) left = check(cur->left, 0), result = (left < cur->value && result == true) ? true : false;
  if (type == 0) {
    ans = (cur->right != NULL) ? right : cur->value;
  } else {
    ans = (cur->left != NULL) ? left : cur->value;
  }
  return ans;
}

node* build() {
  node* head = new node();
  head->value = 5;
  head->left = new node();
  head->left->value = 3;
  head->left->left = new node();
  head->left->left->value = 2;
  head->left->left->left = head->left->left->right = NULL;
  head->left->right = new node();
  head->left->right->value = 6;
  head->left->right->left = head->left->right->right = NULL;
  
  head->right = new node();
  head->right->value = 7;
  head->right->left = head->right->right = NULL;
  
  return head;
}

int main() {
  node *head = build();
  int tmp = check(head, 1);
  tmp = check(head, 0);
  if (result) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

//         5
//     3      7
//   2   6
//
// binary search tree