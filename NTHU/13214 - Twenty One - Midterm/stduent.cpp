#include <iostream>
#include <cstring>
#include "function.h"
using namespace std;

Human::Human(string n, int m, int ski) :name(n), money(m), skill(ski) {
    bets = 0;
    cards = 0;
}
void Human::Draw() {
    this->cards = 0;
    string res = "";
    while (res.size() <= 0)
        getline(cin, res);
    stringstream ss(res);
    while (ss >> res) {
        int temp = 0;
        for (auto i : res)
            temp = temp * 10 + i - '0';
        this->cards += temp;
    }
}
Human::~Human() {}

Guard::Guard(int ski) :Human("Guard", 0, ski) {}
void Guard::Pay(Human* human) {
    if (skill < human->skill) {
        money -= (human->skill - skill);
        human->money += (human->skill - skill);
    }
}

Banker::Banker(int ski) :Human("Banker", 0, ski) {}
int bankerpay;
void Banker::Pay(Human* human) {
    if (human->name == "Guard") {
        money -= 100;
        human->money += 100;
    }
    else {
        bankerpay = human->bets;
        if (human->skill < skill) bankerpay += (10 * human->cards);
        if (human->cards == 21) bankerpay *= 2;
        money -= bankerpay;
        human->money += bankerpay;
    }
}
int Banker::Win(Human* human) {
    if (human->cards <= 21 && (cards > 21 || human->cards > cards)) return 0;
    else if (cards <= 21 && (human->cards > 21 || cards >= human->cards)) return 1;
    return 2;
}
Banker::~Banker() {}

Server::Server(int ski) :Human("Server", 0, ski) {}
Server::~Server() {}

Player::Player(string name, int m, int ski) : Human(name, m, ski) {}
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
    cin >> bets;
}
bool Player::Bankrupt() {
    return money <= 0;
}
bool Player::Cheat(Human* human) {
    return 3 * skill < bankerpay;
}
void Player::Order(Human* banker, Human* server) {
    money -= 3000;
    banker->money += 2000;
    server->money += 1000;
}
Player::~Player() {}

Casino::Casino() {
    fee = U = player_num = total_income = today_income = blacklist_num = 0;
}
Casino::~Casino() {}
void Casino::Enterance(int f, int u) {
    today_income = 0;
    fee = f;
    U = u;
}
void Casino::Guest(string s, int m, int ski) {
    for (int i = 0; i < blacklist_num; i++) {
        if (blacklist[i] == s) return;
    }
    for (int i = 0; i < player_num; i++) {
        if (player[i]->name == s) return;
    }
    if (m <= fee) {
        blacklist[blacklist_num++] = s;
    }
    else {
        player[player_num++] = new Player(s, m - fee, ski);
        today_income += fee;
    }
}

void Casino::TwentyOne() {
    int banker_ski, guard_ski, server_ski;
    cin >> banker_ski >> guard_ski >> server_ski;
    banker = new Banker(banker_ski);
    guard = new Guard(guard_ski);
    server = new Server(server_ski);
    int record[1009];
    for (int i = 0; i < 1009; i++) record[i] = 0;
    int k;
    cin >> k;
    while (k--) {
        string player_name;
        cin >> player_name;
        int flag = 1;
        Player* new_player = new Player(player_name, 0, 0);
        new_player->Bet();
        new_player->Draw();
        for (int i = 0; i < blacklist_num; i++) {
            if (this->blacklist[i] == player_name) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < player_num; i++) {
                if (player[i]->name == player_name) {
                    record[i] = 1;
                    player[i]->bets = new_player->bets;
                    player[i]->cards = new_player->cards;
                    break;
                }
            }
        }
        delete new_player;
    }
    banker->Draw();
    for (int i = 0; i < player_num; i++) {
        if (record[i] == 1) {
            if (banker->Win(player[i]) == 1) {
                player[i]->Pay(banker);
                if (player[i]->Bankrupt()) {
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                }
            }
            else if (banker->Win(player[i]) == 0) {
                banker->Pay(player[i]);
                if (player[i]->money > server->skill) player[i]->Order(banker, server);

                if (player[i]->Cheat(banker)) {
                    this->guard->Pay(this->player[i]);
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                }
            }
        }
    }
    cout << banker->money << ' ' << guard->money << ' ' << server->money << endl;
    for (int i = 0; i < player_num; i++) {
        if (record[i] == 1)
        cout << player[i]->name << ' ' << player[i]->money << endl;
    }
    today_income += banker->money;
}
void Casino::EndDay() {
   
    if (today_income >= U) {
        blacklist_num = 0;
    }
    total_income += today_income;
    today_income = 0;
    player_num = 0;
}
void Casino::Result() {
    cout << total_income << endl;
    for (int i = 0; i < blacklist_num; i++)
        cout << blacklist[i] << endl;
}