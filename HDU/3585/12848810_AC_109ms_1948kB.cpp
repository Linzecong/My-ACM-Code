#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;
struct point
{
    double x;
    double y;
    int index;
    point(int a, int b, int c)
    {
        x = a;
        y = b;
        index = c;
    }
};

int n, k;
int G[55][55];
double dis[55][55];
int all[200][200]; //第j个极大团所包含的节点
int some[200][200];
int none[200][200];

vector<point> ps;
vector<double> ans;

bool dfs(int x, int an, int sn, int nn)
{

    if (an >= k)
        return 1;

    if (an + sn < k)
        return 0;

    int key = some[x][1];
    for (int j = 1; j <= sn; j++)
    {
        int v = some[x][j];
        int tsn = 0;
        int tnn = 0;

        //剪枝，与key相连的，必被搜索过
        if (G[key][v])
            continue;

        for (int i = 1; i <= an; i++)
            all[x + 1][i] = all[x][i];
        all[x + 1][an + 1] = v;

        for (int i = 1; i <= sn; i++)
            if (G[v][some[x][i]])
                some[x + 1][++tsn] = some[x][i];

        for (int i = 1; i <= nn; i++)
            if (G[v][none[x][i]])
                none[x + 1][++tnn] = none[x][i];

        if (dfs(x + 1, an + 1, tsn, tnn))
            return 1;

        some[x][j] = 0;
        none[x][++nn] = v;
    }
    return 0;
}

bool judge(int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                if (dis[i][j] >= ans[m])
                {
                    G[i][j] = 1;
                }
                else
                {
                    G[i][j] = 0;
                }
        }
    }
    for (int i = 1; i <= n; i++)
        some[1][i] = i;

    if (dfs(1, 0, n, 0))
        return 1;
    else
        return false;
}

int main()
{

    int a, b;
    while (~scanf("%d%d", &n, &k))
    {
        ps.clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a, &b);
            ps.push_back(point(a, b, i));
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    dis[i][j] = sqrt((ps[i - 1].x - ps[j - 1].x) * (ps[i - 1].x - ps[j - 1].x) + (ps[i - 1].y - ps[j - 1].y) * (ps[i - 1].y - ps[j - 1].y));
                    ans.push_back(dis[i][j]);
                    //cout<<sqrt((ps[i - 1].x - ps[j - 1].x) * (ps[i - 1].x - ps[j - 1].x) + (ps[i - 1].y - ps[j - 1].y) * (ps[i - 1].y - ps[j - 1].y))<<endl;
                }
            }
        }

        sort(ans.begin(), ans.end());

        int l = 0, r = unique(ans.begin(), ans.end()) - ans.begin();

        while (l < r)
        {
            int m = (l + r) / 2;
            if (judge(m))
            {
                l = m + 1;
            }
            else
                r = m;
        }

        //cout<<l<<endl;
        printf("%.2lf\n", ans[l - 1]);
    }
    return 0;
}