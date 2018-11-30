#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>G[1005];
int x,y,n,m,b;
int main(){
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		cin >> n >> m;
		cin >> b;
		for (int i=1;i<=n;i++) G[i].clear(),G[i].push_back(m);
		for (int i=1;i<=b;i++){
			cin >> x >> y;
			G[x+1].push_back(y);
		}
		for (int i=1;i<=n;i++)
			sort(G[i].begin(),G[i].end());
		int pre,p;
		int Ma=0,Mi=0;
		for (int i=1;i<=n;i++){
			pre=-1;
			for (int j=0;j<G[i].size();j++){
				int u=G[i][j];
				int num=G[i][j]-pre-1;
				Ma+=(num+1)/2;
				Mi+=(num+2)/3;
				pre=G[i][j];
			}
		}
		cout << "Case #"<<Case << ": "<<Ma << ' '<<Mi<< endl;
	}
		
}