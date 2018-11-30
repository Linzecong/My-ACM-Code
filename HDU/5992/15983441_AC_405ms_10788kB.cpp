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

struct  node{
    int Min[3],Max[3];
    int d[3];
    int l,r;
    int id;
}t[MAXN];

int nowD;

int ans;
ll dist;

int x,y,c;//查询的坐标
//查询xy这个点与P所控制的范围的距离
ll getdist(int p){
    if(t[p].Min[2]>c)
        return INF;
    ll dis=0;
    if(x<t[p].Min[0]) dis+=1ll*(t[p].Min[0]-x)*(t[p].Min[0]-x);
    if(x>t[p].Max[0]) dis+=1ll*(t[p].Max[0]-x)*(t[p].Max[0]-x);
    if(y<t[p].Min[1]) dis+=1ll*(t[p].Min[1]-y)*(t[p].Min[1]-y);
    if(y>t[p].Max[1]) dis+=1ll*(t[p].Max[1]-y)*(t[p].Max[1]-y);
    return dis;
}

inline bool cmp(node a, node b)
{
    if (a.d[nowD] == b.d[nowD])
        return a.d[!nowD] < b.d[!nowD];
    return a.d[nowD] < b.d[nowD];
}
void kd_updata(int now)   //由子节点控制范围来更新now点的控制范围
{
    if(t[now].l)
    {
        if(t[t[now].l].Max[0]>t[now].Max[0]) t[now].Max[0]=t[t[now].l].Max[0];
        if(t[t[now].l].Max[1]>t[now].Max[1]) t[now].Max[1]=t[t[now].l].Max[1];
        if(t[t[now].l].Max[2]>t[now].Max[2]) t[now].Max[2]=t[t[now].l].Max[2];
        if(t[t[now].l].Min[0]<t[now].Min[0]) t[now].Min[0]=t[t[now].l].Min[0];
        if(t[t[now].l].Min[1]<t[now].Min[1]) t[now].Min[1]=t[t[now].l].Min[1];
        if(t[t[now].l].Min[2]<t[now].Min[2]) t[now].Min[2]=t[t[now].l].Min[2];
    }
    if(t[now].r)
    {
        if(t[t[now].r].Max[0]>t[now].Max[0]) t[now].Max[0]=t[t[now].r].Max[0];
        if(t[t[now].r].Max[1]>t[now].Max[1]) t[now].Max[1]=t[t[now].r].Max[1];
        if(t[t[now].r].Max[2]>t[now].Max[2]) t[now].Max[2]=t[t[now].r].Max[2];
        if(t[t[now].r].Min[0]<t[now].Min[0]) t[now].Min[0]=t[t[now].r].Min[0];
        if(t[t[now].r].Min[1]<t[now].Min[1]) t[now].Min[1]=t[t[now].r].Min[1];
        if(t[t[now].r].Min[2]<t[now].Min[2]) t[now].Min[2]=t[t[now].r].Min[2];
    }
}

int kd_build(int l,int r,int D)   //kd树的建立
{
    int mid=(l+r)>>1;
    nowD=D;
    nth_element(t+l,t+mid,t+r+1,cmp);
    if(l!=mid) t[mid].l=kd_build(l,mid-1,(D+1)%3);else t[mid].l=0;
    if(r!=mid) t[mid].r=kd_build(mid+1,r,(D+1)%3);else t[mid].r=0;
    t[mid].Max[0]=t[mid].Min[0]=t[mid].d[0];
    t[mid].Max[1]=t[mid].Min[1]=t[mid].d[1];
    t[mid].Max[2]=t[mid].Min[2]=t[mid].d[2];
    kd_updata(mid);
    return mid;
}

void kd_query(int p)   //查询
{
    ll dl=INF,dr=INF,d0=INF;
    if(t[p].d[2]<=c) d0=1ll*(t[p].d[0]-x)*(t[p].d[0]-x)+1ll*(t[p].d[1]-y)*(t[p].d[1]-y);
    if(d0<dist||d0==dist&&t[p].id<t[ans].id)
    {
        ans=p;
        dist=d0;
    }
    if(t[p].l) dl=getdist(t[p].l);
    if(t[p].r) dr=getdist(t[p].r);
    if(dl<dr)
    {
        if(dl<=dist) kd_query(t[p].l);
        if(dr<=dist) kd_query(t[p].r);
    }
    else
    {
        if(dr<=dist) kd_query(t[p].r);
        if(dl<=dist) kd_query(t[p].l);
    }
}



int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++){
            scanf("%d%d%d",&t[i].d[0],&t[i].d[1],&t[i].d[2]);
            t[i].id=i;
        }
        int rt=kd_build(1,N,0);
        while(M--){
            ans=0;
            dist=INF;
            scanf("%d%d%d",&x,&y,&c);
            kd_query(rt);
            printf("%d %d %d\n",t[ans].d[0],t[ans].d[1],t[ans].d[2]);
        }
    }




    return 0;
}



