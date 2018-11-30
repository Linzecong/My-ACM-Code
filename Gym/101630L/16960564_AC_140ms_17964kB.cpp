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
    pos[u]=SEG++;
    if(son[u]!=-1){
        dfs2(son[u],sp);
    }
    else{
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
int lc[MAXN<<2];//线段树数组，看你要存什么
int rc[MAXN<<2];//线段树数组，看你要存什么
int num[MAXN<<2];

int Add[MAXN<<2];//懒惰标记，这里是区间累加

int n;


//更新节点信息，这里是求最值
void pushup(int rt){
    lc[rt]=lc[rt<<1];
    rc[rt]=rc[rt<<1|1];
    num[rt]=num[rt<<1]+num[rt<<1|1]-(rc[rt<<1]==lc[rt<<1|1]);//<<1为*2.<<1|1为*2+1，即左子树和右子树
}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    Add[rt]=-1;
    lc[rt]=0;//将该位置存原数组的值
    rc[rt]=0;//将该位置存原数组的值

    if(l==r){

        num[rt]=1;
        return;
    }

    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);//建完左右子树后，更新当前节点的值
}

//下推函数，ln,rn为左子树，右子树的数字数量。
void pushdown(int rt,int l,int r){
    if(l==r){
        return;
    }

    if(Add[rt]!=-1){//如果存在下推标记

        //将标记下推至子节点
        Add[rt<<1]=Add[rt];
        Add[rt<<1|1]=Add[rt];

        //修改子节点的值
        lc[rt<<1]=rc[rt<<1]=Add[rt];
        lc[rt<<1|1]=rc[rt<<1|1]=Add[rt];
        num[rt<<1]=num[rt<<1|1]=1;
        //清除标记
        Add[rt]=-1;

    }
}


//区间修改，比点修改多了个R参数，这里是区间+C，与查询同理，在查询时修改
void update(int L,int R,int C, int l, int r, int rt){
    if(L==l&&r==R){//如果当前区间在查询区间内，直接对其进行修改
        lc[rt]=C;//C*当前区间含有的数字个数
        rc[rt]=C;//C*当前区间含有的数字个数
        num[rt]=1;
        Add[rt]=C;//增加Add标记，表示本区间的值正确，子区间的值仍需要根据Add的值来调整
        return;
    }
    int m=(l+r)>>1;

    pushdown(rt,l,r);//必须下推标记，因为有pushup

    if(R <= m) //与查询同理
        update(L,R,C,l,m,rt<<1);
    else{
        if(L >  m)
            update(L,R,C,m+1,r,rt<<1|1);
        else{
            update(L,m,C,l,m,rt<<1);
            update(m+1,R,C,m+1,r,rt<<1|1);
        }
    }

    pushup(rt);//更新本节点信息
}

int query(int L, int l, int r, int rt){
    if(L==r)
        return rc[rt];
    if(L==l)
        return lc[rt];
    pushdown(rt,l,r);
    int m=(l+r)>>1;

    if(L<=m)
        return query(L,l,m,rt<<1);
    else
        if(L>m)
            return query(L,m+1,r,rt<<1|1);
}


//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
int query(int L,int R,int l,int r,int rt){
    if(L==l&&r==R)//如果当前区间在查询区间内，直接返回当前存的值
        return num[rt];

    int m=(l+r)>>1;

    //每次查询都下推标记，保证值正确
    pushdown(rt,l,r);

    if(R<=m)
        return query(L,R,l,m,rt<<1);
    else{
        if(L>m)
            return query(L,R,m+1,r,rt<<1|1);
        else
            return query(L,m,l,m,rt<<1)+query(m+1,R,m+1,r,rt<<1|1)-(rc[rt<<1]==lc[rt<<1|1]);
    }
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
         temp+=query(pos[f1],pos[u],1,n,1)-(query(pos[fa[f1]],1,n,1)==query(pos[f1],1,n,1));
       // temp+=query(pos[f1],pos[u],1,n,1)-(A[pos[fa[f1]]]==A[pos[f1]]);
        u=fa[f1];
        f1=top[u];
    }


    if(deep[u]>deep[v])
        swap(u,v);
    temp+=query(pos[u],pos[v],1,n,1);
    return temp;
}

void update(int u,int v,int c){
    int f1=top[u],f2=top[v];
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        update(pos[f1],pos[u],c,1,n,1);

        u=fa[f1];
        f1=top[u];
    }

    if(deep[u]>deep[v])
        swap(u,v);
    update(pos[u],pos[v],c,1,n,1);
}


int LCA(int u, int v)
{
    int uu = top[u], vv = top[v];
    while (uu != vv) {
        if (deep[uu] < deep[vv]) {
            swap(uu, vv);
            swap(u, v);
        }
        u = fa[uu]; uu = top[u];
    }
    if (deep[u] < deep[v])
        swap(u, v);
    return v;
}


struct Query{
    int u,v,d;
}Q[MAXN];
bool cmp(Query &a,Query &b){
    return a.d>b.d;
}


int main(){

    int q;

    scanf("%d%d",&n,&q);
    init();

    int u,v;

    for(int i=0;i<n-1;i++){
        scanf("%d%d",&u,&v);
        insert_edge(u,v);
        insert_edge(v,u);
    }

    dfs1(1,0,0);
    dfs2(1,1);
build(1,n,1);

    for(int i=0;i<q;i++){
        scanf("%d%d",&u,&v);
        Q[i].u=u;
        Q[i].v=v;
        Q[i].d=deep[u]+deep[v]-2*deep[LCA(u,v)];

    }

    sort(Q,Q+q,cmp);

    for(int i=0;i<q;i++){

//        int maa=queryMax(Q[i].u,Q[i].v);
//        int mii=queryMin(Q[i].u,Q[i].v);
//        cout<<maa<<" "<<mii<<endl;

        if(query(Q[i].u,Q[i].v)>1){
            cout<<"No"<<endl;
            return 0;
        }
        update(Q[i].u,Q[i].v,i+1);
    }

    cout<<"Yes"<<endl;

    return 0;
}





