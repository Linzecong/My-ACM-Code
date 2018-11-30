#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
const int MAXN = 100005;

const int INF = 0x3f3f3f3f;
int x, y, N, M;
int source = INF, sink = -INF;

struct Edge
{
    int v, flow, next;
} e[MAXN << 1];

int head[MAXN], edge_num, layer[MAXN];

void addedge(int u, int v, int w)
{
    e[edge_num].v = v;
    e[edge_num].flow = w;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}

bool bfs(int start, int End)
{
    queue<int> Q;
    Q.push(start);
    memset(layer, 0, sizeof(layer));
    layer[start] = 1;
    while (Q.size())
    {
        int u = Q.front();
        Q.pop();

        if (u == End)
            return true;

        for (int j = head[u]; j != -1; j = e[j].next)
        {
            int v = e[j].v;

            if (layer[v] == false && e[j].flow)
            {
                layer[v] = layer[u] + 1;
                Q.push(v);
            }
        }
    }

    return false;
}
int dfs(int u, int MaxFlow, int End)
{
    if (u == End)
        return MaxFlow;

    int uflow = 0;

    for (int j = head[u]; j != -1; j = e[j].next)
    {
        int v = e[j].v;

        if (layer[v] - 1 == layer[u] && e[j].flow)
        {
            int flow = min(MaxFlow - uflow, e[j].flow);
            flow = dfs(v, flow, End);

            e[j].flow -= flow;
            e[j ^ 1].flow += flow;

            uflow += flow;

            if (uflow == MaxFlow)
                break;
        }
    }
    if (uflow == 0)
        layer[u] = 0;
    return uflow;
}
int dinic(int start, int End, int N)
{
    int MaxFlow = 0;

    while (bfs(start, End))
        MaxFlow += dfs(start, INF, End);
    return MaxFlow;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        source = INF, sink = -INF;
        int start = 0, end = 0, i;
        scanf("%d%d", &N, &M);
        edge_num = 0;
        memset(head, -1, sizeof(head));
        for (i = 1; i <= N; i++)
        {
            scanf("%d%d", &x, &y);
            if (source > x)
            {
                source = x;
                start = i;
            }
            if (sink < x)
            {
                sink = x;
                end = i;
            }
        }
        while (M--)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addedge(u, v, c);
            addedge(v, u, c);
        }
        printf("%d\n", dinic(start, end, 1));
    }
    return 0;
}
