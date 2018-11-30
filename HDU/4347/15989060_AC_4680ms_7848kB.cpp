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
    int Min[10],Max[10];//这个点所维护的块内，离这个点最远的点和最近的点
    int d[10];//这个点的坐标
    int l,r;//这个块所维护的点的区间
    int id;
    friend bool operator <(const node &a,const node &b){
        return a.d[nowD] < b.d[nowD];
    }
}t[MAXN];

int DIM=2;//维度数


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
    nth_element(t+l,t+mid,t+r+1);//类似快排，快排后，左边的都比mid小，右边的都比mid大，这样就可以正确的递归了
    if(l!=mid) t[mid].l=build(l,mid-1,(D+1)%DIM);else t[mid].l=0;//递归
    if(r!=mid) t[mid].r=build(mid+1,r,(D+1)%DIM);else t[mid].r=0;
    for(int i=0;i<DIM;i++)
        t[mid].Max[i]=t[mid].Min[i]=t[mid].d[i];//初始化

    pushup(mid);//更新
    return mid;
}

//计算x到p这一块的最短距离，用于A*剪枝
ll getdist_min(int p,node x){
    ll dis=0;
    for(int i=0;i<DIM;i++){
        if(x.d[i]<t[p].Min[i]) dis+=ll(t[p].Min[i]-x.d[i])*ll(t[p].Min[i]-x.d[i]);
        if(x.d[i]>t[p].Max[i]) dis+=ll(x.d[i]-t[p].Max[i])*ll(x.d[i]-t[p].Max[i]);
    }
    return dis;
}

int M;
priority_queue<pair<ll,node> > que;
void query_min(int p, node x)
{
    /***计算x到p这个点的距离***/
    ll dis=0;
    for(int i=0;i<DIM;i++)
        dis+=ll(x.d[i]-t[p].d[i])*ll(x.d[i]-t[p].d[i]);

    if(que.size()==M){
        if(dis<que.top().first){
            que.pop();
            que.push(make_pair(dis,t[p]));
        }
    }
    else
        que.push(make_pair(dis,t[p]));


    ll ld=t[p].l ? getdist_min(t[p].l,x):INF;
    ll rd=t[p].r ? getdist_min(t[p].r,x):INF;

    if(min(ld,rd)>que.top().first&&que.size()==M)
        return;

    if(ld<rd){
        if(ld<que.top().first||que.size()<M)
            query_min(t[p].l,x);
        if(rd<que.top().first||que.size()<M)
            query_min(t[p].r,x);
    }
    else{
        if(ld<que.top().first||que.size()<M)
            query_min(t[p].l,x);
        if(rd<que.top().first||que.size()<M)
            query_min(t[p].r,x);
    }

}

int ans[15][10];

int main()
{

    int N;
    while(~scanf("%d%d",&N,&DIM)){
        for(int i=1;i<=N;i++)
            for(int j=0;j<DIM;j++)
                scanf("%d",&t[i].d[j]);

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
            for(int i=0;i<M;i++){
                pair<ll,node> tp = que.top();
                que.pop();
                for(int j=0;j<DIM;j++)
                    ans[M-i-1][j]=tp.second.d[j];
            }

            for(int i=0;i<M;i++){
                for(int j=0;j<DIM-1;j++)
                    printf("%d ",ans[i][j]);
                printf("%d\n",ans[i][DIM-1]);
            }

        }

    }

    return 0;
}


