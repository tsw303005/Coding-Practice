#include <cstring>
#include <iostream>
using namespace std;

class Guest {
public:
	Guest();
	Guest(string s, int m, int ski);
	~Guest();
	string get_name();
	int get_money();
	int get_skill();
	void Win(int m);
	
private:
	string name;
	int money;
	int skill;
};

class Casino {
public:
	Casino();
	~Casino();
	void Enterance(int f, int u);
	void GuestEnter(string s, int m, int ski);
	void Win(string s, int m);
	void EndDay();
	void Result();
	
private:
	int fee, U;
	
	int guest_num;
	Guest *guest[1009];
	
	int income, pre_income;
	int list_num;
	string blacklist[1000009];
};

//////////////////////////////////////////////////////////////////////////////

class Human {
public:
	string name;
	int money;
	int skill;
	bool kicked;
	int cards;
	int bets;

	Human(string n, int m, int ski);
	
	virtual void Pay(Human *human) = 0;
	virtual void Bet() {}
	virtual void Draw() {}
	virtual bool Kicked() {}
	virtual int Win(Human *human) {}
	virtual bool Bankrupt() {}
	virtual void Kick(Human *human, int flag) {}
	virtual bool Cheat(Human *human) {}
	int get_money();
	~Human();
};

class Guard : public virtual Human {
public:
	Guard(int ski);
	void Pay(Human *human);
	void Kick(Human *human, int flag);
};

class Banker : public virtual Human {
public:
	Banker(int ski);
	void Pay(Human *human);
	int Win(Human *human);
	void Draw();
	~Banker();
};

class Player : public virtual Human {
public:
	Player(string name, int m, int ski);
	void Pay(Human *human);
	void Bet();
	void Draw();
	bool Kicked();
	bool Bankrupt();
	bool Cheat(Human *human);
	~Player();
};
