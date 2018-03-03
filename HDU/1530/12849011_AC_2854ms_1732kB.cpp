#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int G[55][55];
int all[200][200]; //第j个极大团所包含的节点
int some[200][200];
int none[200][200];

//all集合记录的是当前极大团中已经加入的点
//some集合记录的是可能还能加入的点（也就是说可能与R集合中所有点都有边存在的点）
//none集合记录的是已经完成极大团计数的点（作用是判重）
int ans = 0;
bool dfs(int x, int an, int sn, int nn)
{
    ans = max(ans, an);

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

int main()
{

    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &G[i][j]);

        for (int i = 1; i <= n; i++)
            some[1][i] = i;

        dfs(1, 0, n, 0);

        printf("%d\n", ans);
    }
    return 0;
}