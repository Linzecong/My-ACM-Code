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

const int MAXN = 10005;

vector<int> G[MAXN];
int N, M;
int color[MAXN];
int dfn[MAXN];
int low[MAXN];
int vis[MAXN];
int instack[MAXN];
int sta[MAXN];
int cnt = 0;
int vistime = 1;
int col = 1;

int indegree[MAXN];
int outdegree[MAXN];

void init()
{

    for (int i = 0; i < MAXN; i++)
        G[i].clear();
    memset(color, 0, sizeof(color));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(instack, 0, sizeof(instack));
    memset(sta, 0, sizeof(sta));
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
    cnt = 0;
    vistime = 1;
    col = 1;
}

void tarjan(int v1, int fa)
{
    dfn[v1] = low[v1] = vistime;
    vistime++;

    vis[v1] = 1;

    sta[cnt++] = v1;
    instack[v1] = 1;

    int flag=0;
    for (int i = 0; i < G[v1].size(); i++)
    {
        if (G[v1][i] == fa&&!flag){
            flag=1;
            continue;
        }
            

        if (!vis[G[v1][i]])
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
                outdegree[color[i]]++;
            }
        }
    }
}

int main()
{

    scanf("%d%d", &N, &M);
    init();
    int temp;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        if (!vis[i])
            tarjan(i, -1);

    SD();

    int ans = 0;
    for (int i = 1; i < col; i++)
    {
        if (outdegree[i] == 1)
            ans++;
    }
    printf("%d\n", (ans + 1) / 2);

    return 0;
}