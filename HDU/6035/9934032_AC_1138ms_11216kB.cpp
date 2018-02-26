#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define inf 1<<29
#define MAXV 200005
#define MOD 1000000007
using namespace std;
typedef long long int ll;

int col[MAXV];//每个节点的颜色
int head[MAXV];
int edgenum;
int sum[MAXV];
int size[MAXV];
int vis[MAXV];

ll d;

struct node{
    int v;
    int next;
}edge[MAXV*2];

void insert_edge(int a,int b){
    edge[edgenum].v=b;
    edge[edgenum].next=head[a];
    head[a]=edgenum++;
}

void dfs(int x,int fa){
    ll pre=sum[col[x]];
    size[x]=1;
    int add=0;

    for(int i=head[x];i!=-1;i=edge[i].next){
        if(edge[i].v==fa)
            continue;
        dfs(edge[i].v,x);

        size[x]+=size[edge[i].v];
        ll count=size[edge[i].v]-sum[col[x]]+pre;

        pre=sum[col[x]];

        add+=count;

        d+=(count*(count-1))/2;

    }

    sum[col[x]]+=add+1;


}






int main()
{
    int n,tt=1;

    while(~scanf("%d",&n)){
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));

        d=0;
        edgenum=0;

        ll colnum=0;//颜色数

        for(int i=1;i<=n;i++){
            scanf("%d",&col[i]);
            if(!vis[col[i]]){
                colnum++;
                vis[col[i]]=1;
            }
        }

        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            insert_edge(u,v);
            insert_edge(v,u);
        }

        dfs(1,0);

        ll ans=colnum*(n-1)*n/2-d;

        for(int i=1;i<=n;i++){
            if(vis[i]&&i!=col[1]){
                ll count=n-sum[i];
                ans-=count*(count-1)/2;
            }
        }

        printf("Case #%d: %lld\n", tt++, ans);
    }
    return 0;
}
