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
int tree[MAXN<<2];//线段树数组，看你要存什么
int tree2[MAXN<<2];//线段树数组，看你要存什么

int Add[MAXN<<2];//懒惰标记，这里是区间累加
int n;
int A[MAXN];//原数组，下标1~n

//更新节点信息，这里是求最值
void pushup(int rt){
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);//<<1为*2.<<1|1为*2+1，即左子树和右子树
    tree2[rt]=min(tree2[rt<<1],tree2[rt<<1|1]);//<<1为*2.<<1|1为*2+1，即左子树和右子树
}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    Add[rt]=0;

    tree[rt]=-INF;//将该位置存原数组的值
    tree2[rt]=INF;//将该位置存原数组的值

    if(l==r)return;

    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);//建完左右子树后，更新当前节点的值
}

//下推函数，ln,rn为左子树，右子树的数字数量。
void pushdown(int rt,int ln,int rn){
    if(Add[rt]){//如果存在下推标记

        //将标记下推至子节点
        Add[rt<<1]^=1;
        Add[rt<<1|1]^=1;

        //修改子节点的值
        tree[rt<<1]=-tree[rt<<1];
        tree2[rt<<1]=-tree2[rt<<1];
        swap(tree[rt<<1],tree2[rt<<1]);

        tree[rt<<1|1]=-tree[rt<<1|1];
        tree2[rt<<1|1]=-tree2[rt<<1|1];
        swap(tree[rt<<1|1],tree2[rt<<1|1]);

        //清除标记
        Add[rt]=0;

    }
}

//点修改，即A[L]=C，要同时修改相关区间的值，与建树同理，其实就是建树的过程
void update(int L,int C,int l,int r,int rt){
    if(l==r){//若到达叶节点，则修改叶节点的值
        tree[rt]=C;
        tree2[rt]=C;
        Add[rt]=0;
        return;
    }
    int m=(l+r)>>1;

    pushdown(rt,m-l+1,r-m);//必须下推标记，因为有pushup

    //根据L判断是往哪个子树递归修改
    if(L<=m)
        update(L,C,l,m,rt<<1);//左子树
    else
        update(L,C,m+1,r,rt<<1|1);//右子树

    pushup(rt);//子节点更新完了，那么可以更新自己了，即从下而上修改，建树同理
}

//区间修改，比点修改多了个R参数，这里是区间+C，与查询同理，在查询时修改
void update(int L,int R,int C, int l, int r, int rt){
    if(L<=l&&r<=R){//如果当前区间在查询区间内，直接对其进行修改
        tree[rt]=-tree[rt];//C*当前区间含有的数字个数
        tree2[rt]=-tree2[rt];//C*当前区间含有的数字个数
        swap(tree[rt],tree2[rt]);
        Add[rt]^=1;//增加Add标记，表示本区间的值正确，子区间的值仍需要根据Add的值来调整
        return;
    }
    int m=(l+r)>>1;

    pushdown(rt,m-l+1,r-m);//必须下推标记，因为有pushup

    if(L <= m) //与查询同理
        update(L,R,C,l,m,rt<<1);
    if(R >  m)
        update(L,R,C,m+1,r,rt<<1|1);

    pushup(rt);//更新本节点信息
}



//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)//如果当前区间在查询区间内，直接返回当前存的值
        return tree[rt];

    int m=(l+r)>>1;

    //每次查询都下推标记，保证值正确
    pushdown(rt,m-l+1,r-m);

    //累加求答案
    int ANS=-INF;
    if(L<=m)//如果左子区间与[L,R]有重叠，就递归左子树，右子树同理。
        ANS=max(ANS,query(L,R,l,m,rt<<1));
    if(R>m)
        ANS=max(ANS,query(L,R,m+1,r,rt<<1|1));

    return ANS;
}



//线段树+树链剖分部分
int queryMAX(int u,int v){
    int f1=top[u],f2=top[v];
    int temp=-INF;
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        temp=max(temp,query(pos[f1],pos[u],1,n,1));
        u=fa[f1];
        f1=top[u];
    }

    if(u==v)
        return temp==-INF?0:temp;

    if(deep[u]>deep[v])
        swap(u,v);
    return max(temp,query(pos[son[u]],pos[v],1,n,1));
}

void update(int u,int v){
    int f1=top[u],f2=top[v];
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        update(pos[f1],pos[u],1,1,n,1);

        u=fa[f1];
        f1=top[u];
    }

    if(u==v)
        return;

    if(deep[u]>deep[v])
        swap(u,v);
    update(pos[son[u]],pos[v],1,1,n,1);
}



int in[MAXN][3];
int main(){

    int q;
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        init();


        int u,v;

        for(int i=0;i<n-1;i++){
            scanf("%d%d%d",&in[i][0],&in[i][1],&in[i][2]);
            insert_edge(in[i][0],in[i][1]);
            insert_edge(in[i][1],in[i][0]);
        }

        dfs1(1,0,0);
        dfs2(1,1);
        build(1,n,1);

        for(int i=0;i<n-1;i++){
            if(deep[in[i][0]]<deep[in[i][1]])
                swap(in[i][0],in[i][1]);
            update(pos[in[i][0]],in[i][2],1,n,1);
        }



        char op[10];

        while(1){
            scanf("%s",op);
            if(op[0]=='D')
                break;

            scanf("%d%d",&u,&v);

            if(op[0]=='Q'){
                printf("%d\n",queryMAX(u,v));
            }
            else{
                if(op[0]=='N'){
                    update(u,v);
                }
                else
                    update(pos[in[u-1][0]],v,1,n,1);
            }
        }
    }
    return 0;
}



