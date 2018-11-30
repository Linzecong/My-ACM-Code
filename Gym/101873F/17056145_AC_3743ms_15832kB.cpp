#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
typedef long long ll;

struct Edge
{
    int v, next;
    ll flow;
} e[MAXN*2],e1[MAXN*2];

int head[MAXN], edge_num, layer[MAXN];

void addedge(int u, int v, ll w)
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
ll dfs(int u, ll MaxFlow, int End)
{
    if (u == End)
        return MaxFlow;

    ll uflow = 0;

    for (int j = head[u]; j != -1; j = e[j].next)
    {
        int v = e[j].v;

        if (layer[v] - 1 == layer[u] && e[j].flow)
        {
            ll flow = min(MaxFlow - uflow, e[j].flow);
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

ll dinic(int start, int End)
{
    ll MaxFlow = 0;
    while (bfs(start, End))
        MaxFlow += dfs(start, INF, End);
    return MaxFlow;
}

vector<int> imp;

int X[MAXN];
int Y[MAXN];
int tot=0;
int main(){

    memset(head,-1,sizeof(head));

    int  N,M,K;
    scanf("%d%d%d",&N,&M,&K);

    int S=++tot;
    for(int i=1;i<=N;i++)
        X[i]=++tot;
    for(int i=1;i<=M;i++)
        Y[i]=++tot;
    int T=++tot;

    int u,v;
    for(int i=0;i<K;i++){
        scanf("%d%d",&u,&v);
        addedge(X[u],Y[v],1);
    }

    for(int i=1;i<=N;i++){
        addedge(S,X[i],1);
        imp.push_back(edge_num-2);
    }
    for(int i=1;i<=M;i++){
        addedge(Y[i],T,1);
    }

    ll ans=dinic(S,T);
   // cout<<ans<<endl;

    for(int i=0;i<edge_num;i++)
        e1[i]=e[i];

    ll tmp=0;
    for(auto t:imp){

        for(int i=0;i<edge_num;i++)
            e[i]=e1[i];

        e[t].flow+=2;
        tmp=max(tmp,dinic(S,T));
    }
    cout<<ans+tmp<<endl;



    return 0;
}












