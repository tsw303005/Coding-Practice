#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> Item;

void PrintAns(int a, int b, int c) {
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(c);
    sort(ans.begin(), ans.end());

    for (int i = 0; i < 3; i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<Item> arr;
    int n, sum, t;

    cin >> n >> sum;

    for (int i = 0; i < n; i++) {
        cin >> t;
        arr.push_back({t, i + 1});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2 && arr[i].first < sum && sum - arr[i].first >= arr[i].first; i++) {
        for (int j = i + 1; j < n - 1 && arr[i].first + arr[j].first < sum && sum - arr[i].first - arr[j].first >= arr[j].first; j++) {
            for (int k = j + 1; k < n && arr[i].first + arr[j].first + arr[k].first <= sum; k++) {
                if (arr[i].first + arr[j].first + arr[k].first == sum) {
                    PrintAns(arr[i].second, arr[j].second, arr[k].second);
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}