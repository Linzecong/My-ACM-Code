#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=100000;


int tree[MAXN<<2];
int A[MAXN];

void pushup(int rt){
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

void build(int l,int r,int rt){
    if(l==r){
    tree[rt]=A[l];
    return;
}

int m=(r+l)/2;

build(l,m,rt<<1);
build(m+1,r,rt<<1|1);

pushup(rt);

}

void update(int L,int C,int l,int r,int rt){
    if(l==r){
        tree[rt]+=C;
        A[l]+=C;
        return;
    }

    int m=(r+l)/2;

    if(L<=m)
        update(L,C,l,m,rt<<1);
    else
        update(L,C,m+1,r,rt<<1|1);

    pushup(rt);
}


int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)
        return tree[rt];

    int m=(r+l)/2;
    int ANS=0;

    if(L<=m)
        ANS=ANS+query(L,R,l,m,rt<<1);

    if(R>m)
        ANS=ANS+query(L,R,m+1,r,rt<<1|1);

    return ANS;

}





















int main()
{
   int t;

   scanf("%d",&t);

   for(int qqq=1;qqq<=t;qqq++){
       printf("Case %d:\n",qqq);

       int n;
       scanf("%d",&n);

       for(int i=1;i<=n;i++){
           scanf("%d",&A[i]);
       }

       build(1,n,1);

       char c[10];


       scanf("%s",c);

       while(c[0]!='E'){
           int a,b;
           scanf("%d%d",&a,&b);

           if(c[0]=='Q'){
               printf("%d\n",query(a,b,1,n,1));
           }

           if(c[0]=='A'){
               update(a,b,1,n,1);
           }

           if(c[0]=='S'){
               update(a,-b,1,n,1);
           }


           scanf("%s",c);
       }





   }





    return 0;
}
