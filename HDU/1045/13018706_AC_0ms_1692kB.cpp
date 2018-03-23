#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<memory.h>
using namespace std;
typedef long long int ll;

char maze[20][20];
int N;
int ans;

void dfs(int x,int y,int num){
    ans=max(ans,num);

    if(y==N+1){
        dfs(x+1,1,num);
        return;
    }
    
    if(x==N+1)
        return;

    if(maze[x][y]=='O'||maze[x][y]=='X'){
        dfs(x,y+1,num);
        return;
    }
         
    
    

    bool ok=1;
    for(int i=1;i<x;i++)
        if(maze[i][y]=='X'){
            ok=1;
        }
        else{
            if(maze[i][y]=='O')
                ok=0;
        }

    

    if(ok)
    for(int i=1;i<y;i++)
        if(maze[x][i]=='X'){
            ok=1;
        }
        else{
            if(maze[x][i]=='O')
                ok=0;
        }

    
    if(ok){
        maze[x][y]='O';
        dfs(x,y+1,num+1);
        maze[x][y]='.';
    }

    dfs(x,y+1,num);
}

int main(){
   
   

   while(cin>>N){
       if(N==0)
        break;

        memset(maze,0,sizeof(maze));
       for(int i=1;i<=N;i++)
        scanf("%s",maze[i]+1);
        ans=0;

        dfs(1,1,0);

        printf("%d\n",ans);

   }
    
    

    return 0;
}


