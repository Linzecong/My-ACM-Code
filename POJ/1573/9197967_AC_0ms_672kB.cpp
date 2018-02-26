#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<memory>
using namespace std;
typedef long long int ll;

int n,m,t;

char maze[20][20];
int vis[20][20];


int step,loop;
int ans;

bool go(int i,int j){



    while(!(i==0||i==n+1||j==0||j==m+1)){


    ans++;
    if(vis[i][j]==0)
    vis[i][j]=ans;
    else{
        step=vis[i][j]-1;
        loop=ans-step-1;
        return false;
    }


    if(maze[i][j]=='N'){
        i--;
        continue;
    }
    if(maze[i][j]=='S'){
        i++;
        continue;
    }
    if(maze[i][j]=='W'){
        j--;
        continue;
    }
    if(maze[i][j]=='E'){
        j++;
        continue;
    }
    }

    return true;

}



int main(){

    while(1){
        scanf("%d%d%d",&n,&m,&t);
        if(n==0&&m==0&&t==0)
            break;

        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++){
        maze[i][j]=vis[i][j]=0;
            }



        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>maze[i][j];

        step=loop=ans=0;

        if(go(1,t))
            printf("%d step(s) to exit\n",ans);
        else
            printf("%d step(s) before a loop of %d step(s)\n",step,loop);


    }



    return 0;
}
