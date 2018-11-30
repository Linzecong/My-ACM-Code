#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 210;
typedef long long ll;

struct Node
{
    int L[MAXN], R[MAXN];
    int ans[2];
} tree[MAXN << 2];

int N, Q;

int fa[MAXN * MAXN];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int G[MAXN][MAXN];

int id(int x, int y)
{
    return (x - 1) * N + y;
}

Node merge(Node a, Node b, int m)
{
    Node c;
    for (int i = 1; i <= N; i++)
    {
        c.L[i] = a.L[i];
        c.R[i] = b.R[i];
        fa[a.L[i]] = a.L[i];
        fa[a.R[i]] = a.R[i];
        fa[b.L[i]] = b.L[i];
        fa[b.R[i]] = b.R[i];
    }

    c.ans[0] = a.ans[0] + b.ans[0];
    c.ans[1] = a.ans[1] + b.ans[1];

    for (int i = 1; i <= N; i++)
    {
        if (G[i][m] == G[i][m + 1])
        {
            int fx = find(a.R[i]);
            int fy = find(b.L[i]);
            if (fx != fy)
            {
                fa[fx] = fy;
                c.ans[G[i][m]]--;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        c.L[i] = find(c.L[i]);
        c.R[i] = find(c.R[i]);
    }
    return c;
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        for (int i = 1; i <= N; i++)
        {
            tree[rt].L[i] = tree[rt].R[i] = fa[id(i, l)] = id(i, l);
            tree[rt].ans[G[i][l]]++;
        }
        for (int i = 2; i <= N; i++)
        {
            if (G[i][l] == G[i - 1][l])
            {
                fa[id(i, l)] = tree[rt].L[i] = tree[rt].R[i] = fa[id(i - 1, l)];
                tree[rt].ans[G[i][l]]--;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    tree[rt] = merge(tree[rt << 1], tree[rt << 1 | 1], m);
}

void update(int C, int l, int r, int rt)
{
    if (l == r)
    {
        tree[rt].ans[0] = tree[rt].ans[1] = 0;
        for (int i = 1; i <= N; i++)
        {
            tree[rt].L[i] = tree[rt].R[i] = fa[id(i, l)] = id(i, l);
            tree[rt].ans[G[i][l]]++;
        }
        for (int i = 2; i <= N; i++)
            if (G[i][l] == G[i - 1][l])
            {
                fa[id(i, l)] = tree[rt].L[i] = tree[rt].R[i] = fa[id(i - 1, l)];
                tree[rt].ans[G[i][l]]--;
            }
        return;
    }
    int m = (l + r) / 2;
    if (C <= m)
        update(C, l, m, rt << 1);
    else
        update(C, m + 1, r, rt << 1 | 1);
    tree[rt] = merge(tree[rt << 1], tree[rt << 1 | 1], m);
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    build(1, N, 1);
    scanf("%d", &Q);
    while (Q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x][y] ^= 1;
        update(y, 1, N, 1);
        printf("%d %d\n", tree[1].ans[1], tree[1].ans[0]);
    }

    return 0;
}
