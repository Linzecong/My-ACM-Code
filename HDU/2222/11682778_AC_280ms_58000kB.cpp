#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define ll long long
#define pa pair<int,int>
#define maxn 500005
using namespace std;
int tt,n,ans,tot;
int t[maxn][26],go[maxn],v[maxn];
bool used[maxn];
char s[1000005];
inline void insert()
{
	scanf("%s",s);
	int len=strlen(s),now=1;
	F(i,0,len-1)
	{
		int x=s[i]-'a';
		if (!t[now][x]) t[now][x]=++tot;
		now=t[now][x];
	}
	v[now]++;
}
inline void bfs()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x=q.front(),y,j;q.pop();
		F(i,0,25)
		{
			j=go[x];
			while (j&&!t[j][i]) j=go[j];
			if (t[x][i])
			{
				go[y=t[x][i]]=j?t[j][i]:1;
				q.push(y);
			}
			else t[x][i]=j?t[j][i]:1;
		}
	}
}
inline void calc(int j)
{
	while (j&&!used[j])
	{
		if (v[j]) ans+=v[j];
		used[j]=true;
		j=go[j];
	}
}
inline void find()
{
	int len=strlen(s),j=1;
	F(i,0,len-1)
	{
		int x=s[i]-'a';
		j=t[j][x];
		calc(j);
	}
}
int main()
{
	scanf("%d",&tt);
	while (tt--)
	{
		tot=1;ans=0;
		memset(t,0,sizeof(t));
		memset(v,0,sizeof(v));
		memset(go,0,sizeof(go));
		memset(used,false,sizeof(used));
		scanf("%d",&n);
		F(i,1,n) insert();
		bfs();
		scanf("%s",s);
		find();
		printf("%d\n",ans);
	}
}
