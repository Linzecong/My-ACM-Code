#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef unsigned long long ll;

int N,M;

char maze[10][10];

int wallid[10][10];
int bomeid[10][10];



vector<ll> vis[10][10][9*8*8];
vector<ll> pic[10][10][9*8*8];

bool visited(int i,int j,int s,ll cur){

    for(int k=0;k<vis[i][j][s].size();k++){
        if(cur==vis[i][j][s][k])
            return 1;
    }
    return 0;
}

bool picked(int i,int j,int s,ll cur){

    for(int k=0;k<pic[i][j][s].size();k++){
        if(cur==pic[i][j][s][k])
            return 1;
    }
    return 0;
}


struct point{
    int x;
    int y;
    int time;
    int bome;
    ll state;
    ll spick;


    point(int a,int b,int c,int d,ll s,ll p){
        x=a;
        y=b;
        time=c;
        bome=d;
        state=s;
        spick=p;
    }

    bool operator<(const point n1) const{
            return time>n1.time;
    }

    point(){}
};

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

int ans=9999999;

void bfs(point start,point end){

    int aaa=0;
    priority_queue<point> que;
    que.push(start);

    vis[start.x][start.y][start.bome].push_back(start.state);
    pic[start.x][start.y][start.bome].push_back(start.spick);


    while(!que.empty()){

        point tp=que.top();
        que.pop();

        if(tp.x==end.x&&tp.y==end.y){
            aaa++;
            ans=min(ans,tp.time);
            if(aaa>2)
                return;
        }

        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];
            int t=tp.time;
            int b=tp.bome;
            ll s=tp.state;
            ll p=tp.spick;

            int vb=visited(x,y,b,s);
            int pb=picked(x,y,b,p);

            if(!vb||!pb){

                if(!vb)
                    vis[x][y][b].push_back(s);

                if(!pb)
                    pic[x][y][b].push_back(p);

                if(maze[x][y]=='.'){

                    que.push(point(x,y,t+1,b,s,p));

                }
                else{
                    if(maze[x][y]=='X'){
                        if(!(s&(1LL<<wallid[x][y]))){
                            if(b>0){
                                b--;
                                int id=wallid[x][y];
                                s=s|(1LL<<id);
                                vis[x][y][b].push_back(s);

                                que.push(point(x,y,t+2,b,s,p));

                            }
                        }
                        else{

                            que.push(point(x,y,t+1,b,s,p));

                        }
                    }
                    else{
                        if(maze[x][y]!='#'){
                            if(!(p&(1LL<<bomeid[x][y]))){

                                int num=maze[x][y]-'0';
                                b+=num;
                                int id=bomeid[x][y];

                                p=p|(1LL<<id);

                                pic[x][y][b].push_back(p);

                                que.push(point(x,y,t+1,b,s,p));


                            }
                            else{

                                que.push(point(x,y,t+1,b,s,p));

                            }
                        }
                    }
                }
            }




        }


    }

}

int main(){


    while(1){
        scanf("%d%d",&N,&M);
        if(N==0&&M==0)
            break;

        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++){
                maze[i][j]='#';
            }

        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<9*8*8;k++){
                    vis[i][j][k].clear();
                    pic[i][j][k].clear();
                }

        point s,e;

        int wid=0;
        int bid=0;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='S'){
                    s=point(i,j,0,0,0,0);
                    maze[i][j]='.';
                    continue;
                }
                if(maze[i][j]=='D'){
                    e=point(i,j,0,0,0,0);
                    maze[i][j]='.';
                    continue;
                }
                if(maze[i][j]=='X'){
                    wallid[i][j]=wid++;
                    continue;
                }
                if(maze[i][j]!='.'){
                    bomeid[i][j]=bid++;
                }
            }



        ans=9999999;
        bfs(s,e);
        if(ans!=9999999)
            printf("%d\n",ans);
        else
            printf("%d\n",-1);




    }



    return 0;
}
