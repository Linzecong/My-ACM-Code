#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=505;
int n,m;
int g[maxn][maxn];
int linker[maxn];
bool used[maxn];
bool dfs(int u)
{
    for(int v=1; v<=n; v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=1; u<=n; u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
}
void floyd()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(g[i][k]&&g[k][j])
                    g[i][j]=1;
            }
}
int main()
{
     while(scanf("%d%d",&n,&m))
     {
         if(n==0&&m==0)
            break;
            memset(g,0,sizeof(g));
         for(int i=1;i<=m;i++)
         {
             int u,v;
             scanf("%d%d",&u,&v);
             g[u][v]=1;
         }
         floyd();
         int ans=hungary();
         //cout<<ans<<endl;
         printf("%d\n",n-ans);
     }
    return 0;
}