#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long LL;

#define INF 0x3f3f3f3f
#define N 22000
#define MAXN 100000000
#define mod 1000000007

long long dp[60];

int main()
{
    int i,T,a,b;
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<60;i++)
        dp[i]=dp[i-1]+dp[i-2];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &a, &b);

        printf("%lld\n", dp[b-a]);
    }
    return 0;
}