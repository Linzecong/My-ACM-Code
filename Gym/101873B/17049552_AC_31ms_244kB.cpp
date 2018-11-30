#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll quick_mod(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=mod;
        (x*=x)%=mod,y>>=1;
    }
    return res;
}
int main(){
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    ll color=quick_mod(c,n*n),ans=0;
    for(int i=1;i<=m;i++){
        ans+=quick_mod(color,__gcd(i,m));
        ans%=mod;
    }
    ans*=quick_mod(m,mod-2);
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}
