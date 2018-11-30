#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAX_N=2e3+10;
int dp[MAX_N][MAX_N];
int arr[MAX_N];
int n,m,k;
struct seg{
	int l,r;
	bool operator <(const seg& b)const{
		return l==b.r?r<b.r:l<b.l;
	}
}a[MAX_N];
int main(){
	int _;
	scanf("%d",&_);
	for(int cas=1;cas<=_;cas++){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<m;i++){
			scanf("%d%d",&a[i].l,&a[i].r);
		}
		sort(a,a+m);
		mem(dp,0);
		mem(arr,0);
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				if(a[j].l<=i&&a[j].r>=i){
					arr[i-1]=max(arr[i-1],a[j].r);
				}else if(a[j].l>i){
					break;
				}
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				dp[arr[i]][j+1]=max(dp[arr[i]][j+1],dp[i][j]+arr[i]-i);
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			}
		}
		printf("Case #%d: %d\n",cas,dp[n][k]);
	}
	
	return 0;
}