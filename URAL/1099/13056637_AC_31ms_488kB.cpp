#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

#define MEM(a,x) memset(a,x,sizeof a)
#define eps 1e-8
#define MOD 10009
#define MAXN 250
#define INF 99999999
#define ll __int64
#define bug cout<<"here"<<endl
#define fread freopen("ceshi.txt","r",stdin)
#define fwrite freopen("out.txt","w",stdout)

using namespace std;

int Read()
{
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' | ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return a;
}

void Print(int a)
{
     if(a>9)
         Print(a/10);
     putchar(a%10+'0');
}
deque<int> Q;
//g[i][j]存放关系图:i,j是否有边 match[i]存放i所匹配的点
bool g[MAXN][MAXN],inque[MAXN],inblossom[MAXN],inpath[MAXN];
int match[MAXN],pre[MAXN],base[MAXN];
int n,m,mmg;
//vector<int> res;

struct node
{
    int u,v;
}point[MAXN];
//找公共祖先
int findancestor(int u,int v)
{
    MEM(inpath,0);
    while(1)
    {
        u=base[u];
        inpath[u]=1;
        if(match[u]==-1)  break;
        u=pre[match[u]];
    }
    while(1)
    {
        v=base[v];
        if(inpath[v])  return v;
        v=pre[match[v]];
    }
}

//压缩花
void reset(int u,int anc)
{
    while(u!=anc)
    {
        int v=match[u];
        inblossom[base[u]]=1;
        inblossom[base[v]]=1;
        v=pre[v];
        if(base[v]!=anc)  pre[v]=match[u];
        u=v;
    }
}

void contract(int u,int v,int n)
{
    int anc=findancestor(u,v);
    MEM(inblossom,0);
    reset(u,anc); reset(v,anc);
    if(base[u]!=anc)  pre[u]=v;
    if(base[v]!=anc)  pre[v]=u;
    for(int i=1;i<=n;i++)
    {
        if(inblossom[base[i]])
        {
            base[i]=anc;
            if(!inque[i])
            {
                Q.push_back(i);
                inque[i]=1;
            }
        }
    }
}

bool dfs(int S,int n)
{
    for(int i=0;i<=n;i++)
    {
        pre[i]=-1; inque[i]=0; base[i]=i;
    }
    Q.clear(); Q.push_back(S); inque[S]=1;
    while(!Q.empty())
    {
        int u=Q.front(); Q.pop_front();
        for(int v=1;v<=n;v++)
        {
            if(g[u][v]&&base[v]!=base[u]&&match[u]!=v)
            {
                if(v==S||(match[v]!=-1&&pre[match[v]]!=-1)) contract(u,v,n);
                else if(pre[v]==-1)
                {
                    pre[v]=u;
                    if(match[v]!=-1)
                    {
                        Q.push_back(match[v]);
                        inque[match[v]]=1;
                    }
                    else
                    {
                        u=v;
                        while(u!=-1)
                        {
                            v=pre[u];
                            int w=match[v];
                            match[u]=v;
                            match[v]=u;
                            u=w;
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int solve()
{
    int ans=0;
    MEM(match,-1);
    for(int i=1;i<=n;i++)
        if(match[i]==-1&&dfs(i,n))  ans++;
    return ans;
}

int main()
{
//    fread;
    scanf("%d",&n);
    int u,v;
    MEM(g,0);
    while(scanf("%d%d",&u,&v)!=EOF)
    {
            g[u][v]=g[v][u]=1;
    }
    int res=solve();
    printf("%d\n",res*2);
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(match[i]!=-1)
        {
            printf("%d %d\n",i,match[i]);
            match[i]=match[match[i]]=-1;
        }
    }
}
