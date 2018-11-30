#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define lowbit(x) ((x) & -(x))
using namespace std;
const int maxn=1e5+5;
const int INF=1e9;
vector<int>v,h;
int x[maxn],X[maxn];
bool flag[maxn];
int n,m,y,x1,cnt;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		v.push_back(x[i]);
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x1,&X[i],&y);
		if (x1==1){
			h.push_back(X[i]);
		}
	}
	v.push_back(INF);
	sort(v.begin(),v.end());
	sort(h.begin(),h.end());
	int ans=INF;
//	for (int i=0;i<h.size();i++)
//		cout << h[i] << endl;
	for (int i=0;i<v.size();i++){
		int cur=(h.size()+i)-(upper_bound(h.begin(),h.end(),v[i]-1)-h.begin());
	//	cout << v[i] << endl;
	//	cout << upper_bound(h.begin(),h.end(),v[i]-1)-h.begin() << endl;
		ans=min(ans,cur);
	}
	printf("%d",ans);
}/*3 3
1000000000
1000000000
1000000000
1 1000000000 4
1 1000000000 2
1 6 5*/