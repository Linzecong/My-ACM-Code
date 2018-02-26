#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#define Max 50010  
int dp[4][Max];  
int a[Max];  
int b[Max];  
  
int inline max(int a,int b)  
{  
    if(a>b)  
        return a;  
    else  
        return b;  
}  
  
int solve(int n,int k)  
{  
    int i,j;  
    int f;  
    memset(dp,0,sizeof(dp));  
    for(i=1;i<=3;i++)  
    {  
        for(j=k;j<=n;j++)  
        {  
            dp[i][j]=max(dp[i-1][j-k]+b[j],dp[i][j-1]);  
        }  
    }  
    return dp[3][n];  
}  
  
int main()  
{  
    int T,n,sum,i,k;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        a[0]=0;  
        for(i=1;i<=n;i++)  
            scanf("%d",&a[i]);  
        scanf("%d",&k);  
        sum=0;  
        b[0]=a[0];  
        for(i=1;i<=k;i++)  
        {  
            b[i]=b[i-1]+a[i];  
        }  
        sum=b[k];  
        for(i=k+1;i<=n;i++)  
        {  
            sum+=a[i];  
            sum-=a[i-k];  
            b[i]=sum;  
        }  
        printf("%d\n",solve(n,k));  
    }  
    return 0;  
}  