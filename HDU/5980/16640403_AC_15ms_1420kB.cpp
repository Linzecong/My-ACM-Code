#include<iostream>
#include<algorithm>
using namespace std;
long long u;
int main()
{
    int n;
    int ans=0;
    int w=134;
    while (cin >> n)
    {
    for (int i=1;i<=n;i++)
    {
        cin >> u;
        for (int j=1;j<=4;j++)
        {
            int v=0;
            for (int k=1;k<=8;k++)
            {
                v=v*2+u%2;
                u/=2;
            }
            if (v==w)
                ans++;
        }
    }
    cout <<ans << endl;

    }
}
