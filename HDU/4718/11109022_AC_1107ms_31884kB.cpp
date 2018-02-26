#include<cstring>  
#include<string>  
#include<iostream>  
#include<queue>  
#include<cstdio>  
#include<algorithm>  
#include<map>  
#include<cstdlib>  
#include<cmath>  
#include<vector>  
//#pragma comment(linker, "/STACK:1024000000,1024000000");  
  
using namespace std;  
  
#define INF 0x3f3f3f3f  
#define maxn 300004  
  
int fir[maxn],nex[maxn],v[maxn],e_max;  
int son[maxn],fa[maxn],top[maxn],siz[maxn],deep[maxn],tot;  
int a[maxn],val[maxn],pos[maxn];  
  
void init_()  
{  
    memset(fir,-1,sizeof fir);  
    memset(son,-1,sizeof son);  
    e_max=0;  
    tot=1;  
}  
  
void add_edge(int s,int t)  
{  
    int e=e_max++;  
    v[e]=t;  
    nex[e]=fir[s];  
    fir[s]=e;  
}  
  
void dfs1(int k,int pre,int d)  
{  
    deep[k]=d;  
    siz[k]=1;  
    fa[k]=pre;  
    for(int i=fir[k]; ~i; i=nex[i])  
    {  
        int e=v[i];  
        if(e!=pre)  
        {  
            dfs1(e,k,d+1);  
            siz[k]+=siz[e];  
            if(son[k]==-1||siz[son[k]]<siz[e]) son[k]=e;  
        }  
    }  
}  
  
void dfs2(int k,int sp)  
{  
    top[k]=sp;  
    pos[k]=tot++;  
    val[pos[k]]=a[k];  
    if(son[k]==-1) return ;  
    dfs2(son[k],sp);  
    for(int i=fir[k]; ~i; i=nex[i])  
    {  
        int e=v[i];  
        if(e!=fa[k]&&e!=son[k])  
        {  
            dfs2(e,e);  
        }  
    }  
}  
  
struct node  
{  
    int l,r;  
    int Lval,Rval;  
    int LL,LR,RL,RR;  
    int Len,Ren;  
    node()  
    {  
        Len=Ren=0;  
        LL=LR=RL=RR=0;  
        Lval=Rval=0;  
    }  
} T[2*maxn];  
  
node Merge(node A,node B)  
{  
    if(B.Len==0) return A;  
    node temp=A;  
    temp.r=B.r;  
    temp.Rval=B.Rval;  
    temp.Len=max(A.Len,B.Len);  
    temp.Ren=max(A.Ren,B.Ren);  
    if(A.LR==A.r-A.l+1&&A.Rval<B.Lval)  
    {  
        temp.LR=A.LR+B.LR;  
    }  
    else temp.LR=A.LR;  
    if(A.LL==A.r-A.l+1&&A.Rval>B.Lval)  
    {  
        temp.LL=A.LL+B.LL;  
    }  
    else temp.LL=A.LL;  
    if(B.RL==B.r-B.l+1&&A.Rval>B.Lval)  
    {  
        temp.RL=A.RL+B.RL;  
    }  
    else temp.RL=B.RL;  
    if(B.RR==B.r-B.l+1&&A.Rval<B.Lval)  
    {  
        temp.RR=A.RR+B.RR;  
    }  
    else temp.RR=B.RR;  
    temp.Ren=max(temp.Ren,temp.LL);  
    temp.Len=max(temp.Len,temp.LR);  
    temp.Len=max(temp.Len,temp.RR);  
    temp.Ren=max(temp.Ren,temp.RL);  
    if(A.Rval<B.Lval) temp.Len=max(temp.Len,A.RR+B.LR);  
    if(A.Rval>B.Lval) temp.Ren=max(temp.Ren,A.RL+B.LL);  
    return temp;  
}  
  
void init(int l,int r,int k)  
{  
    T[k].l=l;  
    T[k].r=r;  
    if(l==r)  
    {  
        T[k].LL=T[k].LR=T[k].RL=T[k].RR=1;  
        T[k].Lval=T[k].Rval=val[l];  
        T[k].Len=1;  
        T[k].Ren=1;  
        return ;  
    }  
    int mid=l+r>>1;  
    init(l,mid,k<<1);  
    init(mid+1,r,k<<1|1);  
    T[k]=Merge(T[k<<1],T[k<<1|1]);  
}  
  
node query(int s,int t,int l,int r,int k)  
{  
    if(s==l&&r==t)  
    {  
        return T[k];  
    }  
    int mid=l+r>>1;  
    if(t<=mid) return query(s,t,l,mid,k<<1);  
    else if(s>mid) return query(s,t,mid+1,r,k<<1|1);  
    else return Merge(query(s,mid,l,mid,k<<1),query(mid+1,t,mid+1,r,k<<1|1));  
}  
  
int Query(int s,int t)  
{  
    int flag=0;  
    int f1=top[s],f2=top[t];  
    node ans1,ans2;  
    while(f1!=f2)  
    {  
        if(deep[f1]<deep[f2]) flag^=1,swap(f1,f2),swap(s,t),swap(ans1,ans2);  
        ans1=Merge(query(pos[f1],pos[s],1,tot-1,1),ans1);  
        s=fa[f1];  
        f1=top[s];  
    }  
    if(deep[s]>deep[t]) flag^=1,swap(s,t),swap(ans1,ans2);  
    ans2=Merge(query(pos[s],pos[t],1,tot-1,1),ans2);  
    if(flag) swap(ans1,ans2);  
    int ans=max(ans1.Ren,ans2.Len);  
    if(ans1.Lval<ans2.Lval)  
    {  
        ans=max(ans2.LR+ans1.LL,ans);  
    }  
    return ans;  
}  
  
int main()  
{  
    int ca=1;  
    int T;  
    int flag=0;  
    scanf("%d",&T);  
    while(T--)  
    {  
        if(flag) puts("");  
        init_();  
        int n;  
        scanf("%d",&n);  
        for(int i=1; i<=n; i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        for(int i=2; i<=n; i++)  
        {  
            int temp;  
            scanf("%d",&temp);  
            add_edge(temp,i);  
            add_edge(i,temp);  
        }  
        dfs1(1,-1,1);  
        dfs2(1,1);  
        init(1,tot-1,1);  
        int q;  
        scanf("%d",&q);  
        printf("Case #%d:\n",ca++);  
        while(q--)  
        {  
            int l,r;  
            scanf("%d%d",&l,&r);  
            int ans=Query(l,r);  
            printf("%d\n",ans);  
        }  
        flag=1;  
    }  
    return 0;  
}  