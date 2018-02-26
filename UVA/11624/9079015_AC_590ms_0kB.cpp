#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<memory.h>
using namespace std;

char maze[1005][1005];

int mask[1005][1005];
bool map[1005][1005];


int walked[1005][1005];
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
    point(){}
};

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfsfire(point start){

    queue<point> que;
    que.push(start);
    map[start.x][start.y]=1;

    while(!que.empty()){

        point tp=que.front();
        que.pop();

        for(int i=0;i<4;i++){
            if((maze[tp.x+dx[i]][tp.y+dy[i]]=='.'||maze[tp.x+dx[i]][tp.y+dy[i]]=='J')&&map[tp.x+dx[i]][tp.y+dy[i]]==0){
                map[tp.x+dx[i]][tp.y+dy[i]]=1;

                if(mask[tp.x+dx[i]][tp.y+dy[i]]!=0){
                    if(mask[tp.x+dx[i]][tp.y+dy[i]]>tp.time+1){
                        mask[tp.x+dx[i]][tp.y+dy[i]]=tp.time+1;
                        point tt=tp;
                        tt.time=tp.time+1;
                        tt.x=tp.x+dx[i];
                        tt.y=tp.y+dy[i];
                        que.push(tt);
                    }
                    
                }
                else{
                    mask[tp.x+dx[i]][tp.y+dy[i]]=tp.time+1;
                    point tt=tp;
                    tt.time=tp.time+1;
                    tt.x=tp.x+dx[i];
                    tt.y=tp.y+dy[i];
                    que.push(tt);
                }

                
            }
        }
    }
}

int bfsman(point start){

    queue<point> que;
    que.push(start);


    while(!que.empty()){

        point tp=que.front();
        que.pop();

        if(tp.x==0||tp.x==n+1||tp.y==0||tp.y==m+1)
            return tp.time;

        for(int i=0;i<4;i++){
            if((maze[tp.x+dx[i]][tp.y+dy[i]]=='.'||maze[tp.x+dx[i]][tp.y+dy[i]]==0)&&walked[tp.x+dx[i]][tp.y+dy[i]]==0){
                walked[tp.x+dx[i]][tp.y+dy[i]]=tp.time+1;
                if((walked[tp.x+dx[i]][tp.y+dy[i]]<mask[tp.x+dx[i]][tp.y+dy[i]])||mask[tp.x+dx[i]][tp.y+dy[i]]==0){
                    point tt=tp;
                    tt.time=tp.time+1;
                    tt.x=tp.x+dx[i];
                    tt.y=tp.y+dy[i];
                    que.push(tt);
                }
            }
        }
    }
    return -1;
}



int main(){

    int t;
    cin>>t;
    for(int qqq=1;qqq<=t;qqq++){


        cin>>n>>m;

        memset(maze,0,sizeof(maze));
        memset(mask,0,sizeof(mask));
        memset(walked,0,sizeof(walked));

        point fp,mp;


        for(int i=0;i<=n+1;i++){
            mask[i][0]=10000000;
            mask[i][m+1]=10000000;
        }
        for(int i=0;i<=m+1;i++){
            mask[0][i]=10000000;
            mask[n+1][i]=10000000;
        }

        vector<point> pl;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='J')
                    mp=point(i,j,0);
                if(maze[i][j]=='F'){
                    fp=point(i,j,0);
                    pl.push_back(fp);
                }
            }


        for(int i=0;i<pl.size();i++){
            memset(map,0,sizeof(map));
            bfsfire(pl[i]);
        }





        int res=bfsman(mp);

        //        cout<<endl;
        //        for(int i=1;i<=n;i++){
        //        for(int j=1;j<=m;j++){
        //       cout<<mask[i][j]<<" ";

        //        }
        //        cout<<endl;
        //        }

        //        cout<<endl;

        //        for(int i=1;i<=n;i++){
        //        for(int j=1;j<=m;j++){
        //       cout<<walked[i][j]<<" ";

        //        }
        //        cout<<endl;
        //        }


        if(res==-1)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<res<<endl;















    }









    return 0;
}
