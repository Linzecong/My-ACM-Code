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

int dp[40][50][50][2];
int dig[40];


int dfs(int pos,int zn,int on,bool limit,bool have){

    if(pos==0)
        return zn>=on&&zn!=0&&on!=0&&have==0;

    //记忆化搜索
    if(!limit && dp[pos][zn][on][have]!=-1)
        return dp[pos][zn][on][have];

    //循环遍历下一位的每一个数字，end记录最大能达到的数
    int end=limit?dig[pos]:1;
    int ans=0;

    for(int i=0;i<=end;i++){
        if(have){
            if(i==0)
                ans+=dfs(pos-1,zn,on,limit&&i==end,have);
            else
                ans+=dfs(pos-1,zn,on+1,limit&&i==end,0);
        }
        else{
            if(i==0)
                ans+=dfs(pos-1,zn+1,on,limit&&i==end,have);
            else{
                ans+=dfs(pos-1,zn,on+1,limit&&i==end,have);
            }
        }
    }

    if(!limit)
        dp[pos][zn][on][have]=ans;

    return ans;

}


int solve(int x){

    int pos=1;
    while(x){
        dig[pos++]=x&1;
        x>>=1;
    }

    return dfs(pos-1,0,0,1,1);
}


int main()
{



    memset(dp,-1,sizeof(dp));
    int l,r;

    while(~scanf("%d%d",&l,&r)){

        printf("%d\n",solve(r)-solve(l-1));
    }

    return 0;
}
