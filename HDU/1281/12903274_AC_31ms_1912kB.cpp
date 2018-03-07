#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 105;
int map[N][N], use[N], vis[N];
int m, n, k, x[N * N], y[N * N];
int find(int x)
{
    for(int j = 1; j <= m; j++)
    {
        if(map[x][j] && !vis[j])
        {
            vis[j] = 1;
            if(use[j] == 0 || find(use[j]) == 1)
            {
                use[j] = x;
                return 1;
            }
        }
    }
    return 0;
}

int maxP()
{
    int sum = 0;
    memset(use, 0, sizeof(use));
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(find(i)) sum++;
    }
    return sum;
}

int main()
{
    int Case = 1;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        memset(map, 0, sizeof(map));

        for(int i = 1; i <= k; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            map[x[i]][y[i]] = 1;
        }
        int ans = maxP();
        int sum = 0;
        for(int i = 1; i <= k; i++)
        {
            map[x[i]][y[i]] = 0;
            int res = maxP();
            map[x[i]][y[i]] = 1;
            if(res < ans) sum++;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", Case++, sum, ans);
    }
    return 0;
}
