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

ll dp[30][10][2][20];//当前位为第i位，第i位的数字为j时，合格的个数
int dig[30];//保存数字的每一位

//当前是第几位，第几位数是多少，前一位是否是最大的。
ll dfs(int pos,int num,bool limit,bool have,int mod){

    if(pos==-1)
        return have&&mod==0;

    //记忆化搜索
    if(!limit && dp[pos][num][have][mod]!=-1)
        return dp[pos][num][have][mod];


    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:9;
    ll ans=0;

    for(int i=0;i<=end;i++){

        int modx=(mod*10+i)%13;

        if((num==1&&i==3)){

            ans+=dfs(pos-1,i,limit&&(i==end),1,modx);
        }
        else{
            ans+=dfs(pos-1,i,limit&&(i==end),have,modx);
        }

    }


    if(!limit)
        dp[pos][num][have][mod]=ans;

    return ans;

}



ll solve(ll x){
    //记录每一位
    int pos=0;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }

    //比如523，现在从0523开始遍历，实现遍历所有情况
    return dfs(pos-1,0,1,0,0);
}


int main()
{
int n;
    while(scanf("%lld",&n)!=EOF){

        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(n));

    }

    return 0;
}
