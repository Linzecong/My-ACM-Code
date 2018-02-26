#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>
#define INF 1<<29
using namespace std;

int M;
int L;
int N;

int vis[2000];

int w[2000];
int dp[2000];
vector<int> path[2000];


int main(){



    while(~scanf("%d%d",&M,&L)){
        if(M==0&&L==0)
            break;

        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));

        for(int i=0;i<2000;i++)
            path[i].clear();


        scanf("%d",&N);

        for(int i=1;i<=N;i++)
            scanf("%d",&w[i]);


        for(int i=1;i<=N;i++)
            for(int j=M;j>=w[i];j--)
                if(dp[j]<dp[j-w[i]]+w[i]){
                    dp[j]=dp[j-w[i]]+w[i];
                    path[j]=path[j-w[i]];
                    path[j].push_back(i);
                }



        for(int i=0;i<path[M].size();i++)
            vis[path[M][i]]=1;

        int sum=0;
        for(int i=1;i<=N;i++)
            if(!vis[i])
                sum+=w[i];

        if(sum<=L){
            printf("%d ",path[M].size());
            sort(path[M].begin(),path[M].end());
            for(int i=0;i<path[M].size();i++)
                printf("%d ",path[M][i]);
            printf("\n");
        }
        else
            printf("Impossible to distribute\n");


    }


    return 0;
}
