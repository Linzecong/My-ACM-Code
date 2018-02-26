#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define EPS 1e-8
using namespace std;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double pi = acos(-1.0);
int read()
{
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret;
}
const int MAX_N=1e5+7;
ll T[MAX_N],BIT[MAX_N];
ll ans[MAX_N];
int E[MAX_N],R[MAX_N];
int head[MAX_N],cnt=0;
struct Edge
{
	int to,next;
}edge[MAX_N];
void add_edge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,ll k)
{
	while(x<MAX_N)
	{
		BIT[x]+=k;
		x+=lowbit(x);
	}
}
ll sum(int x)
{
	ll res=0;
	while(x)
	{
		res+=BIT[x];
		x-=lowbit(x);
	}
	return res;
}
void dfs(int u,ll tmp)
{
	for(int i=head[u];~i;i=edge[i].next)
	{
		int v=edge[i].to;
		dfs(v,sum(R[v]-1));
	}
	ans[u]+=sum(R[u]-1)-tmp;
	update(R[u],T[u]);
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	mem(head,-1);
	mem(BIT,0);
	int root;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%I64d",&E[i],&R[i],&T[i]);
		if(E[i]!=-1)
		{
			add_edge(E[i],i);
		}
		else
		{
			root=i;
		}
	}
	dfs(root,0);
	for(int i=1;i<=n;i++)
	{
		printf("%I64d\n",ans[i]);
	}
	return 0;
}

