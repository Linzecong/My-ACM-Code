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


double P;
int N;

double v[20000];
int w[20000];
double dp[20000];


int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%lf%d",&P,&N);

        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));


        int W=0;
        for(int i=1;i<=N;i++){
            scanf("%d%lf",&w[i],&v[i]);
            W+=w[i];
        }


        dp[0]=1;


        for(int i=1;i<=N;i++)
            for(int j=W;j>=w[i];j--)
                if(dp[j]<dp[j-w[i]]*(1-v[i])){
                    dp[j]=dp[j-w[i]]*(1-v[i]);
                }

        for(int i=W;i>=0;i--)
            if(dp[i]>1-P){
                printf("%d\n",i);
                break;
            }


    }


    return 0;
}
