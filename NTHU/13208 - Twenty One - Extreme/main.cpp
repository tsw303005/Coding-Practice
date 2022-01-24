#include <iostream>
#include <string>
#include "function.h"
using namespace std;

int n;
Casino casino;

void Twenty_Two();

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		string op;
		int q, fee, U;
		
		cin >> op >> q >> fee >> U;
		casino.Enterance(fee, U);
		for (int j = 0; j < q; ++ j) {
			cin >> op;
			if (op == "Guest") {
				string name; 
				int money, skill;
				cin >> name >> money >> skill;
				casino.GuestEnter(name, money, skill);
			} 
			else if (op == "Win") {
				string name;
				int money;
				cin >> name >> money;
				casino.Win(name, money);
			}
		}
		casino.EndDay();
		
		int A;
		cin >> A;
		if (A == 1) {
			Twenty_Two();
		}
	}
	casino.Result();
}

void Twenty_Two() {
	int guard_skill, banker_skill;
	cin >> guard_skill >> banker_skill;
	Human *guard = new Guard(guard_skill);
	Human *banker = new Banker(banker_skill);

	Human *player[1009];
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		string name;
		int player_money, player_skill;
		cin >> name >> player_money >> player_skill;
		player[i] = new Player(name, player_money, player_skill);
	}

	int k;
	cin >> k;
	while (k--) {
		for (int i = 1; i <= n; ++ i) {
			player[i]->Bet();
			player[i]->Draw();
		}
		banker->Draw();
	
		for (int i = 1; i <= n; ++ i) {
			if (player[i]->Kicked())
				continue;
			
			if (banker->Win(player[i]) == 1) {
				player[i]->Pay(banker);
				if (player[i]->Bankrupt()) {
					banker->Pay(guard);
					guard->Kick(player[i], 0);
				}
			}
			else if (banker->Win(player[i]) == 0) {
				banker->Pay(player[i]);
				if (player[i]->Cheat(banker)) {
					banker->Pay(guard);
					guard->Kick(player[i], 1);
				}
			} // otherwise draw
		}
	}
	
	cout << guard->get_money() << " " << banker->get_money() << endl;
	for (int i = 1; i <= n; ++ i)
		cout << player[i]->name << " " << player[i]->get_money() << endl;
}
