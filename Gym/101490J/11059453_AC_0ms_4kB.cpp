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
const int MAX_N=105;
struct node
{
	int x,y;
}stu[MAX_N],tot[MAX_N];
int n,ans; 
bool cmp(node a,node b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&stu[i].x,&stu[i].y);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&tot[i].x,&tot[i].y);
	}
	sort(stu,stu+n,cmp);
	sort(tot,tot+n,cmp);
	for(int i=0;i<n;i++)
	{
		ans=max(ans,abs(tot[i].x-stu[i].x)+abs(tot[i].y-stu[i].y));
	}
	printf("%d\n",ans);
	return 0;
}

