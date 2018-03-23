#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int a[50005];
int dp[50005][4];
int main()
{
    int n, t, k;
    scanf("%d", &t);
    while (t--)
    {
        a[0] = 0;
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }

        scanf("%d", &k);

        for (int i = k; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + a[i] - a[i - k]);
            }
        }
        printf("%d\n", dp[n][3]);
    }
    return 0;
}
