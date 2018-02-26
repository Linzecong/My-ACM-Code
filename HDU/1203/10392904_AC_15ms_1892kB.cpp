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
double v[10005];
double dp[10005];


int main(){


    while(~scanf("%d%d",&N,&M)){
        if(N==0&&M==0)
            break;

        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));

        for(int i=0;i<=N;i++)
            dp[i]=1.0;

        for(int i=1;i<=M;i++)
            scanf("%d%lf",&w[i],&v[i]);




        for(int i=1;i<=M;i++)
            for(int j=N;j>=w[i];j--)
                if(dp[j]>dp[j-w[i]]*(1.0-v[i]))
                    dp[j]=dp[j-w[i]]*(1.0-v[i]);

        printf("%.1lf%%\n",(1-dp[N])*100);
    }



return 0;
}
