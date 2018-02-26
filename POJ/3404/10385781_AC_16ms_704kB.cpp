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

int N;

int dp[100];
int a[100];

int main(){



    while(~scanf("%d",&N)){

        for(int i=1;i<=N;i++)
                scanf("%d",&a[i]);


        sort(a+1,a+N+1);


        dp[1]=a[1];
        dp[2]=a[2];


        for(int i=3;i<=N;i++)
             dp[i]=min(dp[i-1] + a[1] + a[i],dp[i-2] + a[1] + a[i] + 2*a[2]);


        printf("%d\n",dp[N]);


    }


    return 0;
}
