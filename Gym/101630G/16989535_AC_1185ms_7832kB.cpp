#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=40005;
const int MAXM=MAXN*3;
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];

ll suma[MAXN];
ll sumb[MAXN];
ll sumc[MAXN];

ll g[MAXN];
ll f[MAXN];

ll sorted[MAXN*5];
int tot=0;

int N,R;
ll K;
ll tree[MAXM<<2];

void update(int L,ll C,int l,int r,int rt){
    if(l==r){
        tree[rt]+=C;
        return;
    }
    int m=(l+r)/2;
    if(L<=m)
        update(L,C,l,m,rt<<1);
    else
        update(L,C,m+1,r,rt<<1|1);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

ll query(int L,int R,int l,int r,int rt){
    if(R<L)
        return 0;
    if(L<=l&&r<=R)
        return tree[rt];
    int m=(l+r)/2;
    ll ans=0;
    if(L<=m)
        ans+=query(L,R,l,m,rt<<1);
    if(R>m)
        ans+=query(L,R,m+1,r,rt<<1|1);
    return ans;
}

int id(ll num){
    return lower_bound(sorted,sorted+tot,num)-sorted+1;
}


bool judge(ll s){

    ll rank=0;
    memset(tree,0,sizeof(tree));

    for(int i=R+1,j=1;i+R-1<=N;i++,j++){
        update(id(sumb[j+R-1]-sumb[j-1]),1,1,MAXM,1);
        rank+=query(1,id(s-(sumb[i+R-1]-sumb[i-1]))-1,1,MAXM,1);
    }

    memset(tree,0,sizeof(tree));
    for(int i=2;i+R-1<=N;i++){
        update(id(g[i-1]),1,1,MAXM,1);
        if(i-R>=1)
            update(id(g[i-R]),-1,1,MAXM,1);
        rank+=query(1,id(s-f[i])-1,1,MAXM,1);
    }
    return rank<=K;
}


int main()
{
    scanf("%d%d%lld",&N,&R,&K);
    K--;

    for(int i=1;i<=N;i++){
        scanf("%lld",&a[i]);
        suma[i]=suma[i-1]+a[i];
    }
    for(int i=1;i<=N;i++){
        scanf("%lld",&b[i]);
        sumb[i]=sumb[i-1]+(b[i]-a[i]);
    }
    for(int i=1;i<=N;i++){
        scanf("%lld",&c[i]);
        sumc[i]=sumc[i-1]+(c[i]-a[i]);
    }

    for(int i=1;i+R-1<=N;i++){
        g[i]=(sumc[i-1]-2*sumb[i-1])+(sumc[i+R-1]-sumb[i+R-1])-(sumc[i-1]-sumb[i-1]);
        f[i]=(2*sumb[i-1]-sumc[i-1])+(sumb[i+R-1])-(sumb[i-1]);
    }


    //li san hua
    for(int i=1;i<=N;i++){
        if(i>=R){
            sorted[tot++]=g[i-R+1];
            sorted[tot++]=sumb[i]-sumb[i-R];
        }
    }
    sort(sorted,sorted+tot);
    tot=unique(sorted,sorted+tot)-sorted;


    ll l=0,r=1000000000000ll;
    while(l+1<r){
        ll m=(l+r)/2;
        if(judge(m))
            l=m;
        else
            r=m;
    }

    printf("%lld\n",l+suma[N]);



    return 0;
}










