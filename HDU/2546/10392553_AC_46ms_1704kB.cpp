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









int main(){

    int N,M;
    while(cin>>N&&N){

int a[1010];
        memset(a,0,sizeof(a));

        for(int i=1;i<=N;i++)
            cin>>a[i];



        sort(a+1,a+N+1);

        cin>>M;
        if(M<5){
            cout<<M<<endl;

        }
        else{
            int dp[1010];
            memset(dp,0,sizeof(dp));

            for(int i=1;i<=N-1;i++)
                for(int j=M-5;j>=a[i];j--)
                    if(dp[j]<dp[j-a[i]]+a[i])
                        dp[j]=dp[j-a[i]]+a[i];

            cout<<M-dp[M-5]-a[N]<<endl;
        }

    }

    return 0;
}
