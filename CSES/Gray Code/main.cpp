#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int total;

    cin >> n;
    total = pow(2, n);
    for (int i = 0; i < total; i++) {
        int ans = i ^ (i >> 1);
        string b;
        for (int j = 0; j < n; j++) {
            b.insert(b.begin(), 1, (ans % 2) + '0');
            ans /= 2;
        }
        cout << b << endl;
    }
    
    return 0;
}