#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=50004;

int maxindex[maxn<<2];
int minindex[maxn<<2];

int A[maxn];


void pushup(int rt){
    maxindex[rt]=A[maxindex[rt<<1]]>A[maxindex[rt<<1|1]]?maxindex[rt<<1]:maxindex[rt<<1|1];
    minindex[rt]=A[minindex[rt<<1]]>A[minindex[rt<<1|1]]?minindex[rt<<1|1]:minindex[rt<<1];
}


void build(int l,int r,int rt){
    if(l==r){
        maxindex[rt]=l;
        minindex[rt]=l;
        return;
    }
    int m=(l+r)>>1;

    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}



int query(int L,int R,int l,int r,int rt,bool max){
    if(L<=l&&r<=R){

        if(max)
            return maxindex[rt];
        else
            return minindex[rt];

    }


    int m=(l+r)>>1;


    if(max){
        int ANS=L;
        if(L<=m){
            int temp=query(L,R,l,m,rt<<1,max);
            ANS=A[ANS]>A[temp]?ANS:temp;
        }

        if(R>m){
            int temp=query(L,R,m+1,r,rt<<1|1,max);
            ANS=A[ANS]>A[temp]?ANS:temp;
        }
        return ANS;
    }
    else{
        int ANS=L;
        if(L<=m){
            int temp=query(L,R,l,m,rt<<1,max);
            ANS=A[ANS]>A[temp]?temp:ANS;
        }

        if(R>m){
            int temp=query(L,R,m+1,r,rt<<1|1,max);
            ANS=A[ANS]>A[temp]?temp:ANS;
        }
        return ANS;
    }
}








int main(){



    int n,m;

    cin>>n>>m;

        for(int i=1;i<=n;i++)
            scanf("%d",&A[i]);

        build(1,n,1);


        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",A[query(a,b,1,n,1,1)]-A[query(a,b,1,n,1,0)]);
        }



    return 0;
}
