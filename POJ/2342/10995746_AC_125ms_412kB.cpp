#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
int father[6005],vis[6005],dp[6005][2],t;  
  
void dfs(int node)  
{  
    int i,j;  
    vis[node] = 1;  
    for(i = 1;i<=t;i++)  
    {  
       if(!vis[i] && father[i] == node)  
       {  
           dfs(i);  
           dp[node][1]+=dp[i][0];//node去,则i必不能去  
           dp[node][0]+=max(dp[i][0],dp[i][1]);//node不去，取i去或不去的最大值  
       }  
    }  
}  
  
int main()  
{  
    int i,j,l,k,root;  
    while(~scanf("%d",&t))  
    {  
        for(i = 1;i<=t;i++)  
        scanf("%d",&dp[i][1]);  
        root = 0;  
        while(scanf("%d%d",&l,&k),l+k>0)  
        {  
            father[l] = k;//记录上司  
            root = k;  
        }  
        memset(vis,0,sizeof(vis));  
        dfs(root);  
        printf("%d\n",max(dp[root][1],dp[root][0]));  
    }  
  
    return 0;  
}  