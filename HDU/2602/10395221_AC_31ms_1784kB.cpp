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

int N,M;

int w[10005];
int v[10005];
int dp[10005];

int main(){


    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&M,&N);


        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));



        for(int i=1;i<=M;i++)
            scanf("%d",&v[i]);
        for(int i=1;i<=M;i++)
            scanf("%d",&w[i]);


        for(int i=1;i<=M;i++)
            for(int j=N;j>=w[i];j--)
                if(dp[j]<dp[j-w[i]]+v[i])
                    dp[j]=dp[j-w[i]]+v[i];

        printf("%d\n",dp[N]);
    }


    return 0;
}
