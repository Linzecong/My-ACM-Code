#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1010;
struct edge{
    int to,cap,rev;
    edge(int a,int b,int c){to=a;cap=b;rev=c;}
};
vector<edge>G[maxn];
int level[maxn],iter[maxn];
void add_edge(int from,int to,int cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,0,G[from].size()-1));
}
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int>que;level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front();que.pop();
        for(unsigned int i=0;i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f){
    if(v==t) return f;
    for(int &i=iter[v];i<G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow=0;
    while(1){
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,inf))>0) flow+=f;
    }
}
char str[1010][30],str1[30],str2[30];
int num;
int slove(char *str1){
    if(num==0){
        strcpy(str[1],str1);
        num++;
        return 1;
    }
    for(int i=1;i<=num;i++){
        if(strcmp(str[i],str1)==0)
            return i;
    }
    num++;strcpy(str[num],str1);
    return num;
}
int main(){
    int n,m,k;
    while(scanf("%d",&n)!=-1){
        for(int i=0;i<maxn;i++) G[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%s",str1);
            int a=slove(str1);
            add_edge(0,a,1);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%s%s",str1,str2);
            int a=slove(str1);
            int b=slove(str2);
            add_edge(b,a,1);
            add_edge(a,n+2*m+1,1);
        }
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%s%s",str1,str2);
            int a=slove(str1);
            int b=slove(str2);
            add_edge(b,a,inf);
        }
        printf("%d\n",m-max_flow(0,n+2*m+1));
    }
    return 0;
}