#include<iostream>
#include<memory.h>
#include<string>
#include<algorithm>
#define INF 1<<29
using namespace std;
const int MAXN=100005;
int N;
int dp[MAXN];

int a[MAXN];

int main(){

    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);

        for(int i=0;i<MAXN;i++)
            dp[i]=INF;

        for(int i=0;i<N;i++)
            *lower_bound(dp,dp+N,a[i])=a[i];


        printf("%d\n",lower_bound(dp,dp+N,INF)-dp);
    }


    return 0;
}
