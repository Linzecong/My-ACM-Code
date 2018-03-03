#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <deque>
#include <math.h>
#include <stdio.h>
using namespace std;
using namespace std;

typedef long long int ll;

const int MAXN = 200005;
inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9')
        ;
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

vector<int> G[MAXN];
int N, M;
int color[MAXN];
int dfn[MAXN];
int low[MAXN];
int instack[MAXN];
int sta[MAXN];
int cnt = 0;
int vistime = 1;
int col = 1;

//树的直径部分

int dis[MAXN]; //往上走的最长距离
vector<int> childs[MAXN];
int vis[MAXN];
void dfs(int x)
{
    vis[x]=1;
    for (int i = 0; i < childs[x].size(); i++)
    {
        int ch = childs[x][i];
        if (vis[ch])
            continue;
        if (!dis[ch])
        {
            dis[ch] = dis[x] + 1;
            dfs(ch);
        }
    }
}

int longestpath()
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dfs(1);
    int j = 1;
    for (int i = 1; i < col; i++)
        if (dis[i] > dis[j])
            j = i;
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dfs(j);
    j = 1;
    for (int i = 1; i < col; i++)
        if (dis[i] > dis[j])
            j = i;
    return dis[j];
}

void init()
{

    for (int i = 0; i <= N; i++)
        G[i].clear();
    memset(color, 0, sizeof(color));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(instack, 0, sizeof(instack));
    memset(sta, 0, sizeof(sta));
    for (int i = 0; i <= N; i++)
        childs[i].clear();

    cnt = 0;
    vistime = 1;
    col = 1;
}

void tarjan(int v1, int fa)
{
    dfn[v1] = low[v1] = vistime;
    vistime++;

    sta[cnt++] = v1;
    instack[v1] = 1;

    int flag = 0; //因为有重边，所以要记录往回走了多少次。
    for (int i = 0; i < G[v1].size(); i++)
    {
        if (G[v1][i] == fa && !flag)
        {
            flag = 1;
            continue;
        }

        if (!dfn[G[v1][i]])
        {
            tarjan(G[v1][i], v1);
            low[v1] = min(low[v1], low[G[v1][i]]);
        }
        else if (instack[G[v1][i]])
            low[v1] = min(low[v1], dfn[G[v1][i]]);
    }
    if (dfn[v1] == low[v1])
    {
        int temp;
        do
        {
            temp = sta[--cnt];
            color[temp] = col; //缩点
            instack[temp] = 0;

        } while (temp != v1);
        col++;
    }
}

void SD()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            if (color[i] != color[G[i][j]])
            {
                childs[color[i]].push_back(color[G[i][j]]);
                childs[color[G[i][j]]].push_back(color[i]);
            }
        }
    }
}

int main()
{

    while (1)
    {
        scan_d(N);
        scan_d(M);
        if (N == 0 && M == 0)
            break;
        init();
        int temp;
        for (int i = 1; i <= M; i++)
        {
            int a, b;
            scan_d(a);
            scan_d(b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for (int i = 1; i <= N; i++)
            if (!dfn[i])
                tarjan(i, -1);

        SD();
        printf("%d\n", col - 1 - longestpath()-1);
    }
    return 0;
}