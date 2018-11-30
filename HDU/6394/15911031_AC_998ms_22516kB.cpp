#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 100010;
typedef long long ll;

struct edge
{
    int u;
    int v;
    int next;
} e[MAXN<<1];
int head[MAXN], edge_num = 0;
void insert_edge(int u, int v)
{
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}
int W[MAXN];
int N;
int blocksize, blocknum;
int block[MAXN];
int in[MAXN], out[MAXN];
void build()
{
    blocksize = sqrt(N);
    blocknum = N / blocksize;
    if (N / blocksize)
        blocknum++;

    for (int i = 1; i <= N; i++)
        block[i] = (i - 1) / blocksize + 1;
    for (int i = 1; i <= blocknum; i++)
    {
        in[i] = (i - 1) * blocknum + 1;
        out[i] = i * blocksize;
    }
    out[blocknum] = N;
}

int fa[25][MAXN];
int dfn[MAXN];
int tot = 0;
void dfs(int u, int f)
{
    fa[0][u] = f;
    dfn[u] = ++tot;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == f)
            continue;
        dfs(v, u);
    }
}

int Find(int x, int value)
{
    int d = value;
    ;
    int tmp = 0;
    while (d)
    {
        int k = 0;
        while ((1 << (k + 1)) <= d)
            k++;
        tmp = fa[k][x];
        x = tmp;
        d -= (1 << k);
    }
    return x;
}

int cn[MAXN], nxt[MAXN], pre[MAXN]; //跳出本块的次数,跳向的下一块的点,这个点会跳向的位置,下标都是dfn。
void dfs2(int u, int f)
{
    int tmp = Find(u, W[u]);
    pre[dfn[u]] = dfn[tmp];
    //dfs序性质，可以很方便判断是否已经跳出本块
    if (dfn[tmp] < in[block[dfn[u]]])
    {
        cn[dfn[u]] = 1;
        nxt[dfn[u]] = dfn[tmp];
    }
    else
    {
        cn[dfn[u]] = cn[dfn[tmp]] + 1;
        nxt[dfn[u]] = nxt[dfn[tmp]];
    }
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == f)
            continue;
        dfs2(v, u);
    }
}

void update(int u, int v)
{
    int tmp = Find(u, v);
    W[u] = v;
    pre[dfn[u]] = dfn[tmp];
    if (dfn[tmp] < in[block[dfn[u]]])
    {
        cn[dfn[u]] = 1;
        nxt[dfn[u]] = dfn[tmp];
    }
    else
    {
        cn[dfn[u]] = cn[dfn[tmp]] + 1;
        nxt[dfn[u]] = nxt[dfn[tmp]];
    }
    for (int i = dfn[u] + 1; i <= out[block[dfn[u]]]; i++)
    {
        if (pre[i] >= in[block[i]])
        {
            cn[i] = cn[pre[i]] + 1;
            nxt[i] = nxt[pre[i]];
        }
    }
}

int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += cn[x];
        x = nxt[x];
    }
    return ans;
}

void solve()
{
    build();
    dfs(1, -1);
    //倍增预处理
    for (int k = 0; k < 20; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (fa[k][i] < 0)
                fa[k + 1][i] = -1;
            else
                fa[k + 1][i] = fa[k][fa[k][i]];
        }
    }

    dfs2(1, -1);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(head, -1, sizeof(head));
        edge_num = 0;
        tot = 0;

        scanf("%d", &N);
        int x, y;
        for (int i = 2; i <= N; i++)
        {
            scanf("%d", &x);
            insert_edge(i, x);
            insert_edge(x, i);
        }
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &W[i]);
        }
        solve();
        int Q;
        scanf("%d", &Q);
        while (Q--)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                int x;
                scanf("%d", &x);
                printf("%d\n", query(dfn[x]));
            }
            else
            {
                scanf("%d%d", &x, &y);
                update(x, y);
            }
        }
    }

    return 0;
}
