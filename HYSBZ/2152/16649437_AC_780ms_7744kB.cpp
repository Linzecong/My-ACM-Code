#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=200005;
const int INF=1e9;
struct node{
	int v,w;
	node(int a=0,int b=0)
	{
		v=a;w=b;
	}
};
int ans=0;
int root,Sum;
long long t[5];
int d[maxn];
int Size[maxn],Maxson[maxn]; 
bool vis[maxn];
vector<node>G[maxn];
void Getroot(int w,int fa)
{
	Size[w]=1; Maxson[w]=0;
	for (int i=0;i<(int)G[w].size();i++)
	{
		if (G[w][i].v==fa||vis[G[w][i].v]) continue;
		Getroot(G[w][i].v,w);
		Size[w]+=Size[G[w][i].v];
		Maxson[w]=max(Maxson[w],Size[G[w][i].v]);
	}
	Maxson[w]=max(Maxson[w],Sum-Size[w]);
	if (Maxson[root]>Maxson[w]) root = w;
}
void Getdeep(int w,int fa)
{
	t[d[w]]++;
	for (int i=0;i<(int)G[w].size();i++)
	if (!vis[G[w][i].v]&&fa!=G[w][i].v)
	{
		d[G[w][i].v]=(d[w]+G[w][i].w)%3;
		Getdeep(G[w][i].v,w); 
	}
}
int Solve(int w,int cost)
{
	d[w]=cost%3;
	t[1]=t[2]=t[0]=0;
	Getdeep(w,0);
	return t[1]*t[2]*2+t[0]*t[0];
}
void Divide(int w)
{
	Getroot(w,0);
	ans+=Solve(w,0);
	vis[w]=true;
	for (int i=0;i<(int)G[w].size();i++)
		if (!vis[G[w][i].v])	
		{
			ans-=Solve(G[w][i].v,G[w][i].w);
			Sum=Size[G[w][i].v];root=0;
			Getroot(G[w][i].v,w);
			Divide(root);
		}
}	
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	int i,j,k,n,m;
	int u,v,w;
	memset(vis,false,sizeof(vis));
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		//scanf("%d%d",&u,&v);
		G[u].push_back(node(v,w));
		G[v].push_back(node(u,w));
	}
	root=0;Sum=n;Maxson[0]=INF;
	Getroot(1,0);
	vis[root]=true;
	Divide(root);
	if (!ans)
    {
        puts("0/0");
        return 0;
    }
    else{
	i=gcd(ans,n*n);
	printf("%d/%d",ans/i,n*n/i);
    }
} 