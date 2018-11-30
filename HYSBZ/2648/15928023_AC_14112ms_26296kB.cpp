#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
const int MAXN = 800010;
const int INF = 0x3f3f3f3f;
typedef long long ll;
inline bool scan_d(int &num)
{
    char in;
    bool IsN = false;
    in = getchar();
    if (in == EOF)
        return false;
    while (in != '-' && (in < '0' || in > '9'))
        in = getchar();
    if (in == '-')
    {
        IsN = true;
        num = 0;
    }
    else
        num = in - '0';
    while (in = getchar(), in >= '0' && in <= '9')
    {
        num *= 10, num += in - '0';
    }
    if (IsN)
        num = -num;
    return true;
}
struct node
{
    int d[2];
    int l, r;
    int Max[2];
    int Min[2];
} t[MAXN];

int k1, k2, k3;
int N, M;
int ans;
int cmpd;
int root;

inline bool cmp(node a, node b)
{
    if (a.d[cmpd] == b.d[cmpd])
        return a.d[!cmpd] < b.d[!cmpd];
    return a.d[cmpd] < b.d[cmpd];
}

void kd_updata(int p)
{
    if (t[p].l)
    {
        if (t[p].Max[0] < t[t[p].l].Max[0])
            t[p].Max[0] = t[t[p].l].Max[0];
        if (t[p].Min[0] > t[t[p].l].Min[0])
            t[p].Min[0] = t[t[p].l].Min[0];
        if (t[p].Max[1] < t[t[p].l].Max[1])
            t[p].Max[1] = t[t[p].l].Max[1];
        if (t[p].Min[1] > t[t[p].l].Min[1])
            t[p].Min[1] = t[t[p].l].Min[1];
    }
    if (t[p].r)
    {
        if (t[p].Max[0] < t[t[p].r].Max[0])
            t[p].Max[0] = t[t[p].r].Max[0];
        if (t[p].Min[0] > t[t[p].r].Min[0])
            t[p].Min[0] = t[t[p].r].Min[0];
        if (t[p].Max[1] < t[t[p].r].Max[1])
            t[p].Max[1] = t[t[p].r].Max[1];
        if (t[p].Min[1] > t[t[p].r].Min[1])
            t[p].Min[1] = t[t[p].r].Min[1];
    }
}

int kd_build(int l, int r, int D)
{
    int m = (l + r) / 2;
    cmpd = D;
    nth_element(t + l + 1, t + m + 1, t + r + 1, cmp);
    t[m].Max[0] = t[m].Min[0] = t[m].d[0];
    t[m].Max[1] = t[m].Min[1] = t[m].d[1];

    if (l != m)
        t[m].l = kd_build(l, m - 1, !D);
    if (r != m)
        t[m].r = kd_build(m + 1, r, !D);
    kd_updata(m);
    return m;
}

void kd_insert(int now)
{
    int D = 0, p = root;
    while (1)
    {
        if (t[now].Max[0] > t[p].Max[0])
            t[p].Max[0] = t[now].Max[0];
        if (t[now].Max[1] > t[p].Max[1])
            t[p].Max[1] = t[now].Max[1];
        if (t[now].Min[0] < t[p].Min[0])
            t[p].Min[0] = t[now].Min[0];
        if (t[now].Min[1] < t[p].Min[1])
            t[p].Min[1] = t[now].Min[1];

        if (t[now].d[D] >= t[p].d[D])
        {
            if (t[p].r == 0)
            {
                t[p].r = now;
                return;
            }
            else
                p = t[p].r;
        }
        else
        {
            if (t[p].l == 0)
            {
                t[p].l = now;
                return;
            }
            else
                p = t[p].l;
        }
        D = !D;
    }
}

inline int dist(int p1, int px, int py)
{
    int dis = 0;
    if (px < t[p1].Min[0])
        dis += t[p1].Min[0] - px;
    if (px > t[p1].Max[0])
        dis += px - t[p1].Max[0];
    if (py < t[p1].Min[1])
        dis += t[p1].Min[1] - py;
    if (py > t[p1].Max[1])
        dis += py - t[p1].Max[1];
    return dis;
}

void kd_ask(int p)
{
    int dl, dr, d0;
    d0 = abs(t[p].d[0] - k2) + abs(t[p].d[1] - k3);
    if (d0 < ans)
        ans = d0;

    if (t[p].l)
        dl = dist(t[p].l, k2, k3);
    else
        dl = 0x7f7f7f7f;
    if (t[p].r)
        dr = dist(t[p].r, k2, k3);
    else
        dr = 0x7f7f7f7f;

    if (dl < dr)
    {
        if (dl < ans)
            kd_ask(t[p].l);
        if (dr < ans)
            kd_ask(t[p].r);
    }
    else
    {
        if (dr < ans)
            kd_ask(t[p].r);
        if (dl < ans)
            kd_ask(t[p].l);
    }
}

int main()
{

    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scan_d(t[i].d[0]);
        scan_d(t[i].d[1]);
    }

    root = kd_build(1, N, 0);

    for (int i = 0; i < M; i++)
    {
        scan_d(k1);
        scan_d(k2);
        scan_d(k3);

        if (k1 == 1)
        {
            N++;
            t[N].Max[0] = t[N].Min[0] = t[N].d[0] = k2;
            t[N].Max[1] = t[N].Min[1] = t[N].d[1] = k3;
            kd_insert(N);
        }
        else
        {
            ans = INF;
            kd_ask(root);
            printf("%d\n", ans);
        }
    }

    return 0;
}
