#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=2*ans+1;
    }
    cout<<ans;
    return 0;
}
