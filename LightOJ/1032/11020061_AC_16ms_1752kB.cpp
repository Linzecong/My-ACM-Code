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

ll dp[40][2][100];
int dig[40];

//iszero记录是否有前导0
ll dfs(int pos,int sta,int sum,bool limit){

    if(pos==0)
          return sum;


    //记忆化搜索
    if(!limit && dp[pos][sta][sum]!=-1)
        return dp[pos][sta][sum];


    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:1;
    ll ans=0;

    for(int i=0;i<=end;i++){

        if(sta==1&&i==1)
            ans+=dfs(pos-1,i,sum+1,limit&&i==end);
        else
            ans+=dfs(pos-1,i,sum,limit&&i==end);

    }


    if(!limit)
        dp[pos][sta][sum]=ans;

    return ans;

}



ll solve(ll x){



    int pos=1;
    while(x){
        dig[pos++]=x&1;
        x>>=1;
    }

    return dfs(pos-1,-1,0,1);
}


int main()
{



memset(dp,-1,sizeof(dp));
    ll r;
    int t;
    scanf("%d",&t);
    for(int qqq=1;qqq<=t;qqq++){
        scanf("%lld",&r);
        
        printf("Case %d: %lld\n",qqq,solve(r));

    }

    return 0;
}
