#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int cnt = 1; //点的总个数，下标从1开始
int N, M;
int S, T;
typedef struct
{
    int flow;     //流量
    int capacity; //最大容量值
} maps;
maps G[MAXN][MAXN];

int layer[MAXN];              //保存标号所属层
bool countLayer(int s, int e) //宽搜
{
    int v, i;
    queue<int> q;
    memset(layer, 0, sizeof(layer));

    q.push(s);
    layer[s] = 1;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (i = 1; i <= cnt; i++)
            if (!layer[i] && G[v][i].capacity > G[v][i].flow)
            {
                q.push(i);
                layer[i] = layer[v] + 1;
            }
        if (v == e)
            return 1;
    }
    return 0;
}
int dfs(int cur, int cp, int e)
{
    if (cur == e)
        return cp;

    int tmp = cp, t;
    for (int i = 1; i <= cnt; i++)
        if (layer[i] == layer[cur] + 1 && tmp && G[cur][i].capacity > G[cur][i].flow)
        {
            t = dfs(i, min(G[cur][i].capacity - G[cur][i].flow, tmp), e);
            G[cur][i].flow += t;
            G[i][cur].flow -= t;
            tmp -= t;
        }
    return cp - tmp;
}
int Max_Flow_Dinic(int s, int e)
{
    int maxflow = 0;
    while (countLayer(s, e))
        maxflow += dfs(s, INF, e);
    return maxflow;
}

//用于输出路径
int vis[100];
int q[MAXN];
void bfs()
{
    int front, rear;
    front = 1;
    rear = 1;
    q[rear] = S;
    int x, v, i;
    while (front <= rear)
    {
        x = q[front];
        front++;
        for (i = 1; i <= cnt; i++)
        {
            if (G[x][i].capacity)
            {
                v = i;
                if (vis[v])
                    continue;
                if (G[x][i].capacity && G[x][i].capacity > G[x][i].flow)
                {
                    rear++;
                    q[rear] = v;
                    vis[v] = 1;
                }
            }
        }
    }
}

int main()
{

    while (scanf("%d%d", &N, &M) != EOF)
    {
        if (N == 0 && M == 0)
            break;

        cnt = N, S = 1, T = 2;

        int c, d, f;
        memset(G, 0, sizeof(G));
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d%d", &c, &d, &f);
            G[c][d].capacity = f;
            G[d][c].capacity = f;
        }
        Max_Flow_Dinic(S, T);

        //输出路径
        memset(vis, 0, sizeof(vis));
        vis[S] = 1;
        bfs();

        for (int i = 1; i <= cnt; i++)
        {
            for (int j = i+1; j <= cnt; j++)
            {
                if (G[i][j].capacity)
                {
                    if ((vis[i] && !vis[j]) || (!vis[i] && vis[j]))
                    {
                        printf("%d %d\n", i, j);
                    }
                }
            }
        }

        printf("\n");
    }
    return 0;
}
