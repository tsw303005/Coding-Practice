#include <iostream>
#include <unordered_map>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_map<int, int> s;
    int n, t, max, left;
 
    cin >> n;
    max = 0;
    left = 0;
    s.rehash(n);
 
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (s[t] > left) {
            left = s[t];
        }
        s[t] = i;
        max = (max < i - left) ? i - left : max;
    }
    cout << max << "\n";
 
    return 0;
}