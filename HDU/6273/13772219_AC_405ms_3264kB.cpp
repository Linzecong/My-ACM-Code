#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
int T,n,m;
ll sum1[int(1e5+5)];
ll sum2[int(1e5+5)];
int l,r,op;

ll qpow(ll a, ll n){
	ll ans=1;
	while(n){
		if (n&1) ans=ans*a%MOD;
		a=a*a%MOD;
		n>>=1;	
	}
	return ans;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		while(m--){
			scanf("%d%d%d",&l,&r,&op);
			if (op==2){
				sum1[l]++;
				sum1[r+1]--;
			}
			else if (op==3){
				sum2[l]++;
				sum2[r+1]--;
			}
		}
		ll min1=0x3f3f3f3f,min2=0x3f3f3f3f;
		for (int i=1; i<=n; i++){
			sum1[i]=sum1[i-1]+sum1[i];
			min1=min(min1,sum1[i]);
			sum2[i]=sum2[i-1]+sum2[i];
			min2=min(min2,sum2[i]);
		}
		ll ans1=qpow(2,min1);
		ll ans2=qpow(3,min2);
		
		ll ans=ans1*ans2%MOD;
		//if (min1==0||min2==0) ans=1;
		/*
		cout<<min1<<" "<<min2<<endl;
		cout<<ans1<<" "<<ans2<<endl;
		*/
		cout<<ans<<endl;
	}
	
	
	return 0;
} 