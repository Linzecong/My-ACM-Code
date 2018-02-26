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


int W;
int N;

int v[50005];
int w[50005];
int dp[50005];

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&N,&W);
        W=W-N;
        scanf("%d",&N);

        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));


        for(int i=1;i<=N;i++)
            scanf("%d%d",&v[i],&w[i]);


        for(int i=0;i<50005;i++)
            dp[i]=INF;

        dp[0]=0;


        for(int i=1;i<=N;i++)
            for(int j=w[i];j<=W;j++)
                if(dp[j]>dp[j-w[i]]+v[i]){
                    dp[j]=dp[j-w[i]]+v[i];
                }





        if(dp[W]<INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);

        else
            printf("This is impossible.\n");

    }

    return 0;
}
