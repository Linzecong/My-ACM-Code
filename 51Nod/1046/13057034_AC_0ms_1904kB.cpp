#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
typedef long long int ll;

ll gcd(ll a,ll b){
    ll c=a%b;
    while(c){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

ll mpow(ll a,ll b,ll c){
    ll ans=1;
    a=a%c;
    while(b>0){
        if(b%2)ans=(ans*a)%c;
        b/=2;
        a=(a*a)%c;
    }
    return ans;
}

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<mpow(a,b,c)<<endl;
    return 0;
}
