#include <cstdio>
#include <cstring>
#define ll long long
ll dp[20][5][2][5];
int n;

ll DFS(int num, int t, int ok, int last, int st)
{
    if(num == n)
    {
        if(t >= 3 && ok)
            return 1;
        else
            return 0;
    }
    if(dp[num][t][ok][last] != -1)
        return dp[num][t][ok][last];
    ll tmp = 0;
    for(int i = 1; i <= 4; i++)
    {
        int tt, ok2 = 0, curst = 1 << (i - 1);
        if((i == 1 && last == 4) || (i == 4 && last == 1))
            ok2 = 1;
        if(st & curst)
            tt = t;
        else
            tt = t + 1;
        if(tt > 3)
            tt = 3;
        tmp += DFS(num + 1, tt, ok || ok2, i, st | curst);
    }
    return dp[num][t][ok][last] = tmp;
}

int main()
{
    while(scanf("%d", &n) != EOF && n != -1)
    {
        memset(dp, -1, sizeof(dp));
        printf("%d: %lld\n", n, DFS(0, 0, 0, 0, 0));
    }
}