#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N,M,T;

char maze[25][25];
bool vis[25][25][1<<11];

struct point{
    int x;
    int y;
    int state;
    int time;
    point(int a,int b,int c,int d){
        x=a;
        y=b;
        state=c;
        time=d;
    }
    point(){}
};

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(point start,point end){
    queue<point> que;
    que.push(start);

    vis[start.x][start.y][start.state]=1;

    while(!que.empty()){

        point tp=que.front();
        que.pop();

        if(tp.x==end.x&&tp.y==end.y)
            return tp.time;

        for(int i=0;i<4;i++){

            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            int s=tp.state;
            int t=tp.time;

            if(vis[x][y][s]==0&&maze[x][y]!='*'){
                vis[x][y][s]=1;
                if(maze[x][y]!='.'){
                    if(maze[x][y]>='a'){
                        s=s|(1<<(maze[x][y]-'a'));
                        vis[x][y][s]=1;
                        que.push(point(x,y,s,t+1));
                    }
                    else{
                        if(s&(1<<(maze[x][y]-'A'))){
                            que.push(point(x,y,s,t+1));
                        }
                    }
                }
                else{
                    que.push(point(x,y,s,t+1));
                }
            }



        }



    }


    return -1;
}



int main(){


    while(~scanf("%d %d %d",&N,&M,&T)){

        memset(vis,0,sizeof(vis));

        for(int i=0;i<=N+1;i++)
            for(int j=0;j<=M+1;j++)
                maze[i][j]='*';

        point s,e;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='@'){
                    s=point(i,j,0,0);
                    maze[i][j]='.';
                }
                if(maze[i][j]=='^'){
                    e=point(i,j,0,0);
                    maze[i][j]='.';
                }
            }

        int ans=bfs(s,e);

        if(ans==-1||ans>=T)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;





    }

    return 0;
}
