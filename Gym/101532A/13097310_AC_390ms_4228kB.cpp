#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5+5;

ll a[MAXN];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		ll ret=0;
		for (int i=0; i<n; i++) scanf("%lld",&a[i]);
		
		ll bit=1;
		for (int j=0; j<20; j++){
			ll cnt=0,sum=0;
			for (int i=0; i<n; i++){
				if (a[i]&(1<<j)) cnt++;
				else{
					sum+=cnt*(cnt+1)/2;
					cnt=0;
				}
			} 
			sum+=cnt*(cnt+1)/2;
			ret+=sum*bit;
			bit*=2;
		}
		printf("%lld\n",ret);
	}
	
	
	
	return 0;
}