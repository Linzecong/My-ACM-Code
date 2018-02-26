#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int p[1005], w[1005], dp[35];

int main()
{
    int t, n, i, j, g, sum, maxw;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            scanf("%d%d", &p[i], &w[i]);
        scanf("%d", &g);
        sum = 0;
        while (g--)
        {
            memset(dp, 0, sizeof(dp));
            scanf("%d", &maxw);
            for (i = 0; i < n; ++i)
                for (j = maxw; j >= w[i]; --j)
                    dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            sum += dp[maxw];
        }
        printf("%d\n", sum);
    }
    return 0;
}
