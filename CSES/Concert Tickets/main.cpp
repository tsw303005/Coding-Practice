#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    multiset<int> s;
    int n, m, t, price;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        if (*s.begin() > t || s.empty()) {
            cout << "-1\n";
        } else {
            auto p = s.lower_bound(t);
            if (*p != t) p--;
            cout << *p << "\n";
            s.erase(p);
        }
    }

    return 0;
}