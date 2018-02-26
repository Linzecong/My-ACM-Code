#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;
ll su[1000005];
int cnt;
void sushu(ll x)
{
    cnt=0;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            su[cnt++]=i;
        while(x%i==0)
            x/=i;
    }
    su[cnt++]=x;
}

int a[100005];
int b[100005];

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);
        ll sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sushu(sum);
        ll ans=9999999999999;
        for(int p=0;p<cnt;p++){

           // if(sum%su[p])
           //     continue;

            ll yusum=0;
            for(int i=1;i<=n;i++){
                b[i]=a[i]%su[p];
                yusum+=b[i];
            }

            sort(b+1,b+n+1);

            ll ta=0;

            int k=n;
            while(yusum!=0&&k>=1){
                ta+=su[p]-b[k--];
                yusum-=su[p];
            }

            ans=min(ans,ta);
        }
        printf("%lld\n",ans);
    }

    return 0;
}



