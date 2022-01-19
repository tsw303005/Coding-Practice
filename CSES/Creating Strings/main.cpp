#include <iostream>
#include <math.h>

using namespace std;

int letter[26] = {0};

int fac(int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) result *= i;

    return result;
}

void permutation(int n, int total, string line) {
    if (n == 0) {
        cout << line << endl;
        return ;
    }
    for (int i = 0; i < 26; i++) {
        if (letter[i] != 0) {
            letter[i] -= 1;
            char c = i + 'a';
            permutation(n - 1, total, line + c);
            letter[i] += 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    char c;
    int num = 0;
    int ans;
    while ((c = getchar()) != '\n') letter[c - 'a'] += 1, num++;

    ans = fac(num);
    
    for (int i = 0; i < 26; i++) {
        if (letter[i] != 0) ans /= fac(letter[i]);
    }
    cout << ans << endl;

    permutation(num, num, "");

    return 0;
}