#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

const int N = int(2e5) + 10;

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x)*3 + 1 : ((x)-tb) * 3 + 2)
int wa[N], wb[N], wv[N], ws[N];
int rk[N],height[N];
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
        ws[i] = 0;
    for (i = 0; i < n; i++)
        ws[wv[i]]++;
    for (i = 1; i < m; i++)
        ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--ws[wv[i]]] = a[i];
    return;
}
void dc3(int *r, int *sa, int n, int m)
{
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
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
        dc3(rn, san, tbc, p);
    else
        for (i = 0; i < tbc; i++)
            san[rn[i]] = i;
    for (i = 0; i < tbc; i++)
        if (san[i] < tb)
            wb[ta++] = san[i] * 3;
    if (n % 3 == 1)
        wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++)
        wv[wb[i] = G(san[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++)
        sa[p] = wa[i++];
    for (; j < tbc; p++)
        sa[p] = wb[j++];
    return;
}

void calheight(int *r, int *sa, int n)
{
    //  memset(height,0,sizeof(height));
    //  memset(rk,0,sizeof(rk));
    int i, j, k = 0;
    for (i = 1; i <= n; i++)
        rk[sa[i]] = i;
    for (i = 0; i < n; height[rk[i++]] = k)
        for (k ? k-- : 0, j = sa[rk[i] - 1]; r[i + k] == r[j + k]; k++)
            ;
}

int data[N], sa[N], n;

vector<int> S[N];

bool Judge(int k)
{
    bool flag = false;
    int i, cur = -1;
    for (i = 1; i <= n; i++) //分组
    {
        if (height[i] < k)
            S[++cur].clear();
        S[cur].push_back(i);
    }
    for (i = 1; i <= cur; i++)
    {
        int Max = -1, Min = N;
        if (S[i].size() > 1)
        {
            for (int j = 0; j < S[i].size(); j++)
            {
                Max = max(Max, sa[S[i][j]]);
                Min = min(Min, sa[S[i][j]]);
            }
            if (Max - Min > k) //严格大于
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}

int Deal()
{
    dc3(data, sa, n + 1, 200);
    calheight(data, sa, n);
    int low = 0, high = n, mid, ans = -1;
    while (low < high) //注意二分的写法
    {
        mid = (low + high) >> 1;
        if (Judge(mid))
            ans = mid, low = mid + 1;
        else
            high = mid;
    }
    return ans >= 4 ? ans + 1 : 0;
}

int main()
{
    while (scanf("%d", &n), n)
    {
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &data[i]);
        for (i = 0; i < n - 1; i++)
            data[i] = data[i + 1] - data[i] + 90; //由于要用基数排序,+90以防出现负数
        data[--n] = 0;
        printf("%d\n", Deal());
    }
    return 0;
}
/*
Input
1
2
9
1 1 1 1 1 1 1 1 1
30
25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18
82 78 74 70 66 67 64 60 65 80
0

Out
0
0
5
*/