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
const int MAX_N=1e6+7;
ll n,r,p;
ll rec[MAX_N];
ll dfs(ll t)
{
	if(t<=1)
	{
		return 0;
	}
	if(rec[t])
	{
		return rec[t];
	}
	ll temp=1e18+7;
	for(ll i=1;i<t;i=(t-1)/((t-1)/(i+1)))
	{
		temp=min(temp,1LL*i*p+dfs((t-1)/(i+1)+1)+r);
		if((t-1)/(i+1)==0)
		{
			break;
		}
	}
	return rec[t]=temp;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	mem(rec,0);
	scanf("%I64d%I64d%I64d",&n,&r,&p);
	printf("%I64d\n",dfs(n));
	return 0;
}

