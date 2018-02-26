#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define ads(x) (x<0?-x:x)

struct node
{
    int x,y;
};

int n,m,sx,sy;
int map[305][305],vis1[305][305],vis2[305][305];
int to[4][2]= {1,0,0,1,-1,0,0,-1};

int bfs1()
{
    queue<node> Q;
    node a,next;
    int i,j;
    a.x = sx,a.y = sy;
    Q.push(a);
    vis1[a.x][a.y] = 1;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i<4; i++)
        {
            next = a;
            next.x+=to[i][0];
            next.y+=to[i][1];
            if(next.x>0 && next.x<=n && next.y>0 && next.y<=m)//相当于在原图的外围再加一圈0，表示空地
            {
                if(vis1[next.x][next.y])
                    continue;
                vis1[next.x][next.y] = 1;
                if(map[next.x][next.y]==0)//如果宝藏附近有空地，那么空地附近的石头对于宝藏而言也是外围的，因为走空地不需要消耗步骤
                {
                    Q.push(next);
                }
            }
            else
                return true;
        }
    }
    return false;
}

int bfs2()
{
    queue<node> Q;
    node a,next;
    int i,j,ans = 0;
    a.x = a.y = 0;
    Q.push(a);
    vis2[0][0] = 1;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i<4; i++)
        {
            next = a;
            next.x+=to[i][0];
            next.y+=to[i][1];
            if(next.x<0 || next.y<0 || next.x>n+1 || next.y>m+1)//超出边界
                continue;
            if(vis2[next.x][next.y])
                continue;
            vis2[next.x][next.y] = 1;
            if(vis1[next.x][next.y] && map[next.x][next.y]>0)//如果是宝藏外围的，我们留一个，取走其他的
            {
                ans+=map[next.x][next.y]-1;
            }
            else if(!vis1[next.x][next.y])//其他位置都取走
            {
                ans+=map[next.x][next.y];
                Q.push(next);
            }

        }
    }
    return ans;
}

int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        memset(map,0,sizeof(map));
        for(i = 1; i<=n; i++)
        {
            for(j = 1; j<=m; j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j] == -1)
                    sx = i,sy = j;
            }
        }
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        if(bfs1())//如果存在一条路到底，那么先手胜
        {
            printf("Ali Win\n");
            continue;
        }
        int ans = bfs2();
        if(ans%2)
            printf("Ali Win\n");
        else
            printf("Baba Win\n");
    }

    return 0;
}
