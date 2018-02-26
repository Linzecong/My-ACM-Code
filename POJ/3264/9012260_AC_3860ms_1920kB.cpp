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
const int MAXN=50010;

int treemax[MAXN<<2];
int treemin[MAXN<<2];
int A[MAXN];

void pushup(int rt){
    treemax[rt]=max(treemax[rt<<1],treemax[rt<<1|1]);
    treemin[rt]=min(treemin[rt<<1],treemin[rt<<1|1]);
}



void build(int l,int r,int rt){

    if(l==r){
        treemax[rt]=A[l];
        treemin[rt]=A[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}



int querymax(int L,int R,int l,int r,int rt){

    if(l>=L&&r<=R){
        return treemax[rt];
    }

    int m=(l+r)/2;

    int ANS=-1;
    if(L<=m)
    ANS=max(ANS,querymax(L,R,l,m,rt<<1));

    if(R>m)
    ANS=max(ANS,querymax(L,R,m+1,r,rt<<1|1));
    return ANS;
}

int querymin(int L,int R,int l,int r,int rt){

    if(l>=L&&r<=R){
        return treemin[rt];
    }

    int m=(l+r)/2;

    int ANS=1000005;
    if(L<=m)
    ANS=min(ANS,querymin(L,R,l,m,rt<<1));

    if(R>m)
    ANS=min(ANS,querymin(L,R,m+1,r,rt<<1|1));
    return ANS;
}


int main(){
    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);

    build(1,n,1);

    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",querymax(l,r,1,n,1)-querymin(l,r,1,n,1));
    }


    return 0;
}







