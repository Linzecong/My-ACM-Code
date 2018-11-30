#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=3e5+5;
int n,m,M;
int a[maxn],ans;
int dp[maxn];
int main(){
	ans=0;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	M=0;
	for (int i=m+1;i<=n;i++){
		M=max(M,dp[i-m]);
		dp[i]=M+a[i];
		ans=max(dp[i],ans);
	}
	printf("%d\n",ans);
} 