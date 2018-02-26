#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
struct node{
    ll sum,lazy;
    int lc,rc;
}rec[3000010];
int n,m,cnt,x,y,z,now,a[100010],rt[100010];
char op[3];
void build(int &now,int l,int r)
{
    rec[++cnt]=rec[now];
    now=cnt;
    if(l==r)
    {
        rec[now].sum=a[l];
        return;
    }
    build(rec[now].lc,l,(l+r)/2);
    build(rec[now].rc,(l+r)/2+1,r);
    rec[now].sum=rec[rec[now].lc].sum+rec[rec[now].rc].sum;
}
void add(int &now,int l,int r,int val,int L,int R)
{
    rec[++cnt]=rec[now];
    now=cnt;
    rec[now].sum+=1ll*val*(r-l+1);
    if(l==L&&r==R)
    {
        rec[now].lazy+=val;
        return;
    }
    if(r<=(L+R)/2)add(rec[now].lc,l,r,val,L,(L+R)/2);
    else if(l>(L+R)/2)add(rec[now].rc,l,r,val,(L+R)/2+1,R);
    else
    {
        add(rec[now].lc,l,(L+R)/2,val,L,(L+R)/2);
        add(rec[now].rc,(L+R)/2+1,r,val,(L+R)/2+1,R);
    }
}
ll query(int now,int l,int r,int L,int R)
{
    if(l==L&&r==R)return rec[now].sum;
    ll tmp=1ll*(r-l+1)*rec[now].lazy;
    if(r<=(L+R)/2)return tmp+query(rec[now].lc,l,r,L,(L+R)/2);
    if(l>(L+R)/2)return tmp+query(rec[now].rc,l,r,(L+R)/2+1,R);
    return tmp+query(rec[now].lc,l,(L+R)/2,L,(L+R)/2)+query(rec[now].rc,(L+R)/2+1,r,(L+R)/2+1,R);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        now=cnt=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        build(rt[0],1,n);
        for(int i=1;i<=m;++i)
        {
            scanf("%s",op);
            if(op[0]=='C')
            {
                scanf("%d%d%d",&x,&y,&z);
                ++now;
                add(rt[now]=rt[now-1],x,y,z,1,n);
            }
            else if(op[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                printf("%I64d\n",query(rt[now],x,y,1,n));
            }
            else if(op[0]=='H')
            {
                scanf("%d%d%d",&x,&y,&z);
                printf("%I64d\n",query(rt[z],x,y,1,n));
            }
            else scanf("%d",&now);
        }
    }
}
