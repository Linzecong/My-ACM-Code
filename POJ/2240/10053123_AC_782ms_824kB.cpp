#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
const int inf=1<<29;

struct edge{
    int v1;
    int v2;
    double len;
    int next;
}e[2000];
int head[2000];
int edge_num;

void insert_edge(int v1,int v2,double w){
    e[edge_num].v1=v1;
    e[edge_num].v2=v2;
    e[edge_num].len=w;
    e[edge_num].next=head[v1];
    head[v1]=edge_num++;
}


int N,M;
map<string,int> m;


double d[2000];
bool vis[2000];

bool spfa(int start){
    memset(vis,0,sizeof(vis));

    for(int i=0;i<N;i++)d[i]=0;

    d[start]=1;
    vis[start]=1;

    queue<int> que;

    que.push(start);

    while(!que.empty()){

        int tp=que.front();
        que.pop();


        vis[tp]=0;

        for(int i=head[tp];i!=-1;i=e[i].next){

            if(d[tp]*e[i].len>d[e[i].v2]){
                d[e[i].v2]=d[tp]*e[i].len;

                if(!vis[e[i].v2]){
                    vis[e[i].v2]=1;
                    que.push(e[i].v2);



                }

            }


        }


        if(d[start]>1)
            return true;


    }

    return false;


}




string temp;
string a,b;
double c;
int main()
{

    int tt=1;
    while(~scanf("%d",&N)){
        if(N==0)
            break;
        m.clear();
        for(int i=0;i<N;i++){
            cin>>temp;
            m[temp]=i;
        }

        scanf("%d",&M);

        memset(head,-1,sizeof(head));
        edge_num=0;


        for(int i=0;i<M;i++){
            cin>>a>>c>>b;
            insert_edge(m[a],m[b],c);
        }

        bool have=0;

        for(int i=0;i<N;i++){
            if(spfa(i)){
                cout<<"Case "<<tt++<<": Yes"<<endl;
                have=1;
                break;
            }
        }

        if(!have)
            cout<<"Case "<<tt++<<": No"<<endl;



    }


    return 0;
}
