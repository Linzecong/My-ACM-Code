#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int maxn = 30005;
typedef long long int ll;

int a[2005];
int t[2005];
int dp[2005];

int main()
{
    int ttt = 0;
    scanf("%d", &ttt);
    for (int qqq = 1; qqq <= ttt; qqq++)
    {
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i < n; i++)
            scanf("%d", &t[i]);

        // for (int i = 1; i < n; i++)
        // {
        //     c[i] = a[i] + a[i + 1] - t[i];
        // }

        // int ans = 0;
        // int i;
        // for (i = 1; i < n; i++)
        // {
        //     if (c[i] < 0)
        //     {
        //         ans += a[i];
        //         continue;
        //     }
        //     if (c[i] > c[i + 1])
        //     {
        //         ans += t[i];
        //         i++;
        //         continue;
        //     }
        //     ans += a[i];
        //     continue;
        // }

        // if (i == n)
        //     ans += a[n];

        int ans = 0;
        dp[1]=a[1];
        dp[0]=0;

        
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i-1]+a[i],dp[i-2]+t[i-1]);
        }
        ans=dp[n];
        ans += 8 * 60 * 60;

        //cout << ans << endl;

        int h = (ans / 3600) % 24;
        int m = (ans / 60 % 60);
        int s = (ans % 60);

        if (h < 10)
            cout << "0" << h << ":";
        else
            cout << h << ":";
        if (m < 10)
            cout << "0" << m << ":";
        else
            cout << m << ":";
        if (s < 10)
            cout << "0" << s << " " << ((h < 12) ? "am" : "pm") << endl;
        else
            cout << s << " " << ((h < 12) ? "am" : "pm") << endl;
    }

    return 0;
}

//5 25 25 30  30

//5 2  1  70

//25 48 54 -100
