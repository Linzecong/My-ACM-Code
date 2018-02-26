#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
typedef long long int ll;
int N,D,C;
ll a[1005];
ll sum[1005];//记录前缀和，用于优化计算速度
ll dp[1005];//记录只考虑前i个的时候的最优值

int main(){


    scanf("%d%d%d",&N,&D,&C);
    for(int i=1;i<=N;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }

    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;

    for(int i=1;i<=N;i++)
        for(int j=0;j<i;j++)
            dp[i]=min(dp[i],dp[j]+((i-j)*a[i]-(sum[i]-sum[j]))*C+D);

    //原本是要把a[j]-a[i]的和计算一遍，这里直接用一个公式算出来即可。不用循环。
    
    printf("%lld\n",dp[N]);

    return 0;
}