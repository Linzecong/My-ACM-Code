#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int w[5];
int dp[4005];
int N;

int main(){

    scanf("%d%d%d%d",&N,&w[0],&w[1],&w[2]);

    for(int i=0;i<4005;i++)
        dp[i]=-100000000;
    dp[0]=0;

    for(int i=0;i<3;i++)
        for(int j=w[i];j<=N;j++)
            dp[j]=max(dp[j],dp[j-w[i]]+1);

    int maxx=0;

//    for(int i=0;i<=N;i++)
//        if(dp[i]!=-100000000)
///            maxx=max(dp[i],maxx);

        printf("%d\n",dp[N]);





    return 0;
}

