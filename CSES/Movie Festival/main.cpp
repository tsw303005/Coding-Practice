#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> Item;

bool cmp(Item a, Item b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<Item> v;
    set<Item> s;

    int n, start, end, time;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i : v) {
        if (s.empty()) s.insert(i), time = i.second;
        else if (time <= i.first) s.insert(i), time = i.second;
    }

    cout << s.size() << endl;
    return 0;
}