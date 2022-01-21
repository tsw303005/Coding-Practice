// Not pass

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_map<int, int> m;
    int n, t, max, left;

    cin >> n;
    max = 0;
    left = 0;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (m.find(t) == m.end()) m[t] = i;
        else {
            left = m[t];
            m[t] = i;
        }
        max = (i - left > max) ? i - left : max; 
    }

    cout << max << endl;


    return 0;
}