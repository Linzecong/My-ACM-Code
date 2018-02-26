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

int C,N;
int m[10005][10005];

int dp[10005];

int main(){


    while(~scanf("%d%d",&C,&N)){

        for(int i=1;i<=N;i++)
            for(int j=i;j<=N;j++)
                scanf("%d",&m[i][j]);

        for(int i=1;i<=N;i++)
            dp[i]=INF;

        dp[0]=0;

            dp[1]=m[1][1]+C;




        for(int i=2;i<=N;i++)
            for(int j=1;j<=i;j++){
                dp[i]=min(dp[i],dp[j-1]+m[j][i]+C);
            }


        printf("%d\n",dp[N]);



    }


    return 0;
}
