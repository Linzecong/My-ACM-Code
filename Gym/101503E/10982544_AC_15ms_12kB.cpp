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
int n;
set <int> s;
vector < int > vec;
const int MAX_N=1000;
int a[MAX_N],b[MAX_N];
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	mem(b,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s.insert(a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		if(s.find(a[1]^a[i])!=s.end())
		{
			b[0]++;
			b[b[0]]=i;
		}
	}
	vec.push_back(0);
	vec.push_back(a[1]);
	if(b[0])
	{
		vec.push_back(a[b[1]]);
	}
	for(int i=2;i<=b[0];i++)
	{
		if(s.find(a[b[1]]^a[b[i]])!=s.end()&&(a[b[1]]^a[b[i]])!=a[1])
		{
			vec.push_back(a[b[i]]);
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		printf("%d ",vec[i]);
	}
	return 0;
}

