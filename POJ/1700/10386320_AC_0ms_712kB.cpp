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

int dp[10005];
int a[10005];

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);

        //排完序后a[1]为走的最快的
        sort(a+1,a+N+1);

        dp[1]=a[1];
        dp[2]=a[2];

        for(int i=3;i<=N;i++)
            dp[i]=min(dp[i-1] + a[1] + a[i],dp[i-2] + a[1] + a[i] + 2*a[2]);
        //前者的意思是当这边还有一个人的时候，肯定是让对面走得最快的回来
        //后者的意思是当这边还有两个人（其中一个肯定是a[1]）的时候，肯定是让对面走得最快（这个时候是a[2]）的回来，然后让a[1]和a[i]过去，a[1]回来，再a[1]a[2]过去

        printf("%d\n",dp[N]);
    }

    return 0;
}
