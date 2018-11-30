#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int MAX_N=1e5+10;
ll a[MAX_N];
ll quick_mod(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=mod;
        (x*=x)%=mod,y>>=1;
    }
    return res;
}
void init(){
    a[0]=1;
    for(int i=1;i<MAX_N;i++){
        a[i]=(a[i-1]*i)%mod;
    }
}
int main(){
    int T;
    init();
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        n--,m--;
        printf("%lld %lld\n",a[n+1]*quick_mod(a[m]*a[n-m+1]%mod,mod-2)%mod,a[n]*quick_mod(a[n-m]*a[m]%mod,mod-2)%mod);
    }
    return 0;
}
