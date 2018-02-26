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

int dp[20][20];
int dig[20];

int dfs(int pos,int num,bool limit){

    if(pos==0)
        return 0;

    if(!limit && dp[pos][num])
        return dp[pos][num];

    if(pos==1)
        return dp[pos][num]=(num!=4);
    if(num==4)
        return dp[pos][num]=0;

    int end=limit?dig[pos-1]:9;
    int ans=0;

    for(int i=0;i<=end;i++){
        if(!(num==6&&i==2))
            ans+=dfs(pos-1,i,limit&&(i==end));
    }

    if(!limit)
        dp[pos][num]=ans;
    return ans;

}



int solve(int x){
    int pos=1;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }
    return dfs(pos,0,1);
}


int main()
{

    int l,r;
    while(~scanf("%d%d",&l,&r)){

        if(l==0&&r==0)
            break;

        memset(dp,0,sizeof(dp));
        printf("%d\n",solve(r)-solve(l-1));


    }

    return 0;
}
