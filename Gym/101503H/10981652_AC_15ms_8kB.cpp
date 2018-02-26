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
int n,k1,k2,p1,p2,p3,ans,cnt;
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	ans=0;
	scanf("%d%d%d%d%d%d",&n,&k1,&k2,&p1,&p2,&p3);
	if(n>=p1)
	{
		n-=p1;
		ans+=k1;
		while(n>0&&k2>0)
		{
			n-=p2;
			k2--;
			ans++;
		}
		while(n>0)
		{
			n-=p3;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

