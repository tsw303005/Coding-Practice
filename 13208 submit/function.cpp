#include "function.h"
#include <sstream>

// casino
Casino::Casino() {
  this->list_num = 0;
  this->guest_num = 0;
  this->pre_income = 0;
  this->income = 0;
  this->U = 0;
  this->fee = 0;
}

Casino::~Casino() {
  for (int i = 0; i < this->guest_num; i++) {
    delete this->guest[i];
  }
}

void Casino::Enterance(int f, int u) {
  this->fee = f;
  this->U = u;
}

void Casino::GuestEnter(string s, int m, int ski) {
  for (int i = 0; i < this->list_num; i++) {
    if (this->blacklist[i] == s) return;
  }
  for (int i = 0; i < this->guest_num; i++) {
    if (this->guest[i]->get_name() == s) return;
  }

  int money;
  if (this->fee >= m) {
    money = 0;
    this->pre_income += m;
    this->blacklist[this->list_num] = s;
    this->list_num += 1;
  } else {
    this->pre_income += this->fee;
    money = m - this->fee;
    this->guest[this->guest_num] = new Guest(s, money, ski);
    this->guest_num += 1;
  }
}

void Casino::Win(string s, int m) {
  int i;

  for (int j = 0; j < this->list_num; j++) {
    if (this->blacklist[j] == s) return;
  }

  for (i = 0; i < this->guest_num; i++) {
    if (this->guest[i]->get_name() == s) break;
  }
  if (i == this->guest_num) return ;

  int money;
  if (this->guest[i]->get_money() <= -1*m) {
    money = -1 * this->guest[i]->get_money();
    this->blacklist[this->list_num] = s;
    this->list_num += 1;
  } else if (m > this->guest[i]->get_skill() * 2) {
    money = m;
    this->blacklist[this->list_num] = s;
    this->list_num += 1;
  } else {
    money = m;
  }
  this->pre_income -= money;
  this->guest[i]->Win(money);
}

void Casino::EndDay() {
  this->income += this->pre_income;
  if (this->pre_income >= this->U) this->list_num = 0;
  for (int i = 0; i < this->guest_num; i++) {
    delete this->guest[i];
  }
  this->guest_num = 0;
  this->pre_income = 0;
}

void Casino::Result() {
  cout << this->income << endl;
  for (int i = 0; i < this->list_num; i++) {
    cout << this->blacklist[i] << endl;
  }
}

// guest
Guest::Guest() {
  this->name = "";
  this->money = this->skill = 0;
}

Guest::Guest(string s, int m, int ski) {
  this->name = s;
  this->money = m;
  this->skill = ski;
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

// for twentyone
Human::Human(string n, int m, int ski) {
  this->name = n;
  this->money = m;
  this->skill = ski;
  this->kicked = false;
  this->cards = 0;
  this->bets = 0;
}

Human::~Human() {}

int Human::get_money() {
  return this->money;
}

// guard
Guard::Guard(int ski) : Human("Guard", 0, ski) {

}

void Guard::Pay(Human *human) {
  this->money -= (human->skill-this->skill);
  human->money += (human->skill-this->skill);
}

void Guard::Kick(Human *human, int flag) {
  human->kicked = true;
  if (flag == 1 && human->skill > this->skill) this->Pay(human);
}

// Banker
Banker::Banker(int ski) : Human("Banker", 0, ski) {

}

Banker::~Banker() {

}

void Banker::Draw() {
  int card;
  int c;
  string num;

  this->cards = 0;
  getline(cin, num);
  istringstream input_stream(num);
  while (input_stream >> card) {
      this->cards += card;
  }
}

void Banker::Pay(Human *human) {
  if (human->name == "Guard") {
    this->money -= 100;
    human->money += 100;
    return ;
  } else {
    int x = human->bets;
    if (human->skill < this->skill) x += human->cards * 10;
    if (human->cards == 21) x *= 2;

    this->money -= x;
    human->money += x;
  }
}

int Banker::Win(Human *human) {
  if (this->cards > 21 && human->cards > 21) {
    return 2;
  } else if (this->cards <= 21 && (human->cards <= this->cards || human->cards > 21)) {
    return 1;
  } else return 0;
}

// player
Player::Player(string name, int m, int ski) : Human(name, m, ski) {

}

Player::~Player() {

} 

void Player::Pay(Human *human) {
  int m = (this->bets <= this->money) ? this->bets : this->money;
  this->money -= m;
  human->money += m;
}

void Player::Bet() {
  string name;
  int bet;
  cin >> name >> bet;
  this->bets = bet; 
}

void Player::Draw() {
  int card;
  string num;
  char c;

  this->cards = 0;
  
  getline(cin, num);
  getline(cin, num);
  istringstream input_stream(num);
  while (input_stream >> card) {
      this->cards += card;
  }
}

bool Player::Kicked() {
  return this->kicked;
}

bool Player::Bankrupt() {
  return (this->money <= 0) ? true : false;
}

bool Player::Cheat(Human *human) {
  int x = this->bets;
  if (human->skill > this->skill) x += this->cards * 10;
  if (this->cards == 21) x *= 2;
  if (x > this->skill * 2) return true;
  else return false;
}