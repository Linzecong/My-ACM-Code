#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

char str[1005];
char maze[1005][1005];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N,M,K;

int col[1005][1005];
int cnt=1;
map<int,int> cm;

void bfs(int a,int b){

    queue<pair<int,int> > que;
    que.push(make_pair(a,b));
    col[a][b]=cnt;
    int num=0;

    while(!que.empty()){
        pair<int,int> tp=que.front();
        que.pop();

        if(maze[tp.first][tp.second]=='*'){
            num++;
            continue;
        }

        for(int i=0;i<4;i++){
            int x=tp.first+dx[i];
            int y=tp.second+dy[i];
            if(col[x][y]==0&&maze[x][y]=='.')
            {
                que.push(make_pair(x,y));
                col[x][y]=cnt;
            }
            else{
                if(col[x][y]==0&&maze[x][y]=='*')
                {
                    que.push(make_pair(x,y));
                    //col[x][y]=cnt;
                }
            }
        }
    }
    cm[cnt]=num;
}


int main(){

    scanf("%d%d%d",&N,&M,&K);
    for(int i=1;i<=N;i++){
        scanf("%s",str);
        for(int j=1;j<=M;j++)
            maze[i][j]=str[j-1];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            if(maze[i][j]=='.'&&col[i][j]==0){
                bfs(i,j);
                cnt++;
            }
    }

    int a,b;
    for(int i=0;i<K;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",cm[col[a][b]]);
    }





    return 0;
}

