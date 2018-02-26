#include<stdio.h>  
#include<string.h>  
#define N 10005  
int dp[102][N],s[102],v[102],w[102];  
int max(int a,int b,int c)  
{  
    int t=a>b?a:b;  
    return t>c?t:c;  
}  
int main()  
{  
    int n,m,k,S,i,j;  
    while(scanf("%d%d%d",&n,&m,&S)!=EOF)  
    {  
        for(i=0;i<n;i++)  
         scanf("%d%d%d",&s[i],&v[i],&w[i]);  
        for(i=0;i<=S;i++)  
          for(j=0;j<=m;j++)  
          {  
            if(i==0)  
               dp[i][j]=0;  
            else  
                dp[i][j]=-1;  
          }  
        for(i=1;i<=S;i++)  
          for(j=0;j<n;j++)  
            if(s[j]==i)   //第i款  
             for(k=m;k>=v[j];k--)  
              dp[i][k]=max(dp[i][k],dp[i][k-v[j]]+w[j],dp[i-1][k-v[j]]+w[j]);  
             /* 当前的值，没有要这种且没有要这件时的值加上物品价值，要这种不要这件之前的值加上物品价值*/  
        if(dp[S][m]<0)  
        printf("Impossible\n");  
        else  
        printf("%d\n",dp[S][m]);  
    }  
    return 0;  
}  