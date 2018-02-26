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

ll dp[40][50][3000];
int dig[40];
map<int,int> m;

int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}


ll dfs(int pos,int sta,int mod,bool limit){

    if(pos==0)
        return mod%sta==0;

    //记忆化搜索
    if(!limit && dp[pos][m[sta]][mod]!=-1)
        return dp[pos][m[sta]][mod];


    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:9;
    ll ans=0;

    for(int i=0;i<=end;i++){

        if(i!=0)
        ans+=dfs(pos-1,lcm(sta,i),(mod*10+i)%2520,limit&&i==end);
        else
        ans+=dfs(pos-1,sta,(mod*10+i)%2520,limit&&i==end);
    }


    if(!limit)
        dp[pos][m[sta]][mod]=ans;

    return ans;

}



ll solve(ll x){


    int pos=1;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }

    return dfs(pos-1,1,0,1);
}


int main()
{

    int cnt=0;
    for(int i=1;i<=2520;i++)
        if(2520%i==0)
            m[i]=cnt++;

    memset(dp,-1,sizeof(dp));
    ll l,r;
    int t;
    scanf("%d",&t);
    for(int qqq=1;qqq<=t;qqq++){
        scanf("%I64d%I64d",&l,&r);

        printf("%I64d\n",solve(r)-solve(l-1));

    }

    return 0;
}
