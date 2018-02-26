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

int time[MAXV];
int d[MAXV];
int vis[MAXV];

bool spfa(int s,int e){

    queue<int> que;
    memset(time,0,sizeof(time));
    for(int i=1;i<=n;i++)d[i]=0;
    memset(vis,0,sizeof(vis));

    que.push(e);
    d[e]=MAX;
    time[e]++;
    vis[e]=1;

    while(!que.empty()){
        int tp=que.front();
        que.pop();

        vis[tp]=0;

        for(int i=1;i<=n;i++){
            if(d[i]<min(d[tp],rect[tp][i])){
                d[i]=min(d[tp],rect[tp][i]);

                if(!vis[i]){
                    que.push(i);
                    vis[i]=1;

                    if(++time[i]>=n)
                        return 1;
                }

            }

        }

    }

printf("Scenario #%d:\n%d\n\n", tt++, d[s]);


    return 0;

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


        spfa(1,n);
    }
    return 0;
}
