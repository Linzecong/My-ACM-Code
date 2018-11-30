#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include<queue>
using namespace std;
typedef unsigned long long ll;
const int MAXN=200005;
ll MOD = 1000000007;

struct Edge
{
    int u,v,next;
}e[MAXN];
int head[MAXN];
int edge_num;

void insert_edge(int u,int v){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int size[MAXN];
int pos[MAXN];
int son[MAXN];
int SEG;


//求出fa,deep,num,son
void dfs1(int u,int pre,int d){
    deep[u]=d;
    fa[u]=pre;
    size[u]=1;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v!=pre){
            dfs1(v,u,d+1);
            size[u]+=size[v];
            if(son[u]==-1||size[v]>size[son[u]])
                son[u]=v;
        }
    }
}

//求出top和pos，求的过程中，先求重链上的dfs序
void dfs2(int u,int sp){
    top[u]=sp;
    pos[u]=SEG++;

    if(son[u]!=-1){

        dfs2(son[u],sp);
    }
    else{
        return;
    }

    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v!=son[u]&&v!=fa[u]){
            dfs2(v,v);
        }
    }

}

ll sum[MAXN<<2];
ll lazyAdd[MAXN<<2];
ll lazyMul[MAXN<<2];
int N;
void init(){
    edge_num=0;
    memset(head,-1,sizeof(head));
    SEG=1;
    memset(son,-1,sizeof(son));
}

void build(int l,int r,int rt){
    lazyAdd[rt]=-1;
    if(l==r){
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}


void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,ll ln,ll rn){


    if(lazyAdd[rt]!=-1){
        sum[rt<<1]=lazyAdd[rt]*ln;
        lazyAdd[rt<<1]=lazyAdd[rt];

        sum[rt<<1|1]=lazyAdd[rt]*rn;
        lazyAdd[rt<<1|1]=lazyAdd[rt];

        lazyAdd[rt]=-1;
    }


}


void updateAdd(int L,int R,ll C,int l,int r,int rt){
    if(L<=l&&r<=R){
        lazyAdd[rt]=C;
        sum[rt]=C*(r-l+1);
        return;
    }
    int m=(l+r)/2;
    pushdown(rt,m-l+1,r-m);

    if(L<=m)
        updateAdd(L,R,C,l,m,rt<<1);
    if(R>m)
        updateAdd(L,R,C,m+1,r,rt<<1|1);
    pushup(rt);
}


ll query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    int m=(l+r)/2;
    pushdown(rt,m-l+1,r-m);
    ll ans=0;
    if(L<=m)
        ans+=query(L,R,l,m,rt<<1);
    if(R>m)
        ans+=query(L,R,m+1,r,rt<<1|1);
    return ans;
}

void updateAdd(int u,int v,ll C){
    int f1=top[u];
    int f2=top[v];
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        updateAdd(pos[f1],pos[u],C,1,N,1);
        u=fa[f1];
        f1=top[u];
    }

    if(deep[u]>deep[v])
        swap(u,v);
    updateAdd(pos[u],pos[v],C,1,N,1);
}

ll query(int u,int v){
    int f1=top[u];
    int f2=top[v];
    ll temp=0;
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        temp+=query(pos[f1],pos[u],1,N,1);
        u=fa[f1];
        f1=top[u];
    }

    if(deep[u]>deep[v])
        swap(u,v);
    return temp+query(pos[u],pos[v],1,N,1);
}


int main(){
    scanf("%d",&N);
    int Q;
    scanf("%d",&Q);

    int a,b;
    init();
    for(int i=2;i<=N;i++){
        scanf("%d%d",&a,&b);
        insert_edge(a,b);
        insert_edge(b,a);
    }

    dfs1(1,0,0);
    dfs2(1,1);
    build(1,N,1);

    while(Q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);

            updateAdd(a,b,1);

            printf("%llu\n",query(c,d));
            updateAdd(a,b,0);

    }



return 0;
}
