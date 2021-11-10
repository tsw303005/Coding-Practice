#include "function.h"
#include <iostream>
#include <sstream>

// human
Human::Human(string n, int m, int ski) {
    this->name = n;
    this->money = m;
    this->skill = ski;
    this->kicked = false;
}

Human::~Human() {

}

int Human::get_money() {
    return this->money;
}

// guard
Guard::Guard(int ski) : Human("Guard", 0, ski) {
}

void Guard::Pay(Human *human) {
    this->money -= (human->skill - this->skill);
    human->money += (human->skill - this->skill);
}

void Guard::Kick(Human *human, int flag) {
    if (human->skill > this->skill && flag == 1) {
        this->Pay(human);
    }
    human->kicked = true;
}

// banker
Banker::Banker(int ski) : Human("Banker", 0, ski) {

}

Banker::~Banker() {

}

void Banker::Pay(Human* human) {
    if (human->name == "Guard") {
        this->money -= 100;
        human->money += 100;
    } else {
        int x = human->bets;
        if (human->skill < this->skill) x += (10 * human->cards);
        if (human->cards == 21) x *= 2;
        this->money -= x;
        human->money += x;
    }
}

int Banker::Win(Human* human) {
    if (human->cards > 21 && this->cards > 21) {
        return 2;
    } else if (human->cards <= 21 && (human->cards > this->cards || this->cards > 21)) {
        return 0;
    } else return 1;
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

// player
Player::Player(string name, int m, int ski) : Human(name, m, ski) {

}

Player::~Player() {

}

void Player::Pay(Human* human) {
    int x = (this->money >= this->bets) ? this->bets : this->money;
    this->money -= x;
    human->money += x;
}

bool Player::Bankrupt() {
    return (this->money <= 0) ? true : false;
}

bool Player::Cheat(Human* human) {
    int x = this->bets;
    if (this->skill < human->skill) x += 10 * this->cards;
    if (this->cards == 21) x *= 2;
    return (2*this->skill < x) ? true : false;
}

bool Player::Kicked() {
    return this->kicked;
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