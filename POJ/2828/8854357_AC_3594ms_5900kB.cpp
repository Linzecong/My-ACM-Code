#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=200005;

int tree[maxn<<2];//线段树数组，存有多少个人

int ans[maxn<<2];//原数组，下标1~n

struct{
    int i;
    int val;
}pp[maxn];

//更新节点信息，这里是求和
void pushup(int rt){
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

void build(int l,int r,int rt){
tree[rt]=r-l+1;


    if(l==r){//若到达叶子结点

        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}


//区间修改，比点修改多了个R参数，这里是区间+C，与查询同理，在查询时修改
void update(int L,int l, int r, int rt,int val){

    if(r==l){//如果当前区间在查询区间内，直接对其进行修改
        tree[rt]--;
        ans[rt]=val;
        return;
    }

    int m=(l+r)>>1;

    if(L<=tree[rt<<1])
           update(L,l,m,rt<<1,val);//左子树
       else
           update(L-tree[rt<<1],m+1,r,rt<<1|1,val);//右子树

    pushup(rt);//更新本节点信息
}



void print(int l, int r, int rt)
{
    if(l == r){printf("%d ",ans[rt]);return;}
    int m=(l+r)>>1;
    print(l,m,rt<<1);
    print(m+1,r,rt<<1|1);
}


int main(){



    int n;

    while(~scanf("%d",&n)){



        build(1,n,1);

        for(int i=1;i<=n;i++){
            scanf("%d%d",&pp[i].i,&pp[i].val);
            pp[i].i++;
        }


        for(int i=n;i>=1;i--)
        {

            update(pp[i].i,1,n,1,pp[i].val);
        }


        print(1, n, 1);
        printf("\n");


    }

    return 0;
}
