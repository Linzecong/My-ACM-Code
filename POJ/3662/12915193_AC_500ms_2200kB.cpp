#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;

struct edge
{
    int u, v, w, next;
} e[100005];
int head[100005], edge_num;
void insert_edge(int u, int v, int w)
{
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].w = w;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}

int N, P, K;

int d[100005];
int vis[100005];
bool diji(int s, int en, int mid)
{
    int i, j, v, minn;
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    vis[s] = true;
    d[s] = 0;

    v = s;

    for (j = 1; j <= N; j++)
    {
        for (i = head[v]; i != -1; i = e[i].next)
        {
            int u1 = e[i].v;

            if (!vis[u1])
            {
                if (d[u1] > d[v] + (e[i].w > mid))

                    d[u1] = d[v] + (e[i].w > mid);
            }
        }
        minn = 0x3f3f3f3f;
        for (i = 1; i <= N; i++)
        {
            if (!vis[i] && d[i] < minn)
            {
                v = i;
                minn = d[i];
            }
        }
        vis[v] = true;
    }

    if (d[N] > K)
        return true;
    return false;
}

int main()
{

    scanf("%d%d%d", &N, &P, &K);
    memset(head, -1, sizeof(head));
    edge_num = 0;

    int u, v, w;
    for (int i = 0; i < P; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        insert_edge(u, v, w);
        insert_edge(v, u, w);
    }
    int l = 0, r = 1000005;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (diji(1, N, m))
            l = m + 1;
        else
            r = m;
    }

    if (l == 1000005)
        printf("%d\n", -1);
    else
        printf("%d\n", l);

    return 0;
}
