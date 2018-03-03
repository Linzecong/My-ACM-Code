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

const int MAXN = 300005;

vector<int> G[1005];
int N, M;
int color[1005];
int dfn[1005];
int low[1005];
int vis[1005];
int instack[1005];
int sta[1005];
int cnt = 0;
int vistime = 1;
int col = 1;

int indegree[1005];
int outdegree[1005];

void init()
{

    for (int i = 0; i < 1005; i++)
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

void tarjan(int v1)
{
    dfn[v1] = low[v1] = vistime;
    vistime++;

    vis[v1] = 1;

    sta[cnt++] = v1;
    instack[v1] = 1;

    for (int i = 0; i < G[v1].size(); i++)
    {
        if (!vis[G[v1][i]])
        {
            tarjan(G[v1][i]);
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
            color[temp] = col;
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
                indegree[color[G[i][j]]]++;
            }
        }
    }
}

int main()
{

    int T;
    scanf("%d", &T);
    while (T--)
    {

        init();
        int temp;
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= M; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
        }

        for (int i = 1; i <= N; i++)
            if (!vis[i])
                tarjan(i);

        SD();

        int t1 = 0, t2 = 0, t3 = 0;
        for (int i = 1; i < col; i++)
        {
            if (indegree[i] == 1 && outdegree[i] == 1)
                t1++;
            if (indegree[i] == 0 && outdegree[i] == 1)
                t2++;
            if (indegree[i] == 1 && outdegree[i] == 0)
                t3++;
        }

        if ((t2 == 1 && t3 == 1 && t1 == (col - 3)) || col == 2)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}