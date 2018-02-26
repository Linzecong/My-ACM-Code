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
int cnt(ll x)
{
	int c=0;
	while(x)
	{
		c++;
		x>>=1;
	}
	return c;
}
ll get(ll x)
{
	ll res=x;
	ll a=0,b=0;
	int c=cnt(x);
	{
		for(int i=0;i<=c;i++)
		{
			a=a|((x&1)<<i);
			x>>=1;
			b=x|(a<<(c-i-1));
			if(res>b&&(b&((1ll)<<(c-1))))
			{
				res=b;
			}
		}
	}
	return res;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	ll x,ans;
	scanf("%I64d",&x);
	ans=get(x);
	int pos=0;
	while(x)
	{
		if(x&1)
		{
			ll temp=get((x<<pos)-1);
			if(ans<temp)
			{
				ans=temp;
			}
		}
		x>>=1;
		pos++;
	}
	printf("%I64d\n",ans);
	return 0;
}

