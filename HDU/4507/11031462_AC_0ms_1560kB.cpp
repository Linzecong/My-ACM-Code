#include "cstdio"
#include "math.h"
#include "cstring"
#define mod 1000000007LL
#define LL long long
struct status
{
    LL cnt,sum,sqsum;
    status() {cnt=-1;sum=sqsum=0;}
    status(LL cnt,LL sum,LL sqsum):cnt(cnt),sum(sum),sqsum(sqsum) {}
}dp[20][10][10];
LL digit[20],p[25];
status dfs(int len,int re1,int re2,bool fp)
{
    if(!len) return re1!=0&&re2!=0?status(1,0,0):status(0,0,0);
    if(!fp&&dp[len][re1][re2].cnt!=-1) return dp[len][re1][re2];
    int fpmax=fp?digit[len]:9;
    status ans;ans.cnt=0;
    for(int i=0;i<=fpmax;i++)
    {
        if(i==7) continue;
        status next=dfs(len-1,(re1+i)%7,(re2*10+i)%7,fp&&i==fpmax);
        ans.cnt+=next.cnt;
        ans.cnt%=mod;
        ans.sum+=(next.sum+((p[len]*i)%mod)*next.cnt%mod)%mod;
        ans.sum%=mod;
        ans.sqsum+=(next.sqsum+((2*p[len]*i)%mod)*next.sum)%mod;
        ans.sqsum%=mod;
        ans.sqsum+=((next.cnt*p[len])%mod*p[len]%mod*i*i%mod);
        ans.sqsum%=mod;
    }
    if(!fp) dp[len][re1][re2]=ans;
    return ans;
}
LL f(LL x)
{
    int len=0;
    while(x)
    {
        digit[++len]=x%10;
        x/=10;
    }
    status tt=dfs(len,0,0,true);
    return tt.sqsum;
}
int main()
{
    int T;
    LL l,r;
    scanf("%d",&T);
    p[1]=1;
    for(int i=2;i<=20;i++) p[i]=(p[i-1]*10)%mod;
    while(T--)
    {
        scanf("%I64d%I64d",&l,&r);
        LL ans=f(r);
        ans-=f(l-1);
        printf("%I64d\n",(ans%mod+mod)%mod);
    }
}