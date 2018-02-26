#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

char maze[30][30];

int visbox[30][30];
int visren[30][30];


struct point{
    int x;
    int y;
    string ren;
    char dir;
    string ans;
    int rx;
    int ry;
};

struct node{
    int x;
    int y;
    char dir;
    string ans;
};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool bfsren(string &result,node start,node end,point box){

    memset(visren,0,sizeof(visren));

    visren[start.x][start.y]=1;

    queue<node> que;

    que.push(start);

    while(!que.empty()){

        node tp=que.front();
        que.pop();

        if(tp.x==end.x&&tp.y==end.y){
            result=tp.ans;
            return true;
        }



        visren[tp.x][tp.y]=1;

        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];

            if(visren[x][y]==0&&(maze[x][y]!='#'&&(x!=box.x||y!=box.y))){

                node temp;
                temp.x=x;
                temp.y=y;

                if(i==0)temp.dir='n';
                if(i==1)temp.dir='e';
                if(i==2)temp.dir='s';
                if(i==3)temp.dir='w';

                temp.ans=tp.ans;
                temp.ans.push_back(temp.dir);
                que.push(temp);

                visren[temp.x][temp.y]=1;

            }
        }
    }
    return false;
}


string bfsbox(point boxstart,point boxend){

    visbox[boxstart.x][boxstart.y]=1;

    queue<point> que;

    que.push(boxstart);

    while(!que.empty()){
        point tp=que.front();
        que.pop();

        visbox[tp.x][tp.y]=1;

        if(tp.x==boxend.x&&tp.y==boxend.y){
            return tp.ans;
        }


        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];

            if(visbox[x][y]==1||maze[x][y]=='#')
                continue;

            node rs;
            if(i==0){
                rs.x=tp.x+1;
                rs.y=tp.y;
            }
            if(i==1){
                rs.x=tp.x;
                rs.y=tp.y-1;
            }

            if(i==2){
                rs.x=tp.x-1;
                rs.y=tp.y;
            }

            if(i==3){
                rs.x=tp.x;
                rs.y=tp.y+1;
            }



            node ren;
            ren.x=tp.rx;
            ren.y=tp.ry;

            string lu;
            if(bfsren(lu,ren,rs,tp)){
                point temp;

                if(i==0)temp.dir='N';
                if(i==1)temp.dir='E';
                if(i==2)temp.dir='S';
                if(i==3)temp.dir='W';

                temp.ans=tp.ans;

                temp.x=x;
                temp.y=y;

                temp.ren=lu;

                for(int i=0;i<temp.ren.size();i++)
                    temp.ans.push_back(temp.ren[i]);

                temp.ans.push_back(temp.dir);

                temp.rx=tp.x;
                temp.ry=tp.y;

                que.push(temp);

                visbox[temp.x][temp.y]=1;

            }
        }

    }
    string aaa;
    return aaa;
}




int N,M;

int main()
{

    int case0=1;
    while(cin>>N>>M){
        if(N==0&&M==0)
            break;

        memset(maze,0,sizeof(maze));
        memset(visbox,0,sizeof(visbox));
        memset(visren,0,sizeof(visren));

        for(int i=0;i<=M+1;i++)
            maze[0][i]='#';

        for(int i=0;i<=M+1;i++)
            maze[N+1][i]='#';

        for(int i=1;i<=N;i++)
            maze[i][0]='#';

        for(int i=1;i<=N;i++)
            maze[i][M+1]='#';


        point bs,be;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                cin>>maze[i][j];

                if(maze[i][j]=='T'){
                    be.x=i;
                    be.y=j;
                }
                if(maze[i][j]=='B'){
                    bs.x=i;
                    bs.y=j;
                }
                if(maze[i][j]=='S'){
                    bs.rx=i;
                    bs.ry=j;
                }
            }




        cout<<"Maze #"<<case0++<<endl;

        string result=bfsbox(bs,be);

        if(result.empty()){
            cout<<"Impossible."<<endl;
        }
        else{

            cout<<result<<endl;
        }

        cout<<endl;

    }



}
