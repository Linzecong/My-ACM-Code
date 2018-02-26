#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <deque>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
using namespace std;

typedef long long int ll;

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9')
        ;
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

inline void scan_d(ll &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9')
        ;
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int num[100005];
int ans[100005];
int type[100005];

int che[100005];

int main()
{

    int T;
    scan_d(T);
    int nc = 1;

    while (T--)
    {
        memset(che, 1, sizeof(che));
        int q;
        int MOD;
        scan_d(q);
        scan_d(MOD);

        printf("Case #%d:\n", nc++);

        ans[0] = 1;
        for (int i = 1; i <= q; i++)
        {
            scan_d(type[i]);
            scan_d(num[i]);

            if (type[i] == 1)
            {
                ans[i] = (ll(ans[i - 1]) * ll(num[i] % MOD)) % MOD;
                printf("%d\n", ans[i]);
            }
            else
            {
                che[num[i]] = 0;
                ll last = 1;
                for (int j = 1; j < i; j++)
                {
                    if (che[j] && type[j] == 1)
                    {
                        last = (last * (num[j] % MOD)) % MOD;
                    }
                }

                ans[i] = last;
                printf("%d\n", ans[i]);
            }
        }
    }

    return 0;
}