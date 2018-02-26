#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


char maze[105][105];


int n,m;

struct point{
    int x;
    int y;
    int time;
    point(int a,int b,int c){
        x=a;
        y=b;
        time=c;
    }
};

int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void bfs(point start1){

    queue<point> que1;
    que1.push(start1);

    maze[start1.x][start1.y]='*';

    while(!que1.empty()){


        point tmp=que1.front();
        que1.pop();


        for(int i=0;i<8;i++){
            int ii=tmp.x+dx[i];
            int jj=tmp.y+dy[i];

            if(maze[ii][jj]=='@'){
                maze[ii][jj]='*';
                que1.push(point(ii,jj,tmp.time+1));
            }
        }

    }



}




int main(){

    while(cin>>n>>m){
        if(m==0)
            break;

        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                maze[i][j]='*';

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>maze[i][j];

        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(maze[i][j]=='@'){
                    ans++;
                    bfs(point(i,j,0));
                }
            }



        cout<<ans<<endl;



    }

    return 0;
}
