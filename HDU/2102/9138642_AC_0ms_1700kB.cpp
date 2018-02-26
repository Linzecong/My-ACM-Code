#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;


char maze[15][15][3];
bool vis[15][15][3];

int n,m,t;

struct point{
    int x;
    int y;
    int i;
    int step;
    point(int a,int b,int c,int d){
        x=a;
        y=b;
        i=c;
        step=d;
    }
    point(){}
};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


int bfs(point start,point end){
    queue<point> que;
    que.push(start);

    vis[start.x][start.y][start.i]=1;


    while(!que.empty()){
        point tp=que.front();
        que.pop();


        if(tp.x==end.x&&tp.y==end.y&&tp.i==end.i){

            if(tp.step>t)
                return false;
            else
                return true;
        }

        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            int s=tp.step;
            int c=tp.i;



            if(maze[x][y][c]=='#'&&vis[x][y][c]==0)
            {
                vis[x][y][c]=1;
                if(c==1){
                    if(maze[x][y][2]!='*'){
                        vis[x][y][2]=1;
                        que.push(point(x,y,2,s+1));
                    }
                }
                else{
                    if(maze[x][y][1]!='*'){
                        vis[x][y][1]=1;
                        que.push(point(x,y,1,s+1));
                    }
                }
            }

            if(maze[x][y][c]=='*')
                continue;

            if(maze[x][y][c]=='.'&&vis[x][y][c]==0){
                vis[x][y][c]=1;
                que.push(point(x,y,c,s+1));
            }


        }


    }

    return 0;
}



int main()
{

    int qqq;
    cin>>qqq;

    while(qqq--){

        cin>>n>>m>>t;

        memset(vis,0,sizeof(vis));


        point start;
        point end;

        for(int k=1;k<=2;k++)
            for(int i=0;i<15;i++){
                for(int j=0;j<15;j++){
                    maze[i][j][k]='*';

                }
            }

        for(int k=1;k<=2;k++){

            for(int i=1;i<=n;i++){

                for(int j=1;j<=m;j++){
                    cin>>maze[i][j][k];
                    if(maze[i][j][k]=='S'){
                        maze[i][j][k]='.';
                        start=point(i,j,k,0);
                    }
                    if(maze[i][j][k]=='P'){
                        maze[i][j][k]='.';
                        end=point(i,j,k,0);
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(maze[i][j][1]=='#'&&maze[i][j][2]=='#'){
                    maze[i][j][1]=maze[i][j][2]='*';
                }

            }
        }


        if(bfs(start,end))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;




    }

    return 0;
}

