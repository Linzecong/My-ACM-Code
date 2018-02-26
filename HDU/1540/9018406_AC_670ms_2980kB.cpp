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
const int MAXN=50010;

int treemini[MAXN<<2];
int treemaxi[MAXN<<2];

int A[MAXN];


//更新节点信息，这里是求最值
void pushup(int rt){

    if(treemini[rt<<1]!=0&&treemini[rt<<1|1]!=0)
        treemini[rt]=min(treemini[rt<<1],treemini[rt<<1|1]);
    else{

        treemini[rt]=max(treemini[rt<<1|1],treemini[rt<<1]);

    }



    treemaxi[rt]=max(treemaxi[rt<<1],treemaxi[rt<<1|1]);

}

//建树
void build(int l,int r,int rt){//l,r表示当前区间，rt表示当前区间在线段树数组中的位置
    treemini[rt]=0;
    treemaxi[rt]=0;
    if(l==r){//若到达叶子结点
        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);//建完左右子树后，更新当前节点的值
}


void update(int L,int C,int l,int r,int rt){
    if(l==r){//若到达叶节点，则修改叶节点的值
        treemini[rt]=C;
        treemaxi[rt]=C;
        A[l]=C;
        return;
    }
    int m=(l+r)>>1;


    //根据L判断是往哪个子树递归修改
    if(L<=m)
        update(L,C,l,m,rt<<1);//左子树
    else
        update(L,C,m+1,r,rt<<1|1);//右子树

    pushup(rt);//子节点更新完了，那么可以更新自己了，即从下而上修改，建树同理
}




//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
int querymax(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)//如果当前区间在查询区间内，直接返回当前存的值
        return treemaxi[rt];

    int m=(l+r)>>1;


    int ANS=-1;
    if(L<=m)//如果左子区间与[L,R]有重叠，就递归左子树，右子树同理。
        ANS=max(ANS,querymax(L,R,l,m,rt<<1));
    if(R>m)
        ANS=max(ANS,querymax(L,R,m+1,r,rt<<1|1));
    return ANS;
}

int querymin(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)//如果当前区间在查询区间内，直接返回当前存的值
        return treemini[rt];

    int m=(l+r)>>1;


    int ANS=0;
    if(L<=m){
        int temp=querymin(L,R,l,m,rt<<1);
        if(ANS!=0&&temp!=0)
            ANS=min(ANS,temp);
        else
            ANS=max(ANS,temp);
    }
    if(R>m){
        int temp=querymin(L,R,m+1,r,rt<<1|1);
        if(ANS!=0&&temp!=0)
            ANS=min(ANS,temp);
        else
            ANS=max(ANS,temp);
    }
    return ANS;
}



int main(){
    int n,q;


    while(~scanf("%d%d",&n,&q)){
    build(1,n,1);
    memset(A,0,sizeof(A));


    stack<int> st;
    for(int i=0;i<q;i++){
        char c[5];
        int temp;
        scanf("%s",c);
        if(c[0]=='D')
        {
            scanf("%d",&temp);
            update(temp,temp,1,n,1);
            st.push(temp);



        }

        if(c[0]=='Q'){
            scanf("%d",&temp);

            if(A[temp]!=0)
                printf("%d\n",0);
            else{

            int l=querymax(1,temp,1,n,1);
            int r=querymin(temp,n,1,n,1);



            if(r==0)
                r=n;
            else
                r--;

            printf("%d\n",r-l);
            }

        }

        if(c[0]=='R'){
            temp=st.top();
            update(temp,0,1,n,1);
            st.pop();


        }





    }

}


    return 0;
}







