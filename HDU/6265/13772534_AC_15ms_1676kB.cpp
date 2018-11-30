#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll quick_mod(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
		{
			res=(res*x)%mod;
		}
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
ll ans,p,q;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=1;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld%lld",&p,&q);
			ans=ans*((quick_mod(p,q)+q*(quick_mod(p,q)-quick_mod(p,q-1))%mod)%mod)%mod;
		}	
		if(ans<0)
		{
			ans+=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}