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
using namespace std;
typedef long long ll;
const int maxn=200005;

int sum[maxn<<2];//最大的区间
int leftlen[maxn<<2];//从左往右最大的区间
int rightlen[maxn<<2];//从右往左最大的区间

int A[maxn];


void pushup(int rt,int len){
    leftlen[rt]=leftlen[rt<<1];
    rightlen[rt]=rightlen[rt<<1|1];

    if(leftlen[rt<<1]==len-(len/2))
        leftlen[rt]=leftlen[rt<<1]+leftlen[rt<<1|1];
    if(rightlen[rt<<1|1]==len/2)
        rightlen[rt]=rightlen[rt<<1|1]+rightlen[rt<<1];

    sum[rt]=max(rightlen[rt<<1]+leftlen[rt<<1|1],max(sum[rt<<1],sum[rt<<1|1]));
    //从中间到两边最大，左边最大，右边最大
}

void build(int l,int r,int rt){
    if(l==r){
        sum[rt]=leftlen[rt]=rightlen[rt]=1;//一开始全连续
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt,r-l+1);
}

void update(int L,int C,int l,int r,int rt){
    if(l==r){
        sum[rt]=leftlen[rt]=rightlen[rt]=C;//设置断点标志
        return;
    }
    int m=(l+r)/2;
    if(L<=m)
        update(L,C,l,m,rt<<1);
    else
        update(L,C,m+1,r,rt<<1|1);
    pushup(rt,r-l+1);
}

//查询包含该点的最大连续区间
int query(int P,int l,int r,int rt){
    if(l==r)
        return sum[rt];

    int m=(l+r)/2;

    if(P<=m){
        if(P+rightlen[rt<<1]>m)//如果在连续区间内
            return rightlen[rt<<1]+leftlen[rt<<1|1];
        else
            return query(P,l,m,rt<<1);
    }
    else{
        if(m+leftlen[rt<<1|1]>=P)
            return leftlen[rt<<1|1]+rightlen[rt<<1];
        else
            return query(P,m+1,r,rt<<1|1);
    }

}


int main(){
    int n,m;

    while(~scanf("%d%d",&n,&m)){
        build(1,n,1);

        int tot=0;

        while(m--){
            char op[10];
            scanf("%s",op);

            if(op[0]=='Q'){
                int x;
                scanf("%d",&x);
                printf("%d\n",query(x,1,n,1));
            }
            else if(op[0]=='D'){
                int x;
                scanf("%d",&x);
                A[++tot]=x;
                update(x,0,1,n,1);
            }
            else{
                int x=A[tot--];
                update(x,1,1,n,1);
            }
        }
    }
    return 0;

}


