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
#define MAXV 4005
using namespace std;

//dijkstra 邻接矩阵
//int rect[MAXV][MAXV];
//int n,m;

//void dijkstra(int s,int e){
//    int i,j,min,v;

//    int d[MAXV];

//    bool vis[MAXV];

//    for(i=1;i<=n;i++){
//        vis[i]=0;
//        d[i]=rect[s][i];
//    }

//    for(i=1;i<=n;i++){
//        min=inf;
//        for(j=1;j<=n;j++)
//            if(!vis[j]&&d[j]<min){
//                v=j;
//                min=d[j];
//            }
//        vis[v]=1;

//        for(j=1;j<=n;j++)
//            if(!vis[j]&&d[j]>rect[v][j]+d[v])
//                d[j]=rect[v][j]+d[v];
//    }

//    printf("%d\n",d[e]);


//}

//int main(){

//    int a,b,c;
//    while(~scanf("%d%d",&m,&n)){

//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//                if(i==j)
//                    rect[i][j]=0;
//                else
//                    rect[i][j]=rect[j][i]=inf;


//        for(int i=1;i<=m;i++){
//            scanf("%d%d%d",&a,&b,&c);
//            if(rect[a][b]>c)
//                rect[a][b]=rect[b][a]=c;
//        }

//        dijkstra(n,1);
//    }


//    return 0;
//}


//Dijstra 邻接表

//struct edge{
//    int v1,v2,w,next;
//}e[MAXV];

//int n,m,edge_num;
//int head[MAXV],d[MAXV];
//bool vis[MAXV];

//void insert_edge(int v1,int v2,int w){
//    e[edge_num].v1=v1;
//    e[edge_num].v2=v2;
//    e[edge_num].w=w;
//    e[edge_num].next=head[v1];
//    head[v1]=edge_num++;

//    e[edge_num].v1=v2;
//    e[edge_num].v2=v1;
//    e[edge_num].w=w;
//    e[edge_num].next=head[v2];
//    head[v2]=edge_num++;
//}


//void dijkstra(int s,int en){
//    int i,j,v,min;
//    memset(vis,0,sizeof(vis));

//    vis[s]=true;

//    d[s]=0;

//    v=s;

//    for(j=1;j<=n;j++){


//        for(i=head[v];i!=-1;i=e[i].next){

//            int u1=e[i].v2;

//            if(!vis[u1]&&d[v]+e[i].w<d[u1])
//                d[u1]=d[v]+e[i].w;


//        }

//        min=inf;

//        for(i=0;i<n;i++){
//            if(!vis[i]&&d[i]<min){
//                v=i;
//                min=d[i];
//            }


//        }
//        vis[v]=true;
//    }
//    printf("%d\n",d[en]);
//}

//int main(){

//    int a,b,c;
//    while(~scanf("%d%d",&m,&n)){

//        edge_num=0;
//        memset(head,-1,sizeof(head));

//        for(int i=1;i<=n;i++)
//            d[i]=inf;




//        for(int i=1;i<=m;i++){
//            scanf("%d%d%d",&a,&b,&c);
//            insert_edge(a,b,c);

//        }

//        dijkstra(n,1);
//    }


//    return 0;
//}



//spfa 邻接矩阵

//int rect[MAXV][MAXV];
//int n,m;

//int time[MAXV];
//int d[MAXV];
//int vis[MAXV];

//bool spfa(int s,int e){

//    queue<int> que;
//    memset(time,0,sizeof(time));
//    for(int i=1;i<=n;i++)d[i]=inf;
//    memset(vis,0,sizeof(vis));

//    que.push(e);
//    d[e]=0;
//    time[e]++;
//    vis[e]=1;

//    while(!que.empty()){
//        int tp=que.front();
//        que.pop();

//        vis[tp]=0;

//        for(int i=1;i<=n;i++){
//            if(d[i]>d[tp]+rect[tp][i]){
//                d[i]=d[tp]+rect[tp][i];

//                if(!vis[i]){
//                    que.push(i);
//                    vis[i]=1;

//                    if(++time[i]>=n)
//                        return 1;
//                }

//            }

//        }

//    }

//    printf("%d\n",d[s]);
//    return 0;

//}


//int main(){

//    int a,b,c;
//    while(~scanf("%d%d",&m,&n)){

//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//                if(i==j)
//                    rect[i][j]=0;
//                else
//                    rect[i][j]=rect[j][i]=inf;


//        for(int i=1;i<=m;i++){
//            scanf("%d%d%d",&a,&b,&c);
//            if(rect[a][b]>c)
//                rect[a][b]=rect[b][a]=c;
//        }

//        spfa(n,1);
//    }


//    return 0;
//}


//spfa 邻接表

struct edge{
    int v1,v2,w,next;
}e[MAXV];

int n,m,edge_num;
int head[MAXV],d[MAXV];
bool vis[MAXV];
int time[MAXV];

void insert_edge(int v1,int v2,int w){
    e[edge_num].v1=v1;
    e[edge_num].v2=v2;
    e[edge_num].w=w;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;

    e[edge_num].v1=v2;
    e[edge_num].v2=v1;
    e[edge_num].w=w;
    e[edge_num].next=head[v2];
    head[v2]=edge_num++;
}


bool spfa(int s,int en){
    queue<int> que;
    memset(vis,0,sizeof(vis));
    memset(time,0,sizeof(time));
    for(int i=1;i<=n;i++)d[i]=inf;



    que.push(en);
    d[en]=0;
    time[en]++;
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

                    if(++time[e[i].v2]>=n)
                        return 1;
                }


            }



    }


    printf("%d\n",d[s]);
    return 0;
}

int main(){

    int a,b,c;
    while(~scanf("%d%d",&m,&n)){

        edge_num=0;
        memset(head,-1,sizeof(head));

        for(int i=1;i<=n;i++)
            d[i]=inf;




        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            insert_edge(a,b,c);

        }

        spfa(n,1);
    }


    return 0;
}





