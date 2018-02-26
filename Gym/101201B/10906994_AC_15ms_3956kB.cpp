#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define MAXV 2000005
#define INF (1<<30)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long int ll;

struct point{
    int x;
    int y;
    int pos;
    point(int a=0,int b=0,int c=0){
        x=a;
        y=b;
        pos=c;
    }
};

string commend;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char maze[100][100];
int n,m;
int dp[100][100][100];
int mp[255];

bool check(int i,int j) {
    return i>0&&i<=n&&j>0&&j<=m&&maze[i][j]!='#';
}

void bfs(point s){
    queue<point> que;
    que.push(s);

    while(!que.empty()){
        point tp=que.front();
        que.pop();

        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            int p=tp.pos;
            if(check(x,y)){
                if(dp[x][y][p]>dp[tp.x][tp.y][p]+1){
                    dp[x][y][p]=dp[tp.x][tp.y][p]+1;
                    que.push(point(x,y,p));
                }
            }
        }

        int x=tp.x;
        int y=tp.y;
        int p=tp.pos;

        if(p<commend.length()){
            if(dp[x][y][p+1]>dp[x][y][p]+1){
                dp[x][y][p+1]=dp[x][y][p]+1;
                que.push(point(x,y,p+1));
            }


            x=tp.x+dx[mp[commend[p]]];
            y=tp.y+dy[mp[commend[p]]];

            if(!check(x,y)){
                x=tp.x;
                y=tp.y;
            }

            if(dp[x][y][p+1]>dp[tp.x][tp.y][p]){
                dp[x][y][p+1]=dp[tp.x][tp.y][p];
                que.push(point(x,y,p+1));
            }
        }

    }

}




int main()
{

    mp['D']=0;
    mp['R']=1;
    mp['U']=2;
    mp['L']=3;

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>maze[i][j];
    cin>>commend;

    int sx,sy;
    int ex,ey;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(maze[i][j]=='R')sx=i,sy=j;
            if(maze[i][j]=='E')ex=i,ey=j;
        }

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=commend.length();k++)
                dp[i][j][k]=INF;

    dp[sx][sy][0]=0;
    bfs(point(sx,sy,0));

    int ans=INF;
    for(int i=0;i<=commend.length();i++)
        ans=min(ans,dp[ex][ey][i]);

    printf("%d\n",ans);

    return 0;
}







