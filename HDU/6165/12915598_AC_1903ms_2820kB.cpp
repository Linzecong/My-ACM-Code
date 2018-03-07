#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define inf 1<<29
#define MAXV 6005
using namespace std;

struct edge{
    int v1,v2,w,next;
}e[MAXV];

int n,m,edge_num;
int head[MAXV],d[MAXV];
bool vis[MAXV];

bool ans[1005][1005];

void insert_edge(int v1,int v2,int w){
    e[edge_num].v1=v1;
    e[edge_num].v2=v2;
    e[edge_num].w=w;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;

}


void spfa(int en){
    queue<int> que;
    memset(vis,0,sizeof(vis));


    for(int i=1;i<=n;i++)
        d[i]=inf;

    que.push(en);
    d[en]=0;

    vis[en]=1;


    while(!que.empty()){
        int tp=que.front();
        que.pop();
        vis[tp]=0;

        for(int i=head[tp];i!=-1;i=e[i].next)
            if(d[tp]+e[i].w<d[e[i].v2]){

                d[e[i].v2]=d[tp]+e[i].w;

                if(!vis[e[i].v2]){
                    vis[e[i].v2]=1;
                    que.push(e[i].v2);
                }

            }

    }



    for(int i=1;i<=n;i++){

        if(d[i]==inf)
            ans[en][i]=false;
        else
            ans[en][i]=true;
    }


}

int main(){

    int a,b;

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&m);

        edge_num=0;
        memset(head,-1,sizeof(head));

        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            insert_edge(a,b,1);

        }

        bool flag=true;
        for(int i=1;i<=n;i++){

            spfa(i);

        }


        for(int i=1;i<=n;i++){
            if(!flag)
                break;
            for(int j=i+1;j<=n;j++){
                if(!(ans[i][j]||ans[j][i])){
                    flag=false;
                    break;
                }
            }
        }


        if(!flag)
            printf("Light my fire!\n");
        else
            printf("I love you my love and our love save us!\n");
    }


    return 0;
}