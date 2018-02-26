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
using namespace std;
typedef long long int ll;

ll dp[30][30];
int dig[30];

ll dfs(int pos,int zeronum,bool limit,bool iszero){

    if(pos==-1){
        if(iszero)
            return 1;
        else
            return zeronum;
}


    //记忆化搜索
    if(!limit && dp[pos][zeronum]!=-1&&!iszero)
        return dp[pos][zeronum];


    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:9;
    ll ans=0;

    for(int i=0;i<=end;i++){

        if(iszero)
            ans+=dfs(pos-1,0,limit&&i==end,i==0);
        else{
            if(i==0)
                ans+=dfs(pos-1,zeronum+1,limit&&i==end,0);
              else
                ans+=dfs(pos-1,zeronum,limit&&i==end,0);
        }

    }


    if(!limit&&!iszero)
        dp[pos][zeronum]=ans;

    return ans;

}



ll solve(ll x){
    //记录每一位
    int pos=0;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }
    ll ans=0;


    ans+=dfs(pos-1,0,1,1);

    return ans;
}


int main()
{

    ll l,r;
    int t;
    scanf("%d",&t);
    for(int qqq=1;qqq<=t;qqq++){
        scanf("%lld%lld",&l,&r);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",qqq,solve(r)-solve(l-1));

    }

    return 0;
}
