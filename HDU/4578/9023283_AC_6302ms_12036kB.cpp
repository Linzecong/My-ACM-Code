#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<map>  
#include<queue>  
#include<stack>  
#include<cmath>  
#include<vector>  
#define inf 2139062143  
#define Inf 0x3FFFFFFFFFFFFFFFLL  
#define eps 1e-9  
#define pi acos(-1.0)  
using namespace std;  
typedef long long ll;  
const int maxn=100000+10;  
const int mod=10007;  
ll sum[maxn<<2],sum2[maxn<<2],sum3[maxn<<2],mulv[maxn<<2],addv[maxn<<2];  
ll tmp1,tmp2;  
inline void PushUp(int rt)  
{  
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%mod;  
    sum2[rt]=(sum2[rt<<1]+sum2[rt<<1|1])%mod;  
    sum3[rt]=(sum3[rt<<1]+sum3[rt<<1|1])%mod;  
}  
inline void sumcal(int p,ll ad,int len)  
{  
    tmp1=sum[p],tmp2=sum2[p];  
    ll v=(ad*ad*ad)%mod;  
    sum[p]=(tmp1+len*ad)%mod;  
    sum2[p]=(tmp2+len*ad*ad+2*ad*tmp1)%mod;  
    sum3[p]=(sum3[p]+len*v+3*tmp2*ad+3*ad*ad*tmp1)%mod;  
}  
inline void mulcal(int p,ll v)  
{  
    ll c=v;  
    sum[p]=(sum[p]*c)%mod;  
    c*=v;c%=mod;  
    sum2[p]=(sum2[p]*c)%mod;  
    c*=v;c%=mod;  
    sum3[p]=(sum3[p]*c)%mod;  
}  
void PushDown(int l,int r,int rt)  
{  
    int ls=rt<<1,rs=rt<<1|1;  
    int m=(l+r)>>1;  
    if(mulv[rt]!=1)  
    {  
        mulv[ls]=(mulv[ls]*mulv[rt])%mod;  
        mulv[rs]=(mulv[rs]*mulv[rt])%mod;  
        addv[ls]=(addv[ls]*mulv[rt])%mod;  
        addv[rs]=(addv[rs]*mulv[rt])%mod;  
        mulcal(ls,mulv[rt]);  
        mulcal(rs,mulv[rt]);  
        mulv[rt]=1;  
    }  
    if(addv[rt]!=0)  
    {  
        addv[ls]=(addv[rt]+addv[ls])%mod;  
        addv[rs]=(addv[rt]+addv[rs])%mod;  
        sumcal(ls,addv[rt],m-l+1);  
        sumcal(rs,addv[rt],r-m);  
        addv[rt]=0;  
    }  
}  
void build(int l,int r,int rt)  
{  
    sum[rt]=sum2[rt]=sum3[rt]=0;  
    addv[rt]=0;  
    mulv[rt]=1;  
    if(l==r) return ;  
    int m=(l+r)>>1;  
    build(l,m,rt<<1);  
    build(m+1,r,rt<<1|1);  
}  
ll Query(int L,int R,int l,int r,int rt,int p)  
{  
    if(l>=L&&r<=R)  
    {  
        if(p==1) return sum[rt];  
        else if(p==2) return sum2[rt];  
        else return sum3[rt];  
    }  
    PushDown(l,r,rt);  
    int m=(l+r)>>1;  
    ll sum=0;  
    if(m>=L)  
      sum+=Query(L,R,l,m,rt<<1,p);  
    if(m<R)  
      sum+=Query(L,R,m+1,r,rt<<1|1,p);  
    return sum%mod;  
}  
void Update(int L,int R,int l,int r,int rt,ll c,int op)  
{  
    if(l>=L&&r<=R)  
    {  
        if(op==3)  
        {  
            addv[rt]=c;mulv[rt]=0;  
            sum[rt]=((r-l+1)*c)%mod;  
            sum2[rt]=(sum[rt]*c)%mod;  
            sum3[rt]=(sum2[rt]*c)%mod;  
            return ;  
        }  
        else if(op==1)  
        {  
            addv[rt]+=c;addv[rt]%=mod;  
            sumcal(rt,c,r-l+1);  
            return ;  
        }  
        else  
        {  
            mulv[rt]*=c;mulv[rt]%=mod;  
            addv[rt]*=c;addv[rt]%=mod;  
            mulcal(rt,c);  
            return ;  
        }  
    }  
    PushDown(l,r,rt);  
    int m=(l+r)>>1;  
    if(m>=L)  
      Update(L,R,l,m,rt<<1,c,op);  
    if(m<R)  
      Update(L,R,m+1,r,rt<<1|1,c,op);  
    PushUp(rt);  
}  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);  
    int n,m;  
    while(~scanf("%d%d",&n,&m))  
    {  
        if(n==0&&m==0) break;  
        build(1,n,1);  
        int op,x,y;  
        ll c;  
        for(int i=0;i<m;++i)  
        {  
            scanf("%d%d%d%I64d",&op,&x,&y,&c);  
            if(op==4)  
            {  
                ll ans=Query(x,y,1,n,1,c);  
                printf("%I64d\n",ans);  
            }  
            else  
                Update(x,y,1,n,1,c,op);  
        }  
    }  
    return 0;  
}