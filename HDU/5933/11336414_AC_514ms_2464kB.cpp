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

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

inline void scan_dl(ll &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

ll a[100005];

int main(){

    int t;
    scanf("%d",&t);
    for(int qqq=1;qqq<=t;qqq++){

        ll N,K;
        scan_dl(N);
        scan_dl(K);
        ll sum=0;
        for(int i=0;i<N;i++){
            scan_dl(a[i]);
            sum+=a[i];
        }
        if(sum%K!=0){
            printf("Case #%d: %d\n",qqq,-1);
        }
        else{
            ll num=sum/K;
            ll ans=0;
            ll k=0;
            ll i=0;

            while(k!=K){

                if(a[i]<num){
                    a[i+1]+=a[i];
                    ans++;
                    i++;
                }
                else{
                    if(a[i]>num){

                        k++;
                        a[i]=a[i]-num;
                        ans++;
                    }
                    else{
                        i++;
                        k++;
                    }
                }

            }
            printf("Case #%d: %lld\n",qqq,ans);
        }


    }

    return 0;
}



