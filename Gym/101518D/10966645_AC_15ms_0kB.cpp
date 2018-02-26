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
const int MAX_N=30;
char a[MAX_N];
int cnt[MAX_N];
bool vis[MAX_N];
ll fac[MAX_N];
ll ans;
int n; 
void init()
{
	fac[0]=1;
	for(int i=1;i<=20;i++)
	{
		fac[i]=(ll)i*fac[i-1];
	}
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	while(n--)
	{
		init();
		scanf("%s",a);
		ans=0;
		int len=strlen(a);
		ll tmp;
		for(int i=0;i<len;i++)
		{
			mem(vis,0);
			for(int j=i+1;j<len;j++)
			{
				if(a[j]<a[i]&&!vis[a[j]-'A'])
				{
					vis[a[j]-'A']=true;
					mem(cnt,0);
					for(int k=i;k<len;k++)
					{
						cnt[a[k]-'A']++;	
					} 
					cnt[a[j]-'A']--;
					tmp=fac[len-i-1];
					for(int k=0;k<26;k++)
					{
						if(cnt[k]>1)
						{
							tmp/=fac[cnt[k]];
						}
					}
					ans+=tmp;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

