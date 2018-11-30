#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

const int MAXN=105;
const int INF=0x3f3f3f3f;

int N,NP,NC,M;
int cnt = 1;        //点的总个数，下标从1开始

typedef struct{
    int flow;           //流量
    int capacity;       //最大容量值
}maps;
maps G[MAXN][MAXN];


int layer[MAXN];   //保存标号所属层
bool countLayer(int s, int e) //宽搜
{
    int v,i;
    queue <int>q;
    memset(layer,0,sizeof(layer));

    q.push(s);
    layer[s]=1;
    while(!q.empty()){
        v=q.front();q.pop();
        for(i=1;i<=cnt;i++)
            if(!layer[i] &&G[v][i].capacity>G[v][i].flow){
                q.push(i);
                layer[i]=layer[v]+1;
            }
        if(v==e) return 1;
    }
    return 0;
}
int dfs(int cur,int cp,int e){
    if(cur==e) return cp;

    int tmp=cp,t;
    for(int i=1;i<=cnt;i++)
        if(layer[i]==layer[cur]+1 && tmp && G[cur][i].capacity>G[cur][i].flow){
            t=dfs(i,min(G[cur][i].capacity-G[cur][i].flow,tmp),e);
            G[cur][i].flow+=t;
            G[i][cur].flow-=t;
            tmp-=t;
        }
    return cp-tmp;
}
int Max_Flow_Dinic(int s, int e)
{
    int maxflow=0;
    while(countLayer(s,e))
        maxflow+=dfs(s,INF,e);
    return maxflow;
}


int main()
{

    while(~scanf("%d%d%d%d",&N,&NP,&NC,&M)){

        cnt = 0;
        memset(G,0,sizeof(G));

        char temp;
        int a,b;

        int S=N+1;
        int T=N+2;
        cnt=N+2;

        for(int i=0;i<M;i++){
            cin>>temp;
            cin>>a;
            cin>>temp;
            cin>>b;
            cin>>temp;
            cin>>G[++a][++b].capacity;
        }

        for(int i=0;i<NP;i++){
            cin>>temp;
            cin>>a;
            cin>>temp;
            cin>>G[S][++a].capacity;
        }

        for(int i=0;i<NC;i++){
            cin>>temp;
            cin>>a;
            cin>>temp;
            cin>>G[++a][T].capacity;
        }

        printf("%d\n",Max_Flow_Dinic(S,T));

    }


    return 0;
}
