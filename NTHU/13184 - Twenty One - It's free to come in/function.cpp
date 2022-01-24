#include "function.h"
#include <iostream>
using namespace std;

// casino
Casino::Casino() {
  this->guest_num = 0;
  this->income = 0;
  this->list_num = 0;
}

Casino::~Casino() {
  for (int i = 0; i < this->guest_num; i++) delete this->guest[i];
}

void Casino::GuestEnter(string s, int m, int ski) {
  for (int i = 0; i < this->list_num; i++) {
    if (this->blacklist[i] == s) return;
  }
  for (int i = 0; i < this->guest_num; i++) {
    if (this->guest[i]->get_name() == s) return;
  }
  this->guest[this->guest_num] = new Guest(s, m, ski);
  this->guest_num += 1;
}

void Casino::Win(string s, int m) {
  int guest_id;
  for (int i = 0; i < this->list_num; i++) {
    if (this->blacklist[i] == s) return;
  }
  for (guest_id = 0; guest_id < this->guest_num; guest_id++) {
    if (this->guest[guest_id]->get_name() == s) break;
  }
  if (guest_id == this->guest_num) return;
  if (this->guest[guest_id]->get_money() + m <= 0) {
    int cost = this->guest[guest_id]->get_money();
    this->income += this->guest[guest_id]->get_money();
    this->blacklist[this->list_num] = this->guest[guest_id]->get_name();
    this->list_num += 1;
  } else if (2 * this->guest[guest_id]->get_skill() < m) {
    this->guest[guest_id]->Win(m);
    this->income -= m;
    this->blacklist[this->list_num] = this->guest[guest_id]->get_name();
    this->list_num += 1;
  } else {
    this->income -= m;
    this->guest[guest_id]->Win(m);
  }
}

void Casino::EndDay() {
  for (int i = 0; i < this->guest_num; i++) delete this->guest[i];
  this->guest_num = 0;
}

void Casino::Result() {
  cout << this->income << endl;
  for (int i = 0; i < list_num; i++) cout << blacklist[i] << endl;
}

// guest
Guest::Guest() {
  this->name = "";
  this->money = 0;
  this->skill = 0;
}

Guest::Guest(string s, int m, int skill) {
  this->name = s;
  this->money = m;
  this->skill = skill;
}

Guest::~Guest() {}

string Guest::get_name() {
  return this->name;
}

int Guest::get_money() {
  return this->money;
}

int Guest::get_skill() {
  return this->skill;
}

void Guest::Win(int m) {
  this->money += m;
}