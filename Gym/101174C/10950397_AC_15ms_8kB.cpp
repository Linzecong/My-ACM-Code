#include<iostream>
using namespace std;

int main()
{
    int D,R,T,ans;
    cin>>D;
    cin>>R;
    cin>>T;
    int rita=0,thon=0;
    for(int i=4;i<=R;i++)
    {
        rita+=i;
        if(i-D>=3)thon+=(i-D);
        if(rita+thon==R+T)
        {
            ans=R-rita;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
