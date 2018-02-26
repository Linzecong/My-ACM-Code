#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
using namespace std;
typedef long long int ll;
ll N, M;

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll ans=exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ans;

}



int main()
{

    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll x,y;
    ll g=exgcd(N,M,x,y);
    ll ans=N*M/g;

    if(N==1||M==1){
        if(N==M)
        cout<<"1"<<endl;
        else
        cout<<"2"<<endl;
        return 0;
    }

    if(g==1){
        ans=min(ans,max(abs(x*N),abs(y*M)));
       // ans=min(ans,max(abs(x+M)*N,abs(y+N)*M));
        //ans=min(ans,max(abs(x+M)*N,abs(y-N)*M));
    }
    cout<<ans<<endl;
    

    return 0;
}
