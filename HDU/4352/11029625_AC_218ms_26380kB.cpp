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


ll dp[70][1<<12][11];//第i位，前j个数字组成的最长上升子序列的状态，k
int dig[70];
int k;

//更新最长上升子序列的状态
int setState(int sta,int num){
    for(int i=num;i<=9;i++)
        if(((1<<i)&sta)){
            return (sta^(1<<i))|(1<<num);
        }
    return sta|(1<<num);
}

//获得二进制1的个数
int getOnes(int sta){
    int num=0;
    while(sta){
        if(sta&1)
            num++;
        sta>>=1;
    }
    return num;
}


ll dfs(int pos,int sta,bool have,bool limit){

    if(pos==-1)
        return getOnes(sta)==k;

    //记忆化搜索
    if(!limit && !have && dp[pos][sta][k]!=-1){
        return dp[pos][sta][k];
    }

    int end=limit?dig[pos]:9;
    ll ans=0;
    for(int i=0;i<=end;i++)
        ans+=dfs(pos-1,(have&&i==0)?0:setState(sta,i),have&&i==0,limit&&i==end);

    if(!limit&&!have)
        dp[pos][sta][k]=ans;

    return ans;

}

ll solve(ll x){

    int pos=0;

    while(x){
        dig[pos++]=x%10;
        x/=10;
    }

    return dfs(pos-1,0,1,1);
}


int main(){
    int t;
    scanf("%d",&t);
    ll l,r;
    memset(dp,-1,sizeof(dp));
    for(int qqq=1;qqq<=t;qqq++){
        scanf("%lld%lld%d",&l,&r,&k);
        printf("Case #%d: %lld\n",qqq,solve(r)-solve(l-1));
    }

    return 0;
}
