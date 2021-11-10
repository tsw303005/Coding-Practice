#include <iostream>
#include <cstring>
#include <sstream>
#include "function.h"

using namespace std;

Human::Human(string n, int m, int ski) :name(n), money(m), skill(ski) {
    kicked = false;
	cards = 0;
	bets = 0;
}
int Human::get_money() { return money; }
Human::~Human() {}

Guard::Guard(int ski) :Human("Guard", 0, ski) {}
void Guard::Pay(Human* human) {
	if (skill < human->skill) {
		money -= (human->skill - skill);
		human->money += (human->skill - skill);
	}
}
void Guard::Kick(Human* human, int flag) {
	human->kicked = true;
	if (flag) Pay(human);
}
Guard::~Guard() {}


int bankerpay;

Banker::Banker(int ski) :Human("Banker", 0, ski) {}
void Banker::Pay(Human* human) {
	if (human->name == "Guard") {
		money -= 100;
		human->money += 100;
	}
	else {
		bankerpay = human->bets;
		if (human->skill < skill) bankerpay += 10 * human->cards;
		if (human->cards == 21) bankerpay *= 2;
		money -= bankerpay;
		human->money += bankerpay;
	}
}
int Banker::Win(Human* human) {
	if (human->cards <= 21 && (cards > 21 || human->cards > cards)) { return 0; }		//player win
	else if (cards <= 21 && (human->cards > 21 || cards >= human->cards)) { return 1; }	//player lose
	return 2;
}
void Banker::Draw() {
	int card;
    string num = "";
    char c;

    this->cards = 0;
    
    while (num.length() <= 0) getline(cin, num);
    istringstream input_stream(num);
    while (input_stream >> card) {
        this->cards += card;
    }
}
Banker::~Banker() {}

Player::Player(string name, int m, int ski) :Human(name, m, ski) {}
void Player::Pay(Human* human) {
	if (bets >= money) {
		human->money += money;
		money -= money;
	}
	else {
		money -= bets;
		human->money += bets;
	}
}
void Player::Bet() {
	cin >> name >> bets;
}
void Player::Draw() {
	int card;
    string num = "";
    char c;

    this->cards = 0;
    
    while (num.length() <= 0) getline(cin, num);
    istringstream input_stream(num);
    while (input_stream >> card) {
        this->cards += card;
    }
}
bool Player::Kicked() {
	return kicked;
}
bool Player::Bankrupt() {
	return money <= 0;
}
bool Player::Cheat(Human* human) {
	return (2 * skill) < bankerpay;
}
Player::~Player() {}