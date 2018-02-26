#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define maxn 100001
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[maxn<<2],lazy[maxn<<2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    return;
}
void pushdown(int rt,int len)
{
    if(lazy[rt]>=0)
    {
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        sum[rt<<1]=(len-(len>>1))*lazy[rt];
        sum[rt<<1|1]=(len>>1)*lazy[rt];
        lazy[rt]=-1;
    }
    return;
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        lazy[rt]=c;
        sum[rt]=(r-l+1)*c;
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)update(L,R,c,lson);
    if(R>m)update(L,R,c,rson);
    pushup(rt);
    return;
}
void build(int l,int r,int rt)
{
    lazy[rt]=-1;
    if(l==r){sum[rt]=0;return;}
    int m=(l+r)>>1;
    build(lson);build(rson);
    pushup(rt);
}
long long query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)return sum[rt];
    long long ans=0;
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)ans+=query(L,R,lson);
    if(R>m)ans+=query(L,R,rson);
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sum,0,sizeof(sum));
        memset(lazy,0,sizeof(lazy));
        int len,q;
        scanf("%d%d",&len,&q);
        build(1,len,1);
        int k,a,b;
        while(q--)
        {
            scanf("%d%d%d",&k,&a,&b);
            a++;b++;
            if(k==1)
            {
                b--;
                int t;
                if((t=query(a,len,1,len,1))==len-a+1)
                {
                    puts("Can not put any one.");
                    continue;
                }
                int l=a,r=len,mid;
                b=min(b,len-a+1-t);
                while(l<r)
                {
                    mid=(l+r)>>1;
                    if(query(a,mid,1,len,1)==mid-a+1)l=mid+1;
                    else r=mid;
                }
                printf("%d ",l-1);
                l=a;r=len;
                while(l<r)
                {
                    mid=(l+r)>>1;
                    if((mid-a+1-query(a,mid,1,len,1))>=b)r=mid;
                    else l=mid+1;
                }
                printf("%d\n",r-1);
                update(a,l,1,1,len,1);
            }
            else
            {
                printf("%d\n",query(a,b,1,len,1));
                update(a,b,0,1,len,1);
            }
        }
        puts("");
    }
}