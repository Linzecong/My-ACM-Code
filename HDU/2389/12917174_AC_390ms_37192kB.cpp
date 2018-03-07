#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;
const int MAXN = 3005;



struct point
{
    int x, y, s;
};

point man[MAXN];
point san[MAXN];
int M, N;

//快速二分图匹配算法，优化的匈牙利算法。
int G[MAXN][MAXN];
int vis[MAXN];
int Y[MAXN];
int X[MAXN];
int dx[MAXN], dy[MAXN];
int dis;
bool searchpath()
{
    queue<int> Q;
    dis = 0x3f3f3f3f;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < N; i++)
    {
        //cx[i]表示左集合i顶点所匹配的右集合的顶点序号
        if (X[i] == -1)
        {
            //将未遍历的节点 入队 并初始化次节点距离为0
            Q.push(i);
            dx[i] = 0;
        }
    }
    //广度搜索增广路径
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis)
            break;
        //取右侧节点
        for (int v = 0; v < M; v++)
        {
            //右侧节点的增广路径的距离
            if (G[u][v] && dy[v] == -1)
            {
                dy[v] = dx[u] + 1; //v对应的距离 为u对应距离加1
                if (Y[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[Y[v]] = dy[v] + 1;
                    Q.push(Y[v]);
                }
            }
        }
    }
    return dis != 0x3f3f3f3f;
}

int hungry_fast(int x)
{
    for (int i = 0; i < M; i++)
    {
        if (G[x][i] && !vis[i] && dy[i] == dx[x] + 1)
        {
            vis[i] = 1;
            if (Y[i] != -1 && dy[i] == dis)
                continue;
            if (Y[i] == -1 || hungry_fast(Y[i]))
            {
                Y[i] = x;
                X[x] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int ttt;
    scanf("%d",&ttt);
    for (int qqq = 1; qqq <= ttt; qqq++)
    {
        memset(G, 0, sizeof(G));
        int T;
        scanf("%d",&T);

        scanf("%d",&N);
        int x, y, s;
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&man[i].x);
            scanf("%d",&man[i].y);
            scanf("%d",&man[i].s);
        }
        scanf("%d", &M);
        for (int i = 0; i < M; i++)
        {
            scanf("%d",&san[i].x);
            scanf("%d",&san[i].y);
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (sqrt((man[i].x - san[j].x) * (man[i].x - san[j].x) + (man[i].y - san[j].y) * (man[i].y - san[j].y)) <= T * man[i].s)
                {
                    G[i][j] = 1;
                }
            }
        }

        int ans = 0;
        memset(Y, -1, sizeof(Y));
        memset(X, -1, sizeof(X));
        while (searchpath())
        {
            memset(vis, 0, sizeof(vis));
            for (int i = 0; i < N; i++)
            {
                if (X[i] == -1)
                {
                    ans += hungry_fast(i);
                }
            }
        }

        printf("Scenario #%d:\n%d\n\n", qqq, ans);
    }

    return 0;
}
