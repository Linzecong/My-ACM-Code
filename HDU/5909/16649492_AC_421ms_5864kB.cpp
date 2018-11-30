#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=1e9+5;
const int maxn=1100;
const int Mod=1e9+7;
vector<int>G[maxn];
int Size[maxn],Maxs[maxn]; 
bool vis[maxn];
int dp[maxn][maxn];
int a[maxn],ans[maxn];
int n,m,u,v,Sum;
int root;
void getroot(int k,int fa)
{
	Size[k]=1;Maxs[k]=0;
	for (int i=0;i<G[k].size();i++)
	{	
		if (G[k][i]==fa||vis[G[k][i]]) continue;
		getroot(G[k][i],k);
		Size[k]+=Size[G[k][i]];
		Maxs[k]=max(Maxs[k],Size[G[k][i]]);
	}
	Maxs[k]=max(Maxs[k],Sum-Size[k]);
	if (Maxs[root]>Maxs[k]) root=k;
}
void getans(int k,int fa)
{
	for (int i=0;i<G[k].size();i++)
	{
		if (G[k][i]==fa||vis[G[k][i]]) continue;
		//for (int j=0;j<m;j++) dp[G[k][i]][j]=dp[k][j];
		//for (int j=0;j<m;j++) dp[G[k][i]][j^a[G[k][i]]]=(dp[G[k][i]][j^a[G[k][i]]]+dp[k][j])%Mod;
		//getans(G[k][i],k);
		//for (int j=0;j<m;j++) dp[k][j]=dp[G[k][i]][j];
	    for (int j=0;j<m;j++) dp[G[k][i]][j]=0;//??????
        for (int j=0;j<m;j++) dp[G[k][i]][a[G[k][i]]^j]=(dp[G[k][i]][a[G[k][i]]^j]+dp[k][j])%Mod;//??????
        getans(G[k][i],k);
        for (int j=0;j<m;j++) dp[k][j]=(dp[k][j]+dp[G[k][i]][j])%Mod;//????????
        
	}
}
void divide(int k)
{
	vis[k]=true;
	for (int i=0;i<m;i++) dp[k][i]=0;
	dp[k][a[k]]=1;
	getans(k,0);
	for (int i=0;i<m;i++) ans[i]=(ans[i]+dp[k][i])%Mod;
	for (int i=0;i<G[k].size();i++)
	{
		if (vis[G[k][i]]) continue;
		root=0;Sum=Size[G[k][i]];
		getroot(G[k][i],k);
		divide(root);
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(ans,0,sizeof(ans));
		memset(vis,false,sizeof(vis));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		Sum=n;
		for (int i=1;i<=n;i++)
			G[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		Maxs[0]=INF;root=0;
		getroot(1,0);
		divide(root);
		for (int i=0;i<m-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[m-1]);
	}
}