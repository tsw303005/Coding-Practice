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
    vector<Item> *v = new vector<Item>;
    vector<Item> *tmp = NULL;
    vector<Item> *temp = NULL;
    int ans = 0;

    int n, start, end, time;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        (*v).push_back({start, end});
    }

    sort((*v).begin(), (*v).end(), cmp);

    while (!(*v).empty()) {
        ans += 1;
        time = 0;
        for (auto i : *v) {
            if (time == 0) time = i.second;
            else if (time <= i.first) time = i.second;
            else tmp->push_back(i);
        }
        (*v).clear();
        temp = v;
        v = tmp;
        tmp = v;
    }

    cout << ans << endl;
    return 0;
}