#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define MAXV 2000005
#define INF (1LL<<62)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long int ll;

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

inline void scan_dll(ll &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

struct point{
    ll num;
    int index;
    point(ll a=0,int b=0){
        num=a;
        index=b;
    }
};

const int maxn=200005;
int n, q;
point tree[maxn<<2];//线段树数组，看你要存什么

ll A[maxn];//原数组，下标1~n

//更新节点信息，这里是求最值
void pushup(int rt){

    if(tree[rt<<1].num<tree[rt<<1|1].num){
        tree[rt]=tree[rt<<1];
    }
    else
        tree[rt]=tree[rt<<1|1];

}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    if(l==r){//若到达叶子结点
        tree[rt].num=A[l];//将该位置存原数组的值
        tree[rt].index=l;
        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);//建完左右子树后，更新当前节点的值
}








int findnearest(int L,int R,ll C,int l,int r,int rt){

    if(tree[rt].num>C)
        return -1;


    if(l==r){
        return tree[rt].num<=C?tree[rt].index:-1;
    }

    int m=(l+r)/2;

    int ans=-1;

    if(L<=m){
        if(tree[rt<<1].num<=C)
            ans=findnearest(L,R,C,l,m,rt<<1);
    }

    if(R>m && ans==-1){
        if(tree[rt<<1|1].num<=C)
            ans=findnearest(L,R,C,m+1,r,rt<<1|1);
    }

    return ans;
}


int main()
{


    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++){
        scan_dll(A[i]);
    }



    build(1,n,1);


    ll v;
    int l,r;
    int index;
    for(int i=0;i<q;i++){
        scan_dll(v);
        scan_d(l);
        scan_d(r);


        while(1){
            if(l==r){
                v%=A[l];
                printf("%lld\n",v);
                break;
            }

            index=findnearest(l,r,v,1,n,1);

            if(index==-1){
                printf("%lld\n",v);
                break;
            }
            else{
                v%=A[index];
                l=index+1;
            }
        }

    }




    return 0;
}







