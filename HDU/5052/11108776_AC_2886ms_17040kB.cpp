#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<cstdio>  
  
using namespace std;  
  
#define maxn 100004  
  
int val[maxn],cost[maxn];  
int son[maxn],fa[maxn],deep[maxn],siz[maxn],top[maxn],pos[maxn],tot;  
int fir[maxn],nex[maxn],v[maxn],e_max;  
  
struct node  
{  
    int l,r;  
    long long mxl,mxr,mx,mi,tag;  
} t[2*maxn];  
  
template <class T>  
inline bool scan_d(T &ret)  
{  
    char c;  
    int sgn;  
    if(c=getchar(),c==EOF) return 0; //EOF  
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();  
    sgn=(c=='-')?-1:1;  
    ret=(c=='-')?0:(c-'0');  
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');  
    ret*=sgn;  
    return 1;  
}  
  
inline void out(long long x)  
{  
    if(x>9) out(x/10);  
    putchar(x%10+'0');  
}  
  
  
void init_()  
{  
    memset(son,-1,sizeof son);  
    memset(fir,-1,sizeof fir);  
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
    fa[k]=pre;  
    siz[k]=1;  
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
    pos[k]=tot++;  
    val[pos[k]]=cost[k];  
    top[k]=sp;  
    if(son[k]==-1) return;  
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
  
node Merge(node A,node B)  
{  
    A.mxl=max(max(A.mxl,B.mxl),B.mx-A.mi);  
    A.mxr=max(max(A.mxr,B.mxr),A.mx-B.mi);  
    A.mx=max(A.mx,B.mx);  
    A.mi=min(A.mi,B.mi);  
    return A;  
}  
  
void pushdown(int k)  
{  
    if(!t[k].tag) return ;  
    int lson=k<<1,rson=k<<1|1;  
    t[lson].mi+=t[k].tag;  
    t[lson].mx+=t[k].tag;  
    t[lson].tag+=t[k].tag;  
  
    t[rson].mi+=t[k].tag;  
    t[rson].mx+=t[k].tag;  
    t[rson].tag+=t[k].tag;  
  
    t[k].tag=0;  
}  
  
void pushup(int k)  
{  
    node A=t[k<<1],B=t[k<<1|1];  
    t[k].mxl=max(max(A.mxl,B.mxl),B.mx-A.mi);  
    t[k].mxr=max(max(A.mxr,B.mxr),A.mx-B.mi);  
    t[k].mx=max(A.mx,B.mx);  
    t[k].mi=min(A.mi,B.mi);  
}  
  
void init(int l,int r,int k)  
{  
    t[k].l=l;  
    t[k].r=r;  
    t[k].tag=0;  
    if(l==r)  
    {  
        t[k].mi=t[k].mx=val[l];  
        t[k].mxl=t[k].mxr=0;  
        return ;  
    }  
    int mid=l+r>>1;  
    init(l,mid,k<<1);  
    init(mid+1,r,k<<1|1);  
    pushup(k);  
}  
  
void update(int d,int l,int r,int k)  
{  
    if(t[k].l==l&&t[k].r==r)  
    {  
        t[k].tag+=d;  
        t[k].mi+=d;  
        t[k].mx+=d;  
        return ;  
    }  
    pushdown(k);  
    int mid=t[k].l+t[k].r>>1;  
    if(r<=mid) update(d,l,r,k<<1);  
    else if(l>mid) update(d,l,r,k<<1|1);  
    else update(d,l,mid,k<<1),update(d,mid+1,r,k<<1|1);  
    pushup(k);  
}  
  
node query(int l,int r,int k)  
{  
    if(t[k].l==l&&t[k].r==r)  
    {  
        return t[k];  
    }  
    pushdown(k);  
    int mid=t[k].l+t[k].r>>1;  
    if(r<=mid) return query(l,r,k<<1);  
    else if(l>mid) return query(l,r,k<<1|1);  
    else return Merge(query(l,mid,k<<1),query(mid+1,r,k<<1|1));  
}  
  
void check(node& A,node& B)  
{  
    if(A.mi==0)  
    {  
        A=B;  
        return;  
    }  
    A.mxl=max(max(A.mxl,B.mxl),A.mx-B.mi);  
    A.mxr=max(max(A.mxr,B.mxr),B.mx-A.mi);  
    A.mx=max(A.mx,B.mx);  
    A.mi=min(A.mi,B.mi);  
}  
  
void Query(int s,int t,int c)  
{  
    int f1=top[s],f2=top[t];  
    node ans1,ans2;  
    ans1.tag=-1;  
    ans1.mxl=ans1.mxr=ans1.mx=ans1.mi=0;  
    ans2.tag=1;  
    ans2.mxl=ans2.mxr=ans2.mx=ans2.mi=0;  
    while(f1!=f2)  
    {  
        if(deep[f1]<deep[f2]) swap(f1,f2),swap(s,t),swap(ans1,ans2);  
        int tp=ans1.tag;  
        node temp=query(pos[f1],pos[s],1);  
        check(ans1,temp);  
        ans1.tag=tp;  
        update(c,pos[f1],pos[s],1);  
        s=fa[f1];  
        f1=top[s];  
    }  
    if(deep[s]>deep[t]) swap(s,t),swap(ans1,ans2);  
    int tp=ans2.tag;  
    node temp=query(pos[s],pos[t],1);  
    update(c,pos[s],pos[t],1);  
    check(ans2,temp);  
    ans2.tag=tp;  
    if(ans1.tag==1) swap(ans1,ans2);  
    long long ans;  
    ans=max(ans1.mxr,ans2.mxl);  
    if(ans1.mi) ans=max(ans2.mx-ans1.mi,ans);  
    out(ans);  
    puts("");  
}  
  
int main()  
{  
    int T;  
    scan_d(T);  
    while(T--)  
    {  
        init_();  
        int n;  
        scan_d(n);  
        for(int i=1; i<=n; i++)  
        {  
            scan_d(cost[i]);  
        }  
        for(int i=1; i<n; i++)  
        {  
            int a,b;  
            scan_d(a);  
            scan_d(b);  
            add_edge(a,b);  
            add_edge(b,a);  
        }  
        dfs1(1,-1,1);  
        dfs2(1,1);  
        init(1,tot-1,1);  
        int q;  
        scan_d(q);  
        while(q--)  
        {  
            int a,b,c;  
            scan_d(a);  
            scan_d(b);  
            scan_d(c);  
            Query(a,b,c);  
        }  
    }  
    return 0;  
}  