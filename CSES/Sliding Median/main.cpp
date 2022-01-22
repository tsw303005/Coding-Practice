#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    multiset<int> mx;
    multiset<int> mi;
    vector<int> index_v;
    vector<int> v;
    int n, k, t, mid;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> t;
        v.push_back(t);
        index_v.push_back(t);
    }

    sort(v.begin(), v.end());

    mid = k / 2;
    if (k % 2) {
        for (int i = 0; i < mid; i++) {
            mi.insert(v[i]);
            mx.insert(v[mid + i + 1]);
        }
        mi.insert(v[mid]);
    } else {
        for (int i = 0; i < mid; i++) {
            mi.insert(v[i]);
            mx.insert(v[mid + i]);
        }
    }

    mid = *(mi.rbegin());

    cout << mid;
    for (int i = k; i < n; i++) {
        cin >> t;

        // delete number
        if (mi.find(index_v[i-k]) != mi.end()) {
            mi.erase(mi.find(index_v[i-k]));
        } else {
            mx.erase(mx.find(index_v[i-k]));
        }
        index_v.push_back(t);

        if (mid < t) mx.insert(t);
        else mi.insert(t);
        // maintain
        if (k % 2 && mx.size() + 1 < mi.size()) {
            while (mx.size() + 1 < mi.size()) {
                mx.insert(*mi.rbegin());
                mi.erase(mi.find(*mi.rbegin()));
            }
        } else if (k % 2 && mx.size() + 1 > mi.size()) {
            while (mx.size() + 1 > mi.size()) {
                mi.insert(*mx.begin());
                mx.erase(mx.find(*mx.begin()));
            }
        } else if (k % 2 == 0 && mx.size() < mi.size()) {
            while (mx.size() < mi.size()) {
                mx.insert(*mi.rbegin());
                mi.erase(mi.find(*mi.rbegin()));
            }
        } else if (k % 2 == 0 && mx.size() > mi.size()) {
            while (mx.size() > mi.size()) {
                mi.insert(*mx.begin());
                mx.erase(mx.find(*mx.begin()));
            }
        }
        mid = *mi.rbegin();
        cout << ' ' << mid;
    }

    cout << "\n";

    return 0;
}