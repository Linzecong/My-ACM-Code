#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int maxn=1e5+5;
vector<int>G[maxn];
int depth[maxn],fa[maxn];
int rmq[maxn][18];
int n,q;
int u,v;
void dfs(int rt)
{
	for (int i=0;i<G[rt].size();i++)
	{
		if (fa[rt]==G[rt][i]) continue;
		fa[G[rt][i]]=rt;
		depth[G[rt][i]]=depth[rt]+1;
		rmq[G[rt][i]][0]=rt;
		dfs(G[rt][i]);
	}
}
int Lca(int u,int v)
{
	if (depth[u]<depth[v]) swap(u,v);
	for (int i=17;i>=0;i--)
		if (depth[rmq[u][i]]>=depth[v])
			u=rmq[u][i];
	for (int i=17;i>=0;i--)
		if (rmq[u][i]!=rmq[v][i])
			u=rmq[u][i],v=rmq[v][i];
	/*if (u!=v) return depth[rmq[u][0]];
	return depth[u];*/
	if (u!=v) return rmq[u][0];
	return u;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	depth[1]=1;
	dfs(1);
	int a,b,c,d;
	for (int i=1;i<=17;i++)
		for (int j=1;j<=n;j++)
		{
			rmq[j][i]=rmq[rmq[j][i-1]][i-1];
		}
	while (q--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ans=abs(depth[Lca(a,c)]-depth[Lca(b,c)]-depth[Lca(a,d)]+depth[Lca(b,d)]);
		int LCA=Lca(c,d);
		int u=Lca(LCA,a),v=Lca(LCA,b);
		bool f1=(((u==LCA)^(v==LCA))||(u==LCA&&v==LCA&&LCA==Lca(a,b)));
		swap(a,c);swap(b,d);
		LCA=Lca(c,d);
		u=Lca(LCA,a),v=Lca(LCA,b);
		bool f2=(((u==LCA)^(v==LCA))||(u==LCA&&v==LCA&&LCA==Lca(a,b)));
		if (ans==0&&!(f1||f2))
			printf("0\n");
		else
			printf("%d\n",ans+1);
	}
}/*
6 1
6 1
6 2
3 4
3 5
3 6
1 2 4 5*/