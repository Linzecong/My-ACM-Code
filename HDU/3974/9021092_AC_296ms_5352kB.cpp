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
const int maxn=50005;

int tree[maxn<<2];//线段树数组，看你要存什么




void build(int l,int r,int rt){
    tree[rt]=-1;
    if(l==r){
        return;
    }
    int m=(l+r)>>1;//>>1等于/2
    //递归建树
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}

//下推函数，ln,rn为左子树，右子树的数字数量。
void pushdown(int rt){


    //修改子节点的值
    tree[rt<<1]=tree[rt<<1|1]=tree[rt];

    //清除标记
    tree[rt]=-1;

}


//区间修改，比点修改多了个R参数，这里是区间+C，与查询同理，在查询时修改
void update(int L,int R,int C, int l, int r, int rt){
    if(L<=l&&r<=R){//如果当前区间在查询区间内，直接对其进行修改
        tree[rt]=C;//C*当前区间含有的数字个数
        return;
    }

    int m=(l+r)>>1;

    if(tree[rt]!=-1)
        pushdown(rt);

    if(L <= m) //与查询同理
        update(L,R,C,l,m,rt<<1);
    if(R >  m)
        update(L,R,C,m+1,r,rt<<1|1);

}



//查询，这里为求最值,LR代表要查询的区间,lr代表当前区间，rt表示当前节点在数组中的实际位置
int query(int L,int R,int l,int r,int rt){

    if(l==r)
        return tree[rt];

    int m=(l+r)>>1;

    //每次查询都下推标记，保证值正确
    if(tree[rt]!=-1)
    pushdown(rt);


    if(L<=m)
    return query(L,R,l,m,rt<<1);
    else
    return query(L,R,m+1,r,rt<<1|1);


}



struct node{
    int parent=0;
    vector<int> childs;
};

int li[maxn],ri[maxn];

int len=1;

void dfs(int cn,node* tn){
    li[cn]=len;
    for(int i=0;i<tn[cn].childs.size();i++){
        dfs(tn[cn].childs[i],tn);
    }
    ri[cn]=len++;
}



int main(){

    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++){

        printf("Case #%d:\n",qqq);
    int n,q;


    scanf("%d",&n);


    len=1;


    node* tn=new node[n+1];


    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        tn[b].childs.push_back(a);
        tn[a].parent=b;
    }

    for(int i=1;i<=n;i++){
        if(tn[i].parent==0){
            dfs(i,tn);
            break;
        }
    }

    build(1,len,1);



    scanf("%d",&q);

    for(int i=0;i<q;i++){
        char c[10];

        scanf("%s",c);

        if(c[0]=='C'){
            int temp;
            scanf("%d",&temp);
            printf("%d\n",query(ri[temp],ri[temp],1,len,1));
        }
        else{
            int temp,col;
            scanf("%d%d",&temp,&col);
            update(li[temp],ri[temp],col,1,len,1);
        }
    }




    }


    return 0;
}







