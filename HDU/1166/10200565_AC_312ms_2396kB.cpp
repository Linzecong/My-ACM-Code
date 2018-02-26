#include<iostream>
using namespace std;

const int MAXN=50005;
int nums[MAXN],segTree[MAXN*4];
	
int T,cnt;
int N,i,j;
char oper[10];

void Build(int node,int begin,int end)
{
	if(begin==end)
	{
		segTree[node]=nums[begin];
	}
	else
	{
		Build(2*node,begin,(begin+end)/2);
		Build(2*node+1,(begin+end)/2+1,end);
		segTree[node]=segTree[2*node]+segTree[2*node+1];
	}
}

int Query(int node,int begin,int end,int left,int right)
{
	if(begin>right||end<left)return 0;
	if(begin>=left&&end<=right)return segTree[node];
	int mid=(begin+end)/2;
	return Query(2*node,begin,mid,left,right)+Query(2*node+1,mid+1,end,left,right);
}

void Add(int node,int begin,int end,int pos,int value)
{
	if(begin==end)
	{
		segTree[node]+=value;
		return;
	}
	int mid=(begin+end)/2;
	if(pos<=mid)Add(2*node,begin,mid,pos,value);
	else Add(2*node+1,mid+1,end,pos,value);
	segTree[node]=segTree[2*node]+segTree[2*node+1];
}

void Sub(int node,int begin,int end,int pos,int value)
{
	if(begin==end)
	{
		segTree[node]-=value;
		return;
	}
	int mid=(begin+end)/2;
	if(pos<=mid)Sub(2*node,begin,mid,pos,value);
	else Sub(2*node+1,mid+1,end,pos,value);
	segTree[node]=segTree[2*node]+segTree[2*node+1];
}

int main()
{
	scanf("%d",&T);
	cnt=0;
	while(cnt<T)
	{
		cnt++;
		printf("Case %d:\n",cnt);
		scanf("%d",&N);
		for(int k=1;k<=N;k++)scanf("%d",&nums[k]);
		Build(1,1,N);
		while(scanf("%s",oper))
		{
			if(oper[0]=='E')break;
			scanf("%d%d",&i,&j);
			if(oper[0]=='Q')printf("%d\n",Query(1,1,N,i,j));
			if(oper[0]=='A')Add(1,1,N,i,j);
			if(oper[0]=='S')Sub(1,1,N,i,j);
		}
	}
	return 0;
} 