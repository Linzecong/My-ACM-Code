#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1e5+5;
int fa[maxn];
vector<int>P[maxn];
int get(int w){
	return fa[w]==w?w:fa[w]=get(fa[w]);
}
int main(){
	int n,m;
	int ans=0,x,k;
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++){
		scanf("%d",&k);
		while (k--){
			scanf("%d",&x);
			P[x].push_back(i);
		}
	}
	for (int i=1;i<=m;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		int u=P[i][0],v=P[i][1];
		int fx=get(u);
		int fy=get(v); 
		if (fy!=fx){
			ans++;
			fa[fx]=fy;
		}
	}
	printf("%d\n",ans);
}