#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define inf 2000000000
using namespace std;
int n,cnt,qcnt,Q,a[100010],tmp[100010],ans[100010],bit[100010]={0};
struct query
{
    int id,x,y,val,cur,k;
}q[300010],a1[300010],a2[300010];

int lowbit(int i)
{
    return i&(-i);
}

void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        bit[i]+=d;
}

int sum(int x)
{
    int s=0;
    for(int i=x;i;i-=lowbit(i))
        s+=bit[i];
    return s;
}

void solve(int s,int t,int l,int r)
{
    if (s>t) return;
    if (l==r)
    {
        for(int i=s;i<=t;i++)
            if (q[i].val==0) ans[q[i].id]=l;
        return;
    }

    int mid=(l+r)>>1;
    for(int i=s;i<=t;i++)
    {
        if (q[i].val!=0&&q[i].y<=mid) add(q[i].x,q[i].val);
        if (q[i].val==0) tmp[q[i].id]=sum(q[i].y)-sum(q[i].x-1);
    }
    for(int i=s;i<=t;i++)
        if (q[i].val!=0&&q[i].y<=mid) add(q[i].x,-q[i].val);

    int n1=0,n2=0;
    for(int i=s;i<=t;i++)
    {
        if (q[i].val==0)
        {
            if (q[i].cur+tmp[q[i].id]>=q[i].k) a1[++n1]=q[i];
            else
            {
                q[i].cur+=tmp[q[i].id];
                a2[++n2]=q[i];
            }
        }
        else
        {
            if (q[i].y<=mid) a1[++n1]=q[i];
            else a2[++n2]=q[i];
        }
    }

    for(int i=1;i<=n1;i++) q[s+i-1]=a1[i];
    for(int i=1;i<=n2;i++) q[s+n1+i-1]=a2[i];
    solve(s,s+n1-1,l,mid);
    solve(s+n1,t,mid+1,r);
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0,qcnt=0;
        int Min=inf,Max=-inf;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            Min=min(Min,a[i]),Max=max(Max,a[i]);
            q[++cnt].x=i,q[cnt].y=a[i],q[cnt].val=1;
        }
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++)
        {
            int op,l,r,k;
            scanf("%d",&op);
            if (op==1)
            {
                scanf("%d%d",&l,&k);
                q[++cnt].x=l,q[cnt].y=a[l],q[cnt].val=-1;
                q[++cnt].x=l,q[cnt].y=k,q[cnt].val=1;
                a[l]=k;
                Min=min(Min,a[l]),Max=max(Max,a[l]);
            }
            if (op==2)
            {
                scanf("%d%d%d",&l,&r,&k);
                q[++cnt].x=l,q[cnt].y=r,q[cnt].val=0,q[cnt].id=++qcnt;
                q[cnt].k=k,q[cnt].cur=0;
            }
        }

        solve(1,cnt,Min,Max);

        for(int i=1;i<=qcnt;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
