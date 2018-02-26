#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int ll;
int dp[35][35];
ll X, Y, K, B;

void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 31; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
}

// 计算[0, n)中有多少个二进制含有K个1的数字
int cal(ll x)
{
    int ans = 0, tot = 0;
    for (int i = 31; i>= 1; i--)
    {
        if (x & (1 << i))
        {
            tot++;
            if (tot > K)
                break;
            x ^= (1 << i);
        }
        if ((1 << (i - 1)) <= x)
            ans += dp[i - 1][K - tot];
    }
    return ans;
}

// 将b进制的情况转化成2进制
ll change(ll x)
{
    int digit[35] = {0}, len = 0;
    while (x)
    {
        digit[++len] = x % B;
        x /= B;
    }
    int high = len;
    while (high >= 1 && digit[high] <= 1)
        high--;
    for (int i = high; i >= 1; i--)
        digit[i] = 1;
    ll res = 0;
    for (int i = len; i >= 1; i--)
        res = res * 2 + digit[i];
    return res;
}

int main()
{
    //freopen("test.txt", "r", stdin);

    init();
    while (~scanf("%lld%lld%lld%lld", &X, &Y, &K, &B))
    {
        ll x = change(X);
        ll y = change(Y);
        printf("%d\n", cal(y + 1) - cal(x));
    }
    return 0;
}
