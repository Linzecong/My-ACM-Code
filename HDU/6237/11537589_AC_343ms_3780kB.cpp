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
#define M 1000005
bool visit[1010000];
int prime[1000000];

void table()
{
    memset(visit,true,sizeof(visit));
    int num = 0;
    for (int i = 2; i <= M; ++i)
    {
        if (visit[i] == true)
        {
            num++;
            prime[num] = i;
        }
        for (int j = 1; ((j <= num) && (i * prime[j] <= M));  ++j)
        {
            visit[i * prime[j]] = false;
            if (i % prime[j] == 0) break; //点睛之笔
        }
    }
}

int a[100005];
int b[100005];

int main(){
    int t;
    scanf("%d",&t);
table() ;
    while(t--){
        int n;
        scanf("%d",&n);
        ll sum=0;
        int maxx=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            maxx=max(maxx,a[i]);
        }

        ll ans=sum-maxx;
        for(int p=1;p<=M;p++){

            if(prime[p]==0)
                break;

            if(sum%prime[p])
                continue;

            for(int i=1;i<=n;i++){
                b[i]=a[i]%prime[p];
            }
            sort(b+1,b+n+1);

            ll ta=0;
            int l=1,r=n;

            while(l<r){
                int temp=prime[p]-b[r];
                if(b[l]>temp){
                    b[l]-=temp;
                    ta+=temp;
                    r--;
                }
                else{
                    b[r]+=b[l];
                    ta+=b[l];
                    l++;
                }
            }
            ans=min(ans,ta);
        }
        printf("%lld\n",ans);
    }

    return 0;
}


