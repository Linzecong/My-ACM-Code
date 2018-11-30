#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long ll;
const int MAXN = 100505;

int N,Q;
int a[MAXN];

int sum[MAXN*20];
int ls[MAXN*20];
int rs[MAXN*20];
int T[MAXN];
int tot=0;

void update(int P,int C,int l,int r,int &rt,int lrt){
    rt=++tot;
    ls[rt]=ls[lrt];
    rs[rt]=rs[lrt];
    sum[rt]=sum[lrt];
    if(l==r){
        sum[rt]+=C;
        return;
    }
    int m=(l+r)/2;
    if(P<=m)
        update(P,C,l,m,ls[rt],ls[lrt]);
    else
        update(P,C,m+1,r,rs[rt],rs[lrt]);
    sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}

int query(int L,int R,int l,int r,int rt,int lrt){
    if(L<=l&&r<=R){
        return sum[lrt]-sum[rt];
    }
    int m=(l+r)/2;
    int ans=0;
    if(L<=m)
        ans+=query(L,R,l,m,ls[rt],ls[lrt]);
    if(R>m)
        ans+=query(L,R,m+1,r,rs[rt],rs[lrt]);
    return ans;
}



bool judge(int x,int l,int r){
    if(query(x,N,1,N,T[l-1],T[r])-x>=0)
        return true;
    return false;
}


int main()
{


    while(~scanf("%d%d",&N,&Q)){
        
        tot=0;
        memset(sum,0,sizeof(sum));
        memset(ls,0,sizeof(ls));
        memset(rs,0,sizeof(rs));
        for(int i=1;i<=N;i++){
            scanf("%d",&a[i]);
            update(a[i],1,1,N,T[i],T[i-1]);
        }
        int l,r;
        for(int i=0;i<Q;i++){
            scanf("%d%d",&l,&r);
            int ll=1,rr=N;
            int m;
            while(ll<=rr){
                m=(ll+rr)/2;
                if(judge(m,l,r))
                    ll=m+1;
                else
                    rr=m-1;
            }
            printf("%d\n",rr);
        }
        
        

    }
    

    return 0;
}
