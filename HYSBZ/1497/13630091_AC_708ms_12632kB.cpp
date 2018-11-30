#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 205005;
const int INF = 0x3f3f3f3f;

int N, M;
int P[MAXN];

int A[MAXN];
int B[MAXN];
int C[MAXN];

int cnt = 1;
int S, T;
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

    e[edge_num].v = u;  
    e[edge_num].flow = 0;  
    e[edge_num].next = head[v];  
    head[v] = edge_num++;  
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
int dinic(int start, int End)  
{  
    int MaxFlow = 0;  
  
    while (bfs(start, End))  
        MaxFlow += dfs(start, INF, End);  
    return MaxFlow;  
}  


int SP[MAXN];
int TP[MAXN];

int main()
{
    memset(head, -1, sizeof(head));
    edge_num = 0;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &P[i]);

    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        sum += C[i];
    }

    cnt = 0;
    S = ++cnt;
    for (int i = 0; i < M; i++)
        SP[i] = ++cnt;
    for (int i = 1; i <= N; i++)
        TP[i] = ++cnt;
    T = ++cnt;

    for (int i = 0; i < M; i++)
        addedge(S, SP[i], C[i]);

    for (int i = 0; i < M; i++)
    {
        addedge(SP[i], TP[A[i]], INF);
        addedge(SP[i], TP[B[i]], INF);
    }

    for (int i = 1; i <= N; i++)
        addedge(TP[i], T, P[i]);

    printf("%d\n", sum - dinic(S, T));

    return 0;
}