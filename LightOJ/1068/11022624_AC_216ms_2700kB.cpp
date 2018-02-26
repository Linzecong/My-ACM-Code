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
#include<bitset>
using namespace std;
typedef long long int ll;

int dp[32][90][90];
int dig[32];
int k;

int dfs(int pos,int sum,int mod,bool limit){

    if(pos==0)
        return sum%k==0&&mod==0;

    //记忆化搜索
    if(!limit && dp[pos][sum][mod]!=-1)
        return dp[pos][sum][mod];

    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:9;
    int ans=0;

    for(int i=0;i<=end;i++){

        ans+=dfs(pos-1,sum+i,(mod*10+i)%k,limit&&i==end);

    }

    if(!limit)
        dp[pos][sum][mod]=ans;

    return ans;

}


int solve(int x){

    int pos=1;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }

    return dfs(pos-1,0,0,1);
}


int main()
{


    int t;
    scanf("%d",&t);


    int l,r;

    for(int qqq=1;qqq<=t;qqq++){
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&l,&r,&k);
        if(k>90)
            printf("Case %d: %d\n",qqq,0);
        else
            printf("Case %d: %d\n",qqq,solve(r)-solve(l-1));
    }

    return 0;
}
