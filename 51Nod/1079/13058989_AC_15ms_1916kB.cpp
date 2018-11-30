#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
typedef long long int ll;

//最大公约数
ll gcd(ll a, ll b)
{
    ll c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

//扩展欧几里得：求 gcd(a,b)=ax+by；
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = a;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

//最小公倍数
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

//快速密取模
ll mpow(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a) % c;
        b /= 2;
        a = (a * a) % c;
    }
    return ans;
}

//快速积取模
ll mmul(ll a, ll b, ll c)
{
    ll ans = 0;
    a = a % c;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans + a) % c;
        b /= 2;
        a = (a + a) % c;
    }
    return ans;
}

//素数欧拉筛法
const int MAXP = 100007;
int prime[MAXP];
bool check[MAXP];
int tot = 0;
void getprime()
{
    memset(check, 0, sizeof(check));
    for (int i = 2; i <= MAXP; i++)
    {
        if (!check[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > MAXP)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

//素数测试
bool MillerRabintest(ll n, ll a, ll d)
{
    if (n == 2)
        return true;
    if (n == a)
        return false;
    if (!(n & 1))
        return false;
    while (!(d & 1))
        d >>= 1;
    ll t = mpow(a, d, n);
    while (d != n - 1 && t != n - 1 && t != 1)
    {
        t = t * t % n; //下面介绍防止溢出的办法，对应数据量为10^18次方；
        d <<= 1;
    }
    return t == n - 1 || (d & 1) == 1; //要么t能变成n-1，要么一开始t就等于1
}

bool isprime(ll n)
{
    int a[] = {2, 3, 5, 7}; //或者自己生成[2,N-1]以内的随机数rand（）%（n-2）+2
    for (int i = 0; i <= 3; ++i)
    {
        if (n == a[i])
            return true;
        if (!MillerRabintest(n, a[i], n - 1))
            return false;
    }
    return true;
}

//乘法逆元，即将一个除数变为乘数，就是求倒数
ll inv(ll a, ll mod)
{
    ll x, y;
    exgcd(a, mod, x, y);
    return ((x % mod) + mod) % mod;

    //return mpow(a,mod-2,mod);//mod是质数才能用
}

//中国剩余定理
ll chineseremainder(ll yu[], ll chu[], int num)
{
    ll i, d, x, y, m, n, ret;
    ret = 0;
    n = 1;
    for (int i = 0; i < num; i++)
        n *= chu[i];
    for (int i = 0; i < num; i++)
    {
        m = n / chu[i];
        d = exgcd(chu[i], m, x, y);
        ret = (ret + y * m * yu[i]) % n;
    }
    return (n + ret % n) % n;
}

ll yu[100],chu[100];  
int main()
{
ll n;  
    while(cin>>n)  
    {  
        for(ll i=0;i<n;i++)  
        {  
            cin>>chu[i]>>yu[i];  
        }  
        ll ans=chineseremainder(yu,chu,n);  
        cout<<ans<<endl;  
    }  
   
    return 0;
}
