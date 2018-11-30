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

#define maxn 400    //最大点的个数
#define maxm 400005 //最大边的个数
#define INF 0x3f3f3f3f
int gra[60][60];
struct Edge
{
    int to, next, cap, flow, from;
    Edge() {}
    Edge(int from, int to, int next, int cap, int flow) : from(from), to(to), next(next), cap(cap), flow(flow) {}
} edge[maxm];

int vs, vt, VN;
int tot;
int first[maxn];
int gap[maxn], dep[maxn], cur[maxn];
void addedge(int u, int v, int w)
{
    edge[tot] = Edge(u, v, first[u], w, 0);
    first[u] = tot++;
    edge[tot] = Edge(v, u, first[v], 0, 0);
    first[v] = tot++;
}
int q[maxn];
void bfs(int vt)
{
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[vt] = 0;
    q[rear++] = vt;
    while (front != rear)
    {
        int u = q[front++];
        for (int i = first[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dep[v] != -1)
                continue;
            q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}

int S[maxn];
int sap(int vs, int vt, int VN) //VN表示总的点数,vs表示起点,vt表示终点
{
    bfs(vt);
    memcpy(cur, first, sizeof(first));
    int top = 0, u = vs, ans = 0;
    while (dep[vs] < VN)
    {
        if (u == vt)
        {
            int Min = INF, inser;
            for (int i = 0; i < top; i++)
            {
                if (Min > edge[S[i]].cap - edge[S[i]].flow)
                {
                    Min = edge[S[i]].cap - edge[S[i]].flow;
                    inser = i;
                }
            }
            for (int i = 0; i < top; i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i] ^ 1].flow -= Min;
                //edge[S[i]].cap-=Min;
                //edge[S[i]^1].cap+=Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top] ^ 1].to;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
            {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if (flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = VN;
        for (int i = first[u]; i != -1; i = edge[i].next)
        {
            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if (!gap[dep[u]])
            return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != vs)
            u = edge[S[--top] ^ 1].to;
    }
    return ans;
}

//用于输出路径
int vis[100];
void bfs()
{
    int front, rear;
    front = 1;
    rear = 1;
    q[rear] = vs;
    int x, v, i;
    while (front <= rear)
    {
        x = q[front];
        front++;
        for (i = first[x]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (vis[v])
                continue;
            if (edge[i].cap && edge[i].cap > edge[i].flow)
            {
                rear++;
                q[rear] = v;
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    int n, m, i, j, c, d, f, u, v;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        tot = 0;
        memset(first, -1, sizeof(first));
        VN = n, vs = 1, vt = 2;

        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &c, &d, &f);
            addedge(c, d, f);
            addedge(d, c, f);
        }
        sap(vs, vt, VN);

        //输出路径
        memset(vis, 0, sizeof(vis));
        vis[vs] = 1;
        bfs();

        memset(gra, 0, sizeof(gra)); //gra保存的是答案
        for (i = 1; i <= tot; i++)
        {
            int u = edge[i].from;
            int v = edge[i].to;
            if (u > v)
                swap(u, v);
            if ((vis[u] && !vis[v]) || (!vis[u] && vis[v]))
            {
                gra[u][v] = gra[v][u] = 1;
            }
        }

        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (gra[i][j])
                {
                    printf("%d %d\n", i, j);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
