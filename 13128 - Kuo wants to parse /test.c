#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _Node {
  struct _Node *left, *right;
  int isNumber;
  int number;
  char operation;
} Node;

Node* Expr();
Node* Factor();
Node* makeNode();
void printResult(Node* cur);
void deleteTree(Node* cur);
int pos;
int flag;
char str[1000];

int main() {
  Node* root;
  while (scanf(" %s", str) != EOF) {
    pos = strlen(str)-1;
    root = Expr();
    printResult(root);
    printf("\n");
    deleteTree(root);
  }
  return 0;
}

void printResult(Node* cur) {
  if (cur->isNumber == 1) {
    printf("%d ", cur->number);
  } else {
    printf("%c ", cur->operation);
  }

  if (cur->left != NULL) {
    printResult(cur->left);
  }

  if (cur->right != NULL) {
    printResult(cur->right);
  }
}

void deleteTree(Node* cur) {
  if (cur->left != NULL) {
    deleteTree(cur->left);
  } if (cur->right != NULL) {
    deleteTree(cur->right);
  }

  free(cur);
  return ;
}

int getNumber() {
  int start, end;
  int run = 0;
  int re;
  char strToNum[20];

  start = pos;
  while (pos >= 0 && isdigit(str[pos]) != 0) {
    pos--;
  }
  end = pos+1;

  for (int i = end; i <= start; i++) {
    strToNum[run++] = str[i];
  }
  strToNum[run] = '\0';
  
  re = atoi(strToNum);
  return re;
}

Node* Expr() {
  Node* root;
  Node* right;
  if (pos >= 0) {
    right = Factor();
  }
  if (pos > 0) {
    if (str[pos] == '+' || str[pos] == '-') {
      root = makeNode();
      root->right = right;
      root->left = Expr();
      return root;
    } else {
      return right;
    }
  } else {
    return right;
  }
}

Node* Factor() {
  Node* re;
  if (str[pos] == ')') {
    pos--;
    re = Expr();
    pos--;
    return re;
  } else {
    re = makeNode();
    return re;
  }
}

Node* makeNode() {
  Node* re = malloc(sizeof(Node));
  int num;
  int isNum;
  int operation;

  re->right = re->left = NULL;
  if (isdigit(str[pos]) != 0) {
    num = getNumber();
    re->isNumber = 1;
    re->number = num;
  } else {
    re->isNumber = 0;
    re->operation = str[pos];
    pos--;
  }

  return re;
}