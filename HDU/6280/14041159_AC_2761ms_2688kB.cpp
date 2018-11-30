#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int MAXLOGV=20;
vector<int> G[MAXN];
int N;
/****LCA****/
int f[MAXLOGV+2][MAXN];
int dep[MAXN];
void dfs(int u,int fa)
{
    f[0][u]=fa;dep[u]=dep[fa]+1;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
}
void lca_init(){
    memset(f,0,sizeof(f));
    dep[0]=0;
    dfs(1,0);
    for(int k=0;k+1<MAXLOGV;++k){
        for(int v=1;v<=N;++v){
            if(f[k][v]==0) f[k+1][v]=0;
            else f[k+1][v]=f[k][f[k][v]];
        }
    }
}
int LCA(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<MAXLOGV;++k){
        if( (dep[v]-dep[u])>>k&1){
            v=f[k][v];
        }
    }
    if(u==v) return u;
    for(int k=MAXLOGV-1;k>=0;--k){
        if(f[k][u]!=f[k][v]){
            u=f[k][u];
            v=f[k][v];
        }
    }
    return f[0][u];
}
/****LCA****/


int sz[MAXN];
int ans=0;
int pre[MAXN];
int find(int x){
    return pre[x]==x?x:pre[x]=find(pre[x]);
}

void init(){
    ans=0;
    for(int i=0;i<=N;i++){
        G[i].clear();
        pre[i]=i;
    }
}

void link(int x,int y){
    
    x=find(x);
    if(dep[f[0][x]]<=dep[y]||f[0][x]==0){
        return;
    }
    ans=ans^sz[f[0][x]]^(sz[f[0][x]]-1);
    sz[f[0][x]]--;
    pre[x]=f[0][x];
    link(f[0][x],y);
   
}

int main(){
    int m,a,b,x,y;

    while(~scanf("%d%d%d%d%d%d",&N,&m,&a,&b,&x,&y)){
        int u,v;
        init();
        for(int i=1;i<N;i++){
            scanf("%d%d",&u,&v);
            u++;
            v++;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        lca_init();
        for(int i=1;i<=N;i++){
            sz[i]=G[i].size();
            ans^=sz[i];
        }

        for(int i=0;i<m;i++){
            int nx=(a*x+b*y+ans)%N;
            int ny=(b*x+a*y+ans)%N;
            x=nx;
            y=ny;
            link(x+1,LCA(x+1,y+1));
        }
        printf("%d %d\n",x,y);

    }

}