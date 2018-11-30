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

bool vis[MAXN];
int d[MAXN],pre[MAXN];
bool SPFA(int vs,int vt){
    for(int i=0;i<cnt;++i){
        vis[i]=0;
        d[i]=INF;
    }
    vis[vs]=1;
    d[vs]=0;
    queue<int> que;
    que.push(vs);
    while(!que.empty()){
        int u=que.front(); que.pop();
        for(int i=head[u]; i!=-1; i=e[i].next){
            int v=e[i].v;
            if(e[i].cap && d[v]>d[u]+e[i].cost){
                d[v]=d[u]+e[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
        vis[u]=0;
    }
    return d[vt]!=INF;
}
int MCMF(int vs,int vt){
    int res=0;
    while(SPFA(vs,vt)){
        int flow=INF,cost=0;
        for(int u=vt; u!=vs; u=e[pre[u]].u){
            flow=min(flow,e[pre[u]].cap);
        }
        for(int u=vt; u!=vs; u=e[pre[u]].u){
            e[pre[u]].cap-=flow;
            e[pre[u]^1].cap+=flow;
            cost+=flow*e[pre[u]].cost;
        }
        res+=cost;
    }
    return res;
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

            ans+=MCMF(S,T);
        }


        printf("%d\n",ans);

    }


    return 0;
}
