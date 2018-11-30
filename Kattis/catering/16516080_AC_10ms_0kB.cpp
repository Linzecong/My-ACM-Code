#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50005;
const int INF = 0x3f3f3f3f;

struct edge
{
    int u, v, cap, cost, next;
} e[4 * MAXN];

int edge_num;
int head[300];

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

int dis[300];
int pre[300];
bool vis[300];
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


int N,K;
int SX[MAXN];
int SY[MAXN];
int C[105][105];
int cnt=0;
int main()
{
    edge_num=0;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&N,&K);

    int s=++cnt;
    int t=++cnt;

    int S=++cnt;
    int T=++cnt;
    for(int i=1;i<=N+1;i++){
        SX[i]=++cnt;
        SY[i]=++cnt;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=(N-i)+1;j++){
            scanf("%d",&C[i][i+j]);
            C[i+j][i]=C[i][i+j];
        }
    }

    insert_edge(S,SX[1],K,0);
    for(int i=2;i<=N+1;i++)
        insert_edge(SX[1],SX[i],INF,C[1][i]);

    for(int i=2;i<=N+1;i++){
        insert_edge(s,SY[i],1,0);
        insert_edge(SX[i],t,1,0);

        insert_edge(SY[i],S,INF,0);
    }

    for(int i=2;i<=N;i++)
        for(int j=i+1;j<=N+1;j++){
         //   cout<<C[i][j]<<endl;
            insert_edge(SY[i],SX[j],INF,C[i][j]);
        }

    printf("%d\n",MCMF(s,t).first);



    return 0;
}














