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
const int MAX_N=3e5+10;
priority_queue<int,vector<int>,greater<int> >q;
struct Node
{
	int s,l;
}node[MAX_N];
int n,m;
bool cmp(Node x,Node y)
{
	if(x.s==y.s)
		return x.l<y.l;
	return x.s<y.s;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	while(!q.empty())
	{
		q.pop();
	}
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&node[i].s,&node[i].l);
	}
	int ans=0;
	sort(node,node+n,cmp);
	for(int i=0;i<n;i++)
	{
		while(!q.empty()&&node[i].s-q.top()>m)
		{
			q.pop();
		}
		if(!q.empty()&&node[i].s>=q.top()&&node[i].s-q.top()<=m)
		{
			q.pop();
			ans++;
		}
		q.push(node[i].s+node[i].l);
	}
	printf("%d\n",ans);
	return 0;
}

