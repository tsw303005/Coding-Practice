#include "function.h"
#include <sstream>
#include <iostream>
#include <cstring>

Human::Human(string n, int m, int ski) {
  this->name = n;
  this->money = m;
  this->skill = ski;
}

Human::~Human() {

}

void Human::Draw() {
  string num = "";
  int card;

  this->cards = 0;
  while (num.length() <= 0) getline(cin, num);
  istringstream input_stream(num);
  while (input_stream >> card) {
      this->cards += card;
  }
}

// Guard
Guard::Guard(int ski) : Human("Guard", 0, ski) {

}

void Guard::Pay(Human *human) {
  human->money += (human->skill - this->skill);
  this->money -= (human->skill - this->skill);
}

// Banker
Banker::Banker(int ski) : Human("Banker", 0, ski) {

}

Banker::~Banker() {

}

void Banker::Pay(Human *human) {
  if (human->name == "Guard") {
    this->money -= 100;
    human->money += 100;
  } else {
    int x = human->bets;
    if (this->skill > human->skill) x += (10 * human->cards);
    if (human->cards == 21) x *= 2;

    this->money -= x;
    human->money += x;
  }
}

int Banker::Win(Human *human) {
  if (this->cards > 21 && human->cards > 21) return 0;
  else if (this->cards <= 21 && (human->cards > 21 || human->cards <= this->cards)) return 1;
  else return 2;
}

// Server
Server::Server(int ski) : Human("Server", 0, ski) {

}

Server::~Server() {

}

// Player
Player::Player(string name, int m, int ski) : Human(name, m, ski) {
  this->bets = 0;
  this->cards = 0;
}

Player::~Player() {

}

void Player::Pay(Human *human) {
  int m = (this->bets > this->money) ? this->money : this->bets;
  this->money -= m;
  human->money += m;
}

void Player::Bet() {
  int bet;
  cin >> bet;
  this->bets = bet;
}

bool Player::Bankrupt() {
  return (this->money == 0);
}

bool Player::Cheat(Human *human) {
  int x = this->bets;
  if (this->skill < human->skill) x += 10 * this->cards;
  if (this->cards == 21) x *= 2;
  if (3 * this->skill < x) return true;
  else return false;
}

void Player::Order(Human *banker, Human *server) {

}


// Casino
Casino::Casino() {
  for (int i = 0; i < 1009; i++) this->player[i] = nullptr;
  this->player_num = 0;
  this->blacklist_num = 0;
  this->total_income = 0;
  this->today_income = 0;
}

Casino::~Casino() {
  for (int i = 0; i < this->player_num; i++) delete this->player[i];
  this->player_num = 0;
}

void Casino::Enterance(int f, int u) {
  this->fee = f;
  this->U = u;
} 
void Casino::Guest(string s, int m, int ski) {
  for (int i = 0; i < this->blacklist_num; i++) {
    if (this->blacklist[i] == s) return;
  }
  for (int i = 0; i < this->player_num; i++) {
    if (this->player[i]->name == s) return;
  }
  if (m <= this->fee) {
    this->blacklist[this->blacklist_num] = s;
    this->blacklist_num += 1;
  } else {
    this->player[this->player_num] = new Player(s, m-this->fee, ski);
    this->player_num += 1;
    this->today_income += this->fee;
  }
}

void Casino::TwentyOne() {
  int b, g, s, K;
  cin >> b >> g >> s;
  this->banker = new Banker(b);
  this->guard = new Guard(g);
  this->server = new Server(s);

  cin >> K;

  // check 21 player
  string n;
  int record[1009];
  for (int i = 0; i < 1009; i++) record[i] = 0;
  for (int i = 0; i < K; i++) {
    cin >> n;
    int flag = 1;
    Player* new_player = new Player(n, 0, 0);
    new_player->Bet();
    new_player->Draw();

    for (int j = 0; j < this->blacklist_num; j++) {
      if (this->blacklist[j] == n) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      for (int j = 0; j < this->player_num; j++) {
        if (this->player[j]->name == n) {
          record[j] = 1;
          this->player[j]->bets = new_player->bets;
          this->player[j]->cards = new_player->cards;
        }
      }
    }
    delete new_player;
  }
  // banker draw
  this->banker->Draw();

  // start play game
  for (int i = 0; i < this->player_num; i++) {
    if (record[i] == 1) {
      if (this->banker->Win(this->player[i]) == 1) {
        // player pay money
        this->player[i]->Pay(this->banker);
        // chekc bankrupt
        if (this->player[i]->Bankrupt() == true) {
          // update blacklist num
          this->blacklist[this->blacklist_num] = this->player[i]->name;
          this->blacklist_num += 1;
          this->banker->Pay(this->guard);
        }
      } else if (this->banker->Win(this->player[i]) == 2) {
        // the banker pay
        this->banker->Pay(this->player[i]);
        // check buy wine
        if (this->player[i]->money > this->server->skill) {
          this->player[i]->money -= 3000;
          this->server->money += 1000;
          this->banker->money += 2000;
        }
        // check player cheat
        if (this->player[i]->Cheat(this->banker) == true) {
          // update blacklist num
          this->blacklist[this->blacklist_num] = this->player[i]->name;
          this->blacklist_num += 1;
          this->banker->Pay(this->guard);
          if (this->player[i]->skill > this->guard->skill) this->guard->Pay(this->player[i]);
        }
      }
    }
  }
  cout << this->banker->money << ' ' << this->guard->money << ' ' << this->server->money << endl;
  for (int i = 0; i < this->player_num; i++) {
    if (record[i] == 1) {
      cout << this->player[i]->name;
      cout << ' ' << this->player[i]->money << endl;
    }
  }
  this->today_income += this->banker->money;
}

void Casino::EndDay() {
  if (this->today_income >= this->U) {
    this->blacklist_num = 0;
  }

  // for (int i = 0; i < this->player_num; i++) delete this->player[i];
  this->player_num = 0;
  this->total_income += this->today_income;
  this->today_income = 0;
}

void Casino::Result() {
  cout << this->total_income << endl;
  for (int i = 0; i < this->blacklist_num; i++) cout << this->blacklist[i] << endl;
}