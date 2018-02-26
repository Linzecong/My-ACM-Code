#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long int ll;

int N;
ll ans[1005][1005];
ll qian[1005][1005];

ll money[1005];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%lld", &qian[i][j]);
            money[j] += qian[i][j];
            money[i] -= qian[i][j];
        }

    int q = 1;
    for (int i = 1; i <= N; i++)
    {
        while (money[i] < 0)
        {
            while (money[q] <= 0)
                q++;
            ll jie = min(-money[i], money[q]);
            ans[i][q] = jie;
            money[i] += jie;
            money[q] -= jie;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j != N)
                printf("%lld ", ans[i][j]);
            else
                printf("%lld\n", ans[i][j]);
        }
    }

    return 0;
}
