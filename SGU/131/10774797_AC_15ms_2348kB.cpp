#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define INF 1<<29
using namespace std;
typedef long long int ll;

ll dp[15][1<<12];
int h,w;

void dfs(int prestate,int nowstate,int nextstate,int n,int cnt){

    if(n>=w){
        dp[cnt+1][nextstate]+=dp[cnt][prestate];
        return;
    }

    if(((1<<n)&nowstate)!=0){
        dfs(prestate,nowstate,nextstate,n+1,cnt);//下一个
        return;
    }


    if((nextstate&(1<<n))==0)
    dfs(prestate,nowstate|(1<<n),nextstate|(1<<n),n+1,cnt);

    if(n!=0)
    if((nextstate&(1<<n))==0&&(nextstate&(1<<(n-1)))==0)
    dfs(prestate,nowstate|(1<<n),nextstate|(1<<n)|(1<<(n-1)),n+1,cnt);

    if(n<w-1)
    if((nextstate&(1<<n))==0&&(nextstate&(1<<(n+1)))==0)
    dfs(prestate,nowstate|(1<<n),nextstate|(1<<n)|(1<<(n+1)),n+1,cnt);

    if(n+1<w&&((1<<(n+1))&nowstate)==0){
        dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate,n+2,cnt);

        if((nextstate&(1<<n))==0)
        dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate|(1<<n),n+2,cnt);

        if((nextstate&(1<<(n+1)))==0)
        dfs(prestate,nowstate|(1<<n)|(1<<(n+1)),nextstate|(1<<(n+1)),n+2,cnt);
    }

}


int main(){

    while(~scanf("%d%d",&h,&w)){


        memset(dp,0,sizeof(dp));
        dp[1][0]=1;


        int state=1<<w;

        for(int i=1;i<=h;i++)
            for(int j=0;j<state;j++)
                dfs(j,j,0,0,i);

        printf("%lld\n",dp[h+1][0]);

    }

    return 0;
}
