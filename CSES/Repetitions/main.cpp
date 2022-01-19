#include <iostream>

using namespace std;

int main() {
    char prev, c;
    int max = 1;
    int now = 1;

    prev = getchar();
    while ((c = getchar()) != '\n') {
        if (prev == c) now += 1;
        else prev = c, now = 1;
        if (now > max) max = now;
    }

    cout << max << endl;


    return 0;
}