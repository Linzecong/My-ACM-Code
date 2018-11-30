#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
long long my_sqrt(long long x) {
  if(x<0){
    return -1;
  }
  long long y = (long long) (sqrtl((long double) x) + 0.5);
  while (y * y < x) {
    y++;
  }
  while (y * y > x) {
    y--;
  }
  if (y * y == x) {
    return y;
  }
  return -1;
}
int main()
{
    long long a,b;
    while(cin>>a>>b){
            bool flag=true;
            ll t=__gcd(a,b);
            a/=t,b/=t;
            ll xx=a;
            ll yy=my_sqrt(a*a-4LL*b);
            if(yy==-1){
                flag=false;
                cout<<"No Solution\n";
            }
            ll x=(xx+yy)/2LL*t;
            ll y=(xx-yy)/2LL*t;
            if(x+y==a*t&&x*y/__gcd(x,y)==b*t){
                cout<<min(x,y)<<" "<<max(x,y)<<'\n';
                flag=false;
            }
            if(flag){
            cout<<"No Solution\n";
        }
    }



    return 0;
}



