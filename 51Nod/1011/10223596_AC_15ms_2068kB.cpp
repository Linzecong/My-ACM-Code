#include <iostream>
#include <string>
#include<vector>
#include <cstring>
#include<math.h>

using namespace std;
typedef long long int ll;

ll a,b;
ll GCD(ll a,ll b){
    if(b>0)
        return GCD(b,a%b);
    else
        return a;
}


int main()
{


    while(~scanf("%lld%lld",&a,&b)){
        printf("%lld\n",GCD(a,b));
    }




    return 0;
}
