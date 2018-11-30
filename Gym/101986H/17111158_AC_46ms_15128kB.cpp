#include<bits/stdc++.h>
using namespace std;
const int MAXN=1605;
const int INF=0x3f3f3f3f;
typedef long long ll;

int N,M;

int cnt=0;
struct edge{
    int v,next,flow;
}e[800*800*2];

int head[MAXN],edge_num,layer[MAXN];

void insert_edge(int u,int v,int w){
    e[edge_num].v=v;
    e[edge_num].flow=w;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
    e[edge_num].v=u;
    e[edge_num].flow=0;
    e[edge_num].next=head[v];
    head[v]=edge_num++;
}

bool bfs(int start,int End){
    queue<int> Q;
    Q.push(start);
    memset(layer,0,sizeof(layer));
    layer[start]=1;

    while (Q.size()) {
        int u=Q.front();
        Q.pop();
        if(u==End)
            return true;
        for(int j=head[u];~j;j=e[j].next){
            int v=e[j].v;
            if(layer[v]==false&&e[j].flow){
                layer[v]=layer[u]+1;
                Q.push(v);
            }
        }
    }
    return false;
}

int dfs(int u,int Maxflow,int End){
    if(u==End)
        return Maxflow;
    int uflow=0;
    for(int j=head[u];~j;j=e[j].next){
        int v=e[j].v;
        if(layer[v]-1==layer[u]&&e[j].flow){
            int flow=min(Maxflow-uflow,e[j].flow);
            flow=dfs(v,flow,End);
            e[j].flow-=flow;
            e[j^1].flow+=flow;
            uflow+=flow;
            if(uflow==Maxflow)
                break;
        }
    }
    if(uflow==0)
        layer[u]=0;
    return uflow;
}

int dinic(int start,int End){
    int Maxflow=0;
    while(bfs(start,End))
        Maxflow+=dfs(start,INF,End);
    return Maxflow;
}

struct point{
    int s,e;
}P[MAXN*4];

int in[MAXN],out[MAXN],tian1[MAXN],tian2[MAXN];

int main(){

    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++)
        scanf("%d%d",&P[i].s,&P[i].e);

    memset(head,-1,sizeof(head));
    edge_num=0;
    cnt=0;

    int S,T;

    S=++cnt;
    for(int i=1;i<=400;i++)
        in[i]=++cnt;
    for(int i=1;i<=N;i++)
        out[i]=++cnt;
    T=++cnt;


    for(int i=1;i<=N;i++)
        for(int j=P[i].s;j<=P[i].e;j++)
            insert_edge(in[j],out[i],INF);

    for(int i=1;i<=400;i++)
        insert_edge(S,in[i],1);
    for(int i=1;i<=N;i++)
        insert_edge(out[i],T,1);

    int ans1=dinic(S,T);


    memset(head,-1,sizeof(head));
    edge_num=0;
    cnt=0;

    S=++cnt;
    for(int i=1;i<=M;i++)
        in[i]=++cnt;
    for(int i=M+1;i<=N;i++)
        out[i]=++cnt;
    for(int i=1;i<=400;i++)
        tian1[i]=++cnt;
    for(int i=1;i<=400;i++)
        tian2[i]=++cnt;
    T=++cnt;

    for(int i=1;i<=M;i++)
        insert_edge(S,in[i],1);

    for(int i=1;i<=M;i++)
        for(int j=P[i].s;j<=P[i].e;j++)
            insert_edge(in[i],tian1[j],1);

    for(int i=1;i<=400;i++)
        insert_edge(tian1[i],tian2[i],1);

    for(int i=M+1;i<=N;i++)
        for(int j=P[i].s;j<=P[i].e;j++)
            insert_edge(tian2[j],out[i],1);

    for(int i=M+1;i<=N;i++)
        insert_edge(out[i],T,1);


    int ans2=dinic(S,T);

    printf("%d\n%d",ans1,ans2);


    return 0;
}



