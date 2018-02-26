#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxnum=101;
int map[maxnum][maxnum];
int n,m;

void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=map[i][j] || (map[i][k]&&map[k][j]);//判断i和j是否连通
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(map,0,sizeof(map));
    int i,j,u,v;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        map[u][v]=1;
    }
    floyd();
    int ans,res=0;
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(j=1;j<=n;j++)
        {
            if(i==j)    continue;
            else if(map[i][j] || map[j][i])
                ans++;
        }
        if(ans==n-1)//出度+入度=n-1
            res++;
    }
    printf("%d\n",res);
    return 0;
}