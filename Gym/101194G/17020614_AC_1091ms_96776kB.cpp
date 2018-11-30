#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=210005,MAXM=200005;

int N,M;
struct edge{
    int u,v,w;
    bool operator < (const edge &b)const{
        return w<b.w;
    }
}e[MAXM];

int pre[MAXN*2];
int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}

int root[MAXN*2];
int ls[MAXN*20];
int rs[MAXN*20];
int tree[MAXN*20];
int val[MAXN*20];
int tot=0;


void pushup(int rt){
    if(tree[ls[rt]]>=tree[rs[rt]]){
        tree[rt]=tree[ls[rt]];
        val[rt]=val[ls[rt]];
    }
    else{
        tree[rt]=tree[rs[rt]];
        val[rt]=val[rs[rt]];
    }
}

void update(int L,int l,int r,int &rt){
    if(!rt)
        rt=++tot;
    if(l==r){
        tree[rt]=1;
        val[rt]=L;
        return;
    }
    int m=(l+r)/2;
    if(L<=m)
        update(L,l,m,ls[rt]);
    if(L>m)
        update(L,m+1,r,rs[rt]);
    pushup(rt);
}

int merge(int L,int R,int l,int r){
    if(!L||!R)
        return L+R;
    if(l==r){
        tree[L]+=tree[R];
        return L;
    }
    int m=(l+r)/2;
    ls[L]=merge(ls[L],ls[R],l,m);
    rs[L]=merge(rs[L],rs[R],m+1,r);
    pushup(L);
    return L;
}

int query(int rt){
    return val[rt];
}

int col[MAXN*3];
int ans[MAXN*3];

int dep[MAXN],fa[MAXN][20];
void init(){
   for(int i=0;i<MAXM;i++){
       pre[i]=i;
       root[i]=0;
   }
   tot=0;
   memset(ls,0,sizeof(ls));
   memset(rs,0,sizeof(rs));
   memset(tree,0,sizeof(tree));
   memset(val,0,sizeof(val));
   memset(fa,0,sizeof(fa));
}

int P;
int ch[MAXN][2];
void kruskal(){
    P=N;
    sort(e,e+M);
    for(int i=0;i<M;i++){
        int u=e[i].u;
        int v=e[i].v;
        int fx=find(u);
        int fy=find(v);
        if(fx!=fy){

            col[++P]=e[i].w;
            ch[P][0]=fx;
            ch[P][1]=fy;
            pre[fx]=P;
            pre[fy]=P;

        }
    }
}


void dfs(int u,int p){
    fa[u][0]=p;
    dep[u]=dep[p]+1;
    for(int i=1;i<20;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    if(u<=N)
        return;
    dfs(ch[u][0],u);
    dfs(ch[u][1],u);
    root[u]=merge(root[ch[u][0]],root[ch[u][1]],1,N);
    ans[u]=query(root[u]);
}

int find(int x,int w){
    for(int i=19;i>=0;i--)
        if(col[fa[x][i]]<=w&&fa[x][i]!=0)
            x=fa[x][i];
    return x;
}

int main(){

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){

        init();
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++){
            scanf("%d",&col[i]);
            ans[i]=col[i];
            update(col[i],1,N,root[i]);
        }

        for(int i=0;i<M;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

        kruskal();
        dfs(P,0);

        printf("Case #%d:\n",qqq);
        int Q;
        scanf("%d",&Q);
        int last=0;
        while(Q--){
            int u,x;
            scanf("%d%d",&u,&x);
            u=u^last;
            x=x^last;
            printf("%d\n",last=ans[find(u,x)]);
        }
    }

    return 0;
}









