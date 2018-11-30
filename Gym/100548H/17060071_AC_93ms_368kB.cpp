#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct node{
	int a,b,flag;
};
queue<node>Q;
bool G[105][105];
int num[105][105],u,v,n,m,x,y;
bool dp[105][105][5];//0alice  1bob
//dp false ±íÊ¾bobÊä true bobÓ® 
int deg[105];
int main(){
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		memset(dp,-1,sizeof(dp));
		memset(num,0,sizeof(num));
		memset(deg,0,sizeof(deg));
		memset(G,false,sizeof(G));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			G[u][v]=true;
			deg[u]++;
		}
		for (int i=1;i<=n;i++){
			dp[i][i][0]=false;
			dp[i][i][1]=false;
			Q.push({i,i,0});
			Q.push({i,i,1});
		}
		scanf("%d%d",&x,&y);
		for (int i=1;i<=n;i++){
			if (deg[i]==0){
				for (int j=1;j<=n;j++){
					if (i==j) continue;
					dp[j][i][0]=false;
					Q.push({j,i,0});
				}
			}
		}
		while (!Q.empty()){
			node u=Q.front();
			Q.pop();
			if (!u.flag){
				for (int i=1;i<=n;i++){
					if (G[i][u.a]){
						if (dp[i][u.b][1]) Q.push({i,u.b,1});
						dp[i][u.b][1]=false;
					}
				}
			}else{
				for (int i=1;i<=n;i++){
					if (G[i][u.b]){
						num[i][u.a]++;
						if (num[i][u.a]==deg[i]){
							if (dp[u.a][i][0]) 
								Q.push({u.a,i,0});
							dp[u.a][i][0]=false;
						}	
					}
				}
			}
		}
		printf("Case #%d: ",Case);
		if (dp[y][x][0]) printf("Yes\n");
		else printf("No\n");
	}
	
}/*5
4 3
1 2
2 3
3 4
1 2
*/