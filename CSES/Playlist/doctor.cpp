#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    unordered_map<int, int> m;
    int left = 0, right = 0;
    int mx = 0;
    while (right < n) {
        if(m.find(arr[n]) == m.end()) {
            m[arr[right]] = right;
            mx++;
            right++;
        } else {
            left = m[arr[right]]+1;
            right++;
            mx = max(mx, right-left+1);
        }
    }
    cout << mx << endl;
}