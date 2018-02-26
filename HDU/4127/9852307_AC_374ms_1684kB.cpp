#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int N,MAXD;
int a[15][15];
int vis[15][15];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfsxl(int x,int y,int color){
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=N||ty<0||ty>=N)
            continue;

        if(vis[tx][ty]==1)
            continue;

        vis[tx][ty]=2;

        if(a[tx][ty]==color)
            dfsxl(tx,ty,color);
    }
}

int H(){
    int m[8];
    int count=0;

    memset(m,0,sizeof(m));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(vis[i][j]==1)
                continue;
            if(!m[a[i][j]]){
                m[a[i][j]]=1;
                count++;
            }

        }
    }
    return count;
}


int filled(int color){
    int count=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(a[i][j] != color)
                continue;

            if(vis[i][j] == 2){
                count++;
                dfsxl(i,j,color);
            }
        }
    return count;//返回染色的个数
}


bool dfs(int d){
    if(d==MAXD)
        return H()==0;

    if(H()+d>MAXD)
        return false;

    int tempvis[15][15];
    memcpy(tempvis,vis,sizeof(vis));

    for(int i=0;i<6;i++){
        if(filled(i)==0)
            continue;

        if(dfs(d+1))
            return true;

        memcpy(vis,tempvis,sizeof(vis));

    }

    return false;

}




int main()
{

    while(~scanf("%d",&N)&&N){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&a[i][j]);

        memset(vis,0,sizeof(vis));

        dfsxl(0,0,a[0][0]);

        MAXD=0;

        do{
            if(dfs(0))
                break;

        }while(++MAXD);


        printf("%d\n",MAXD);


    }

    return 0;
}
