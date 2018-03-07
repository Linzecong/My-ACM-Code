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
const int MAXN = 1505;

vector<int> G[MAXN];
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

    while (~scanf("%d", &N))
    {
        int node, num, temp;
        for (int i = 0; i < N; i++)
        {
            G[i].clear();
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d:(%d)", &node, &num);

            for (int j = 0; j < num; j++)
            {
                scanf("%d", &temp);
                G[node].push_back(temp);
                G[temp].push_back(node);
            }
        }

        int ans = 0;
        memset(Y, -1, sizeof(Y));
        for (int i = 0; i < N; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (hungry(i))
                ans++;
        }

        printf("%d\n", ans / 2);
    }

    return 0;
}