#pragma comment(linker, "/STACK:1024000000,1024000000") //加栈
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define inf 0x3f3f3f3f
int num,tot;
int m,q,n;
int head[maxn];
int h[maxn];
int dfn[maxn];
int parent[30][maxn];
int bnum,block,belong[maxn],l[maxn],r[maxn];
int cn[maxn],nxt[maxn],pre[maxn];//跳出本块的次数,跳向的下一块的点,这个点会跳向的位置
struct Edge
{
    int u,v,next,w,id;
}edge[maxn<<1];
void addEdge(int u,int v,int w)
{
    edge[num].u=u;
    edge[num].v=v;
    edge[num].w=w;
    edge[num].next=head[u];
    head[u]=num++;
}
void init()
{
    num=0;
    tot=0;
    memset(head,-1,sizeof(head));
}
void dfs(int u,int pre)
{
    parent[0][u]=pre;
    dfn[u]=++tot;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==pre) continue;
        dfs(v,u);
    }
}
void Build()
{
    block=sqrt(n);
    bnum=n/block;
    if(n/block) bnum++;
    for(int i=1;i<=n;i++)//分块处理技巧
    {
        belong[i]=(i-1)/block+1;
    }
    for(int i=1;i<=bnum;i++)//记录块的左右端点
    {
        l[i]=(i-1)*block+1,r[i]=i*block;
    }
    r[bnum]=n;
}
int Find(int x,int value)//找x向走上value能到达的点
{
    int d=value;
    int tmp=0;
    while(d)
    {
        int k=0;
        while((1<<(k+1))<=d)
        {
            k++;
        }
        tmp=parent[k][x];
        x=tmp;
        d-=(1<<k);
    }
    return x;
}
void dfs2(int u,int pr)
{
   int tmp=Find(u,h[u]);
   pre[dfn[u]]=dfn[tmp]; 
   if(dfn[tmp]<l[belong[dfn[u]]])
   {
       cn[dfn[u]]=1;
       nxt[dfn[u]]=dfn[tmp];
   }
   else
   {
       cn[dfn[u]]=cn[dfn[tmp]]+1;
       nxt[dfn[u]]=nxt[dfn[tmp]];
   }
   for(int i=head[u];i!=-1;i=edge[i].next)
   {
       int v=edge[i].v;
       if(v==pr) continue;
       dfs2(v,u);
   }
}
int query(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=cn[x];
        x=nxt[x];
    }
    return ans;
}
void updata(int x,int v)
{
    int tmp=Find(x,v);
    h[x]=v;
    pre[dfn[x]]=dfn[tmp];
    if(dfn[tmp]<l[belong[dfn[x]]])//在块外，只需要一次
   {
       cn[dfn[x]]=1;
       nxt[dfn[x]]=dfn[tmp];
   }
   else//之所以不判r是因为dfs序是递增的，所以x的前一个点的dfn必然小于x的dfn
   {
       cn[dfn[x]]=cn[dfn[tmp]]+1;//在块内，则递归求
       nxt[dfn[x]]=nxt[dfn[tmp]];
   }
   for(int i=dfn[x]+1;i<=r[belong[dfn[x]]];i++)
   {
       if(pre[i]>=l[belong[i]])//只更新在块内的
       {
           cn[i]=cn[pre[i]]+1;
           nxt[i]=nxt[pre[i]];//找跳向下一块的点，也是递归
       }
   }
}
void solve()
{
    Build();
    dfs(1,-1);
    for(int k=0;k<20;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(parent[k][i]<0)
            {
                parent[k+1][i]=-1;
            }
            else
            {
                parent[k+1][i]=parent[k][parent[k][i]];
            }
        }
    }
    dfs2(1,-1);
}
int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    cin>>T;
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            addEdge(i,x,0);
            addEdge(x,i,0);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
        }
        solve();
        scanf("%d",&q);
        while(q--)
        {
            int op;
            scanf("%d",&op);
            if(op==1)
            {
                int x;
                scanf("%d",&x);
                printf("%d\n",query(dfn[x]));
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                updata(x,y);
            }
        }
    }
    return 0;
}
