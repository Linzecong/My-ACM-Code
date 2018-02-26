#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;

char maze[505][505];

bool vis[505][505][5];




struct point{
    int x1,y1;
    int x2,y2;

    int t;

    point(int a=0,int b=0,int c=0,int d=0,int f=0){
        x1=a;
        y1=b;
        x2=c;
        y2=d;
        t=f;
    }

};


bool check(point tp){

    if(tp.x1==tp.x2&&tp.y1==tp.y2){

        if(maze[tp.x1][tp.y1]=='#'||maze[tp.x1][tp.y1]=='E')
            return false;
    }
    else{
        if(maze[tp.x1][tp.y1]=='#'||maze[tp.x2][tp.y2]=='#')
            return false;
    }



    if(tp.x2==tp.x1&&tp.y1==tp.y2){
        if(vis[tp.x1][tp.y1][0])
            return false;
    }
    else{
        if(tp.x2-tp.x1!=0){
            if(vis[tp.x1][tp.y1][4]||vis[tp.x2][tp.y2][2])
                return false;

        }
        else{
            if(vis[tp.x1][tp.y1][3]||vis[tp.x2][tp.y2][1])
                return false;
        }
    }

    return true;

}


int bfs(point start){

    queue<point> que;
    que.push(start);


    if(start.x2==start.x1&&start.y1==start.y2)
        vis[start.x1][start.y1][0]=1;
    else{
        if(start.x2-start.x1!=0){
            vis[start.x1][start.y1][4]=1;
            vis[start.x2][start.y2][2]=1;
        }
        else{
            vis[start.x1][start.y1][3]=1;
            vis[start.x2][start.y2][1]=1;
        }
    }


    while(!que.empty()){
        point tp=que.front();
        que.pop();




        if(tp.x2<tp.x1){
            swap(tp.x1,tp.x2);
            swap(tp.y1,tp.y2);
        }

        if(tp.y2<tp.y1){
            swap(tp.x1,tp.x2);
            swap(tp.y1,tp.y2);
        }



        if(tp.x1==tp.x2&&tp.y1==tp.y2){

            if(maze[tp.x1][tp.y1]=='O')
                return tp.t;
        }


        if(tp.x1==tp.x2&&tp.y1==tp.y2){


            point temp=tp;
            temp.x1++;
            temp.x2+=2;
            temp.t++;

            if(check(temp)){
                que.push(temp);
                vis[temp.x1][temp.y1][4]=1;
                vis[temp.x2][temp.y2][2]=1;
            }

            temp=tp;
            temp.x1-=2;
            temp.x2--;
            temp.t++;
            if(check(temp)){
                que.push(temp);
                vis[temp.x1][temp.y1][4]=1;
                vis[temp.x2][temp.y2][2]=1;
            }

            temp=tp;
            temp.y1++;
            temp.y2+=2;
            temp.t++;
            if(check(temp)){
                que.push(temp);
                vis[temp.x1][temp.y1][3]=1;
                vis[temp.x2][temp.y2][1]=1;
            }

            temp=tp;
            temp.y1-=2;
            temp.y2--;
            temp.t++;
            if(check(temp)){
                que.push(temp);
                vis[temp.x1][temp.y1][3]=1;
                vis[temp.x2][temp.y2][1]=1;
            }

        }
        else{

            if(tp.x2-tp.x1!=0){

                point temp=tp;
                temp.x1--;
                temp.x2=temp.x1;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][0]=1;
                }

                temp=tp;
                temp.x2++;
                temp.x1=temp.x2;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][0]=1;
                }


                temp=tp;
                temp.y1--;
                temp.y2--;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][4]=1;
                    vis[temp.x2][temp.y2][2]=1;
                }

                temp=tp;
                temp.y1++;
                temp.y2++;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][4]=1;
                    vis[temp.x2][temp.y2][2]=1;
                }

            }
            else{



                point temp=tp;
                temp.y1--;
                temp.y2=temp.y1;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][0]=1;
                }

                temp=tp;
                temp.y2++;
                temp.y1=temp.y2;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][0]=1;
                }


                temp=tp;
                temp.x1--;
                temp.x2--;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][3]=1;
                    vis[temp.x2][temp.y2][1]=1;
                }

                temp=tp;
                temp.x1++;
                temp.x2++;
                temp.t++;
                if(check(temp)){
                    que.push(temp);
                    vis[temp.x1][temp.y1][3]=1;
                    vis[temp.x2][temp.y2][1]=1;
                }

            }

        }

    }


    return -1;
}





int main()
{
    char str[505];

    while(scanf("%d%d",&N,&M)&&N&&M){

        memset(maze,0,sizeof(maze));
        memset(vis,0,sizeof(vis));


        for(int i=0;i<=N+1;i++){
            maze[i][0]='#';
            maze[i][M+1]='#';
        }

        for(int i=0;i<=M+1;i++){
            maze[0][i]='#';
            maze[N+1][i]='#';
        }

        point temp;

        int num=1;

        for(int i=1;i<=N;i++){
            scanf("%s" ,str);

            for(int j = 1 ;j <= M ;j ++){
                maze[i][j]=str[j-1];


                if(maze[i][j]=='X'){
                    if(num==1){
                        temp.x1=i;
                        temp.y1=j;
                        num++;
                    }
                    else{
                        temp.x2=i;
                        temp.y2=j;
                        num++;
                    }

                    maze[i][j]='.';
                }

            }
        }


        if(num==2){
            temp.x2=temp.x1;
            temp.y2=temp.y1;
        }
        temp.t=0;

        int ans=bfs(temp);
        if(ans==-1)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;



    }

    return 0;
}
