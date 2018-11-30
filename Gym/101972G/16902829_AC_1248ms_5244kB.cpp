#include <iostream>
#include <cstring>
using namespace std;
const int maxn=5e2+5;
int n,m;
int w[maxn][maxn];
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],d[maxn][maxn];
int main(){
	int T;
	cin >> T;
	while (T--){
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				scanf("%d",&w[i][j]);
				a[i][j]=b[i][j]=c[i][j]=d[i][j]=w[i][j];
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				a[i][j]=max(a[i][j],max(a[i-1][j],a[i][j-1]));
			}
		for (int i=n;i>=1;i--)
			for (int j=1;j<=m;j++){
				b[i][j]=max(b[i][j],max(b[i+1][j],b[i][j-1]));
			}
		for (int i=1;i<=n;i++)
			for (int j=m;j>=1;j--){
				c[i][j]=max(c[i][j],max(c[i-1][j],c[i][j+1]));
			}
		for (int i=n;i>=1;i--)
			for (int j=m;j>=1;j--){
				d[i][j]=max(d[i][j],max(d[i+1][j],d[i][j+1]));
			}
		int Ma,Mi;
		int ans=1e9+5;
		for (int i=2;i<=n-1;i++)
			for (int j=2;j<=m-1;j++){
				Ma=max(max(a[i-1][j-1],b[i+1][j-1]),max(c[i-1][j+1],d[i+1][j+1]));
				Mi=min(min(a[i-1][j-1],b[i+1][j-1]),min(c[i-1][j+1],d[i+1][j+1]));
				ans=min(Ma-Mi,ans);
			}
		printf("%d\n",ans);
	}
}