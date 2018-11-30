#include<bits/stdc++.h>
using namespace std;
const int MAXN=400005;
typedef long long ll;
map<pair<int,int>,int > mp;
struct edge{
    int u,v,w,next;
}ee[MAXN];
bool cmp(edge a,edge b){
    return a.w<b.w;
}


edge e[MAXN];
int edge_num=0;
int head[MAXN];
void insert_edge(int u,int v,int w){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].w=w;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}
int pre[MAXN];
int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}



//树链剖分部分
int top[MAXN];//重链顶点
int fa[MAXN];//父亲节点
int deep[MAXN];//深度
int size[MAXN];//子树大小
int pos[MAXN];//dfs序
int son[MAXN];//重儿子是哪个
int SEG;//dfs序当前点
    int N,M;
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

    if(son[u]!=-1){
        pos[u]=SEG++;
        dfs2(son[u],sp);
    }
    else{
        pos[u]=SEG++;
        return;
    }

    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v!=son[u]&&v!=fa[u]){
            dfs2(v,v);
        }
    }

}

//线段树部分
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int MAX[MAXN<<2];
int val[MAXN<<2];
void pushup(int rt){
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l==r){
        MAX[rt]=val[l];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R){
        return MAX[rt];
    }
    int m=(l+r)>>1;
    int res=0;
    if(m>=L)
        res=max(res,query(L,R,lson));
    if(R>m)
        res=max(res,query(L,R,rson));
    return res;
}

//线段树+树链剖分部分
int query(int u,int v){
    int f1=top[u],f2=top[v];
    int temp=0;
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        temp=max(temp,query(pos[f1],pos[u],1,N,1));
        u=fa[f1];
        f1=top[u];
    }
    if(u==v)
        return temp;
    if(deep[u]>deep[v])
        swap(u,v);
    //cout<<son[u]<<" "<<v<<endl;
    return max(temp,query(pos[son[u]],pos[v],1,N,1));//因为是边权，所以是pos[son[u]]
}



int main(){
    init();
    for(int i=0;i<MAXN;i++)
        pre[i]=i;
    int u,v,w;

    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&ee[i].u,&ee[i].v,&ee[i].w);
        mp[make_pair(ee[i].u,ee[i].v)]=ee[i].w;
        mp[make_pair(ee[i].v,ee[i].u)]=ee[i].w;
    }

    sort(ee,ee+M,cmp);
    int ans=0;
    for(int i=0;i<M;i++){
        u=ee[i].u;
        v=ee[i].v;
        int fx=find(u);
        int fy=find(v);
        if(fy!=fx){
            ans+=ee[i].w;
            pre[fx]=fy;
            insert_edge(u,v,ee[i].w);
            insert_edge(v,u,ee[i].w);
        }
    }


    dfs1(1,0,0);
    dfs2(1,1);

    for(int i=0;i<edge_num;i+=2){
        if(deep[e[i].u]<deep[e[i].v])
             val[pos[e[i].v]]=e[i].w;
        else
            val[pos[e[i].u]]=e[i].w;

    }


    build(1,N,1);

    int Q;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&u,&v);
        int mm=query(u,v);
      //  cout<<mm<<endl;
        cout<<ans-mm+mp[make_pair(u,v)]<<endl;

    }




    return 0;
}
