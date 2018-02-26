#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
using namespace std;
const int MAXV=500;
const int inf=0x3f3f3f3f;

int rect[MAXV][MAXV];
int n,m;
int rect2[MAXV][MAXV];
int dijkstra1(int s,int e){
    int i,j,min,v;

    int d[MAXV];

    bool vis[MAXV];

    for(i=1;i<=n;i++){
        vis[i]=0;
        d[i]=rect[s][i];
    }

    for(i=1;i<=n;i++){
        min=inf;
        for(j=1;j<=n;j++)
            if(!vis[j]&&d[j]<min){
                v=j;
                min=d[j];
            }
        vis[v]=1;

        for(j=1;j<=n;j++)
            if(!vis[j]&&d[j]>rect[v][j]+d[v])
                d[j]=rect[v][j]+d[v];
    }

    return d[e];


}

int dijkstra2(int s,int e){
    int i,j,min,v;

    int d[MAXV];

    bool vis[MAXV];

    for(i=1;i<=n;i++){
        vis[i]=0;
        d[i]=rect2[s][i];
    }

    for(i=1;i<=n;i++){
        min=inf;
        for(j=1;j<=n;j++)
            if(!vis[j]&&d[j]<min){
                v=j;
                min=d[j];
            }
        vis[v]=1;

        for(j=1;j<=n;j++)
            if(!vis[j]&&d[j]>rect2[v][j]+d[v])
                d[j]=rect2[v][j]+d[v];
    }

    return d[e];


}

int main(){

    scanf("%d%d",&n,&m);
    int a,b;

    memset(rect,0x3f,sizeof(rect));
    memset(rect2,0x3f,sizeof(rect2));


    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        rect[a][b]=1;
        rect[b][a]=1;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(rect[i][j]==inf){
                rect2[i][j]=1;
            }
            else
                rect2[i][j]=inf;

    int len1=dijkstra1(1,n);
    int len2=dijkstra2(1,n);

    if(len1==inf||len2==inf)
        printf("%d\n",-1);
    else
        printf("%d\n",max(len1,len2));


    return 0;
}

