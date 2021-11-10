#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  string str;
  map <char, vector<int> > m;

  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    m[str[i]].push_back(i);
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    cout << i->first << ":";
    for (auto j : i->second) {
      cout << ' ' << j;
    }
    cout << endl;
  }
  return 0;
}