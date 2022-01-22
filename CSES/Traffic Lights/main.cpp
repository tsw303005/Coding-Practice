#include <iostream>
#include <set>
#include <utility>


using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    set<int> order;
    multiset<int> len;
    int x, n, t, right, left, flag, ans, max;

    cin >> x >> n;
    flag = 0;
    ans = 0;
    max = 0;
    order.clear();
    order.insert(0);
    order.insert(x);
    len.insert(x);

    for (int i = 0; i < n; i++) {
        cin >> t;
        left = *(--order.lower_bound(t));
        right = *(order.upper_bound(t));
        order.insert(t);
        len.erase(len.find(right - left));
        len.insert(t - left);
        len.insert(right - t);
        if (flag) cout << ' ';
        else flag = 1;
        cout << *len.rbegin();
    }
    cout << '\n';

    return 0;
}