#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    char c;
    int hour;
    int minute;
    int i;
    double angle = 0;
    double one_clock = 360.0 / 12.0;
    double minute_head;
    double hour_head;
    double ans;

    while (cin >> input) {
        if (input == "0:00") break;
        hour = minute = 0;
        angle = 0.0;
        for (i = 0; input[i] != ':'; i++) {
            hour *= 10;
            hour = hour + (input[i] - '0');
        }
        hour %= 12;
        i++;
        for (; i < input.length(); i++) {
            minute *= 10;
            minute = minute + (input[i] - '0');
        }
        hour_head = (double)hour * 30.0 + one_clock * (double)minute / 60.0;
        minute_head = (double)minute / 5.0 * one_clock;
        hour_head -= minute_head;
        ans = hour_head >= 0 ? hour_head : -1 * hour_head;
        ans = (ans > 180.0) ? 360.0 - ans : ans;
        printf("%.3lf\n", ans);
    }

    return 0;
}