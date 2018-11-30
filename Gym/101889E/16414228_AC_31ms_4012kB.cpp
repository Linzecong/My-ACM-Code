#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005],k,l;
char s[1005],ans[1005];
int dfs(int now,int yu){
    if(now==l+1){
        return yu==0;
    }
    if(dp[now][yu]!=-1) return dp[now][yu];
    int tmp=0;
    if(s[now]!='?'){
        ans[now]=s[now];
        tmp=dfs(now+1,(yu*10+s[now]-'0')%k);
    }
    else {
        int down=(now==1?1:0),tmp;
        for(int i=down;i<=9;i++){
            ans[now]=i+'0';
            tmp=dfs(now+1,(yu*10+i)%k);
            if(tmp) return dp[now][yu]=tmp;
        }
    }
    return  dp[now][yu]=tmp;
}
int main(){
    scanf("%s%d",s+1,&k);
    l=strlen(s+1);
    memset(dp,-1,sizeof(dp));
    if(dfs(1,0)) ans[l+1]='\0',printf("%s\n",ans+1);
    else printf("*\n");
    return 0;
}
