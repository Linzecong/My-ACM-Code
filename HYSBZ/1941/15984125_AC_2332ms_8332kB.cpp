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
const int INF = 0x3f3f3f3f;

struct  node{
    int Min[2],Max[2];
    int d[2];
    int l,r;
    int id;
}t[MAXN];

int nowD;
int DIM=2;

inline bool cmp(node a, node b)
{
    if (a.d[nowD] == b.d[nowD])
        return a.d[!nowD] < b.d[!nowD];
    return a.d[nowD] < b.d[nowD];
}

void pushup(int now)   //由子节点控制范围来更新now点的控制范围
{
    for(int i =0;i<DIM;i++){
        if(t[now].l)
        {
            if(t[t[now].l].Max[i]>t[now].Max[i]) t[now].Max[i]=t[t[now].l].Max[i];
            if(t[t[now].l].Min[i]<t[now].Min[i]) t[now].Min[i]=t[t[now].l].Min[i];
        }
        if(t[now].r)
        {
            if(t[t[now].r].Max[i]>t[now].Max[i]) t[now].Max[i]=t[t[now].r].Max[i];
            if(t[t[now].r].Min[i]<t[now].Min[i]) t[now].Min[i]=t[t[now].r].Min[i];
        }
    }

}

int build(int l,int r,int D)   //kd树的建立
{
    int mid=(l+r)>>1;
    nowD=D;
    nth_element(t+l,t+mid,t+r+1,cmp);
    if(l!=mid) t[mid].l=build(l,mid-1,(D+1)%DIM);else t[mid].l=0;
    if(r!=mid) t[mid].r=build(mid+1,r,(D+1)%DIM);else t[mid].r=0;
    t[mid].Max[0]=t[mid].Min[0]=t[mid].d[0];
    t[mid].Max[1]=t[mid].Min[1]=t[mid].d[1];
    pushup(mid);
    return mid;
}

//计算x到p这一块的最短距离
int getdist_min(int p,node x){
    int dis=0;
    for(int i=0;i<DIM;i++){
        if(x.d[i]<t[p].Min[i]) dis+=t[p].Min[i]-x.d[i];
        if(x.d[i]>t[p].Max[i]) dis+=x.d[i]-t[p].Max[i];
    }
    return dis;
}

int _ans;
void _query_min(int p, node x)
{
    /***计算x到p这个点的距离***/
    int dis=0;
    for(int i=0;i<DIM;i++)
        dis+=abs(x.d[i]-t[p].d[i]);

    /***更新你的答案***/
    if(dis) _ans=min(_ans,dis);

    /***计算到左右两块的距离***/
    int ld=t[p].l ? getdist_min(t[p].l,x):INF;
    int rd=t[p].r ? getdist_min(t[p].r,x):INF;

    if(min(ld,rd)>=_ans)return; //剪枝

    /***A*搜索***/
    if(ld<rd){
        _query_min(t[p].l,x);
        if(rd<_ans)//剪枝
            _query_min(t[p].r,x);
    }
    else{
        _query_min(t[p].r,x);
        if(ld<_ans)//剪枝
            _query_min(t[p].l,x);
    }
}

int query_min(int p, node x){
    _ans=INF;
    _query_min(p,x);
    return _ans;
}


//计算x到k这一块的最大距离
int getdist_max(int k,node x){
    int dis=0;
    for(int i=0;i<DIM;i++)
        dis+=max(abs(t[k].Min[i]-x.d[i]),abs(t[k].Max[i]-x.d[i]));
    return dis;
}

void _query_max(int p,node x)   //查询
{
    int dis=0;
    for(int i=0;i<DIM;i++)
        dis+=abs(x.d[i]-t[p].d[i]);

    _ans=max(_ans,dis);

    int ld = t[p].l ? getdist_max(t[p].l,x) : -1, rd = t[p].r ? getdist_max(t[p].r,x) : -1;
    if (max(ld, rd) <= _ans) return;
    if (ld > rd)
    {
        _query_max(t[p].l,x);
        if (rd > _ans) _query_max(t[p].r,x);
    }
    else
    {
        _query_max(t[p].r,x);
        if (ld > _ans) _query_max(t[p].l,x);
    }

}
int query_max(int p,node x){
    _ans=0;
    _query_max(p,x);
    return _ans;
}


int main()
{

    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&t[i].d[0],&t[i].d[1]);
    }

    int ans=INF;
    int rt=build(1,N,0);
    for(int i=1;i<=N;i++){
        int a1=query_min(rt,t[i]);
        int a2=query_max(rt,t[i]);
        ans=min(ans,a2-a1);
    }
    printf("%d\n",ans);




    return 0;
}



