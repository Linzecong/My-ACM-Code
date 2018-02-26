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
const int MAX_N=2e5+10;
ll BIT[MAX_N],n,pos[MAX_N],a[MAX_N],b[MAX_N],c[MAX_N];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,ll v)
{
	while(x)
	{
		BIT[x]+=v;
		x-=lowbit(x);
	}
}
ll sum(int x)
{
	ll res=0;
	while(x<MAX_N)
	{
		res+=BIT[x];
		x+=lowbit(x);
	}
	return res;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	ll ans=0;
	mem(pos,0);
	for(int i=1;i<=n;i++)
	{
		pos[a[i]]=i;
	}
	mem(BIT,0);
	for(int i=1;i<=n;i++)
	{
		ans+=(ll)sum(pos[b[i]]+1);
		update(pos[b[i]],1LL);
	}
	mem(BIT,0);
	for(int i=1;i<=n;i++)
	{
		ans+=(ll)sum(pos[c[i]]+1);
		update(pos[c[i]],1LL);
	}
	mem(BIT,0);
	for(int i=1;i<=n;i++)
	{
		pos[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(ll)sum(pos[c[i]]+1);
		update(pos[c[i]],1LL);
	}
	printf("%I64d\n",((ll)n*(n-1)-ans)/2);
	return 0;
}

