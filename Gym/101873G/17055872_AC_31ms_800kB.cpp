#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
const int MAX_N=1e5+10;
int x[MAX_N],y[MAX_N],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    x[n]=x[0],y[n]=y[0];
    for(int i=0;i<n;i++) ans+=(1LL*x[i]*y[i+1]-1LL*x[i+1]*y[i]);
    ll del=0;
    for(int i=0;i<n;i++) del+=abs(__gcd(x[i]-x[i+1],y[i]-y[i+1]));
    printf("%lld\n",(abs(ans)-(del-2))/2);
    return 0;
}
