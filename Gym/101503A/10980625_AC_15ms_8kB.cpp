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
int a[10];
string s;
int ans=0,pos=0;
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	for(int i=1;i<=7;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=0)
		{
			pos=i;
		}
	}
	cin>>s;
	if(s=="RED")
	{
		ans+=pos;
	}
	while(a[1])
	{
		if(pos!=1)
		{
			ans+=pos+1;
		}
		else
		{
			ans++;
		}
		a[1]--;
	}
	for(int i=1;i<=7;i++)
	{
		if(a[i])
		{
			ans+=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

