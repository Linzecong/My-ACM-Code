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
const int MAXN=100005;

ll tree[MAXN<<2];
ll Add[MAXN<<2];

ll A[MAXN];

void pushup(int rt){
    tree[rt]=(tree[rt<<1]+tree[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=A[l];
        return;
    }

    int m=(l+r)/2;

    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);

    pushup(rt);

}

void pushdown(int rt,int ln,int rn){
    if(Add[rt]){
        Add[rt<<1]+=Add[rt];
        Add[rt<<1|1]+=Add[rt];

        tree[rt<<1]+=Add[rt]*ln;
        tree[rt<<1|1]+=Add[rt]*rn;
        Add[rt]=0;
    }
}

void update(int L,ll C,int l,int r,int rt){
    if(l==r){
        tree[rt]+=C;
        A[l]+=C;
        return;
    }
    int m=(l+r)/2;

    pushdown(rt,m-l+1,r-m);

    if(L<=m)
        update(L,C,l,m,rt<<1);
    else
        update(L,C,m+1,r,rt<<1|1);
    pushup(rt);
}


void update(int L,int R,ll C, int l, int r, int rt){
    if(L<=l&&r<=R){
        tree[rt]+=C*(r-l+1);
        Add[rt]+=C;
        return;
    }

    int m=(l+r)/2;

    pushdown(rt,m-l+1,r-m);

    if(L<=m)
        update(L,R,C,l,m,rt<<1);

    if(R>m)
        update(L,R,C,m+1,r,rt<<1|1);
    pushup(rt);

}

ll query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)
        return tree[rt];

    int m=(l+r)/2;

    pushdown(rt,m-l+1,r-m);

    ll ANS=0;
    if(L<=m)
        ANS=ANS+query(L,R,l,m,rt<<1);
    if(R>m)
        ANS=ANS+query(L,R,m+1,r,rt<<1|1);
    return ANS;
}


int main(){


        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld",&A[i]);

        build(1,n,1);



        int a,b;
        ll c;
        char ct[10];

        for(int i=1;i<=m;i++){
            scanf("%s",ct);


            if(ct[0]=='Q'){
                scanf("%d%d",&a,&b);

                printf("%lld\n",query(a,b,1,n,1));

            }

            if(ct[0]=='C'){
                scanf("%d%d%lld",&a,&b,&c);
                update(a,b,c,1,n,1);
            }



        }

}






