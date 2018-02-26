#include<iostream>  
#include<deque>  
#include<memory.h>  
#include<stdio.h>  
#include<map>  
#include<string>  
#include<algorithm>  
#include<vector>  
#include<math.h>  
#include<stack>  
#include<queue>  
#include<set>  
#define inf 0x3f3f3f3f 
#define MAXV 300005  
using namespace std;  

vector<int> list;
  
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
  
    e[edge_num].v1=v2;  
    e[edge_num].v2=v1;  
    e[edge_num].w=w;  
    e[edge_num].next=head[v2];  
    head[v2]=edge_num++;  
}  
  
  
int spfa(int s,int en,int limit){  
    queue<int> que;  
    memset(vis,0,sizeof(vis));  
    memset(time,0,sizeof(time));  
    for(int i=1;i<=n;i++)d[i]=inf;  
  
  
    que.push(en);  
    d[en]=0;  
    time[en]++;  
    vis[en]=1;  
  
  
    while(!que.empty()){  
        int tp=que.front();  
        que.pop();  
        vis[tp]=0;  
  
        for(int i=head[tp];i!=-1;i=e[i].next){
        	if(e[i].w>limit)
        		continue;
        
            if(d[tp]+e[i].w<d[e[i].v2]){  
  
                d[e[i].v2]=d[tp]+e[i].w;  
  
                if(!vis[e[i].v2]){  
                    vis[e[i].v2]=1;  
                    que.push(e[i].v2);  
  
                    if(++time[e[i].v2]>=n)  
                        return 1;  
                }  
  
  
            }  
  
		}
  
    }  
  
  
    return d[s];  
   
}  
  
int main(){  
  
    int a,b,c,x;  
    while(~scanf("%d%d%d",&n,&m,&x)){  
  
        edge_num=0;  
        memset(head,-1,sizeof(head));  
  
        for(int i=1;i<=n;i++)  
            d[i]=inf;  
  
  
        for(int i=1;i<=m;i++){  
            scanf("%d%d%d",&a,&b,&c);  
            insert_edge(a,b,c);  
  			list.push_back(c);
        }
		
		sort(list.begin(),list.end());
		list.erase(unique(list.begin(), list.end()), list.end());
		  
		
		double mmm=spfa(1,n,inf)*(1.0+x/100.0);
		
		int i=0;
		for(i=0;i<list.size();i++){
			int aaa=spfa(1,n,list[i]);
			if(aaa<mmm){
				break;
			}
		}
		
		cout<<list[i]<<endl;
		 
    }  
  
  
    return 0;  
}  