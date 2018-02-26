#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=200005;

int tree[maxn<<2];//线段树数组，看你要存什么
int Add[maxn<<2];//懒惰标记，这里是区间累加

int A[maxn];//原数组，下标1~n

//更新节点信息，这里是求最值
void pushup(int rt){
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);//<<1为*2.<<1|1为*2+1，即左子树和右子树
}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    if(l==r){//若到达叶子结点
        tree[rt]=A[l];//将该位置存原数组的值
        return;
    }
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
        Add[rt<<1]+=Add[rt];
        Add[rt<<1|1]+=Add[rt];

        //修改子节点的值
        tree[rt<<1]+=Add[rt]*ln;
        tree[rt<<1|1]+=Add[rt]*rn;

        //清除标记
        Add[rt]=0;

    }
}

//点修改，即A[L]=C，要同时修改相关区间的值，与建树同理，其实就是建树的过程
void update(int L,int C,int l,int r,int rt){
    if(l==r){//若到达叶节点，则修改叶节点的值
        tree[rt]=C;
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
        tree[rt]+=C*(r-l+1);//C*当前区间含有的数字个数
        Add[rt]+=C;//增加Add标记，表示本区间的值正确，子区间的值仍需要根据Add的值来调整
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
    int ANS=0;
    if(L<=m)//如果左子区间与[L,R]有重叠，就递归左子树，右子树同理。
        ANS=max(ANS,query(L,R,l,m,rt<<1));
    if(R>m)
        ANS=max(ANS,query(L,R,m+1,r,rt<<1|1));
    return ANS;
}


int main(){



    int n,m;

    while(cin>>n>>m){

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            update(i,A[i],1,n,1);
        }

        int a,b;
        char c[5];

        for(int i=0;i<m;i++){
            scanf("%s",c);

            scanf("%d%d",&a,&b);

            if(c[0]=='Q'){
                printf("%d\n",query(a,b,1,n,1));
            }
            else{
                update(a,b,1,n,1);
            }


        }
    }

    return 0;
}













