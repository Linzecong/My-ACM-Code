#include<iostream>
#include<deque>
#include<math.h>
#include<vector>
#include<memory.h>
using namespace std;

char maze[8][8];

int mask[8][8];

struct point{
    int par;
    int x;
    int y;
    point(int a,int b,int c){
        par=a;
        x=b;
        y=c;
    }
    point(){}
};

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

deque<point> bfs(){
    deque<point> que;
    deque<point> all;

    point start(-1,1,1);
    que.push_back(start);
    all.push_back(start);
    int index=0;
    while(!que.empty()){
        point tp=que.front();
        que.pop_front();

        if(tp.x==5&&tp.y==5){
            deque<point> tmp;
            while(tp.par!=-1){
                tmp.push_back(tp);
                tp=all[tp.par];
            }
            return tmp;
        }

        for(int i=0;i<4;i++){
            if(maze[tp.x+dx[i]][tp.y+dy[i]]=='0'&&mask[tp.x+dx[i]][tp.y+dy[i]]==0){
                mask[tp.x+dx[i]][tp.y+dy[i]]=1;
                point tt(index,tp.x+dx[i],tp.y+dy[i]);
                que.push_back(tt);
                all.push_back(tt);
            }
        }
        index++;
    }
    deque<point> aaa;
    return aaa;

}


int main(){


    for(int i=0;i<=6;i++)
        for(int j=0;j<=6;j++){
            maze[i][j]=1;
        }


    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++){
            cin>>maze[i][j];
        }


    deque<point> l=bfs();

    cout<<"(0, 0)"<<endl;

    for(int i=l.size()-1;i>=0;i--){
        printf("(%d, %d)\n",l[i].x-1,l[i].y-1);
    }



    return 0;
}
