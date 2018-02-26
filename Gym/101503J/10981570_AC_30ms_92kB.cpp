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
const int MAX_N=1e4+7;
int color[MAX_N];
int n,cnt=0,prime[MAX_N];
bool is_prime[MAX_N];
void seive()
{
	fill(is_prime,is_prime+MAX_N,true);
	for(int i=2;i<=100;i++)
	{
		if(is_prime[i])
		{
			for(int j=2*i;j<=100;j+=i)
			{
				is_prime[j]=false;
			}
			prime[cnt++]=i;
		}
	}
}
void solve()
{
	for(int i=1;i<MAX_N;i++)
	{
		int k=i;
		for(int j=0;j<cnt&&k>=prime[j];j++)
		{
			while(k%prime[j]==0)
			{
				k/=prime[j];
				color[i]++;
			}
		}
		if(k!=1)
		{
			color[i]++;
		}
	}
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	seive();
	solve();
	scanf("%d",&n);
	set <int> s;
	s.clear();
	for(int i=1;i<=n;i++)
	{
		s.insert(color[i]);
	}
	printf("%d\n",s.size());
	for(int i=1;i<=n;i++)
	{
		printf("%d ",color[i]+1);
	}
	return 0;
}

