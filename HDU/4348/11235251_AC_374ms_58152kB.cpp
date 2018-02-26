#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

int lc[3000010];//左孩子
int rc[3000010];//右孩子
ll sum[3000010];//区间和
ll lazy[3000010];//懒惰标记
int n,m,cnt,x,y,z,now;

//原数组，第N次操作的根节点
int A[100010],T[100010];
char op[3];

//建一棵空树
void build(int &now,int l,int r){

    now=++cnt;
    if(l==r){
        sum[now]=A[l];
        return;
    }
    build(lc[now],l,(l+r)/2);
    build(rc[now],(l+r)/2+1,r);

    //push_up
    sum[now]=sum[lc[now]]+sum[rc[now]];
}

void add(int &now,int l,int r,int val,int L,int R){

    //新建一个节点，并初始化为前一棵线段树的节点的值
    cnt++;
    lc[cnt]=lc[now];
    rc[cnt]=rc[now];
    sum[cnt]=sum[now];
    lazy[cnt]=lazy[now];
    now=cnt;

    sum[now]+=1ll*val*(r-l+1);

    if(l==L&&r==R){
        lazy[now]+=val;//打上懒惰标记
        return;
    }
    if(r<=(L+R)/2)
        add(lc[now],l,r,val,L,(L+R)/2);
    else
        if(l>(L+R)/2)
            add(rc[now],l,r,val,(L+R)/2+1,R);
        else{
            add(lc[now],l,(L+R)/2,val,L,(L+R)/2);
            add(rc[now],(L+R)/2+1,r,val,(L+R)/2+1,R);
        }
}


ll query(int now,int l,int r,int L,int R){
    if(l==L&&r==R)
        return sum[now];

    ll tmp=1ll*(r-l+1)*lazy[now];//超级巧妙，不用下推了，直接算就对了！

    if(r<=(L+R)/2)
        return tmp+query(lc[now],l,r,L,(L+R)/2);

    if(l>(L+R)/2)
        return tmp+query(rc[now],l,r,(L+R)/2+1,R);

    return tmp+query(lc[now],l,(L+R)/2,L,(L+R)/2)+query(rc[now],(L+R)/2+1,r,(L+R)/2+1,R);
}

int main(){

    while(~scanf("%d%d",&n,&m)){
        now=cnt=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]);

        build(T[0],1,n);

        for(int i=1;i<=m;++i){
            scanf("%s",op);
            if(op[0]=='C'){
                scanf("%d%d%d",&x,&y,&z);
                ++now;
                add(T[now]=T[now-1],x,y,z,1,n);
            }
            else
                if(op[0]=='Q'){
                    scanf("%d%d",&x,&y);
                    printf("%I64d\n",query(T[now],x,y,1,n));
                }
                else
                    if(op[0]=='H'){
                        scanf("%d%d%d",&x,&y,&z);
                        printf("%I64d\n",query(T[z],x,y,1,n));
                    }
                    else
                        scanf("%d",&now);
        }
    }
}
