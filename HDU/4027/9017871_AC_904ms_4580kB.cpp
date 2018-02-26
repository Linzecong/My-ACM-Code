#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100010;

ll tree[MAXN<<2];//线段树数组，看你要存什么
//int Add[MAXN<<2];//懒惰标记，这里是区间累加

ll A[MAXN];//原数组，下标1~n

//更新节点信息，这里是求最值
void pushup(int rt){
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];//<<1为*2.<<1|1为*2+1，即左子树和右子树
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
//void pushdown(int rt,int ln,int rn){
//    if(Add[rt]){//如果存在下推标记

//        //将标记下推至子节点
//        Add[rt<<1]+=Add[rt];
//        Add[rt<<1|1]+=Add[rt];

//        //修改子节点的值
//        tree[rt<<1]+=Add[rt]*ln;
//        tree[rt<<1|1]+=Add[rt]*rn;

//        //清除标记
//        Add[rt]=0;

//    }
//}

//点修改，即A[L]=C，要同时修改相关区间的值，与建树同理，其实就是建树的过程
//void update(int L,int R,int l,int r,int rt){
//    if(l==r){//若到达叶节点，则修改叶节点的值
//        tree[rt]=ll(sqrt(tree[rt]));
//        return;
//    }
//    int m=(l+r)>>1;

//    // pushdown(rt,m-l+1,r-m);//必须下推标记，因为有pushup

//    //根据L判断是往哪个子树递归修改
//    if(L<=m)
//        update(L,l,m,rt<<1);//左子树
//    else
//        update(L,m+1,r,rt<<1|1);//右子树

//    pushup(rt);//子节点更新完了，那么可以更新自己了，即从下而上修改，建树同理
//}

//区间修改，比点修改多了个R参数，这里是区间+C，与查询同理，在查询时修改
void update(int L,int R, int l, int r, int rt){

    if(l==r){
        tree[rt]=(ll)sqrt(tree[rt]);
        return;
    }

    if(L<=l&&r<=R&&r-l+1==tree[rt]){
        return;
    }



    int m=(l+r)>>1;

    //pushdown(rt,m-l+1,r-m);//必须下推标记，因为有pushup

    if(L <= m) //与查询同理
        update(L,R,l,m,rt<<1);
    if(R >  m)
        update(L,R,m+1,r,rt<<1|1);

    pushup(rt);//更新本节点信息
}



//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
ll query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)//如果当前区间在查询区间内，直接返回当前存的值
        return tree[rt];

    int m=(l+r)>>1;

    //每次查询都下推标记，保证值正确
    // pushdown(rt,m-l+1,r-m);

    //累加求答案
    ll ANS=0;
    if(L<=m)//如果左子区间与[L,R]有重叠，就递归左子树，右子树同理。
        ANS=(ANS+query(L,R,l,m,rt<<1));
    if(R>m)
        ANS=(ANS+query(L,R,m+1,r,rt<<1|1));
    return ANS;
}



int main(){
    int n,q;
int casenum=1;
    while(~scanf("%d",&n)){
printf("Case #%d:\n",casenum++);

        for(int i=1;i<=n;i++)
            scanf("%lld",&A[i]);

        build(1,n,1);

        scanf("%d",&q);

        for(int i=0;i<q;i++){
            int t,l,r;
            scanf("%d%d%d",&t,&l,&r);
            if(l>r)swap(l,r);

            if(t==0){

                        update(l,r,1,n,1);

            }
            else
                printf("%lld\n",query(l,r,1,n,1));
        }

printf("\n");
    }


    return 0;
}







