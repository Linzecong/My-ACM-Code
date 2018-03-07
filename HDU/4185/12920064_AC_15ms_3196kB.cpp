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

vector<int> G[MAXN];
int temp[MAXN][MAXN];
int cnt;
int N;

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
        memset(G, 0, sizeof(G));
        cnt = 0;

        scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            scanf("%s", maze[i]);
            for (int j = 0; j < N; j++)
                if (maze[i][j] == '#')
                    temp[i][j] = cnt++;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (maze[i][j] == '.')
                    continue;

                if (j > 0 && maze[i][j - 1] == '#')
                    G[temp[i][j]].push_back(temp[i][j - 1]);
                if (j < N - 1 && maze[i][j + 1] == '#')
                    G[temp[i][j]].push_back(temp[i][j + 1]);
                if (i > 0 && maze[i - 1][j] == '#')
                    G[temp[i][j]].push_back(temp[i - 1][j]);
                if (i < N - 1 && maze[i + 1][j] == '#')
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

        printf("Case %d: %d\n", qqq, ans / 2);
    }

    return 0;
}
