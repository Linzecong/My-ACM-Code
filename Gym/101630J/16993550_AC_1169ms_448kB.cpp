#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=3005;

struct edge{
    int u,v,next;
    ll w;
}ye[MAXN*2],e[MAXN*2];
int head[MAXN],edge_num;
void insert_edge(int u,int v,ll w){
    ye[edge_num].u=u;
    ye[edge_num].v=v;
    ye[edge_num].w=w;
    ye[edge_num].next=head[u];
    head[u]=edge_num++;
}

int N,M,K;
ll c[MAXN*2];

void rebuild(ll x){
    for(int i=0;i<edge_num;i++){
        e[i]=ye[i];
        if(ye[i].w<x){
            e[i].w=0;
        }
        else
            e[i].w-=x;
    }
}

ll d[MAXN];
bool vis[MAXN];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> >> que;
ll dij(){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    que.push({0,1});
    d[1]=0;
    while(!que.empty()){
        auto tp=que.top();
        que.pop();
        int u=tp.second;
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=head[u];~i;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                que.push({d[v],v});
            }
        }
    }
    return d[N];
}



int main()
{
    memset(head,-1,sizeof(head));
    edge_num=0;
    scanf("%d%d%d",&N,&M,&K);
    int u,v;
    ll w;
    for(int i=0;i<M;i++){
        scanf("%d%d%lld",&u,&v,&w);
        insert_edge(u,v,w);
        insert_edge(v,u,w);
        c[i]=w;
    }
    rebuild(0);
    ll ans=dij();
    for(int i=0;i<M;i++){
        rebuild(c[i]);
        ll p=dij();
        ans=min(ans,p+K*c[i]);
    }
    printf("%lld\n",ans);

    return 0;
}










