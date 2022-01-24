#include <iostream>
#include "function.h"
using namespace std;

int flag = 0;
KuoYangPresent::KuoYangPresent(int k) {
  head = mid = tail = nullptr;
	this->k = k;
	this->sz = 0;
}

void KuoYangPresent::Push(int x) {
  sz += 1;
	if (!head) {
		head = new Node;
		head->val = x;
    head->tag = flag;
		head->next = nullptr;
		head->prev = nullptr;
		tail = mid = head;
	} else {
    tail->next = new Node;
    tail->next->next = NULL;
    tail->next->prev = tail;
    tail->next->val = x;
    tail->next->tag = flag;
    tail = tail->next;
    if (sz % 2 == 1) {
      mid = mid->next;
    }
  }
}

void KuoYangPresent::Pop() {
  if (sz == 0) return ;
  if (sz == 1) {
    delete head;
    head = tail = head = nullptr;
    sz = 0;
  } else if (sz == 2) {
    mid = tail;
    delete(head);
    head = tail;
    sz -= 1;
  } else {
    sz -= 1;
    Node* des = mid;
    mid->prev->next = mid->next;
    mid->next->prev = mid->prev;
    if (sz % 2 == 0) mid = mid->prev;
    else mid = mid->next;
    delete des;
  }
}

void KuoYangPresent::ProgrammingTanoshi() {
  flag += 1;
}

void KuoYangPresent::KuoYangTeTe() {
  Node* cur = head;
  while (cur) {
    if (cur->tag < flag) cur->val %= k;
    else break;
    cur = cur->next;
  }
}

void KuoYangPresent::PrintList() {
  Node* cur = head;
  while (cur) {
    cout << cur->val << ' ';
    cur = cur->next;
  }
  cout << endl;
}