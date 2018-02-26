#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
using namespace std;



bool prime[10005];

void init(){    //对素数打表
    int i,j;
    for(i=1000;i<=10005;i++){
        for(j=2;j<i;j++)
            if(i%j==0){
                prime[i]=false;
                break;
            }
        if(j==i)
            prime[i]=true;
    }
}

int times[10005];


int bfs(int start,int end){

    queue<int> que;
    que.push(start);
    times[start]=1;

    while(!que.empty()){
        int temp=que.front();
        que.pop();

       // cout<<"         "<<temp<<endl;

        if(temp==end)
            return times[temp];

        int gewei=temp-temp%10;
        for(int i=0;i<10;i++){
            if(prime[gewei+i]&&times[gewei+i]==0){
            que.push(gewei+i);
            times[gewei+i]=times[temp]+1;
            }
        }

        int shiwei=temp-temp%100+temp%10;

        for(int i=0;i<10;i++){
            if(prime[shiwei+i*10]&&times[shiwei+i*10]==0){
            que.push(shiwei+i*10);
            times[shiwei+i*10]=times[temp]+1;
            }
        }

        int baiwei=temp-temp%1000+temp%100;

        for(int i=0;i<10;i++){
            if(prime[baiwei+i*100]&&times[baiwei+i*100]==0){
            que.push(baiwei+i*100);
            times[baiwei+i*100]=times[temp]+1;
            }
        }

        int qianwei=temp%1000+1000;

        for(int i=0;i<9;i++){
            if(prime[qianwei+i*1000]&&times[qianwei+i*1000]==0){
            que.push(qianwei+i*1000);
            times[qianwei+i*1000]=times[temp]+1;
            }
        }

    }


    return -1;

}


int main(){

init();
    int t;
    scanf("%d",&t);
    while(t--){
        memset(times,0,sizeof(times));
        int a,b;
        scanf("%d%d",&a,&b);
        int aa=bfs(a,b);

        if(aa==-1){
            cout<<"Impossible"<<endl;
        }
        else
        cout<<aa-1<<endl;


    }

}
