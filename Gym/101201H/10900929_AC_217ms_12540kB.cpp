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
const int MAX_K=4e5+100;
struct Node
{ 
	int left,cnt;
	ll pos,len;
	Node(int left=0,int cnt=0,ll pos=0,ll len=0)
	{
		this->left=left;
		this->cnt=cnt;
		this->pos=pos;
		this->len=len;
	}
}node[MAX_K];
ll n,ans,dp[MAX_K];
int k;
bool cmp(Node x,Node y)
{
	if(x.pos==y.pos)
		x.left<y.left;
	return x.pos<y.pos;
}
int main()
{
	mem(dp,0);
	ans=0;
	scanf("%lld%d",&n,&k);
	ll x,y;
	for(int i=0;i<k;i++)
	{
		scanf("%lld%lld",&x,&y);
		node[i]=Node(0,i,x,y-x+1);
		node[i+k]=Node(1,i,y,y-x+1);
	}
	sort(node,node+2*k,cmp);
	ll tmp=0;
	for(int i=0;i<2*k;i++)
	{
		if(node[i].left==0)
		{
			dp[node[i].cnt]=tmp+node[i].len;
		}
		else
		{
			tmp=max(tmp,dp[node[i].cnt]);
		}
	}
	ll ans=0;
	for(int i=0;i<k;i++)
	{
		ans=max(ans,dp[i]);
		//cout<<dp[i]<<endl;
	}
	printf("%lld\n",n-ans);
	return 0;
}