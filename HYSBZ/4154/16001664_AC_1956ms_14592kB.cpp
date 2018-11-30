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
int DIM=2;//维度数
int nowD;//当前排序的维度
struct  node{
    int Min[2],Max[2];//这个点所维护的块内，离这个点最远的值和最近的值
    int d[2];//这个点的坐标
    int l,r;//这个块所维护的点的区间

    int col;
    int lazy;

    friend bool operator <(const node &a,const node &b){
        return a.d[nowD] < b.d[nowD];
    }

}t[MAXN];



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
    for(int i=0;i<DIM;i++){
        t[mid].Max[i]=t[mid].Min[i]=t[mid].d[i];//初始化
    }

    pushup(mid);//更新
    return mid;
}

int ql0,qr0;
int ql1,qr1;

//检查这一块是否可能存在答案
bool check(int p,node x){
    if(p==0)
        return false;
    if(t[p].Max[0]<x.Min[0]||t[p].Min[0]>x.Max[0]) return false;
    if(t[p].Max[1]<x.Min[1]||t[p].Min[1]>x.Max[1]) return false;
    return true;
//    int ans = 0;
//        for (int i = 0; i < DIM; i++)
//        {
//            int temp = 1;
//            if (x.Max[i] < t[p].Min[i] || x.Min[i] > t[p].Max[i]) temp = 0;
//            ans += temp;
//        }
//        if (ans == 2) return 1;
//        return 0;

}

void pushdown(int a){
    if(t[a].lazy!=-1){
        t[t[a].l].lazy=t[a].lazy;
        t[t[a].r].lazy=t[a].lazy;
        t[a].col=t[a].lazy;
        t[a].lazy=-1;
    }
}

bool check1(int p,node x){
    if(p==0)
        return false;
    if(t[p].Max[0]<x.d[0]||t[p].Min[0]>x.d[0]) return false;
    if(t[p].Max[1]<x.d[1]||t[p].Min[1]>x.d[1]) return false;
    return true;

//    if (x.d[0] <= t[p].Max[0] && t[p].Min[0] <= x.d[0] && x.d[1] <= t[p].Max[1] && t[p].Min[1] <= x.d[1]) return 1;
//        return 0;
}

node temp;

ll query(int p)
{
    pushdown(p);

    if(t[p].d[0]==temp.d[0]&&t[p].d[1]==temp.d[1])
        return t[p].col;

    if(!t[p].l&&!t[p].r)
        return -1;
    ll ans=-1;
    if(check1(t[p].l,temp))
            ans = query(t[p].l);

    if(ans!=-1)
            return ans;
    return query(t[p].r);

}



void update(int p){


    if(t[p].Min[0]>=temp.Min[0]&&t[p].Max[0]<=temp.Max[0]&&t[p].Min[1]>=temp.Min[1]&&t[p].Max[1]<=temp.Max[1]){
        t[p].lazy=temp.col;
        t[p].col=temp.col;
        return;
    }

    pushdown(p);

    if(t[p].d[0]>=temp.Min[0]&&t[p].d[0]<=temp.Max[0]&&t[p].d[1]>=temp.Min[1]&&t[p].d[1]<=temp.Max[1]){
        t[p].col=temp.col;
    }

    if(check(t[p].l,temp))
        update(t[p].l);

    if(check(t[p].r,temp))
        update(t[p].r);

}



vector<int> G[MAXN];
int dep[MAXN];
int siz[MAXN];
int dfn[MAXN];
int clo=0;
void dfs(int u,int d){
    siz[u]=1;
    dep[u]=d;
    dfn[u]=clo++;
    for(int i=0;i<G[u].size();i++)
    {
        dfs(G[u][i],d+1);
        siz[u]+=siz[G[u][i]];
    }
}


int main()
{

    int T;
    scanf("%d",&T);
    int N,C,Q;
    while(T--){
        clo=1;

        scanf("%d%d%d",&N,&C,&Q);
        int tmp;
        for(int i=2;i<=N;i++){
            scanf("%d",&tmp);
            G[tmp].push_back(i);
        }
        dfs(1,1);
        for(int i=1;i<=N;i++){
            t[i].d[0]=dfn[i];
            t[i].d[1]=dep[i];
            t[i].lazy=-1;
            t[i].col=1;
           // cout<<dfn[i]<<" "<<dep[i]<<" "<<siz[i]<<endl;
        }

        int rt=build(1,N,0);
        ll ans=0;
        int a,one,c;
        for(int i=1;i<=Q;i++){
            scanf("%d%d%d",&a,&one,&c);
            if(c==0){
                temp.d[0]=dfn[a];
                temp.d[1]=dep[a];
                ll yi=query(rt);
               // cout<<yi<<endl;
                ans=(ans+(yi*i)%ll(1e9+7))%ll(1e9+7);
            }
            else{

                temp.Min[0]=dfn[a];
                temp.Max[0]=dfn[a]+siz[a]-1;
                temp.Min[1]=dep[a];
                temp.Max[1]=dep[a]+one;
                temp.col=c;
                update(rt);
            }


        }
        printf("%lld\n",ans);
        
        for(int i=0;i<=N;i++)
            G[i].clear();


    }



    return 0;
}










