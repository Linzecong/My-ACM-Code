#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

vector<vector<int> > data={{0,0,0,0},
                           {0,0,0,1},
                           {0,0,1,0},
                           {0,0,1,1},
                           {0,1,0,0},
                           {0,1,0,1},
                           {0,1,1,0},
                           {0,1,1,1},
                           {1,0,0,0},
                           {1,0,0,1},
                           {1,0,1,0},
                           {1,0,1,1},
                           {1,1,0,0},
                           {1,1,0,1},
                           {1,1,1,0},
                           {1,1,1,1}};


vector<int> maze[300];
bool vis[300][400];

char hmaze[300][100];

int N,M;

void changemaze(){
    for(int j=0;j<=M+1;j++)
        for(int k=0;k<4;k++)
            maze[0].push_back(data[0][k]);

    for(int i=1;i<=N;i++){
        for(int k=0;k<4;k++)
            maze[i].push_back(data[0][k]);
        for(int j=0;j<M;j++){
            if(hmaze[i-1][j]=='0')for(int k=0;k<4;k++)
                maze[i].push_back(data[0][k]);
            if(hmaze[i-1][j]=='1')for(int k=0;k<4;k++)
                maze[i].push_back(data[1][k]);
            if(hmaze[i-1][j]=='2')for(int k=0;k<4;k++)
                maze[i].push_back(data[2][k]);
            if(hmaze[i-1][j]=='3')for(int k=0;k<4;k++)
                maze[i].push_back(data[3][k]);
            if(hmaze[i-1][j]=='4')for(int k=0;k<4;k++)
                maze[i].push_back(data[4][k]);
            if(hmaze[i-1][j]=='5')for(int k=0;k<4;k++)
                maze[i].push_back(data[5][k]);
            if(hmaze[i-1][j]=='6')for(int k=0;k<4;k++)
                maze[i].push_back(data[6][k]);
            if(hmaze[i-1][j]=='7')for(int k=0;k<4;k++)
                maze[i].push_back(data[7][k]);
            if(hmaze[i-1][j]=='8')for(int k=0;k<4;k++)
                maze[i].push_back(data[8][k]);
            if(hmaze[i-1][j]=='9')for(int k=0;k<4;k++)
                maze[i].push_back(data[9][k]);
            if(hmaze[i-1][j]=='a')for(int k=0;k<4;k++)
                maze[i].push_back(data[10][k]);
            if(hmaze[i-1][j]=='b')for(int k=0;k<4;k++)
                maze[i].push_back(data[11][k]);
            if(hmaze[i-1][j]=='c')for(int k=0;k<4;k++)
                maze[i].push_back(data[12][k]);
            if(hmaze[i-1][j]=='d')for(int k=0;k<4;k++)
                maze[i].push_back(data[13][k]);
            if(hmaze[i-1][j]=='e')for(int k=0;k<4;k++)
                maze[i].push_back(data[14][k]);
            if(hmaze[i-1][j]=='f')for(int k=0;k<4;k++)
                maze[i].push_back(data[15][k]);

        }
        for(int k=0;k<4;k++)
            maze[i].push_back(data[0][k]);
    }

    for(int j=0;j<=M+1;j++)
        for(int k=0;k<4;k++)
            maze[N+1].push_back(data[0][k]);
}


void bfs_fu1(){
    point start;
    start.x=1;
    start.y=1;
    queue<point> que;
    que.push(start);
    vis[1][1]=1;


    while(!que.empty()){

        point tp=que.front();
        que.pop();




        int x=tp.x;
        int y=tp.y;

        maze[x][y]=-1;

        if(x+1!=N+2)
        if(maze[x+1][y]==0&&vis[x+1][y]==0){
            vis[x+1][y]=1;
            point tmp;
            tmp.x=x+1;
            tmp.y=y;
            que.push(tmp);
        }

        if(x-1!=-1)
        if(maze[x-1][y]==0&&vis[x-1][y]==0){
            vis[x-1][y]=1;
            point tmp;
            tmp.x=x-1;
            tmp.y=y;
            que.push(tmp);
        }

        if(y-1!=-1)
        if(maze[x][y-1]==0&&vis[x][y-1]==0){
            vis[x][y-1]=1;
            point tmp;
            tmp.x=x;
            tmp.y=y-1;
            que.push(tmp);
        }

        if(y+1!=(M+2)*4+1)
        if(maze[x][y+1]==0&&vis[x][y+1]==0){
            vis[x][y+1]=1;
            point tmp;
            tmp.x=x;
            tmp.y=y+1;
            que.push(tmp);
        }







    }


}


void bfs_black(point start,int num){
    queue<point> que;
    que.push(start);
    vis[start.x][start.y]=1;

    while(!que.empty()){

        point tp=que.front();
        que.pop();


        int x=tp.x;
        int y=tp.y;

        maze[x][y]=num;


        if(x+1!=N+2)
        if(maze[x+1][y]==1&&vis[x+1][y]==0){
            vis[x+1][y]=1;
            point tmp;
            tmp.x=x+1;
            tmp.y=y;
            que.push(tmp);
        }

        if(x-1!=-1)
        if(maze[x-1][y]==1&&vis[x-1][y]==0){
            vis[x-1][y]=1;
            point tmp;
            tmp.x=x-1;
            tmp.y=y;
            que.push(tmp);
        }

        if(y-1!=-1)
        if(maze[x][y-1]==1&&vis[x][y-1]==0){
            vis[x][y-1]=1;
            point tmp;
            tmp.x=x;
            tmp.y=y-1;
            que.push(tmp);
        }

if(y+1!=(M+2)*4+1)
        if(maze[x][y+1]==1&&vis[x][y+1]==0){
            vis[x][y+1]=1;
            point tmp;
            tmp.x=x;
            tmp.y=y+1;
            que.push(tmp);
        }






    }


}

int bfs_white(point start){
    queue<point> que;
    que.push(start);
    vis[start.x][start.y]=1;

    int ans=0;

    while(!que.empty()){

        point tp=que.front();
        que.pop();




        int x=tp.x;
        int y=tp.y;

        maze[x][y]=-1;


        if(x+1!=N+2)
        if(maze[x+1][y]==0&&vis[x+1][y]==0){
            vis[x+1][y]=1;
            point tmp;
            tmp.x=x+1;
            tmp.y=y;
            que.push(tmp);
        }
        else{
            if(maze[x+1][y]>0)
                ans=maze[x+1][y];
        }

        if(x-1!=-1)
        if(maze[x-1][y]==0&&vis[x-1][y]==0){
            vis[x-1][y]=1;
            point tmp;
            tmp.x=x-1;
            tmp.y=y;
            que.push(tmp);
        }else{
            if(maze[x-1][y]>0)
                ans=maze[x-1][y];
        }

        if(y-1!=-1)
        if(maze[x][y-1]==0&&vis[x][y-1]==0){
            vis[x][y-1]=1;
            point tmp;
            tmp.x=x;
            tmp.y=y-1;
            que.push(tmp);
        }else{
            if(maze[x][y-1]>0)
                ans=maze[x][y-1];
        }

        if(y+1!=(M+2)*4+1)
        if(maze[x][y+1]==0&&vis[x][y+1]==0){
            vis[x][y+1]=1;
            point tmp;
            tmp.x=x;
            tmp.y=y+1;
            que.push(tmp);
        }else{
            if(maze[x][y+1]>0)
                ans=maze[x][y+1];
        }






    }
    return ans;
}



int main()
{
    int case0=1;
    while(1){
        scanf("%d%d",&N,&M);
        memset(maze,0,sizeof(maze));
        memset(hmaze,0,sizeof(hmaze));

        if(N==0&&M==0)
            break;

        for(int i=0;i<N;i++){
            getchar();
            for(int j=0;j<M;j++){
                scanf("%c",&hmaze[i][j]);
            }
        }

 memset(vis,0,sizeof(vis));
        changemaze();

//        for(int i=0;i<=N+1;i++){
//            for(int j=0;j<maze[i].size();j++)
//                printf("%d",maze[i][j]);
//            printf("\n");
//        }



        memset(vis,0,sizeof(vis));
        bfs_fu1();
        memset(vis,0,sizeof(vis));





        map<int,int> mp;
        int num=2;
        for(int i=1;i<=N;i++)
            for(int j=1;j<maze[i].size();j++){
                if(maze[i][j]==1){
                    point tp;
                    tp.x=i;
                    tp.y=j;
                    mp[num]=0;
                    bfs_black(tp,num++);

                }
            }


        for(int i=1;i<=N;i++)
            for(int j=1;j<maze[i].size();j++){
                if(maze[i][j]==0){
                    point tp;
                    tp.x=i;
                    tp.y=j;
                    mp[bfs_white(tp)]++;
                }
            }


        vector<char> ans;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second==1)
                ans.push_back('A');
            if(it->second==2)
                ans.push_back('K');

            if(it->second==3)
                ans.push_back('J');
            if(it->second==4)
                ans.push_back('S');
            if(it->second==5)
                ans.push_back('D');
            if(it->second==0)
                ans.push_back('W');

        }
        sort(ans.begin(),ans.end());
        printf("Case %d: ",case0++);
        for(int i=0;i<ans.size();i++)
            printf("%c",ans[i]);
        printf("\n");

    }



    return 0;
}
