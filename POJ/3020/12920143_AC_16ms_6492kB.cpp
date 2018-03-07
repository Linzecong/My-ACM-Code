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
const int MAXN = 605;

char maze[MAXN][MAXN];

vector<int> G[MAXN*MAXN];
int temp[MAXN][MAXN];
int cnt;
int N, M;

//匈牙利算法
bool vis[MAXN];
int Y[MAXN];
bool hungry(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        if (vis[G[x][i]] == 0)
        {
            vis[G[x][i]] = 1;
            if (Y[G[x][i]] == -1 || hungry(Y[G[x][i]]))
            {
                Y[G[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int ttt;
    scanf("%d", &ttt);
    for (int qqq = 1; qqq <= ttt; qqq++)
    {
        memset(temp, 0, sizeof(temp));
        cnt = 0;

        scanf("%d%d", &N, &M);

        for (int i = 0; i < N; i++)
        {
            scanf("%s", maze[i]);
            for (int j = 0; j < M; j++)
                if (maze[i][j] == '*')
                    temp[i][j] = cnt++;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (maze[i][j] == 'o')
                    continue;

                if (j > 0 && maze[i][j - 1] == '*')
                    G[temp[i][j]].push_back(temp[i][j - 1]);
                if (j < M - 1 && maze[i][j + 1] == '*')
                    G[temp[i][j]].push_back(temp[i][j + 1]);
                if (i > 0 && maze[i - 1][j] == '*')
                    G[temp[i][j]].push_back(temp[i - 1][j]);
                if (i < N - 1 && maze[i + 1][j] == '*')
                    G[temp[i][j]].push_back(temp[i + 1][j]);
            }

        int ans = 0;
        memset(Y, -1, sizeof(Y));
        for (int i = 0; i < cnt; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (hungry(i))
                ans++;
        }
        for (int i = 0; i < cnt; i++)
        {
            G[i].clear();
        }

        printf("%d\n", ans / 2 + (cnt - ans));
    }

    return 0;
}
