#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Item;

int main() {
    vector<Item> v;

    int n, t, sum, left, right;

    cin >> n >> sum;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        v.push_back({t, i});
    }

    sort(v.begin(), v.end());

    left = 0;
    right = n - 1;
    while (left < right) {
        if (v[left].first + v[right].first == sum) {
            if (v[left].second < v[right].second) {
                cout << v[left].second << " " << v[right].second << endl;
            } else {
                cout << v[right].second << " " << v[left].second << endl;
            }
            return 0;
        } else if (v[left].first + v[right].first < sum) {
            left += 1;
        } else right -= 1;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}