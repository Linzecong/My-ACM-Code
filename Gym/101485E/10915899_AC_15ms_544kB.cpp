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
const int MAX_N=2600;
map <ll,int> m;
int tot=1,cnt=0;
struct edge
{
	int to,next;
}e[MAX_N*3];
struct Node
{
	ll a,b,ans;
	char oper;
}node[MAX_N];
int head[MAX_N];
bool used[MAX_N*3];
ll rec[MAX_N*3];
int pipei[MAX_N*3];
void add_edge(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
int n;
ll a,b;
bool find(int x)
{
	for(int i=head[x];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!used[v])
		{
			used[v]=true;
			if(pipei[v]==-1||find(pipei[v]))
			{
				pipei[v]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	m.clear();
	mem(head,-1);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&a,&b);
		node[i].a=a;
		node[i].b=b;
		ll temp;
		temp=(ll)a-b;
		if(m[temp]==0)
		{
			m[temp]=tot;
			rec[tot++]=temp;
		}
		add_edge(i,m[temp]);
		temp=(ll)a+b;
		if(m[temp]==0)
		{
			m[temp]=tot;
			rec[tot++]=temp;
		}
		add_edge(i,m[temp]);
		temp=(ll)a*b;
		if(m[temp]==0)
		{
			m[temp]=tot;
			rec[tot++]=temp;
		}
		add_edge(i,m[temp]); 
	}
	int ans=0;
	mem(pipei,-1);
	for(int i=0;i<n;i++)
	{
		mem(used,0);
		if(find(i))
		{
			ans++;
		}
	}
	if(ans!=n)
	{
		puts("impossible");
	}
	else
	{
		for(int i=1;i<tot;i++)
		{
			if(pipei[i]!=-1)
			{
				int t=pipei[i];
				node[t].ans=rec[i];
				if(node[t].a+node[t].b==node[t].ans)
				{
					node[t].oper='+';
				}
				else if(node[t].a-node[t].b==node[t].ans)
				{
					node[t].oper='-';
				}
				else
				{
					node[t].oper='*';
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			printf("%I64d %c %I64d = %I64d\n",node[i].a,node[i].oper,node[i].b,node[i].ans);
		}
	}
	return 0;
}

