#include<iostream>  
#include<cstring>  
#include<cstdio>  
  
using namespace std;  
  
int dp[35][35];  
  
int f(int i,int j)  
{  
    if(i==0)    return 0;  
    if(j==0)    return i;  
    if(dp[i][j]>0)   return dp[i][j];  
  
    dp[i][j]=f(i-1,j)+f(i-1,j-1)+1;  
  
    return dp[i][j];  
}  
  
int main()  
{  
    int G,L,cas=0;  
    while(cin>>G>>L)  
    {  
        if(G==0&&L==0)  break;  
        ++cas;  
        memset(dp,0,sizeof(dp));  
  
        if(L==0)  
        {  
            printf("Case %d: %d\n",cas,G);  
            continue;  
        }  
        if(L>G)  L=G;  
        printf("Case %d: %d\n",cas,f(G,L));  
    }  
    return 0;  
}  