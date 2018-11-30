#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

const int MAXN=111;
const int INF=0x3f3f3f3f;

int N,M,K;

int cnt=1;
int in[MAXN];
int on[MAXN];

struct edge{
    int u,v,cap,cost,next;
}e[4*MAXN*MAXN];

int edge_num;
int head[MAXN];

void insert_edge(int u,int v,int cap,int cost){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].cap=cap;
    e[edge_num].cost=cost;
    e[edge_num].next=head[u];
    head[u]=edge_num++;

    //反向边 k^1即可求出反向边
    e[edge_num].u = v;
    e[edge_num].v = u;
    e[edge_num].cap = 0;      //注意这里
    e[edge_num].cost = -cost; //注意这里
    e[edge_num].next = head[v];
    head[v] = edge_num++;
}

int dis[MAXN*MAXN];
int pre[MAXN*MAXN];
bool vis[MAXN*MAXN];
bool spfa(int s,int t){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));

    dis[s]=0;
    vis[s]=1;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int tp=que.front();
        que.pop();
        vis[tp]=0;
        for(int i=head[tp];~i;i=e[i].next){
            int v=e[i].v;
            int cost=e[i].cost;

            if(e[i].cap&&dis[v]>dis[tp]+cost){
                dis[v]=dis[tp]+cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
    }
    if(dis[t]==INF)
        return false;
    return true;

}

pair<int,int> MCMF(int s,int t){
    int maxflow=0;
    int mincost=0;
    int minc;
    while(spfa(s,t)){
        minc=INF;
        int cost=0;
        for(int i=pre[t];~i;i=pre[e[i].u])
            minc=min(minc,e[i].cap);
        for(int i=pre[t];~i;i=pre[e[i].u]){
            e[i].cap-=minc;
            e[i^1].cap+=minc;
            cost+=minc*e[i].cost;
        }
        mincost+=cost;
        maxflow+=minc;
    }
    return make_pair(mincost,maxflow);
}

int need[MAXN][MAXN];
int tnk[MAXN];
int supp[MAXN][MAXN];
int tsk[MAXN];
int cost[MAXN][MAXN][MAXN];


int main()
{

flag:
    while(~scanf("%d%d%d",&N,&M,&K)){
        if(N==0&&M==0&&K==0)
            break;


        cnt = 1;
        memset(tnk,0,sizeof(tnk));
        memset(tsk,0,sizeof(tsk));

        for(int i=1;i<=N;i++)
            for(int j=1;j<=K;j++){
                scanf("%d",&need[i][j]);
                tnk[j]+=need[i][j];
            }


        for(int i=1;i<=M;i++)
            for(int j=1;j<=K;j++){
                scanf("%d",&supp[i][j]);
                tsk[j]+=supp[i][j];
            }

        for(int i=1;i<=K;i++)
            for(int j=1;j<=N;j++)
                for(int k=1;k<=M;k++)
                    scanf("%d",&cost[i][j][k]);

        for(int i=1;i<=K;i++)
            if(tnk[i]>tsk[i])
            {
                printf("-1\n");
                goto flag;
            }

        int S=cnt++;
        for(int i=1;i<=M;i++)
            in[i]=cnt++;

        for(int i=1;i<=N;i++)
            on[i]=cnt++;
        int T=cnt++;

        int ans=0;
        for(int t=1;t<=K;t++){
            memset(head, -1, sizeof(head));
            edge_num = 0;

            for(int i=1;i<=M;i++){
                insert_edge(S,in[i],supp[i][t],0);
            }

            for(int i=1;i<=M;i++){
                for(int j=1;j<=N;j++){
                    insert_edge(in[i],on[j],INF,cost[t][j][i]);
                }
            }

            for(int i=1;i<=N;i++){
                insert_edge(on[i],T,need[i][t],0);
            }

            pair<int,int> aa=MCMF(S,T);
            ans+=aa.first;
        }


        printf("%d\n",ans);

    }


    return 0;
}
