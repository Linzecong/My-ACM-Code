#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=998244353;

ll qmod(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
		{
			res=(res*x)%MOD;
		}
		y>>=1;
		x=(x*x)%MOD;
	}
	return res;
}

ll dp[100005];


ll f[100005];
ll a[100005];


int main(){
	f[0]=1;
	f[1]=1;
	for(ll i=2;i<=100004;i++)
		f[i]=f[i-1]*i%MOD;	
	
	int t;
	scanf("%d",&t);
	while(t--){
		
		memset(dp,0,sizeof(dp));
		
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%lld",&a[i]);
			
		 dp[0]=f[N-1];
		 ll sum=dp[0]%MOD;
		 
		 for(int i=1;i<N;i++){
		 	dp[i]=(qmod(i,MOD-2)*(sum)%MOD+f[N-1])%MOD;
		 	sum+=dp[i];	
		 	sum=sum%MOD;
		 }
		 
		 ll fenzi=0;
		 for(int i=0;i<N;i++){
		 	fenzi+=a[i]*dp[i]%MOD;
		 	fenzi=fenzi%MOD;
		 }
		 
		 ll fenmu=f[N];
		 
		 cout<<fenzi*qmod(fenmu,MOD-2)%MOD<<endl;
		
		
	}
	return 0;
}





