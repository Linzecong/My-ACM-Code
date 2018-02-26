#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;


bool vis[8][8][8][8][8][8][8][8];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct point{
    int x[4],y[4];
    int t;

    point(int a1=0,int a2=0,int a3=0,int a4=0,int a5=0,int a6=0,int a7=0,int a8=0,int a=0){
        x[0]=a1;
        y[0]=a2;
        x[1]=a3;
        y[1]=a4;
        x[2]=a5;
        y[2]=a6;
        x[3]=a7;
        y[3]=a8;
        t=a;
        adjust();
    }

    void adjust(){
        for(int i=0;i<4;i++)
            for(int j=i+1;j<4;j++){
                if(x[i]>x[j])
                {
                    swap(x[i],x[j]);
                    swap(y[i],y[j]);
                }
                else{
                    if(x[i]==x[j]){
                        if(y[i]>y[j]){
                            swap(x[i],x[j]);
                            swap(y[i],y[j]);
                        }
                    }
                }
            }
    }


};

point endp;
point start;


bool same(point a,point b){
    a.adjust();
    b.adjust();

    for(int i=0;i<4;i++){
        if(a.x[i]!=b.x[i])
            return false;
        if(a.y[i]!=b.y[i])
            return false;
    }
    return true;
}

bool have(int x,int y,point a){


    for(int i=0;i<4;i++)
        if(a.x[i]==x&&a.y[i]==y)
            return true;
    return false;
}


bool bfs(){

    queue<point> que;
    que.push(start);

    vis[start.x[0]-1][start.y[0]-1][start.x[1]-1][start.y[1]-1][start.x[2]-1][start.y[2]-1][start.x[3]-1][start.y[3]-1]=1;

    while(!que.empty()){

        point tp=que.front();
        que.pop();

        if(tp.t>8)
            return false;

        if(same(tp,endp))
            return true;


        int x,y;
        //4个棋子，4个方向
        for(int i=0;i<4;i++){


            for(int j=0;j<4;j++){
                x=tp.x[i]+dx[j];
                y=tp.y[i]+dy[j];

                if(x==0||y==0||x==9||y==9)
                    continue;

                if(have(x,y,tp)){

                    if(j==0)
                    x--;
                    if(j==1)
                    x++;
                    if(j==2)
                    y--;
                    if(j==3)
                    y++;

                    if(x==0||y==0||x==9||y==9)
                        continue;

                    if(!have(x,y,tp)){
                        if(i==0){
                            point temp=point(x,y,tp.x[1],tp.y[1],tp.x[2],tp.y[2],tp.x[3],tp.y[3],tp.t+1);

                            if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                                vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                                que.push(temp);
                            }

                        }
                        if(i==1){
                            point temp=point(tp.x[0],tp.y[0],x,y,tp.x[2],tp.y[2],tp.x[3],tp.y[3],tp.t+1);

                            if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                                vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                                que.push(temp);
                            }

                        }
                        if(i==2){
                            point temp=point(tp.x[0],tp.y[0],tp.x[1],tp.y[1],x,y,tp.x[3],tp.y[3],tp.t+1);

                            if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                                vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                                que.push(temp);
                            }

                        }
                        if(i==3){
                            point temp=point(tp.x[0],tp.y[0],tp.x[1],tp.y[1],tp.x[2],tp.y[2],x,y,tp.t+1);

                            if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                                vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                                que.push(temp);
                            }

                        }
                    }
                }
                else{
                    if(i==0){
                        point temp=point(x,y,tp.x[1],tp.y[1],tp.x[2],tp.y[2],tp.x[3],tp.y[3],tp.t+1);

                        if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                            vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                            que.push(temp);
                        }

                    }
                    if(i==1){
                        point temp=point(tp.x[0],tp.y[0],x,y,tp.x[2],tp.y[2],tp.x[3],tp.y[3],tp.t+1);

                        if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                            vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                            que.push(temp);
                        }

                    }
                    if(i==2){
                        point temp=point(tp.x[0],tp.y[0],tp.x[1],tp.y[1],x,y,tp.x[3],tp.y[3],tp.t+1);

                        if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                            vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                            que.push(temp);
                        }
                    }
                    if(i==3){
                        point temp=point(tp.x[0],tp.y[0],tp.x[1],tp.y[1],tp.x[2],tp.y[2],x,y,tp.t+1);

                        if(vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]==0){
                            vis[temp.x[0]-1][temp.y[0]-1][temp.x[1]-1][temp.y[1]-1][temp.x[2]-1][temp.y[2]-1][temp.x[3]-1][temp.y[3]-1]=1;
                            que.push(temp);
                        }

                    }
                }


            }

        }

    }



    return false;
}





int main()
{

    int a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0;




    while(cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8){
        start=point(a1,a2,a3,a4,a5,a6,a7,a8,0);

        cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8;

        endp=point(a1,a2,a3,a4,a5,a6,a7,a8,0);


       memset(vis,0,sizeof(vis));


        if(bfs()){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;



    }






    return 0;
}
