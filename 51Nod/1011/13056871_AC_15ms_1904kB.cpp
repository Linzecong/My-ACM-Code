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

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
