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
    int Min[10],Max[10];//这个点所维护的块内，离这个点最远的点和最近的点
    int d[10];//这个点的坐标
    int l,r;//这个块所维护的点的区间
    ll dis;
    friend bool operator <(const node &a,const node &b){
        return a.dis < b.dis;
    }
}t[MAXN];

int DIM=2;//维度数
int nowD;//当前排序的维度
bool cmp(const node &a,const node &b){
    return a.d[nowD] < b.d[nowD];
}

void pushup(int now)   //由子节点控制范围来更新now点的控制范围
{
    for(int i =0;i<DIM;i++){
        if(t[now].l)
        {
            if(t[t[now].l].Max[i]>t[now].Max[i])
                t[now].Max[i]=t[t[now].l].Max[i];
            if(t[t[now].l].Min[i]<t[now].Min[i])
                t[now].Min[i]=t[t[now].l].Min[i];
        }
        if(t[now].r)
        {
            if(t[t[now].r].Max[i]>t[now].Max[i])
                t[now].Max[i]=t[t[now].r].Max[i];
            if(t[t[now].r].Min[i]<t[now].Min[i])
                t[now].Min[i]=t[t[now].r].Min[i];
        }
    }

}

int build(int l,int r,int D)   //kd树的建立
{
    if(r<l)
        return 0;
    int mid=(l+r)>>1;
    nowD=D;
    nth_element(t+l,t+mid,t+r+1,cmp);//类似快排，快排后，左边的都比mid小，右边的都比mid大，这样就可以正确的递归了
    t[mid].l=build(l,mid-1,(D+1)%DIM);
    t[mid].r=build(mid+1,r,(D+1)%DIM);
    pushup(mid);//更新
    return mid;
}

//计算x到p这一块的最短距离，用于A*剪枝
ll getdist_min(int p,node x){
    ll dis=0;
    for(int i=0;i<DIM;i++){
        if(x.d[i]<t[p].Min[i]) dis+=1ll*(t[p].Min[i]-x.d[i])*(t[p].Min[i]-x.d[i]);
        if(x.d[i]>t[p].Max[i]) dis+=1ll*(x.d[i]-t[p].Max[i])*(x.d[i]-t[p].Max[i]);
    }
    return dis;
}

int M;
priority_queue<node> que;
void query_min(int p, node x)
{

    /***计算x到p这个点的距离***/
    t[p].dis=0;
    for(int i=0;i<DIM;i++)
        t[p].dis+=1ll*(x.d[i]-t[p].d[i])*(x.d[i]-t[p].d[i]);

    if(que.size()<M){
        que.push(t[p]);
    }
    else{
        if(t[p].dis<que.top().dis){
            que.pop();
            que.push(t[p]);
        }
    }



    ll ld=t[p].l ? getdist_min(t[p].l,x):INF;
    ll rd=t[p].r ? getdist_min(t[p].r,x):INF;

    if(min(ld,rd)>que.top().dis&&que.size()>=M)
        return;

    if(ld<rd){
        if(ld<que.top().dis||que.size()<M)
            query_min(t[p].l,x);
        if(rd<que.top().dis||que.size()<M)
            query_min(t[p].r,x);
    }
    else{
        if(rd<que.top().dis||que.size()<M)
            query_min(t[p].r,x);
        if(ld<que.top().dis||que.size()<M)
            query_min(t[p].l,x);
    }

}

node ans[15];

int main()
{

    int N;
    while(~scanf("%d%d",&N,&DIM)){

        for(int i=1;i<=N;i++){
            for(int j=0;j<DIM;j++){
                scanf("%d",&t[i].d[j]);
                t[i].Min[j] = t[i].Max[j] = t[i].d[j];
                t[i].l = t[i].r = 0;
            }

        }

        int rt=build(1,N,0);
        int Q;
        scanf("%d",&Q);
        node tmp;
        while(Q--){
            for(int i=0;i<DIM;i++)
                scanf("%d",&tmp.d[i]);
            scanf("%d",&M);

            query_min(rt,tmp);

            printf("the closest %d points are:\n",M);
            for(int i=M;i>=1;i--){
                ans[i] = que.top();
                que.pop();
            }

            for(int i=1;i<=M;i++){
                for(int j=0;j<DIM-1;j++)
                    printf("%d ",ans[i].d[j]);
                printf("%d\n",ans[i].d[DIM-1]);
            }

        }

    }

    return 0;
}



