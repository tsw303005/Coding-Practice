#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ans;
int nm[15] = {0};
int vert[15] = {0};
int right[1000] = {0};
int left[1000] = {0};
int map[100][100] = {0};

void Nq_and_Mr(int n, int m, int now, int layer)
{
    if (layer + 1 == now)
    {
        ans++;
        return ;
    }
    if (m != 0)
    {
        for (int i = 1; i <= layer; i++)
        {
            if (vert[i] == 1 || left[i+now] == 2 || right[now-i+layer] == 2) continue;
            left[i+now] += 3;
            right[now-i+layer] += 3;
            vert[i] = 1;
            Nq_and_Mr(n, m-1, now+1, layer);
            left[i+now] -= 3;
            right[now-i+layer] -= 3;
            vert[i] = 0;
        }
    }
    if (n != 0)
    {
        for (int i = 1; i <= layer; i++)
        {
            if (vert[i] == 1 || left[i+now] != 0 || right[now-i+layer] != 0) continue;
            left[i+now] = 2;
            right[now-i+layer] = 2;
            vert[i] = 1;
            Nq_and_Mr(n-1, m, now+1, layer);
            left[i+now] = 0;
            right[now-i+layer] = 0;
            vert[i] = 0;
        }
    }
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        ans = 0;
        Nq_and_Mr(n, m, 1, n+m);
        printf("%d\n", ans);
    }
    return 0;
}