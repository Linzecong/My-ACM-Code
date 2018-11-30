#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2510;
const int mod=1e9+7;
ll a[MAX_N];
void init(){
	a[0]=1LL;
	for(int i=1;i<MAX_N;i++){
		a[i]=(a[i-1]*i)%mod;
	}
}
ll quick_mod(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1){
			(res*=x)%=mod;
		}
		(x*=x)%=mod,y>>=1;
	}
	return res;
}
ll C(int n,int m){
	return a[m]*quick_mod(a[m-n],mod-2)%mod*quick_mod(a[n],mod-2)%mod;
}
/*vector <int> G[MAX_N];
void add_edge(int x,int y){
	G[y].push_back(x),G[x].push_back(y);
}
ll dfs(int x,int fa,int k){
	for(auto y:G[x]){
		if(y!=fa){
			dfs(y,x,k);
		}
	}
}*/
int n,m;
int main(){
	init();
	scanf("%d%d",&n,&m);
	ll ans=0,t=1;
	for(int i=m;i>=2;i--){
		(ans+=(C(i,m)*t%mod*i%mod*quick_mod(i-1,n-1)%mod))%=mod;
		t*=-1;
	}
	printf("%lld\n",ans<0?ans+mod:ans);
	return 0;
}
