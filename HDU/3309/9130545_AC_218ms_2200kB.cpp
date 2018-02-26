#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
char map[24][24];
bool vis[24][24][24][24];
int n,m;
struct node
{
    int x[2],y[2]; //两个球坐标
    bool ball[2];  //球的状态
    bool hole[2];  //洞的状态
    int step;
    node()
    {
        ball[0]=ball[1]=hole[0]=hole[1]=false;
        step=0;
    }
    void init()
    {
        ball[0]=ball[1]=hole[0]=hole[1]=false;
        step=0;
    }
};
node start;
bool check(node &a)
{
    for (int i=0; i<2; i++)
    {
        if(a.x[i]<0 ||a.x[i]>=n || a.y[i]<0 || a.y[i]>=m)
            return false;
    }

    if(a.x[0]==a.x[1]&& a.y[0]==a.y[1] && a.ball[0]==a.ball[1] && a.ball[0]==0)
        return false;
    if(vis[a.x[0]][a.y[0]][a.x[1]][a.y[1]])
        return false;
    return true;
}
int bfs()
{
    memset(vis,0, sizeof(vis));
    queue<node>q;
    q.push(start);
    vis[start.x[0]][start.y[0]][start.x[1]][start.y[1]]=true;
    node temp;
    while (!q.empty())
    {
        start=q.front();
        q.pop();
        for (int i=0; i<4; i++)
        {
            temp=start;
            temp.step++;
            for (int j=0; j<2; j++)//对两个球进行移动
            {
                if(!temp.ball[j])
                {
                    temp.x[j]+=dir[i][0];
                    temp.y[j]+=dir[i][1];
                    if(map[temp.x[j]][temp.y[j]]=='*')
                    {
                        temp.x[j]-=dir[i][0];
                        temp.y[j]-=dir[i][1];
                    }
                }
            }
            if(check(temp))
            {
                vis[temp.x[0]][temp.y[0]][temp.x[1]][temp.y[1]]=true;
                bool flag=true;
                for (int j=0; j<2; j++) //检查球是否进洞
                {
                    int k=map[temp.x[j]][temp.y[j]]; //判断第k个洞的状态
                    if(k<2 && !temp.hole[k])
                    {
                        temp.hole[k]=1;
                        temp.ball[j]=1;
                    }
                    if(!temp.ball[j])
                        flag=false;
                }
                if(flag)  //都进洞了
                    return temp.step;
                q.push(temp);
            }
        }

    }
    return -1;
}

int main()
{
    int t,cnt;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        getchar();
        cnt=0;
        bool flag=false;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='B' && !flag)
                {
                    start.x[0]=i;
                    start.y[0]=j;
                    flag=true;
                }
                else if(map[i][j]=='B' && flag)
                {
                    start.x[1]=i;
                    start.y[1]=j;
                }
                if(map[i][j]=='H')
                {
                    map[i][j]=cnt++;
                }
            }
            getchar();
        }
        start.init();
        int ans=bfs();
        if(ans!=-1)
            printf("%d\n",ans);
        else
            printf("Sorry , sir , my poor program fails to get an answer.\n");
    }
    return 0;
}
