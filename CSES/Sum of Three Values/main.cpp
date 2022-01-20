#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Item;

int main() {
    vector<Item> v;

    int n, t, sum, num, left, right;

    cin >> n >> sum;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        v.push_back({t, i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        left = i + 1;
        right = n - 1;
        num = sum - v[i].first;
        while (left < right) {
            if (v[left].first + v[right].first == num) {
                cout << v[i].second << " " << v[left].second << " " << v[right].second << endl;
                return 0;
            } else if (v[left].first + v[right].first < num) {
                left += 1;
            } else right -= 1;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}