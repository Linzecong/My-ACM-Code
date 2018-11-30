#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=1e6+10;
const int mod=1e9+7;
ll pre[MAX_N],dp[MAX_N];
ll s[MAX_N];
ll quick_mod(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=mod;
        (x*=x)%=mod,y>>=1;
    }
    return res;
}
int main(){
    int cas=1,t,n,k;
    scanf("%d",&t);
    for(int i=1;i<MAX_N;i++){
        pre[i]=pre[i-1]+i;
    }
    while(t--){
        ll ans=0;
        scanf("%d%d",&n,&k);
        memset(s,0,sizeof(s));
        if(k!=1&&k!=n){
            ll sum=k;
            int ind=k-1;
            while(sum<=pre[ind]&&ind>=0){
                sum+=ind;
                ind--;
            }
            ans=quick_mod(2LL,ind);
            s[k]=ans;
            int pos=k;
            for(int i=k+1;i<=n;i++){
                while(pre[pos]<pre[i]-pre[pos]){
                    pos++;
                }
                dp[i]=(s[i-1]-s[pos-1])%mod;
                s[i]=s[i-1]+dp[i];
                //cout<<i<<" "<<pos<<endl;
            }
            ans=dp[n]*2LL%mod;
        }
        if(k==1) ans=0;
        if(k==n){
            ll sum=k;
            int ind=k-1;
            while(sum<=pre[ind]&&ind>=0){
                sum+=ind;
                ind--;
            }
            ans=quick_mod(2LL,ind);
            ans*=2;
            ans%=mod;
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
