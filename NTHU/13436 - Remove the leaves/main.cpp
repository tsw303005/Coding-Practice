#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, k, u, v, flag;

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> n >> k;

        vector<vector<int> > V(n + 1);
        vector<int> C(n + 1, 0);
        queue<int> Q;
        flag = 1;

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
            C[u]++;
            C[v]++;
        }

        if (k >= n - 1) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (C[i] == 1) Q.push(i);
        }

        for (int i = 0; i < k; i++) {
            if (n <= 2) {
                flag = 0;
                break;
            }

            int size = Q.size();

            for (int j = 0; j < size; j++) {
                int now = Q.front();

                n -= 1;
                Q.pop();
                C[now] = 0;

                for (auto node : V[now]) {
                    if (C[node] != 0) C[node]--;
                    if (C[node] == 1) Q.push(node);
                }
            }
        }
        if (!flag) cout << 0 << endl;
        else cout << n << endl;
    }


    return 0;
}