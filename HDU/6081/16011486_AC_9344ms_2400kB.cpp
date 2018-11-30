#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const int MAXV = 3010;
const int MAXE = 200010;
const int INF = 0x3f3f3f3f;

struct edge{
    int u,v,w,next;
}e[MAXE];
int head[MAXV],edge_num;

void insert_edge(int u,int v,int w){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].w=w;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}


int fa[MAXV],link[MAXV];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int val[MAXV];
bool vis[MAXV];
int N,M;

void init(){
    memset(head,-1,sizeof(head));
    memset(link,-1,sizeof(link));
    for(int i=1;i<=N;i++){
        fa[i]=i;
    }
    edge_num=0;
}

void merge(int u,int v){
    int p=u;
    while(~link[p])p=link[p];
    link[p]=v;
    fa[v]=u;
}

int MCP(int cnt,int &s,int &t){
    memset(val,0,sizeof(val));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int> > que;

    t=1;
    while(--cnt){
        s=t;
        vis[s]=true;
        for(int u=s;~u;u=link[u]){
            for(int p=head[u];~p;p=e[p].next){
                int v=find(e[p].v);
                if(!vis[v])
                    que.push(make_pair(val[v]+=e[p].w,v));
            }
        }
        t=0;
        while(!t){
            if(que.empty())
                return 0;
            pair<int,int> tp=que.top();
            que.pop();
            if(val[tp.second]==tp.first)
                t=tp.second;
        }
    }
    return val[t];
}

int StoerWagner(){
    int res=INF;
    for(int i=N,s,t;i>1;i--){
        res=min(res,MCP(i,s,t));
        if(res==0)
            break;
        merge(s,t);
    }
    return res;
}




int main()
{
    while(~scanf("%d%d",&N,&M)){
        init();
        int u,v,w;
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&u,&v,&w);
            insert_edge(u,v,w);
            insert_edge(v,u,w);
        }
        printf("%d\n",StoerWagner());
    }


    return 0;
}











