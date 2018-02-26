#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;

char str[150005];
char mm[150005];

bool vis[150005];
ll ma[150005];
int top;

ll N;

struct point{
    ll i;
    int step;
    point(ll a=0,int b=0){
        i=a;
        step=b;
    }
    friend bool operator <(point a,point b){
        if(a.step==b.step)
            return str[a.i]<str[b.i];
        return a.step>b.step;
    }
};


priority_queue<point> que;


void bfs(){

    int last=-1;
    while(!que.empty()){
        point tp=que.top();
        que.pop();

        if(tp.step!=last){
            last=tp.step;
            while(top){
                vis[ma[--top]]=0;
            }
        }

        if(tp.step>=N)
            continue;

        if(mm[tp.step]>str[tp.i])
            continue;

        if(vis[tp.i])
            continue;

        vis[tp.i]=1;
        ma[top++]=tp.i;
        mm[tp.step]=str[tp.i];
        que.push(point((tp.i*tp.i+1)%N,tp.step+1));

    }

}

int main(){
    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++){

        scanf("%lld",&N);
        scanf("%s",str);

        char ma=0;
        for(ll i=0;i<N;i++)
            ma=max(ma,str[i]);

        for(ll i=0;i<N;i++)
            if(ma==str[i])
                que.push(point(i,0));

       

        bfs();
        printf("Case #%d: ",qqq);
        for(ll i=0;i<N;i++)
            putchar(mm[i]);
        puts("");


        for(ll i=0;i<N;i++)
            mm[i]=0;

    }

    return 0;
}














