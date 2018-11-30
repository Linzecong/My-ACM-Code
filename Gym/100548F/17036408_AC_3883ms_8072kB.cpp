#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=1e6+10;
const int mod=1e9+7;
ll quick_mod(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=mod;
        (x*=x)%=mod,y>>=1;
    }
    return res;
}
ll a[MAX_N];
void init(){
    a[0]=a[1]=1;
    for(int i=2;i<MAX_N;i++){
        a[i]=a[i-1]*i%mod;
    }
}
int main(){
    init();
    ll cas=1,t,n,m,k;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&k);
        ll ans=0,flag=1;
        for(ll i=k;i>=1;i--){
            (ans+=flag*a[k]*quick_mod(a[i]*a[k-i]%mod,mod-2)%mod*i%mod*quick_mod(i-1,n-1)%mod)%=mod;
            flag*=-1;
        }
        //cout<<ans<<endl;
        for(ll i=m;i>m-k;i--){
            (ans*=i)%=mod;
        }
        (ans*=quick_mod(a[k],mod-2))%=mod;
        printf("Case #%lld: %lld\n",cas++,ans<0?ans+mod:ans);
    }
    return 0;
}
