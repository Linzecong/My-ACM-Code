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

int N, M;
int vistime = 0;
int dfn[MAXN], low[MAXN], vis[MAXN];

int fa[MAXN], isGB[MAXN];
int ans;

void GB(int u, int last)
{
    dfn[u] = low[u] = ++vistime;
    vis[u] = 1;

    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == last)
            continue;
        if (!vis[v])
        {
            fa[v] = u;
            GB(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v])
            {
                ans++;
                isGB[v] = 1;
            }
        }
        else
        {
            if (vis[v] == 1)
                low[u] = min(low[u], dfn[v]);
        }
    }
    vis[u] = 2;
}

void LCA(int u, int v)
{
    while (dfn[v] > dfn[u])
    {
        if (isGB[v])
            ans--;
        isGB[v] = 0;
        v = fa[v];
    }

    while (dfn[u] > dfn[v])
    {
        if (isGB[u])
            ans--;
        isGB[u] = 0;
        u = fa[u];
    }

    while (u != v)
    {
        if (isGB[u])
            ans--;
        if (isGB[v])
            ans--;
        isGB[u] = isGB[v] = 0;
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

        ans = vistime = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(isGB, 0, sizeof(isGB));
        memset(vis, 0, sizeof(vis));
        fa[1] = 1;
        GB(1, 0);

        printf("Case %d:\n", t++);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &u, &v);
            LCA(u, v);
            printf("%d\n", ans);
        }
        printf("\n");
    }
}