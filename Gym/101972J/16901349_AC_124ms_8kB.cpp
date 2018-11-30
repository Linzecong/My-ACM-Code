#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=63;
ll n,a[MAX_N],m[MAX_N];
void init(){
    a[0]=1;
    for(int i=1;i<MAX_N;i++){
        a[i]=a[i-1]*2LL;
    }
    m[0]=1;
    m[1]=m[2]=m[4]=2LL;
    m[3]=4LL;
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        ll rec=n;
        ll ans=1;
        while(n>4){
             int t=upper_bound(a,a+MAX_N,n)-a;
             ans*=2LL,n-=a[t-1];
        }
        ans*=m[n];
        printf("%lld\n",rec+1-ans);
    }
    return 0;
}
