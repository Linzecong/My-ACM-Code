#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int N;
ll M;
ll a[MAXN];
ll b[MAXN];

bool judge(ll m){
    if(m==0)
        return true;
    for(int i=1;i<=N+1;i++)
        b[i]=0;
    for(int i=1;i<=N;i++){
        ll num=(m+a[i]-1)/a[i];
        if(i==N&&b[i]>=num)
            break;
        b[i]++;
        if(b[i]<num){
            b[i+1]+=num-b[i];
            b[i]=num;
        }
    }
    ll tmp=0;
    for(int i=1;i<=N+1;i++){
        tmp+=b[i];
        if(tmp>M)
            return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&N,&M);
        for(int i=1;i<=N;i++)
            scanf("%lld",&a[i]);
        ll l=0,r=1e18;
        while(l<r){
            ll m=(l+r)/2;
            if(judge(m))
                l=m+1;
            else
                r=m;
        }
        printf("%lld\n",l-1);

    }

    return 0;
}


