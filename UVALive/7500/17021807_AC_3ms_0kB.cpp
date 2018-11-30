#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        ll n;
        scanf("%lld",&n);
        ll l=1,r=2e9+10;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(mid*(mid+1)/2<=n){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //cout<<r<<endl;
        printf("Case #%d: %lld\n",i,r*(r+1)/2);
    }
    return 0;
}
