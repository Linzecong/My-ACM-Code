#include<iostream>
#include<math.h>
#include<queue>
#include<memory.h>
using namespace std;


const int MAXV = 400117;  
const int inf=0x3f3f3f3f; 
int C[MAXV];  

int near[MAXV];

struct edge{  
    int v1,v2,w,next;  
}e[MAXV];  
  
int n,m,edge_num;  
int head[MAXV],d[MAXV];  
bool vis[MAXV];  
int time[MAXV];  
  
void insert_edge(int v1,int v2,int w){  
    e[edge_num].v1=v1;  
    e[edge_num].v2=v2;  
    e[edge_num].w=w;  
    e[edge_num].next=head[v1];  
    head[v1]=edge_num++;
}  
  
int spfa(int s,int en){  
    queue<int> que;  
    memset(vis,0,sizeof(vis));  
    for(int i=1;i<=n;i++)d[i]=inf;  
    que.push(s);  
    d[s]=0;  
    vis[s]=1;  
    while(!que.empty()){  
        int tp=que.front();  
        que.pop();  
        vis[tp]=0;  
        for(int i=head[tp];i!=-1;i=e[i].next)  
            if(d[tp]+e[i].w<d[e[i].v2]){  
                d[e[i].v2]=d[tp]+e[i].w;  
  
                if(!vis[e[i].v2]){  
                    vis[e[i].v2]=1;  
                    que.push(e[i].v2);
                }  
            }  
    }   
    return d[en];  
}  
  

int main(){

    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof(head));
        edge_num=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&C[i]);
        
        memset(near,0,sizeof(near));
        for(int i=1;i<=n;i++)
        {
            if(near[C[i]]==0){
                near[C[i]]=i;
            }
            else{
                insert_edge(near[C[i]],i,1);
                near[C[i]]=i;
            }
        }

        for(int i=1;i<n;i++)
            insert_edge(i,i+1,1);
            
        printf("%d\n",spfa(1,n));
     


    }

    
    return 0;
}