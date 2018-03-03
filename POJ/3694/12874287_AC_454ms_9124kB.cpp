#include <iostream>
#include <vector>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int MAXM = 200010;

struct edge
{
    int u;
    int v;
    int next;
} e[2 * MAXM];
int edge_num, head[MAXN];
void insert_edge(int u, int v)
{
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}

int pre[MAXN];
int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}
void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        pre[fx] = fy;
}

int N, M;
int dfn[MAXN], low[MAXN], vis[MAXN];

int fa[MAXN], isGB[MAXN];
int ans;

void GB(int u, int last, int vistime)
{
    dfn[u] = low[u] = vistime;
    vis[u] = 1;
    fa[u] = last;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;

        if (vis[v] == 1 && v != last)
            low[u] = min(low[u], dfn[v]);

        if (!vis[v])
        {

            GB(v, u, vistime + 1);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v])
            {
                ans++;
            }
            else
            {
                join(u, v);
            }
        }
    }
    vis[u] = 2;
}

void func(int u)
{
    int fx = find(u);
    int fy = find(fa[u]);
    if (fx != fy)
    {
        ans--;
        pre[fx] = fy;
    }
}

void LCA(int u, int v)
{

    while (dfn[u] > dfn[v])
    {
        func(u);
        u = fa[u];
    }

    while (dfn[v] > dfn[u])
    {
        func(v);
        v = fa[v];
    }

    while (u != v)
    {
        func(u);
        func(v);
        u = fa[u];
        v = fa[v];
    }
}

int main()
{
    int t = 1;
    while (~scanf("%d%d", &N, &M))
    {
        if (N == 0 && M == 0)
            break;
        memset(head, -1, sizeof(head));
        edge_num = 0;
        int u, v;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &u, &v);
            insert_edge(u, v);
            insert_edge(v, u);
        }

        ans = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= N; i++)
            pre[i] = i;

        GB(1, 0, 1);

        printf("Case %d:\n", t++);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &u, &v);
            if (find(u) != find(v))
                LCA(u, v);
            printf("%d\n", ans);
        }
        printf("\n");
    }
}