#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#define endl '\n';

using namespace std;

bool compfunc(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first != b.first) return a.first > b.first;
  else return a.second < b.second;
}
multiset<pair<int, int> > modity;
multiset<pair<int, int>, decltype(&compfunc)> money(&compfunc);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, weight, price, type, w, p;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> weight >> price;
    modity.insert({weight, price});
    money.insert({{price, weight}});
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> type;
    if (type == 1) {
      cin >> weight >> price;
      modity.insert({weight, price});
      money.insert({{price, weight}});
    } else if (type == 2) {
      cin >> w >> p;
      auto tmp = modity.find({w, p});
      if (tmp != modity.end()) {
        cout << "OK\n";
        modity.erase(tmp);
        money.erase(money.find({p, w}));
      } else {
        cout << "No Item\n";
      }
    } else if (type == 3) {
      cin >> w;
      auto tmp = modity.lower_bound({w, -1});
      if (tmp != modity.end()) {
        cout << "OK ";
        cout << tmp->first << ' ' << tmp->second << endl;
        money.erase(money.find({tmp->second, tmp->first}));
        modity.erase(tmp);
      } else {
        cout << "No Item\n";
      }
    } else if (type == 4) {
      cin >> p;
      auto tmp = money.lower_bound({p, -1});
      if (tmp != money.end()) {
        cout << "OK ";
        cout << tmp->second << ' ' << tmp->first << endl;
        modity.erase(modity.find({tmp->second, tmp->first}));
        money.erase(tmp);
      } else {
        cout << "No Item\n";
      }
    }
  }
  return 0;
}