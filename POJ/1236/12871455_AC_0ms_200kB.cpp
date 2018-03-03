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

vector<int> G[105];
int N;
int color[105];
int dfn[105];
int low[105];
int vis[105];
int instack[105];
int sta[105];
int cnt = 0;
int vistime = 1;
int col = 1;

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

int indegree[105];
int outdegree[105];

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

    int temp;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        while (1)
        {
            scanf("%d", &temp);
            if (temp == 0)
                break;
            G[i].push_back(temp);
        }
    }

    for (int i = 1; i <= N; i++)
        if (!vis[i])
            tarjan(i);

    // for (int i = 1; i <= N; i++)
    //     cout << color[i] << " ";

    SD();

    int t1 = 0, t2 = 0;
    for (int i = 1; i < col; i++)
    {
        if (indegree[i] == 0)
            t1++;
        if (outdegree[i] == 0)
            t2++;
    }

    if (col == 2)
        printf("1\n0\n");
    else
        printf("%d\n%d\n", t1, max(t1, t2));

    return 0;
}