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
#include<bitset>
#include<set>
#define INF (0x3f3f3f3f)
using namespace std;
typedef long long int ll;
const int MAXN=100010;

//邻接图部分
struct Edge{
    int to;
    int next;
}e[MAXN*2];
int head[MAXN],edge_num;
void insert_edge(int u,int v){
    e[edge_num].to=v;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

//树链剖分部分
int top[MAXN];//重链顶点
int fa[MAXN];//父亲节点
int deep[MAXN];//深度
int size[MAXN];//子树大小
int pos[MAXN];//dfs序
int son[MAXN];//重儿子是哪个
int SEG;//dfs序当前点

void init(){
    edge_num=0;
    memset(head,-1,sizeof(head));
    SEG=1;
    memset(son,-1,sizeof(son));
  
}

//求出fa,deep,num,son
void dfs1(int u,int pre,int d){
    deep[u]=d;
    fa[u]=pre;
    size[u]=1;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
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

    if(son[u]!=-1){
        pos[u]=SEG++;
        dfs2(son[u],sp);
    }
    else{
        pos[u]=SEG++;
        return;
    }

    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(v!=son[u]&&v!=fa[u]){
            dfs2(v,v);
        }
    }

}

//线段树部分
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll SUM[MAXN<<2];
ll val[MAXN<<2];
int n;
void pushup(int rt){
    SUM[rt]=(SUM[rt<<1]+SUM[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l==r){
        SUM[rt]=val[l];
        return;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,ll x,int l,int r,int rt){
    if(l==r){
        SUM[rt]=x;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,x,lson);
    else
        update(p,x,rson);
    pushup(rt);
}

ll querySUM(int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R){
        return SUM[rt];
    }
    int m=(l+r)>>1;
    ll res=0;
    if(m>=L)
        res=(res+querySUM(L,R,lson));
    if(R>m)
        res=(res+querySUM(L,R,rson));
    return res;
}



//线段树+树链剖分部分
ll querySUM(int u,int v){
    int f1=top[u],f2=top[v];
    ll temp=0;
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        temp=(temp+querySUM(pos[f1],pos[u],1,n,1));
        u=fa[f1];
        f1=top[u];
    }

    if(u==v)
        return temp;

    if(deep[u]>deep[v])
        swap(u,v);
    return (temp+querySUM(pos[son[u]],pos[v],1,n,1));
}

ll in[MAXN][3];
int main(){

    int q;

    while(~scanf("%d%d",&n,&q)){
        init();
        memset(val,0,sizeof(val));
        memset(SUM,0,sizeof(SUM));
        int u,v;

        for(int i=0;i<n-1;i++){
            scanf("%I64d%I64d%I64d",&in[i][0],&in[i][1],&in[i][2]);
            insert_edge(in[i][0],in[i][1]);
            insert_edge(in[i][1],in[i][0]);
        }

        dfs1(1,0,0);
        dfs2(1,1);

        for(int i=0;i<n-1;i++){
            if(deep[in[i][0]]<deep[in[i][1]])
                swap(in[i][0],in[i][1]);
            val[pos[in[i][0]]]=in[i][2];
        }

        build(1,n,1);

        int op;

        for(int i=0;i<q;i++){
            scanf("%d",&op);
            scanf("%d%d",&u,&v);

                if(op==1){
                    printf("%I64d\n",querySUM(u,v));
                }
                else
                    update(pos[in[u-1][0]],v,1,n,1);
        }
    }
    return 0;
}




