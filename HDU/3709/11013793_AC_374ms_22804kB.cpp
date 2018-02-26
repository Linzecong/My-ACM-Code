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

ll dp[30][30][3000];
int dig[30];

ll dfs(int pos,bool limit,int pri,int sum){

    if(pos==-1)
        return sum==0;

    if(sum<0)
        return 0;

    //记忆化搜索
    if(!limit && dp[pos][pri][sum]!=-1)
        return dp[pos][pri][sum];


    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:9;
    ll ans=0;

    for(int i=0;i<=end;i++){

        ans+=dfs(pos-1,limit&&i==end,pri,(pos-pri)*i+sum);
    }


    if(!limit)
        dp[pos][pri][sum]=ans;

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

    for(int i=0;i<pos;i++)
    ans+=dfs(pos-1,1,i,0);

    return ans-pos+1;
}


int main()
{

    ll l,r;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(r)-solve(l-1));

    }

    return 0;
}
