#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include<queue>
using namespace std;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int vis[105][105];
char maze[105][105];
int N,M;

int bfs(int x,int y){

    queue<pair<int,int> > que;
    que.push(make_pair(x,y));
    vis[x][y]=1;
    while(!que.empty()){
        pair<int,int> tp= que.front();
        que.pop();

        int count=0;
        for(int i=0;i<8;i++){
            int nx=tp.first+dx[i];
            int ny=tp.second+dy[i];
            if(maze[nx][ny]=='#')
                count++;
            if(vis[nx][ny]==0&&maze[nx][ny]=='#'){
                que.push(make_pair(nx,ny));
                vis[nx][ny]=1;
            }
        }
        if(count<2)
            return 0;
    }
    return 1;

}


int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%s",maze[i]);

    int cnt=0;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            if(maze[i][j]=='#'&&vis[i][j]==0)
                cnt+=bfs(i,j);
        }
    printf("%d\n",cnt);


    return 0;
}






