#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const int MAXN = 200050;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int nowD;//当前排序的维度
struct  node{
    int Min[3],Max[3];//这个点所维护的块内，离这个点最远的值和最近的值
    int d[3];//这个点的坐标
    int l,r;//这个块所维护的点的区间

    int s,pre,nxt;//这个点的值，第一个相同的前驱坐标，第一个相同的后继坐标
    int smax;//这个点所代表的块内，最大的值
    int id;
    friend bool operator <(const node &a,const node &b){
        return a.d[nowD] < b.d[nowD];
    }
}t[MAXN];

int DIM=3;//维度数


void pushup(int now)   //由子节点控制范围来更新now点的控制范围
{
    for(int i =0;i<DIM;i++){
        if(t[now].l)
        {
            if(t[t[now].l].Max[i]>t[now].Max[i]) t[now].Max[i]=t[t[now].l].Max[i];
            if(t[t[now].l].Min[i]<t[now].Min[i]) t[now].Min[i]=t[t[now].l].Min[i];
            t[now].smax=max(t[now].smax,t[t[now].l].smax);
        }
        if(t[now].r)
        {
            if(t[t[now].r].Max[i]>t[now].Max[i]) t[now].Max[i]=t[t[now].r].Max[i];
            if(t[t[now].r].Min[i]<t[now].Min[i]) t[now].Min[i]=t[t[now].r].Min[i];
            t[now].smax=max(t[now].smax,t[t[now].r].smax);
        }
    }

}

int build(int l,int r,int D)   //kd树的建立
{
    int mid=(l+r)>>1;
    nowD=D;
    nth_element(t+l,t+mid,t+r+1);//类似快排，快排后，左边的都比mid小，右边的都比mid大，这样就可以正确的递归了
    if(l!=mid) t[mid].l=build(l,mid-1,(D+1)%DIM);else t[mid].l=0;//递归
    if(r!=mid) t[mid].r=build(mid+1,r,(D+1)%DIM);else t[mid].r=0;
    for(int i=0;i<DIM;i++){
        t[mid].Max[i]=t[mid].Min[i]=t[mid].d[i];//初始化
        t[mid].smax=t[mid].s;
    }

    pushup(mid);//更新
    return mid;
}

int ql,qr,ans;//查询的区间和答案

//检查这一块是否可能存在答案
bool check(int p){
    if(p==0)
        return false;
    //如果这一块所代表的点的极值坐标都不在查询区间内，那么这一块不可能存在答案
    if(t[p].Max[0]<ql||t[p].Min[0]>qr) return false;
    //如果这一块的最小前缀都比ql大，最大的后缀都比qr小，那么这一块不可能存在答案
    if(t[p].Min[1]>=ql||t[p].Max[2]<=qr) return false;
    return true;
}

void query_MAX(int p)
{
    //判断这一块的最值是否符合要求，符合的话直接返回
    if(t[p].Min[0]>=ql&&t[p].Max[0]<=qr&&t[p].Max[1]<ql&&t[p].Min[2]>qr){
        ans=max(ans,t[p].smax);
        return;
    }

    //计算这个点对答案的贡献
    if(t[p].id>=ql && t[p].id<=qr && t[p].pre<ql && t[p].nxt>qr)
        ans=max(ans,t[p].s);

    //A*搜索
    int ld=t[t[p].l].smax;
    int rd=t[t[p].r].smax;
    if(ld>rd){
        if(t[p].l && ld>ans && check(t[p].l))//双重剪枝暴力搜索
            query_MAX(t[p].l);
        if(t[p].r && rd>ans && check(t[p].r))
            query_MAX(t[p].r);
    }
    else{
        if(t[p].r && rd>ans && check(t[p].r))
            query_MAX(t[p].r);
        if(t[p].l && ld>ans && check(t[p].l))
            query_MAX(t[p].l);
    }

}

int a[MAXN];
int pre[MAXN],nxt[MAXN];
int lastans;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=N;i++){
        t[i].pre=t[i].d[1]=pre[a[i]];
        pre[a[i]]=i;
    }
    memset(nxt,0x3f,sizeof(nxt));
    for(int i=N;i>=1;i--){
        t[i].nxt=t[i].d[2]=nxt[a[i]];
        nxt[a[i]]=i;
    }
    for(int i=1;i<=N;i++)
        t[i].s=a[i],t[i].id=t[i].d[0]=i;
    int rt=build(1,N,0);
    lastans=0;
    int x,y;
    while(M--){
        scanf("%d%d",&x,&y);
        ql=min((x+lastans)%N+1,(y+lastans)%N+1);
        qr=max((x+lastans)%N+1,(y+lastans)%N+1);
        ans=0;
        query_MAX(rt);
        printf("%d\n",ans);
        lastans=ans;
    }

    return 0;
}










