#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 23000
int n, r[maxn], tmp[maxn];

struct Suffix
{
    int sa[maxn], rk[maxn], height[maxn];
    int t[maxn], t2[maxn], c[maxn], m;
    void init() { m = 200; }
    int cmp(int *r, int a, int b, int l) { return r[a] == r[b] && r[a + l] == r[b + l]; }
    void build()
    {
        int i, k, p, *x = t, *y = t2;
        r[n++] = 0;
        for (i = 0; i < m; i++)
            c[i] = 0;
        for (i = 0; i < n; i++)
            c[x[i] = r[i]]++;
        for (i = 1; i < m; i++)
            c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--c[x[i]]] = i;
        for (k = 1, p = 1; k < n; k *= 2, m = p)
        {
            for (p = 0, i = n - k; i < n; i++)
                y[p++] = i;
            for (i = 0; i < n; i++)
                if (sa[i] >= k)
                    y[p++] = sa[i] - k;
            for (i = 0; i < m; i++)
                c[i] = 0;
            for (i = 0; i < n; i++)
                c[x[y[i]]]++;
            for (i = 1; i < m; i++)
                c[i] += c[i - 1];
            for (i = n - 1; i >= 0; i--)
                sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (i = 1; i < n; i++)
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], k) ? p - 1 : p++;
        }
        n--;
    }
    void LCP()
    {
        int i, j, k = 0;
        for (i = 1; i <= n; i++)
            rk[sa[i]] = i;
        for (i = 0; i < n; i++)
        {
            if (k)
                k--;
            j = sa[rk[i] - 1];
            while (r[i + k] == r[j + k])
                k++;
            height[rk[i]] = k;
        }
    }
    bool judge(int len)
    {
        int l = sa[1], r = sa[1];
        for (int i = 2; i <= n; i++)
        {
            if (height[i] < len)
            {
                l = sa[i];
                r = sa[i];
                continue;
            }
            l = min(l, sa[i]);
            r = max(r, sa[i]);
            if (r - l > len)
                return true;
        }
        return false;
    }
    int BinarySearch()
    {
        int l = 0, r = n, mid, ans = 0; //注意ans=0，不然当n=1的时候返回的是没赋值的ans
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (judge(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};
int main()
{
    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d", &tmp[i]);
        for (int i = 0; i < n - 1; i++)
        {
            r[i] = tmp[i + 1] - tmp[i] + 90;
        }
        Suffix a;
        a.init();
        a.build();
        a.LCP();
        int ans = a.BinarySearch();
        if (ans < 4)
            printf("0\n");
        else
            printf("%d\n", ans + 1);
    }
}