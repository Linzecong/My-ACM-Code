#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll MAXQ=1e9+7;

struct point{
    ll x,r,q;
}Q[MAXN];

bool cmp(point &a,point &b){
    return a.r>b.r;
}
map<ll,int> mp;

int tot=0;
int ls[MAXN*40];
int rs[MAXN*40];
int sum[MAXN*40];
void update(int L,ll l,ll r,int &rt){
    if(rt==0)
        rt=++tot;
    if(l==r){
        sum[rt]++;
        return;
    }
    ll m=(l+r)/2;
    if(L<=m)
        update(L,l,m,ls[rt]);
    else
        update(L,m+1,r,rs[rt]);
    sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}

int query(int L,int R,ll l,ll r,int rt){
    if(rt==0)
        return 0;
    if(L<=l&&r<=R)
        return sum[rt];
    ll m=(l+r)/2;
    int ans=0;
    if(L<=m)
        ans+=query(L,R,l,m,ls[rt]);
    if(R>m)
        ans+=query(L,R,m+1,r,rs[rt]);
    return ans;
}


int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%lld%lld%lld",&Q[i].x,&Q[i].r,&Q[i].q);

    sort(Q,Q+N,cmp);
    ll ans=0;
    for(int i=0;i<N;i++){

        for(ll j=Q[i].q-K;j<=Q[i].q+K;j++){
            if(!mp[j])
                continue;
            ans=ans+query(max(0ll,Q[i].x-Q[i].r),min(MAXQ,Q[i].x+Q[i].r),0,MAXQ,mp[j]);
        }
        update(Q[i].x,0,MAXQ,mp[Q[i].q]);
    }
    cout<<ans<<endl;

    return 0;
}





