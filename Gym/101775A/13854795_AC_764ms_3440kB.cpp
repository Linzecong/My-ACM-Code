#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1000000007;
ll quick_mod(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
		{
			res=res*x%mod;
		}
		y>>=1;
		x=x*x%mod;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
	
		ll n,k;
		scanf("%lld%lld",&n,&k);
		ll ans=quick_mod(2LL,n)-1;
		ll tmp=n;
		for(ll i=1;i<k;i++)
		{
			ans=(ans-tmp+mod)%mod;
			tmp=tmp*(n-i)%mod;
			tmp=tmp*quick_mod(i+1,mod-2)%mod;
		}
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}