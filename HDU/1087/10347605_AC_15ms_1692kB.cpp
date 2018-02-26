#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define ll long long

using namespace std;

int N;
int a[1005];

int dp[1005];


int main()
{



    while(~scanf("%d",&N)){


        if(N==0)
            break;

        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);


        for(int i=0;i<N;i++)
            dp[i]=a[i];


        for(int i=1;i<N;i++)
            for(int j=0;j<i;j++){
                if(a[j]<a[i])
                    dp[i]=max(dp[i],dp[j]+a[i]);

            }


        int maxnum=dp[0];
for(int i=1;i<N;i++)
        maxnum=max(maxnum,dp[i]);

cout<<maxnum<<endl;






    }




    return 0;
}
