#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
int n,m,pre;
int x[maxn],w[maxn],cnt[maxn];
bool flag[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+m;i++){
		scanf("%d",&x[i]);
	}
	for (int i=1;i<=n+m;i++){
		scanf("%d",&flag[i]);
	}
	pre=0;
	for (int i=1;i<=n+m;i++){
		if (!flag[i]) continue;
		for (int j=i-1;j>=max(pre,1);j--){
			if (flag[j]) break;
			if (w[j]>x[i]-x[j]||w[j]==0){
				cnt[pre]--;
				cnt[i]++;
			}
			else break;
		}		
		for (int j=i+1;j<=n+m;j++){
			if (flag[j]) break;
			cnt[i]++;
			w[j]=x[j]-x[i];
		}
		pre=i;
	}
	for (int i=1;i<=n+m;i++){
		if (!flag[i]) continue;
		printf("%d ",cnt[i]);
	}
}