#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
const int MAXN = 400010;
const int INF = 0x3f3f3f3f;
typedef long long ll;

struct edge
{
    int u, v, cap, cost, next;
} e[4 * MAXN];

int edge_num;
int head[MAXN];

void insert_edge(int u, int v, int cap, int cost)
{
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].cap = cap;
    e[edge_num].cost = cost;
    e[edge_num].next = head[u];
    head[u] = edge_num++;

    //反向边 k^1即可求出反向边
    e[edge_num].u = v;
    e[edge_num].v = u;
    e[edge_num].cap = 0;      //注意这里
    e[edge_num].cost = -cost; //注意这里
    e[edge_num].next = head[v];
    head[v] = edge_num++;
}

int dis[MAXN];
int pre[MAXN];
bool vis[MAXN];
bool spfa(int s, int t)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));

    dis[s] = 0;
    vis[s] = 1;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        vis[tp] = 0;
        for (int i = head[tp]; ~i; i = e[i].next)
        {
            int v = e[i].v;
            int cost = e[i].cost;

            if (e[i].cap && dis[v] > dis[tp] + cost)
            {
                dis[v] = dis[tp] + cost;
                pre[v] = i;
                if (!vis[v])
                {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }
    if (dis[t] == INF)
        return false;
    return true;
}

pair<int, int> MCMF(int s, int t)
{
    int maxflow = 0;
    int mincost = 0;
    int minc;
    while (spfa(s, t))
    {
        minc = INF;
        int cost = 0;
        for (int i = pre[t]; ~i; i = pre[e[i].u])
            minc = min(minc, e[i].cap);
        for (int i = pre[t]; ~i; i = pre[e[i].u])
        {
            e[i].cap -= minc;
            e[i ^ 1].cap += minc;
            cost += minc * e[i].cost; //flow*unit cost=total cost
        }
        mincost += cost;
        maxflow += minc;
    }
    return make_pair(mincost, maxflow);
}

struct node
{
    int b, e, w, op;
} p[MAXN];

bool cmp(node a,node b){
    if(a.b==b.b)
        return a.e<b.e;
    return a.b<b.b;
}

int tot = 0;

int in[MAXN];
int out[MAXN];
int S, SK, T;

int main()
{
    int TT;
    scanf("%d", &TT);
    while (TT--)
    {

        edge_num = 0;
        memset(head, -1, sizeof(head));
        tot = 0;

        int N, M, K, W;
        scanf("%d%d%d%d", &N, &M, &K, &W);
        int a, b, c, d;
        for (int i = 1; i <= M; i++)
            scanf("%d%d%d%d", &p[i].b, &p[i].e, &p[i].w, &p[i].op);
        sort(p+1,p+1+M,cmp);
        
        
        S = ++tot;
        SK = ++tot;
        for (int i = 1; i <= M; i++)
        {
            in[i] = ++tot;
            out[i] = ++tot;
        }
        T = ++tot;

        insert_edge(S, SK, K, 0);
        for (int i = 1; i <= M; i++)
            insert_edge(SK, in[i], 1, 0);
        for (int i = 1; i <= M; i++)
            insert_edge(in[i], out[i], 1, -p[i].w);
        for (int i = 1; i <= M; i++)
            insert_edge(out[i], T, 1, 0);

        for (int i = 1; i <= M; i++)
            for (int j = i + 1; j <= M; j++)
                if (p[j].b >= p[i].e)
                    insert_edge(out[i], in[j], 1, p[j].op == p[i].op ? W : 0);

        printf("%d\n", -MCMF(S, T).first);
    }

    return 0;
}