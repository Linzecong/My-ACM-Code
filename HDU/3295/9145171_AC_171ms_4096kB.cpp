#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n,m;

vector<vector<int> > maze;
bool vis[7][7];

struct point{
    int x;
    int y;
    point(int a,int b){
        x=a;
        y=b;
    }
};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

vector<vector<int> > bfs2(int ii,int jj,vector<vector<int> > mm){
    queue<point> que;
    que.push(point(ii,jj));

    int cur=mm[ii][jj];

    while(!que.empty()){

        point tp=que.front();
        que.pop();
        mm[tp.x][tp.y]=0;
        vis[tp.x][tp.y]=1;

        for(int i=0;i<4;i++){
            int x=tp.x+dx[i];
            int y=tp.y+dy[i];

            if(x==-1||x==n||y==-1||y==m)
                continue;

            if(mm[x][y]==cur)
                que.push(point(x,y));

        }
    }



    for(int j=0;j<m;j++){
        bool yes=1;
        for(int i=0;i<n;i++){
            if(mm[i][j]!=0)
                yes=0;
        }
        if(yes){

            for(int k=j+1;k<m;k++){
                for(int i=0;i<n;i++){
                    swap(mm[i][k],mm[i][k-1]);
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mm[i][j]==0){
                for(int k=i-1;k>=0;k--)
                    swap(mm[k][j],mm[k+1][j]);
            }
        }
    }

    return mm;

}

struct node{
    vector<vector<int> > m;
    int time;
    node(){
        m.clear();
        time=0;
    }
};

int bfs(){

    queue<node> que;
    node ttt;
    ttt.m=maze;
    ttt.time=0;
    que.push(ttt);


    while(!que.empty()){
        node tp=que.front();
        que.pop();

        memset(vis,0,sizeof(vis));



        bool yes=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tp.m[i][j]!=0)
                    yes=0;
            }
        }
        if(yes)
            return tp.time;


        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&tp.m[i][j]!=0){
                ttt.m=bfs2(i,j,tp.m);
                ttt.time=tp.time+1;
                que.push(ttt);
                }
            }



    }


   return 0;
}




int main(){


    while(cin>>n>>m){


        maze.clear();
        for(int i=0;i<n;i++){
            vector<int> tl;
            for(int j=0;j<m;j++){
                int temp;
                cin>>temp;
                tl.push_back(temp);

            }
            maze.push_back(tl);
        }

        cout<<bfs()<<endl;



    }


    return 0;
}
