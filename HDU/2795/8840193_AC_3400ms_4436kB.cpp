#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
const int maxn=200005;


int treeindex[maxn<<2];//线段树数组，最大剩余大小的下标
int A[maxn];//原数组，剩余大小，下标1~n


//更新节点信息，这里是求和
void pushup(int rt){
    treeindex[rt]=A[treeindex[rt<<1]]>A[treeindex[rt<<1|1]]?treeindex[rt<<1]:treeindex[rt<<1|1];
}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    if(l==r){//若到达叶子结点
        treeindex[rt]=l;
        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);//建完左右子树后，更新当前节点的值
}



int query(int L,int R,int len,int rt){

    if(L==R){
       A[L]-=len;
       return treeindex[rt];
    }

    int ll=0,rr=0;

    if(A[treeindex[rt<<1]]>=len){
        ll=query(L,(L+R)/2,len,rt<<1);
    }
    else{
        rr=query((L+R)/2+1,R,len,rt<<1|1);
    }

    pushup(rt);

    return ll+rr;
    
}




int main(){

    int h,w,n;

    while(cin>>h>>w>>n){

        int b=min(h,n);
        
        for(int i=1;i<=b;i++)
            A[i]=w;

        build(1,b,1);

        for(int i=0;i<n;i++){
            int len;
            scanf("%d",&len);

            if(A[treeindex[1]]<len)
                printf("%d\n",-1);
            else{
                int j=query(1,b,len,1);



                printf("%d\n",j);

            }
        }

    }




    return 0;
}
