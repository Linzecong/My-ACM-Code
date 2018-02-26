#include <iostream>
#include <string>
#include<vector>
#include <cstring>
#include<math.h>

using namespace std;
typedef long long int ll;

ll a,b,c;

ll quickpow(ll a,ll b,ll c){
    ll r=1,base=a;
    while(b!=0){
    if(b%2) r=(r*base)%c;
    base=(base*base)%c;
    b/=2;
    }
    return r;
}

int main()
{


    while(~scanf("%lld%lld%lld",&a,&b,&c)){
        printf("%lld\n",quickpow(a,b,c));
    }




    return 0;
}
