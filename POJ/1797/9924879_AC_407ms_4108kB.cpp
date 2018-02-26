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
#define MAXV 1005
using namespace std;


#define MAX 0x3f3f3f3f


int rect[MAXV][MAXV];
int n,m;
int tt;


void dijkstra(int s,int e){
    int i,j,f,v;

    int d[MAXV];

    bool vis[MAXV];

    for(i=1;i<=n;i++){
        vis[i]=0;
        d[i]=rect[s][i];
    }

    for(i=1;i<=n;i++){
        f=-1;
        for(j=1;j<=n;j++)
            if(!vis[j]&&d[j]>f){
                v=j;
                f=d[j];
            }
        vis[v]=1;

        for(j=1;j<=n;j++)
            if(!vis[j]&&d[j]<min(d[v],rect[v][j]))
                d[j]=min(d[v],rect[v][j]);
    }

    printf("Scenario #%d:\n",tt++);
    printf("%d\n\n",d[e]);

}


int main()
{
    tt=1;
    int t;
    scanf("%d",&t);
    int a,b,c;
    while(t--){

        memset(rect,0,sizeof(rect));
        scanf("%d%d",&n,&m);

        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);

            rect[a][b]=c;
            rect[b][a]=c;

        }


        dijkstra(1,n);
    }
    return 0;
}
