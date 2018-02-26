#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long int ll;

struct edge
{
    int v1;
    int v2;
    ll w;
    int next;
} e[1000005];
int edge_num = 0;
int head[1000005];
void insert_edge(int v1, int v2, ll w)
{
    e[edge_num].v1 = v1;
    e[edge_num].v2 = v2;
    e[edge_num].w = w;
    e[edge_num].next = head[v1];
    head[v1] = edge_num++;
}

int N, M;
ll d[1000005];
int type[1000005];
int near[1000005];

bool vis[1000005];
void spfa()
{
    queue<int> que;
    for (int i = 1; i <= N; i++)
        if (!d[i])
        {
            que.push(i);
            vis[i] = 1;
        }

    while (!que.empty())
    {
        int tp = que.front();
        que.pop();
        vis[tp] = 0;
        for (int i = head[tp]; i!=-1; i = e[i].next)
        {
            int v2 = e[i].v2;
            if (d[tp] + e[i].w < d[v2])
            {
                d[v2] = d[tp] + e[i].w;
                near[v2] = near[tp];
                if (!vis[v2])
                {
                    vis[v2] = 1;
                    que.push(v2);
                }
            }
        }
    }
}

int main()
{

    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &type[i]);
        if (type[i])
        {
            d[i] = 0;
            near[i] = i;
        }
        else
            d[i] = 0x3f3f3f3f3f3f3f3f;
    }

    edge_num = 0;
    memset(head, -1, sizeof(head));
    int v1, v2;
    ll w;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%lld", &v1, &v2, &w);
        insert_edge(v1, v2, w);
        insert_edge(v2, v1, w);
    }


    spfa();

//    for(int i=1;i<=N;i++)
//        cout<<near[i]<<endl;

    ll ans = 0x3f3f3f3f3f3f3f3f;

    for (int i = 0; i < edge_num; i++)
    {
        if (type[e[i].v1] == 1 && type[e[i].v2] == 1)
        {
            if (e[i].w < ans)
            {
                ans = e[i].w;
                v1 = e[i].v1;
                v2 = e[i].v2;
            }
        }

        if (type[e[i].v1] == 0 && type[e[i].v2] == 1)
        {
            if (near[e[i].v1] != e[i].v2)
                if (e[i].w + d[e[i].v1] < ans)
                {
                    ans = e[i].w + d[e[i].v1];
                    v1 = near[e[i].v1];
                    v2 = e[i].v2;
                }
        }

        if (type[e[i].v1] == 1 && type[e[i].v2] == 0)
        {
            if (near[e[i].v2] != e[i].v1)
                if (e[i].w + d[e[i].v2] < ans)
                {
                    ans = e[i].w + d[e[i].v2];
                    v1 = e[i].v1;
                    v2 = near[e[i].v2];
                }
        }

        if (type[e[i].v1] == 0 && type[e[i].v2] == 0)
        {
            if (near[e[i].v2] != near[e[i].v1])
                if (e[i].w + d[e[i].v1] + d[e[i].v2] < ans)
                {
                    ans = e[i].w + d[e[i].v1] + d[e[i].v2];
                    v1 = near[e[i].v1];
                    v2 = near[e[i].v2];
                }
        }
    }

    if (ans == 0x3f3f3f3f3f3f3f3f)
    {
        printf("No luck at all\n");
    }
    else
    {
        printf("%lld\n%d %d\n", ans, v1, v2);
    }

    return 0;
}
