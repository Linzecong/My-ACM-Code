#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 30005;
const int inf = 0x3f3f3f3f;
typedef long long int ll;

struct edge
{
    int v1, v2, w, next;
} e[MAXV];

int N, M, edge_num;
int head[MAXV], d[MAXV];
bool vis[MAXV];

void insert_edge(int v1, int v2, int w)
{
    e[edge_num].v1 = v1;
    e[edge_num].v2 = v2;
    e[edge_num].w = w;
    e[edge_num].next = head[v1];
    head[v1] = edge_num++;

    e[edge_num].v1 = v2;
    e[edge_num].v2 = v1;
    e[edge_num].w = w;
    e[edge_num].next = head[v2];
    head[v2] = edge_num++;
}

void spfa(int s)
{
    queue<int> que;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; i++)
        d[i] = inf;
    que.push(s);
    d[s] = 0;
    vis[s] = 1;

    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        vis[tp] = 0;

        for (int i = head[tp]; i != -1; i = e[i].next)
            if (d[tp] + e[i].w < d[e[i].v2])
            {
                d[e[i].v2] = d[tp] + e[i].w;
                if (!vis[e[i].v2])
                {
                    vis[e[i].v2] = 1;
                    que.push(e[i].v2);
                }
            }
    }
}

int v[MAXV];
int w[MAXV];
int dp[MAXV];

int main()
{
    int ttt = 0;
    scanf("%d", &ttt);
    for (int qqq = 1; qqq <= ttt; qqq++)
    {

        memset(head, -1, sizeof(head));
        edge_num = 0;

        memset(v, 0, sizeof(v));
        memset(w, 0, sizeof(w));
        memset(dp, 0x3f, sizeof(dp));
        scanf("%d%d", &N, &M);
        int a, b, c;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            insert_edge(a, b, c);
        }
        double total = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &w[i]);
            total += w[i];
        }

        int W = int(total / 2 + 1);

        spfa(0);

        for (int i = 1; i <= N; i++)
        {
            v[i] = d[i];
            // cout<<v[i]<<" ";
        }
        //  cout<<endl;

        dp[0] = 0;
        for (int i = 1; i <= N; i++)
            for (int j = total; j >= w[i]; j--)
                if (dp[j] > dp[j - w[i]] + v[i])
                {
                    dp[j] = dp[j - w[i]] + v[i];
                }

        int ans = inf;
        for (int i = W; i <= total; i++)
        {
            ans = min(ans, dp[i]);
        }
        if (ans >= inf)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
