#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int num[100001], dp[100001];
// dp[i] 存储前 i 项的最大字段和 
int main()
{
    int n, max, sum, ans;
    while(scanf("%d", &n), n)
    {
        sum = 0;
        max = -0x3fffffff;
        //memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            sum += num[i];
            if(sum > max)
                max = sum;
            dp[i] = max;
            if(sum < 0)
                sum = 0;
        }
        dp[0] = ans = max = -0x3fffffff;
        sum = 0;
        for(int i = n; i > 0; --i) // 逆向遍历 
        {
            sum += num[i];
            if(sum > max)
                max = sum;
            if(ans < max+dp[i-1])
                ans = max+dp[i-1];
            if(sum < 0)
                sum = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}