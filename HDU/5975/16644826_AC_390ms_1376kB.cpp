#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[70];
void init(){
	a[0]=1;
	for(int i=1;i<=60;i++){
		a[i]=a[i-1]*2LL;
	}
}
ll lowbit(ll x){
	return x&(-x);
}
ll calc(ll m){
	ll i=0,res=0;
	while(a[i]<=m){
		res+=(m/a[i]-m/a[i+1])*(a[i]);
		i++;
	}
	return res;
}
int main(){
	init();
	ll n;
	int q;
	while(~scanf("%lld%d",&n,&q)){
		while(q--){
			int d;
			scanf("%d",&d);
			if(d==1){
				ll x,y;
				scanf("%lld%lld",&x,&y);
				printf("%lld\n",calc(y)-calc(x-1));
			}else{
				ll x,ans=0;
				ll t;
				scanf("%lld",&x);
				while(x<=n){
					x+=lowbit(x);
					ans++;
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}