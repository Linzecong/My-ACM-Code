#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<memory.h>
#include<queue>
using namespace std;

const int inf=1<<29;

struct edge{
    int v1;
    int v2;
    int len;
    int next;
}e[20000];
int edge_num,head[20000];

void insert_edge(int v1,int v2,int w){
    e[edge_num].v1=v1;
    e[edge_num].v2=v2;
    e[edge_num].len=w;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;
}

bool vis[20000];
int d[505];
int N;
int a,b,c;

int spfa(int st){
    queue<int> que;
    memset(vis,0,sizeof(vis));

    for(int i=1;i<=N;i++)d[i]=inf;

    que.push(st);
    d[st]=0;
    vis[st]=1;

    while(!que.empty()){
        int tp=que.front();
        que.pop();
        vis[tp]=0;

        for(int i=head[tp];i!=-1;i=e[i].next){
            if(d[tp]+e[i].len<d[e[i].v2]){
                d[e[i].v2]=d[tp]+e[i].len;

                if(!vis[e[i].v2]){
                    vis[e[i].v2]=1;
                    que.push(e[i].v2);
                }
            }
        }
    }


    int max1=0;
    for(int i=1;i<=N;i++)
        max1=max(max1,d[i]);

    return max1;


}



char str[100];

int main()
{



    while(~scanf("%d",&N)){
        edge_num=0;
        memset(head,-1,sizeof(head));


        for(int i=2;i<=N;i++){
            for(int j=1;j<i;j++){
                scanf("%s",str);
                if(str[0]!='x'){
                    c=atoi(str);

                    insert_edge(i,j,c);
                    insert_edge(j,i,c);
                }
            }
        }




        cout<<spfa(1)<<endl;




    }




    return 0;
}