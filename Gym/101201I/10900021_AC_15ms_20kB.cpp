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
const int MAX_N=1010;
struct Node
{
	ll x,m;
}node[MAX_N];
bool cmp(Node x,Node y)
{
	if(x.x!=y.x)
	{
		return x.x<y.x;
	}
	return x.m<y.m;
}
int n,k;
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	ll ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&node[i].x,&node[i].m);
	}
	sort(node,node+n,cmp);
	int pos=n-1,carry=k;
	while(pos>=0&&node[pos].x>=0)
	{
		ll t=(ll)(node[pos].m+k-1)/k;
		ans+=2LL*t*node[pos].x;
		carry=k*t-node[pos].m;
		node[pos].m=0;
		pos--;
		while(carry>=node[pos].m&&pos>=0&&node[pos].x>=0)
		{
			carry-=node[pos].m;
			node[pos].m=0;
			pos--;
		}
		if(pos>=0&&node[pos].x>=0)
		{
			node[pos].m-=carry;
		}
		carry=k;
	}
	int pos1=0;
	while(pos1<=pos)
	{
		ll t=(ll)(node[pos1].m+k-1)/k;
		ans+=2LL*t*(-node[pos1].x);
		carry=k*t-node[pos1].m;
		node[pos1].m=0;
		pos1++;
		while(carry>=node[pos1].m&&pos1<=pos)
		{
			carry-=node[pos1].m;
			node[pos1].m=0;
			pos1++;
		}
		if(pos1<=pos)
		{
			node[pos1].m-=carry;
		}
		carry=k;
	}
	printf("%lld\n",ans);
	return 0;
}

