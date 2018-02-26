#include<iostream>
#include<queue>

using namespace std;

int N,K;

struct point{
    int X;
    int T;
};

bool vis[200050];

int main(){

    cin>>N>>K;

    point a;
    a.X=N;

    a.T=0;

    queue<point> que;
    que.push(a);

    for(int i=0;i<200050;i++)
    vis[i]=0;


    while(!que.empty()){

        point temp=que.front();
        que.pop();

        if(temp.X==K){
            cout<<temp.T<<endl;
            return 0;
        }

        if(temp.X-1>=0&&vis[temp.X-1]==0){
            point tt=temp;
            tt.X--;
            tt.T++;
            que.push(tt);
            vis[temp.X-1]=1;
        }

        if(temp.X<K&&vis[temp.X+1]==0){
            point tt=temp;
            tt.X++;
            tt.T++;
            que.push(tt);
            vis[temp.X+1]=1;
        }

        if(temp.X<K&&vis[temp.X*2]==0){
            point tt=temp;
            tt.X*=2;
            tt.T++;
            que.push(tt);
            vis[temp.X*2]=1;
        }


    }


    return 0;
}
