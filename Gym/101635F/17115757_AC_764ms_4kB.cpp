#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,K;
    scanf("%lld%lld",&K,&N);


    ll tot=0;
    ll h,w;
    for(int i=0;i<N;i++){
        scanf("%lld%lld",&h,&w);
        tot+=h*w;


    }

    printf("%lld\n",tot/K);







    return 0;
}
