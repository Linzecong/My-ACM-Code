#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 100005;

struct edge
{
    int u;
    int v;
    int next;
} e[MAXM];
int head[MAXN], edge_num;
void insert_edge(int u, int v)
{
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}

struct query
{
    int type;
    int x, y;
} q[MAXM];

map<pair<int, int>, int> es;

int N, M, Q;

//边双联通部分
int vistime;
int dfn[MAXN];
int low[MAXN];
int col[MAXN];
int cnt;
bool isbridge[MAXM];

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++vistime;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                isbridge[i] = isbridge[i ^ 1] = true;
        }
        else if (dfn[v] < dfn[u] && v != fa)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void SD(int u)
{
    dfn[u] = 1;
    col[u] = cnt;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (isbridge[i])
            continue;
        if (!dfn[v])
            SD(v);
    }
}

edge ne[MAXM];
int nhead[MAXN], nedge_num;
void newinsert(int u, int v)
{
    ne[nedge_num].u = u;
    ne[nedge_num].v = v;
    ne[nedge_num].next = nhead[u];
    nhead[u] = nedge_num++;
}

void rebuild()
{
    nedge_num = 0;
    memset(nhead, -1, sizeof(nhead));
    es.clear();


    for (int i = 0; i < edge_num; i++)
    {
        if (col[e[i].u] != col[e[i].v])
        {
            es[make_pair(min(col[e[i].u], col[e[i].v]),max(col[e[i].u], col[e[i].v]))]=1;
        }
    }

    for (auto &it : es)
    {

        newinsert(it.first.first, it.first.second);
        newinsert(it.first.second, it.first.first);
    }

//    for (int i = 0; i < nedge_num; i++)
//    {
//        printf("%d %d\n",ne[i].u,ne[i].v);
//    }

}

//树链剖分部分
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int siz[MAXN];
int pos[MAXN];
int son[MAXN];
int SEG;
void dfs1(int u, int pre, int d)
{
    if (siz[u] != 0) //有可能有重边，排除之
        return;
    deep[u] = d;
    fa[u] = pre;
    siz[u] = 1;
    for (int i = nhead[u]; ~i; i = ne[i].next)
    {
        int v = ne[i].v;
        if (v != pre)
        {
            dfs1(v, u, d + 1);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
}
void dfs2(int u, int sp)
{
    top[u] = sp;
    if (son[u] != -1)
    {
        pos[u] = SEG++;
        dfs2(son[u], sp);
    }
    else
    {
        pos[u] = SEG++;
        return;
    }
    for (int i = nhead[u]; ~i; i = ne[i].next)
        if (ne[i].v != son[u] && ne[i].v != fa[u])
            dfs2(ne[i].v, ne[i].v);
}

//线段树部分
int sum[MAXN << 2];
int lazy[MAXN << 2];
void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt)
{
    lazy[rt] = -1;
    if (l == r)
    {
        sum[rt] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}
void pushdown(int rt, int ln, int rn)
{
    if (lazy[rt] != -1)
    {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        sum[rt << 1] = lazy[rt] * ln;
        sum[rt << 1 | 1] = lazy[rt] * rn;
        lazy[rt] = -1;
    }
}
void update(int L, int R, int C, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        sum[rt] = C * (r - l + 1);
        lazy[rt] = C;
        return;
    }
    int m = (l + r) / 2;
    pushdown(rt, m - l + 1, r - m);
    if (L <= m)
        update(L, R, C, l, m, rt << 1);
    if (R > m)
        update(L, R, C, m + 1, r, rt << 1 | 1);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];
    int m = (l + r) / 2;
    pushdown(rt, m - l + 1, r - m);
    int ans = 0;
    if (L <= m)
        ans += query(L, R, l, m, rt << 1);
    if (R > m)
        ans += query(L, R, m + 1, r, rt << 1 | 1);
    return ans;
}

//树链剖分+线段树部分
int query(int u, int v)
{
    int f1 = top[u];
    int f2 = top[v];
    int ans = 0;
    while (f1 != f2)
    {
        if (deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        ans += query(pos[f1], pos[u], 1, cnt, 1);
        u = fa[f1];
        f1 = top[u];
    }
    if (u == v)
        return ans;
    if (deep[u] > deep[v])
        swap(u, v);
    return ans + query(pos[son[u]], pos[v], 1, cnt, 1);
}

void update(int u, int v)
{
    int f1 = top[u];
    int f2 = top[v];
    while (f1 != f2)
    {
        if (deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        update(pos[f1], pos[u], 0, 1, cnt, 1);
        u = fa[f1];
        f1 = top[u];
    }
    if (u == v)
        return;
    if (deep[u] > deep[v])
        swap(u, v);
    update(pos[son[u]], pos[v], 0, 1, cnt, 1);
}

int main()
{

    int t;
    scanf("%d", &t);
    for (int qqq = 1; qqq <= t; qqq++)
    {
        scanf("%d%d%d", &N, &M, &Q);

        edge_num = 0;
        memset(head, -1, sizeof(head));
        es.clear();
        vistime = 0;
        cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(isbridge, 0, sizeof(isbridge));
        memset(col, 0, sizeof(col));
        SEG = 1;
        memset(son, -1, sizeof(son));
        memset(siz, 0, sizeof(siz));

        int u, v;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &u, &v);
            es[make_pair(min(u, v), max(u, v))]++;
        }

        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d%d", &q[i].type, &q[i].x, &q[i].y);
            if (q[i].type == 1)
                es[make_pair(min(q[i].x, q[i].y), max(q[i].x, q[i].y))]--;
        }

        for (auto &it : es)
        {
            for (int i = 0; i < it.second; i++)
            {
                insert_edge(it.first.first, it.first.second);
                insert_edge(it.first.second, it.first.first);
            }
        }

        for (int i = 1; i <= N; i++)
            if (!dfn[i])
                tarjan(i, -1);
        memset(dfn, 0, sizeof(dfn));
        for (int i = 1; i <= N; i++)
            if (!dfn[i])
            {
                cnt++;
                SD(i);
            }
        rebuild();

        dfs1(1, 0, 0);
        dfs2(1, 1);
        build(1, cnt, 1);

        vector<int> ans;
        for (int i = Q - 1; i >= 0; i--)
            if (q[i].type == 1)
                update(col[q[i].x], col[q[i].y]);
            else
                ans.push_back(query(col[q[i].x], col[q[i].y]));

        printf("Case #%d:\n", qqq);
        for (int i = ans.size() - 1; i >= 0; i--)
            printf("%d\n", ans[i]);
    }
}
