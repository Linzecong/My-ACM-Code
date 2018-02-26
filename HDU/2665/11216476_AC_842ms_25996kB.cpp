#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;
const int MAXN=100101;

int ls[MAXN*20];
int rs[MAXN*20];
int sum[MAXN*20];

int num[MAXN];
int san[MAXN];
int T[MAXN];
int n,m,tot=0;

void build(int l,int r,int &x){
    x=++tot;
    sum[x]=0;
    if(l==r)
        return;
    int m=(l+r)/2;
    build(l,m,ls[x]);
    build(m+1,r,rs[x]);
}

void update(int last,int p,int l,int r,int &x){
    x=++tot;
    ls[x]=ls[last];
    rs[x]=rs[last];
    sum[x]=sum[last]+1;
    if(l==r)
        return;
    int m=(l+r)/2;
    if(p<=m)
        update(ls[last],p,l,m,ls[x]);
    else
        update(rs[last],p,m+1,r,rs[x]);
}

int query(int s,int t,int l,int r,int k){
    if(l==r)
        return l;
    int m=(l+r)/2;
    int cnt=sum[ls[t]]-sum[ls[s]];

    if(k<=cnt)
        return query(ls[s],ls[t],l,m,k);
    return query(rs[s],rs[t],m+1,r,k-cnt);
}



int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        tot=0;


        int x,y,z;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&san[i]);
            num[i]=san[i];
        }

        sort(san+1,san+n+1);

        int cnt=unique(san+1,san+n+1)-san-1;
        build(1,cnt,T[0]);

        for(int i=1;i<=n;i++)
            num[i]=lower_bound(san+1,san+cnt+1,num[i])-san;

        for(int i=1;i<=n;i++)
            update(T[i-1],num[i],1,cnt,T[i]);

        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",san[query(T[x-1],T[y],1,cnt,z)]);
        }
    }


    return 0;
}



