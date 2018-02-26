#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define inf 2000000000
#define ll long long 
#define N 100005
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n,m,top;
int q[N];
int c[N][2],fa[N],v[N];
int mx1[N],mx2[N],c1[N],c2[N],size[N];
int ta[N],tc[N];
bool rev[N];
void solve(int x,int val,int c)
{
	if(val>mx1[x])mx2[x]=mx1[x],mx1[x]=val,c2[x]=c1[x],c1[x]=c;
	else if(val==mx1[x])c1[x]+=c;
	else if(val>mx2[x])mx2[x]=val,c2[x]=c;
	else if(val==mx2[x])c2[x]+=c;
}
void update(int x)
{
	int l=c[x][0],r=c[x][1];
	mx1[x]=mx2[x]=-inf;c1[x]=c2[x]=0;
    solve(x,v[x],1);
	if(l)solve(x,mx1[l],c1[l]),solve(x,mx2[l],c2[l]);
	if(r)solve(x,mx1[r],c1[r]),solve(x,mx2[r],c2[r]);
	size[x]=size[l]+size[r]+1;
}
void add(int y,int val)
{
	mx1[y]+=val;v[y]+=val;
	if(mx2[y]!=-inf)mx2[y]+=val;
	ta[y]+=val;
}
void change(int y,int val)
{
	mx1[y]=val;v[y]=val;c1[y]=size[y];
	mx2[y]=-inf;c2[y]=0;
    tc[y]=val;
	if(ta[y])ta[y]=0;
}
void pushdown(int x)
{
	int l=c[x][0],r=c[x][1];
	if(rev[x])
	{
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);
	}
	if(tc[x]!=-inf)
	{
		if(l)change(l,tc[x]);
		if(r)change(r,tc[x]);
		tc[x]=-inf;
	}
	if(ta[x])
	{
		if(l)add(l,ta[x]);
		if(r)add(r,ta[x]);
		ta[x]=0;
	}
}
bool isroot(int x)
{
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}
void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	if(c[y][0]==x)l=0;else l=1;r=l^1;
	if(!isroot(y))
	{
		if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;
	}
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	update(y);update(x);
}
void splay(int x)
{
	top=0;q[++top]=x;
	for(int i=x;!isroot(i);i=fa[i])
		q[++top]=fa[i];
	while(top)pushdown(q[top--]);
	while(!isroot(x))
	{
		int y=fa[x],z=fa[y];
		if(!isroot(y))
		{
			if(c[y][0]==x^c[z][0]==y)rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void access(int x)
{
	for(int t=0;x;t=x,x=fa[x])
		splay(x),c[x][1]=t,update(x);
}
void makeroot(int x)
{
	access(x);splay(x);rev[x]^=1;
}
void link(int x,int y)
{
	makeroot(x);fa[x]=y;
}
void cut(int x,int y)
{
	makeroot(x);access(y);splay(y);
	c[y][0]=fa[x]=0;update(y);
}
void query(int x,int y)
{
   makeroot(x);access(y);splay(y);
	if(c1[y]==size[y])puts("ALL SAME");
	else printf("%d %d\n",mx2[y],c2[y]);
}
int main()
{
	T=read();
	for(int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:\n",cas);
		n=read();m=read();
		for(int i=1;i<=n;i++)
			v[i]=read();
		for(int i=1;i<=n;i++)
		{
			mx1[i]=v[i],c1[i]=1;
			mx2[i]=-inf,c2[i]=0;
			size[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			fa[i]=c[i][0]=c[i][1]=0;
			ta[i]=rev[i]=0;tc[i]=-inf;
		}
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			link(u,v);
		}
		int opt,x,y,a,b,d;
	    while(m--)
		{
		    opt=read();
			if(opt==1)
			{
				x=read();y=read();a=read();b=read();
				cut(x,y);link(a,b);
			}
			else if(opt==2)
			{
				a=read();b=read();x=read();
				makeroot(a);access(b);splay(b);
				change(b,x);
			}
			else if(opt==3)
			{
				a=read();b=read();d=read();
				makeroot(a);access(b);splay(b);
				add(b,d);
			}
			else 
			{
				a=read();b=read();
				query(a,b);
			}
		}
	}
	return 0;
}