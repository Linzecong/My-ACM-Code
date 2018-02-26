#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <deque>
#include <math.h>
using namespace std;
using namespace std;

typedef long long int ll;

const int MAXN = 200000; //用DC3要开三倍大小

int wa[MAXN], wb[MAXN], wv[MAXN], JS[MAXN]; //计算SA用的辅助数组

int rk[MAXN], height[MAXN], SA[MAXN]; //三个常用数组

/***后缀数组倍增解法***/
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *r, int *SA, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++)
        JS[i] = 0;
    for (i = 0; i < n; i++)
        JS[x[i] = r[i]]++;
    for (i = 1; i < m; i++)
        JS[i] += JS[i - 1];
    for (i = n - 1; i >= 0; i--)
        SA[--JS[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (SA[i] >= j)
                y[p++] = SA[i] - j;
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < m; i++)
            JS[i] = 0;
        for (i = 0; i < n; i++)
            JS[wv[i]]++;
        for (i = 1; i < m; i++)
            JS[i] += JS[i - 1];
        for (i = n - 1; i >= 0; i--)
            SA[--JS[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[SA[0]] = 0, i = 1; i < n; i++)
            x[SA[i]] = cmp(y, SA[i - 1], SA[i], j) ? p - 1 : p++;
    }
    return;
}
/*******************/

/***后缀数组DC3解法***/
#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x)*3 + 1 : ((x)-tb) * 3 + 2)
int c0(int *r, int a, int b)
{
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b)
{
    if (k == 2)
        return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
    else
        return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}
void sort(int *r, int *a, int *b, int n, int m)
{
    int i;
    for (i = 0; i < n; i++)
        wv[i] = r[a[i]];
    for (i = 0; i < m; i++)
        JS[i] = 0;
    for (i = 0; i < n; i++)
        JS[wv[i]]++;
    for (i = 1; i < m; i++)
        JS[i] += JS[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--JS[wv[i]]] = a[i];
    return;
}
void DC3(int *r, int *SA, int n, int m)
{
    int i, j, *rn = r + n, *SAn = SA + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++)
        if (i % 3 != 0)
            wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc)
        DC3(rn, SAn, tbc, p);
    else
        for (i = 0; i < tbc; i++)
            SAn[rn[i]] = i;
    for (i = 0; i < tbc; i++)
        if (SAn[i] < tb)
            wb[ta++] = SAn[i] * 3;
    if (n % 3 == 1)
        wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++)
        wv[wb[i] = G(SAn[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        SA[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++)
        SA[p] = wa[i++];
    for (; j < tbc; p++)
        SA[p] = wb[j++];
    return;
}
/***********************/

//计算rank和height数组
void calheight(int *r, int *SA, int n)
{
    //  memset(height,0,sizeof(height));
    //  memset(rk,0,sizeof(rk));
    int i, j, k = 0;
    for (i = 1; i <= n; i++)
        rk[SA[i]] = i;
    for (i = 0; i < n; height[rk[i++]] = k)
        for (k ? k-- : 0, j = SA[rk[i] - 1]; r[i + k] == r[j + k]; k++)
            ;
}

int N;         //字符串长度
int str[MAXN]; //主字符串

/*****RMQ部分*****/
int ST[MAXN][16];
void RMQ(int *a)
{
    int m = (int)(log(N * 1.0) / log(2.0));
    for (int i = 1; i <= N; i++)
        ST[i][0] = a[i];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
            ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
int query(int a, int b)
{
    int k = int(log(b - a + 1.0) / log(2.0));
    return min(ST[a][k], ST[b - (1 << k) + 1][k]);
}

//计算两个后缀的最长公共前缀长度
int calMaxPrefix(int a, int b)
{
    a = rk[a];
    b = rk[b];
    if (a > b)
        swap(a, b);
    return query(a + 1, b);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int qqq = 0; qqq < t; qqq++)
    {

        scanf("%d", &N);

        char temp[10];
        for (int i = 0; i < N; i++)
        {
            scanf("%s", temp);
            str[i] = temp[0] - 'a' + 1;
        }
        str[N] = 0;

        DC3(str, SA, N + 1, 10);
        calheight(str, SA, N);

        //debug

        // for (int i = 0; i <= N + 1; i++)
        //     printf("%d ", rk[i]);
        // printf("\n");
        // for (int i = 0; i <= N + 1; i++)
        //     printf("%d ", SA[i]);
        // printf("\n");
        // for (int i = 0; i <= N + 1; i++)
        //     printf("%d ", height[i]);
        // printf("\n");

        int ans = 1;
        RMQ(height);
        for (int len = 1; len <= N; len++)
        {
            for (int j = 0; j + len < N; j += len)
            {
                int hou = calMaxPrefix(j, j + len);
                int h_ans = hou / len + 1;
                int q = j - (len - hou % len);
                if (q >= 0)
                {
                    int qian = calMaxPrefix(q, q + len);
                    int q_ans = qian / len + 1;
                    ans = max(ans, max(h_ans, q_ans));
                }
                ans = max(ans, h_ans);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
