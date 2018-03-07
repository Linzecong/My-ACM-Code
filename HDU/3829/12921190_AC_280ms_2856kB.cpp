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
const int MAXN = 505;

int G[MAXN][MAXN];
int N, M, P;

vector<pair<string, string>> chs;

//匈牙利算法
bool vis[MAXN];
int Y[MAXN];
bool hungry(int x)
{
    for (int i = 0; i < P; i++)
    {

        if (vis[i] == 0 && G[x][i])
        {
            vis[i] = 1;
            if (Y[i] == -1 || hungry(Y[i]))
            {
                Y[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    while (~scanf("%d%d%d", &N, &M, &P))
    {

        chs.clear();
        memset(G, 0, sizeof(G));
        string a, b;
        for (int i = 0; i < P; i++)
        {
            cin >> a >> b;
            chs.push_back(make_pair(a, b));
        }

        for (int i = 0; i < P; i++)
            for (int j = 0; j < P; j++)
                if (chs[i].first == chs[j].second || chs[j].first == chs[i].second)
                    G[i][j] = 1;

        int ans = 0;
        memset(Y, -1, sizeof(Y));
        for (int i = 0; i < P; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (hungry(i))
                ans++;
        }

        printf("%d\n", P - ans / 2);
    }

    return 0;
}