#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define MAXV 400005
using namespace std;
typedef long long int ll;

ll a[100005];
ll dp[100005];

int main()
{
    int N;
    cin>>N;



    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);



    sort(a+1,a+N+1);

    dp[1]=a[1];
    dp[2]=a[2];

    for(int i=3;i<=N;i++)
        dp[i]=min(dp[i-1] + a[1] + a[i],dp[i-2] + a[1] + a[i] + 2*a[2]);
    //前者的意思是当这边还有一个人的时候，肯定是让对面走得最快的回来
    //后者的意思是当这边还有两个人（其中一个肯定是a[1]）的时候，肯定是让对面走得最快（这个时候是a[2]）的回来，然后让a[1]和a[i]过去，a[1]回来，再a[1]a[2]过去

    printf("%lld\n",dp[N]);





    return 0;
}
