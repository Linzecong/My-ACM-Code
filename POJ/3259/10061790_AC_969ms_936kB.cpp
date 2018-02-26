#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int inf=1<<29;

struct edge{
    int v1;
    int v2;
    int len;
    int next;
}e[30000];
int edge_num,head[30000];

void insert_edge(int v1,int v2,int w){
    e[edge_num].v1=v1;
    e[edge_num].v2=v2;
    e[edge_num].len=w;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;
}

bool vis[30000];
int d[30000];
int N,M,W;
int a,b,c;

bool spfa(int st){
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


        if(d[st]<0)
            return true;

    }


    return false;




}





int main()
{


    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        scanf("%d%d%d",&N,&M,&W);

        edge_num=0;
        memset(head,-1,sizeof(head));

        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            insert_edge(a,b,c);
            insert_edge(b,a,c);
        }

        for(int i=0;i<W;i++){
            scanf("%d%d%d",&a,&b,&c);
            insert_edge(a,b,-c);
        }

        bool have=0;
        for(int i=1;i<=N;i++)
        if(spfa(i)){
            cout<<"YES"<<endl;
            have=1;
            break;
        }

        if(!have)
            cout<<"NO"<<endl;



    }








    return 0;
}