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

char maze[205][205];
bool mask[205][205];

struct point{
    int x;
    int y;
    int time;

    point(int aa,int bb,int cc){
        x=aa;
        y=bb;
        time=cc;
    }

};

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


map<int,int> pl;


void bfs(point start1,point start2){

    queue<point> que;
    que.push(start1);

    memset(mask,0,sizeof(mask));

    while(!que.empty()){
        point tp = que.front();
        que.pop();


        if(maze[tp.x][tp.y]=='@')
            pl[tp.x*1000+tp.y]=tp.time;


        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            if(maze[x][y]!='#'&&mask[x][y]==0){
                mask[x][y]=1;
                que.push(point(x,y,tp.time+1));
            }
        }
    }


    memset(mask,0,sizeof(mask));


    queue<point> que2;
    que2.push(start2);


    while(!que2.empty()){
        point tp = que2.front();
        que2.pop();


        if(maze[tp.x][tp.y]=='@')
            pl[tp.x*1000+tp.y]+=tp.time;


        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            if(maze[x][y]!='#'&&mask[x][y]==0){
                mask[x][y]=1;
                que2.push(point(x,y,tp.time+1));
            }
        }

    }

}




int main(){


    while(~scanf("%d %d",&N,&M)){


        for(int i=0;i<=N+1;i++)
            for(int j=0;j<=M+1;j++)
                maze[i][j]='#';

        point e1(0,0,0);
        point e2(0,0,0);

        pl.clear();

        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='Y')
                    e1=point(i,j,0);
                if(maze[i][j]=='M')
                    e2=point(i,j,0);
            }




        bfs(e1,e2);

        int ans=9999999;
        for(map<int,int>::iterator it=pl.begin();it!=pl.end();it++)
           ans=min(ans,it->second);

        cout<<ans*11<<endl;


    }

    return 0;
}
