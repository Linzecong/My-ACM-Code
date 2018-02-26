#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;

char maze[105][105];
bool vis[105][105][1<<5];

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
map<int,int> ex;

int kd[255];
int kdh[255];

int bfs(point start){
    queue<point> que;
    que.push(start);

    vis[start.x][start.y][start.state]=1;

    while(!que.empty()){

        point tp=que.front();
        que.pop();


        if(ex[tp.x*1000+tp.y]==1)
            return tp.time;

        for(int i=0;i<4;i++){

            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            int s=tp.state;
            int t=tp.time;

            if(vis[x][y][s]==0&&maze[x][y]!='#'){
                vis[x][y][s]=1;
                if(maze[x][y]!='.'){
                    if(maze[x][y]>='a'){
                        s=s|(1<<(kd[maze[x][y]]));
                        vis[x][y][s]=1;
                        que.push(point(x,y,s,t+1));
                    }
                    else{
                        if(s&(1<<(kd[maze[x][y]]))){
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
    kd['B']=0;
    kd['b']=0;
    kd['Y']=1;
    kd['y']=1;
    kd['R']=2;
    kd['r']=2;
    kd['G']=3;
    kd['g']=3;




    while(scanf("%d %d",&N,&M),(N+M)){

        memset(vis,0,sizeof(vis));
        //memset(kdh,0,sizeof(kdh));

        for(int i=0;i<=N+1;i++)
            for(int j=0;j<=M+1;j++)
                maze[i][j]='#';

        point s;

        ex.clear();

        bool have=0;

        for(int i=1;i<=N;i++){
            getchar();
            for(int j=1;j<=M;j++){
                scanf("%c",&maze[i][j]);
                if(maze[i][j]=='*'){
                    s=point(i,j,0,0);
                    maze[i][j]='.';
                }
                if(maze[i][j]=='X'){

                    have=1;
                    ex[i*1000+j]=1;

                    maze[i][j]='.';
                }

                //kdh[maze[i][j]]=1;
            }
        }


        if(have==0){
            printf("The poor student is trapped!\n");
            continue;
        }

        if(kdh['B']!=kdh['b']||kdh['Y']!=kdh['y']||kdh['R']!=kdh['r']||kdh['G']!=kdh['g'])
        {
            printf("The poor student is trapped!\n");
            continue;
        }



        int ans=bfs(s);

        if(ans==-1)
            printf("The poor student is trapped!\n");
        else
            printf("Escape possible in %d steps.\n",ans);





    }

    return 0;
}
