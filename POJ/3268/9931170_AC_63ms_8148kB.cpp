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


int rect[MAXV][MAXV];
int reverserect[MAXV][MAXV];

int n,m;

int time[MAXV];

int d[MAXV];
int rd[MAXV];

int vis[MAXV];

bool spfa1(int s,int e){

    queue<int> que;
    memset(time,0,sizeof(time));

    for(int i=1;i<=n;i++)d[i]=inf;

    memset(vis,0,sizeof(vis));

    que.push(e);
    d[e]=0;
    time[e]++;
    vis[e]=1;

    while(!que.empty()){
        int tp=que.front();
        que.pop();

        vis[tp]=0;

        for(int i=1;i<=n;i++){
            //同上描述，看看有没有更窄的
            if(d[i]>(d[tp]+rect[tp][i])){
                d[i]=(d[tp]+rect[tp][i]);

                if(!vis[i]){
                    que.push(i);
                    vis[i]=1;

                    if(++time[i]>=n)
                        return 1;
                }

            }

        }

    }


    return 0;

}

bool spfa2(int s,int e){

    queue<int> que;
    memset(time,0,sizeof(time));

    for(int i=1;i<=n;i++)rd[i]=inf;

    memset(vis,0,sizeof(vis));

    que.push(e);
    rd[e]=0;//初始化为最宽
    time[e]++;
    vis[e]=1;

    while(!que.empty()){
        int tp=que.front();
        que.pop();

        vis[tp]=0;

        for(int i=1;i<=n;i++){
            //同上描述，看看有没有更窄的
            if(rd[i]>(rd[tp]+reverserect[tp][i])){
                rd[i]=(rd[tp]+reverserect[tp][i]);

                if(!vis[i]){
                    que.push(i);
                    vis[i]=1;

                    if(++time[i]>=n)
                        return 1;
                }

            }

        }

    }


    return 0;

}


int main()
{
    int X;
    int a,b,c;
    while(~scanf("%d%d%d",&n,&m,&X)){


        for(int i=0;i<MAXV;i++)
            for(int j=0;j<MAXV;j++){
                rect[i][j]=inf;
                reverserect[i][j]=inf;
            }


        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            rect[a][b]=c;
            reverserect[b][a]=c;
        }


        spfa1(1,X);
        spfa2(1,X);

        int ans=0;
        for(int i=1;i<=n;i++){

            if(d[i]+rd[i]>ans)
                ans=d[i]+rd[i];
        }

        cout<<ans<<endl;

    }
    return 0;
}
