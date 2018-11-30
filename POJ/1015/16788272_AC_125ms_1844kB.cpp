#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 200+5;
const int MAXM = 20+5;
int n, m, Fix, sub[MAXN], sum[MAXN], dp[MAXM][805];
vector<int> path[MAXM][805];
void init()//初始化
{
    memset(dp, -1, sizeof(dp));//表示所有状态都不合法
    for (int j = 0; j <= m; j++)
        for (int k = 0; k < 805; k++)
            path[j][k].clear();
}
int main()
{
    int CASE = 1;
    while (~scanf("%d%d", &n, &m) && (n+m))
    {
        for (int i = 1; i <= n; i++)
        {
            int p, d; scanf("%d%d", &p, &d);
            sub[i] = p-d;
            sum[i] = p+d;
        }
        init();
        Fix = 20*m;
        dp[0][Fix] = 0;//只有辩控差为0的状态合法,原来的0即此时的Fix
        for (int i = 1; i <= n; i++)//物品循环
        {
            for (int j = m; j >= 1; j--)//背包容量循环
            {
                for (int k = 0; k <= Fix*2; k++)//枚举辩控差循环
                {
                    if (k-sub[i] < 0 || k-sub[i] > 2*Fix) continue; //越界了,不在[0,2*Fix]中
                    if (dp[j-1][k-sub[i]] == -1) continue; //不合法的状态

                    if (dp[j][k] < dp[j-1][k-sub[i]]+sum[i])
                    {
                        dp[j][k] = dp[j-1][k-sub[i]]+sum[i];
                        path[j][k] = path[j-1][k-sub[i]];//把之前的路径复制到该位置
                        path[j][k].push_back(i);         //存储本次选的物品i
                    }
                }
            }
        }
        //寻找最小辩控差
        int state = 0;
        while(dp[m][Fix-state] == -1 && dp[m][Fix+state] == -1) state++;
        //选取辩控和最大
        if (dp[m][Fix-state] > dp[m][Fix+state]) state = Fix-state;
        else state = Fix+state;

        //计算并输出
        int ans1 = (dp[m][state]+state-Fix)/2, ans2 = (dp[m][state]-state+Fix)/2;
        printf("Jury #%d\n", CASE++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", ans1, ans2);
        for (int i = 0; i < m; i++) printf(" %d", path[m][state][i]);
        printf("\n\n");
    }
    return 0;
}

