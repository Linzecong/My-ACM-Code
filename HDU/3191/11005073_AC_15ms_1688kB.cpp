#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x7f7f7f7f;
const int N = 55;
int cost[N][N];
bool vis[N][2];
int dis[N][2];
int dp[N][2];
void Dijsktra(int n, int s, int e)
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0x7f, sizeof(dis));
    memset(dp, 0, sizeof(dp));
    dis[s][0] = 0;
    dp[s][0] = 1;
    int j;
    for(int i = 0; i < 2 * n; i++)
    {
        int min = INF;
        int x;
        int flag;
        for(j = 0; j < n; j++)
        {
            if(!vis[j][0] && dis[j][0] < min)
            {
                min = dis[j][0];
                x = j;
                flag = 0;
            }
            else if(!vis[j][1] && dis[j][1] < min)
            {
                min = dis[j][1];
                x = j;
                flag = 1;
            }

        }
        if(min == INF)
            break;
        vis[x][flag] = true;
        for(j = 0; j < n ; j++)
        {
            if(min + cost[x][j] < dis[j][0])
            {
                dis[j][1] = dis[j][0];
                dis[j][0] = min + cost[x][j];
                dp[j][1] = dp[j][0];
                dp[j][0] = dp[x][flag];
            }
            else if(min + cost[x][j] == dis[j][0])
            {
                dp[j][0] += dp[x][flag];
            }
            else if(min + cost[x][j] < dis[j][1])
            {
                dis[j][1] = min + cost[x][j];
                dp[j][1] = dp[x][flag];
            }
            else if(min + cost[x][j] == dis[j][1])
            {
                dp[j][1] += dp[x][flag];
            }
        }

    }


}
int main()
{
    int n, m, s, e;
    while(scanf("%d %d %d %d", &n, &m, &s, &e) != EOF )
    {
        int a, b, c;
        memset(cost, 0x7f, sizeof(cost));
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            cost[a][b] = c;
        }
        Dijsktra(n, s, e);
        printf("%d %d\n", dis[e][1], dp[e][1]);
    }
    return 0;
}
