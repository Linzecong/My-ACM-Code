#include<iostream>
#include<string.h>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=100105;
int N,M;
int fa[MAXN];
int C[MAXN];
int dep[MAXN];

//学习一下结构体写法……
struct Node{
    int ls,rs,val;
}node[MAXN*110];
int tot;

int root1[MAXN];//每个深度的颜色数
int root2[MAXN];//每个颜色最浅的那个位置

int update(int P,int C,int l,int r,int rt){
    int nrt=++tot;
    node[nrt].val=node[rt].val+C;
    if(l==r)
        return nrt;
    int m=(l+r)/2;
    if(P<=m){
        node[nrt].ls=update(P,C,l,m,node[rt].ls);
        node[nrt].rs=node[rt].rs;
    }
    else{
        node[nrt].ls=node[rt].ls;
        node[nrt].rs=update(P,C,m+1,r,node[rt].rs);
    }
    return nrt;
}

int merge1(int r1,int r2,int l,int r){
    if(r1==0||r2==0)
        return r1+r2;
    int nrt=++tot;
    node[nrt].val=node[r1].val+node[r2].val;
    if(l==r)
        return nrt;
    int m=(l+r)/2;
    node[nrt].ls=merge1(node[r1].ls,node[r2].ls,l,m);
    node[nrt].rs=merge1(node[r1].rs,node[r2].rs,m+1,r);
    return nrt;
}

int merge2(int r1,int r2,int l,int r,int u){
    if(r1==0||r2==0)
        return r1+r2;
    int nrt=++tot;

    if(l==r){
        if(node[r1].val>node[r2].val){
            node[nrt].val=node[r2].val;
            root1[u]=update(node[r1].val,-1,1,N,root1[u]);
        }
        else{
            node[nrt].val=node[r1].val;
            root1[u]=update(node[r2].val,-1,1,N,root1[u]);
        }
        return nrt;
    }
    int m=(l+r)/2;
    node[nrt].ls=merge2(node[r1].ls,node[r2].ls,l,m,u);
    node[nrt].rs=merge2(node[r1].rs,node[r2].rs,m+1,r,u);
    return nrt;
}

int query(int P,int l,int r,int rt){
    if(!rt)
        return 0;
    if(r<=P)
        return node[rt].val;
    int m=(l+r)/2;
    int ans=query(P,l,m,node[rt].ls);
    if(P>=m+1)
        ans+=query(P,m+1,r,node[rt].rs);
    return ans;
}




int main(){
    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        tot=0;
        scanf("%d%d",&N,&M);

        for(int i=1;i<=N;i++)
            scanf("%d",&C[i]);
        for(int i=2;i<=N;i++)
            scanf("%d",&fa[i]);


        dep[1]=1;for (int i=2;i<=N;i++) dep[i]=dep[fa[i]]+1;//得到深度
        for (int i=1;i<=N;i++)//初始化每一棵线段树
        {
            root1[i]=update(dep[i],1,1,N,0);//注意这里的0
            root2[i]=update(C[i],dep[i],1,N,0);
        }
        for (int i=N;i>=2;i--)//把子树信息合并
        {
            root1[fa[i]]=merge1(root1[fa[i]],root1[i],1,N);
            root2[fa[i]]=merge2(root2[fa[i]],root2[i],1,N,fa[i]);
        }

        int lastans=0;
        for(int i=1;i<=M;i++){
            int u,d;
            scanf("%d%d",&u,&d);
            u^=lastans;
            d^=lastans;
            printf("%d\n",lastans=query(min(dep[u]+d,N),1,N,root1[u]));
        }

    }

    return 0;
}

