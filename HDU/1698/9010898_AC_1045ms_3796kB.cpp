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

int tree[MAXN<<2];
int Add[MAXN<<2];

void pushup(int rt){


    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

void build(int l,int r,int rt){
    Add[rt]=-1;
    if(l==r){
        tree[rt]=1;

        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);

}

void pushdown(int rt,int n){
    if(Add[rt]!=-1){
        Add[rt<<1]=Add[rt];
        Add[rt<<1|1]=Add[rt];

        tree[rt<<1]=(n-n/2)*Add[rt];
        tree[rt<<1|1]=(n/2)*Add[rt];

        Add[rt]=-1;
    }
}



void update(int L,int R,int C, int l, int r, int rt){
    if(L<=l&&r<=R){
        tree[rt]=C*(r-l+1);
        Add[rt]=C;
        return;
    }

    int m=(l+r)/2;

    pushdown(rt,r-l+1);

    if(L<=m)
        update(L,R,C,l,m,rt<<1);

    if(R>m)
        update(L,R,C,m+1,r,rt<<1|1);
    pushup(rt);
}





int main(){
    int t;
    scanf("%d",&t);
    int n;

    for(int aaa=0;aaa<t;aaa++){

        scanf("%d",&n);
        build(1,n,1);

        int q;
        scanf("%d",&q);

        for(int i=0;i<q;i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            update(a,b,w,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",aaa+1,tree[1]);



    }


    return 0;
}







