#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#define lson num<<1,s,mid  
#define rson num<<1|1,mid+1,e  
#define maxn 100005  
   
typedef long long LL;  
using namespace std;  
   
LL tre[maxn<<2][5];  
LL cnt[maxn<<2];  
struct node  
{  
    char op[10];  
    LL w;  
}P[maxn];  
LL X[maxn];  
   
void build(int num,int s,int e)  
{  
    int mid=(s+e)>>1;  
    cnt[num]=0;  
    memset(tre[num],0,sizeof(tre[num]));  
    if(s==e)  
    {  
        return;  
    }  
    build(lson);  
    build(rson);  
}  
   
void pushup(int num)  
{  
    for(int i=0;i<5;i++)  
    tre[num][i]=tre[num<<1][i]+tre[num<<1|1][((i-cnt[num<<1])%5+5)%5];//这个地方有点难得想- =  
}  
   
void update(int num,int s,int e,int pos,int val,int k)  
{  
    cnt[num] += 2*k-1;  
    if(s==e)  
    {  
        if(k==1)tre[num][1]=val;  
        else tre[num][1]=0;  
        return;  
    }  
    int mid=(s+e)>>1;  
    if(pos<=mid)update(lson,pos,val,k);  
    else update(rson,pos,val,k);  
    pushup(num);  
}  
   
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        int tot=1;  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%s",&P[i].op);  
            if(P[i].op[0]!='s')  
            {  
                scanf("%I64d",&P[i].w);  
                X[tot++]=(LL)P[i].w;  
            }  
        }  
        sort(X+1,X+tot);  
        tot=unique(X+1,X+tot)-(X+1);  
   
        build(1,1,tot);  
        for(int i=1;i<=n;i++)  
        {  
            if(P[i].op[0]!='s')  
            {  
                int pos = lower_bound(X+1,X+tot+1,P[i].w)-X;  
                if(P[i].op[0]=='a')update(1,1,tot,pos,P[i].w,1);  
                else update(1,1,tot,pos,P[i].w,0);  
            }  
            else printf("%I64d\n",tre[1][3]);  
        }  
    }  
    return 0;  
}  