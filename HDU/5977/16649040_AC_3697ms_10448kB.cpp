#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=5e4+5;
const int INF=1e9+5;
vector<int>G[maxn];
int Sum,n,k;
int a[maxn],Size[maxn],Maxs[maxn],b[maxn];
bool vis[maxn];
long long cnt[2050],p[2050];
long long ans=0;
int root;
void getroot(int rt,int fa)
{
	Size[rt]=1;Maxs[rt]=0;
	for (int i=0;i<G[rt].size();i++)
	{
		if (G[rt][i]==fa||vis[G[rt][i]]) continue;
		getroot(G[rt][i],rt);
		Size[rt]+=Size[G[rt][i]];
		Maxs[rt]=max(Maxs[rt],Size[G[rt][i]]);
	}
	Maxs[rt]=max(Maxs[rt],Sum-Size[rt]);
	if (Maxs[root]>Maxs[rt]) root=rt;
}
int getdis(int rt,int fa,int d)
{
	int u=d|b[rt];
	cnt[u]++;
	for (int i=0;i<G[rt].size();i++)
	{
		if (vis[G[rt][i]]||G[rt][i]==fa) continue;
		getdis(G[rt][i],rt,u);
	}
}
long long solve(int rt,int w)
{
	memset(cnt,0,sizeof(cnt));
	getdis(rt,0,w);
	int u=(1<<k);
	long long sum=0;
	for (int i=0;i<u;i++) 
		p[i]=cnt[i];
	for (int j=0;j<k;j++)
	{
		for (int i=0;i<u;i++)
		{
			int v=1<<j;
			if (!(i&v)) p[i]+=p[i|v];
		}
	}
	long long W=0;
	for (int i=1;i<u;i++)
		W+=1ll*cnt[i]*p[(u-1)^i];
	return W;
}
void dfs(int rt,int fa)
{
	ans+=solve(rt,0);
	vis[rt]=true;
	for (int i=0;i<G[rt].size();i++)
	{
		if (vis[G[rt][i]]) continue;
		ans-=solve(G[rt][i],b[rt]);
		Sum=Size[rt];root=0;
		getroot(G[rt][i],rt);
		dfs(root,0);
	}
}
int main()
{
	int u,v;
	while (~scanf("%d%d",&n,&k))
	{
	    ans=0;
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=1<<(a[i]-1),G[i].clear();
		for (int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		root=0;Maxs[0]=INF;Sum=n;
		getroot(1,0);
		dfs(root,0);
		printf("%lld\n",ans);
	}
}