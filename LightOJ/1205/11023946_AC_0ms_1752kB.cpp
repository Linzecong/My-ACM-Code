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

ll dp[90][90];
int dig[32];
int num[32];
int k;

ll dfs(int pos,int len,bool have,bool limit){

    if(pos==-1)
        return 1;

    //记忆化搜索
    if(!limit && !have && dp[pos][len]!=-1)
        return dp[pos][len];

    int end=limit?dig[pos]:9;
    ll ans=0;

    for(int i=0;i<=end;i++){
        if(have){
            num[len]=i;
            ans+=dfs(pos-1,len-!i,have&&i==0,limit&&i==end);
        }
        else{
            int mid=((len+1)/2);
            if(len&1){

                if(pos<mid){
                    if(num[2*mid-pos-1]==i)
                        ans+=dfs(pos-1,len,have&&i==0,limit&&i==end);
                }
                else{
                    num[pos]=i;
                    ans+=dfs(pos-1,len,have&&i==0,limit&&i==end);
                }

            }
            else{

                if(pos==mid){
                    ans+=dfs(pos-1,len,have&&i==0,limit&&i==end);
                }
                else{
                    if(pos<mid){
                        if(num[mid*2-pos]==i)
                            ans+=dfs(pos-1,len,have&&i==0,limit&&i==end);
                    }
                    else{
                        num[pos]=i;
                        ans+=dfs(pos-1,len,have&&i==0,limit&&i==end);
                    }
                }


            }



        }

    }

    if(!limit&&!have)
        dp[pos][len]=ans;

    return ans;

}


ll solve(ll x){

    int pos=0;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }

    return dfs(pos-1,pos-1,1,1);
}


int main()
{


    int t;
    scanf("%d",&t);


    ll l,r;
    memset(dp,-1,sizeof(dp));
    for(int qqq=1;qqq<=t;qqq++){

        scanf("%lld%lld",&l,&r);
        if(l>r)
            swap(l,r);

        printf("Case %d: %lld\n",qqq,solve(r)-solve(l-1));
    }

    return 0;
}
