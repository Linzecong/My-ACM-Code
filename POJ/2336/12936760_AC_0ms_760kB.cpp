#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int a[1505];

int dp1[1505];
int dp2[1505];

int main()
{
    int ttt;
    scanf("%d", &ttt);
    while (ttt--)
    {
        int n, t, m;
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        scanf("%d%d%d", &n, &t, &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", a + i);
            dp1[i] = max(dp1[max(i - n, 0)], a[i]) + 2 * t;
            dp2[i] = dp2[max(i - n, 0)] + 1;
        }
        cout << dp1[m] - t << " " << dp2[m] << endl;
    }
    return 0;
}
