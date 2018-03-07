#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;

const int MAXN = 300;

int G[MAXN][MAXN]; //连线
int N, M;
//二分图匹配部分
int used[MAXN];
int Y[MAXN];
bool hungry(int x)
{
    for (int i = 1; i <= N; i++)
    {
        if (G[x][i] && !used[i])
        {
            used[i] = 1;
            if (Y[i] == 0 || hungry(Y[i]))
            {
                Y[i] = x;
                return true;
            }
        }
    }
    return false;
}

bool bfs()
{
    queue<int> que;
    que.push(1);
    used[1] = true;

    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        for (int j = 1; j <= N; j++)
        {
            if (G[tp][j])
            {
                if (used[j] == 0)
                {
                    if (used[tp] == 1)
                        used[j] = 2;
                    else
                        used[j] = 1;
                    que.push(j);
                }
                else if (used[j] == used[tp])
                    return false;
            }
        }
    }
    return true;
}

int main()
{

    while (~scanf("%d%d", &N, &M))
    {
        memset(G, 0, sizeof(G));
        memset(used, 0, sizeof(used));
        memset(Y, 0, sizeof(Y));

        int a, b;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);
            G[a][b] = 1;
            G[b][a] = 1;
        }

        int flag = bfs();

        if (flag == 0)
            printf("No\n");
        else
        {
            int ans = 0;
            for (int i = 1; i <= N; i++)
            {
                memset(used, 0, sizeof(used));
                if (hungry(i))
                    ans++;
            }
            printf("%d\n", ans / 2);
        }
    }

    return 0;
}
