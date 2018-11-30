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
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int N, M;
char maze[200][200];
int cnt = 1;
int in[MAXN];
int on[MAXN];

//最小费用最大流部分！！
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

int dis[MAXN]; //记录最短距离
int pre[MAXN]; //记录最短路径(记录边)
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

pair<int, int> Min_Cost_Max_Flow(int s, int t)
{
    int maxflow = 0;
    int mincost = 0;
    int minc;
    while (spfa(s, t))
    {
        minc = INF;
        for (int i = pre[t]; ~i; i = pre[e[i].u])
            minc = min(minc, e[i].cap);
        for (int i = pre[t]; ~i; i = pre[e[i].u])
        {
            e[i].cap -= minc;
            e[i ^ 1].cap += minc;
        }
        mincost += dis[t];
        maxflow += minc;
    }
    return make_pair(mincost, maxflow);
}

int main()
{

    while (~scanf("%d%d", &N, &M))
    {
        if (N == 0 && M == 0)
            break;

        memset(head, -1, sizeof(head));
        edge_num = 0;
        cnt = 1;

        vector<pair<int, int> > HH;
        vector<pair<int, int> > mm;

        for (int i = 1; i <= N; i++)
        {
            scanf("%s", maze[i] + 1);
            for (int j = 1; j <= M; j++)
            {
                if (maze[i][j] == 'H')
                    HH.push_back(make_pair(i, j));
                if (maze[i][j] == 'm')
                    mm.push_back(make_pair(i, j));
            }
        }

        int S = cnt++;
        for (int i = 0; i < mm.size(); i++)
            in[i] = cnt++;
        for (int i = 0; i < HH.size(); i++)
            on[i] = cnt++;

        int T = cnt++;

        for (int i = 0; i < mm.size(); i++)
        {
            insert_edge(S, in[i], 1, 0);
        }

        for (int i = 0; i < HH.size(); i++)
        {
            insert_edge(on[i], T, 1, 0);
        }

        for (int i = 0; i < mm.size(); i++)
            for (int j = 0; j < HH.size(); j++)
                insert_edge(in[i], on[j], INF, abs(mm[i].first - HH[j].first) + abs(mm[i].second - HH[j].second));

        printf("%d\n", Min_Cost_Max_Flow(S, T).first);
    }

    return 0;
}