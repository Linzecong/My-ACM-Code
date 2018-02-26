#include<iostream>
using namespace std;

const int MAXN=200001;
int nums[MAXN],segTree[MAXN*4];
	
int N,M,i,j;
char oper[5];

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
		segTree[node]=max(segTree[2*node],segTree[2*node+1]);
	}
}

int Query(int node,int begin,int end,int left,int right)
{
	if(begin>right||end<left)return -1;
	if(begin>=left&&end<=right)return segTree[node];
	int mid=(begin+end)/2;
	return max(Query(2*node,begin,mid,left,right),Query(2*node+1,mid+1,end,left,right));
}

void Update(int node,int begin,int end,int pos,int value)
{
	if(begin==pos&&end==pos)
	{
		segTree[node]=value;
		return;
	}
	int mid=(begin+end)/2;
	if(pos<=mid)Update(2*node,begin,mid,pos,value);
	else Update(2*node+1,mid+1,end,pos,value);
	segTree[node]=max(segTree[2*node],segTree[2*node+1]);
}

int main()
{
	while(~scanf("%d%d",&N,&M))
	{
		for(int k=1;k<=N;k++)scanf("%d",&nums[k]);
		Build(1,1,N);
		for(int k=1;k<=M;k++)
		{
			scanf("%s%d%d",oper,&i,&j);
			if(oper[0]=='Q')printf("%d\n",Query(1,1,N,i,j));
			if(oper[0]=='U')Update(1,1,N,i,j);
		}
	}
	return 0;
} 