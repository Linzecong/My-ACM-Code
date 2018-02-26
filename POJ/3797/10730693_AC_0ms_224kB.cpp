#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define INF 1<<29
using namespace std;

int dp[1005];
int a[1005];
int b[1005];
int c[1005];
int d[1005];


int main()
{
    dp[0]=1;dp[1]=1;
    a[0]=0;a[1]=1;
    b[0]=0;b[1]=1;
    c[0]=0;c[1]=1;
    d[0]=1;d[1]=1;


    for(int i=2;i<1005;i++){
        dp[i]=a[i-1]+b[i-1]+c[i-1]+dp[i-1]+dp[i-2];

        a[i]=a[i-2]+dp[i-1];

        b[i]=c[i-1]+dp[i-1];

        c[i]=b[i-1]+dp[i-1];


    }
    
    int t;
    scanf("%d",&t);
    for(int qqq=1;qqq<=t;qqq++){

        int w;
        scanf("%d",&w);
        
        


      

       printf("%d %d\n",qqq,dp[w]);



    }





    return 0;
}






