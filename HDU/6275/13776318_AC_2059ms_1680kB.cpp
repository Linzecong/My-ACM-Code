#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f (ll a,ll b,ll c,ll n)//首项   公差   c    项数
{
    if (!n) return 0;
    return (b/c)*n*(n-1)/2+(a/c)*n+f((b*n+a)%c,c,b%c,((b%c)*n+(a%c))/c);
}
ll solve(ll n)
{
    ll res=0;
    for(ll st=1,last;st<=n;st=last+1){
        ll temp=0;
        last=n/(n/st);
        ll dis=n/st;
        ll x=n-dis*st;
        ll y=n-dis*last;
        //cout<<x<<" "<<y<<" "<<dis<<endl;
        if(last-st<=1000){
            for(ll i=x;i>=y;i-=dis)
            {
                temp^=i;
            }
        }
        else
         for(ll i=0;x>>i;i++)
         {
             temp|=(f(y,dis,1LL<<i,last-st+1)&1LL)<<i;
         }
        res^=temp;
        //cout<<temp<<endl;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",solve(n));
    }

    return 0;
}
