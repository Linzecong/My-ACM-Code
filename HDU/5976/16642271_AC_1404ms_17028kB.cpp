#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=1e6+10;
const int mod=1e9+7;
ll quick_mod(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) (res*=x)%=mod;
		(x*=x)%=mod, y>>=1;
	}
	return res;
}
ll a[MAX_N],sum[MAX_N];
void init(){
	sum[1]=0,a[1]=1LL;
	for(ll i=2;i<MAX_N;i++){
		sum[i]=(sum[i-1]+i);
		a[i]=a[i-1]*i%mod;
	}
}
int main(){
	init();
	int T;
	for(scanf("%d",&T);T;T--){
		ll x;
		scanf("%lld",&x);
		if(x<=4){
			printf("%lld\n",x);
			continue;
		}
		int s=2;
		int t=upper_bound(sum,sum+MAX_N,x)-sum-1;
		int left=x-sum[t];
		int len=t-s+1;
		s+=left/len,t+=left/len;
		left%=len;
		int mid=t-left;
		//cout<<s<<" "<<t<<" "<<mid<<" "<<endl;
		printf("%lld\n",a[mid]%mod*quick_mod(a[s-1],mod-2)%mod*a[t+1]%mod*quick_mod(a[mid+1],mod-2)%mod);
	}
	return 0;
}