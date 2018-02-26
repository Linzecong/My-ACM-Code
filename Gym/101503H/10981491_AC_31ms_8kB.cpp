#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k1,k2,p1,p2,p3;
    cin>>n>>k1>>k2>>p1>>p2>>p3;
    int ans=0;
    if(n<p1)
    {
        cout<<ans<<endl;
        return 0;
    }
    ans+=k1;
    n-=p1;
    while(n>0&&k2>0)
    {
        n-=p2;
        k2--;
        ans++;
    }
    while(n>0)
    {
        n-=p3;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
