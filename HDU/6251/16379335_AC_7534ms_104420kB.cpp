#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef long long ll;

struct edge{
    int u;
    int v;
    int w;
    int next;
}e[MAXN*4];
int edge_num,head[MAXN];
void insert_edge(int u,int v,int w){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].w=w;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}
int N,M;
map<pair<int,int>,int> G;
map<int,int> Col[MAXN];

map<int,int> Cir;
int pre[MAXN];
int prew[MAXN];
bool flag=0;
bool vis[MAXN];
bool tag[MAXN];
void dfs(int u,int fa){
    if(flag)
        return;
    vis[u]=1;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)
            continue;
        if(vis[v]==0){
            pre[v]=u;
            prew[v]=e[i].w;
            dfs(v,u);
        }
        else{
            int ok=u;
            tag[v]=1;
            Cir[e[i].w]++;
            while(ok!=v){
                tag[ok]=1;
                Cir[prew[ok]]++;
                ok=pre[ok];
            }
            flag=1;
        }
        if(flag)
            return;
    }
}


int main(){
    
    int T;
    scanf("%d",&T);
    for(int ttt=1;ttt<=T;ttt++){
        printf("Case #%d:\n",ttt);
        scanf("%d%d",&N,&M);
        
        flag=0;
        edge_num=0;
        Cir.clear();
        G.clear();
        for(int i=1;i<=N;i++){
            Col[i].clear();
            tag[i]=0;
            vis[i]=0;
            head[i]=-1;
        }
        
        
        int u,v,w;
        for(int i=1;i<=N;i++){
            scanf("%d%d%d",&u,&v,&w);
            
            G[make_pair(u,v)]=w;
            G[make_pair(v,u)]=w;
            
            Col[u][w]++;
            Col[v][w]++;
            insert_edge(u,v,w);
            insert_edge(v,u,w);
            
        }
        
        dfs(1,1);
        int tot=0;
        int hsize=Cir.size();
        for(int i=1;i<=N;i++)
            tot+=Col[i].size();
        tot-=N;
        
        while(M--){
            scanf("%d%d%d",&u,&v,&w);
            int lw=G[make_pair(u,v)];
            G[make_pair(u,v)]=w;
            G[make_pair(v,u)]=w;
            
            Col[u][lw]--;
            if(Col[u][lw]==0){
                tot--;
            }
            
            Col[v][lw]--;
            if(Col[v][lw]==0){
                tot--;
            }
            
            Col[u][w]++;
            if(Col[u][w]==1)
                tot++;
            
            Col[v][w]++;
            if(Col[v][w]==1)
                tot++;
            
            if(tag[u]&&tag[v]){
                Cir[lw]--;
                if(Cir[lw]==0){
                    hsize--;
                }
                Cir[w]++;
                if(Cir[w]==1)
                    hsize++;
            }
            
            if(hsize==1)
                printf("%d\n",tot+1);
            else
                printf("%d\n",tot);
            
            
        }
        
        
    }
    
    return 0;
}





















