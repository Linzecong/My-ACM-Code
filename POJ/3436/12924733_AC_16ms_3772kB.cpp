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
const int MAXN = 505;
const int INF = 0x3f3f3f3f;

int P, N;
int w[MAXN];
int ip[MAXN][MAXN];
int op[MAXN][MAXN];
int cnt = 1;
int no[MAXN][MAXN];
int in[MAXN];
int on[MAXN];
int Gt[MAXN][MAXN];
int ans[MAXN][3];

//最大流部分 Dinic算法
int G[MAXN][MAXN];
int layer[MAXN];
bool vis[MAXN];

bool countLayer(int s, int e)
{
    layer[s] = 0;
    queue<int> q;
    q.push(s);
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i <= e; i++)
        {
            if (G[tmp][i] && !vis[i])
            {
                layer[i] = layer[tmp] + 1;
                if (i == e)
                {
                    return true;
                }
                vis[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int Max_Flow_Dinic(int s, int e)
{
    int flow = 0;
    deque<int> q;
    while (countLayer(s, e))
    {
        memset(vis, 0, sizeof(vis));
        vis[s] = true;
        q.push_back(s);
        while (!q.empty())
        {
            int tmp = q.back();
            if (tmp == e)
            {
                int minn = INF;
                int min_index = 0;
                for (int i = 1; i < q.size(); i++)
                {
                    if (G[q[i - 1]][q[i]] && G[q[i - 1]][q[i]] < minn)
                    {
                        minn = G[q[i - 1]][q[i]];
                        min_index = i - 1;
                    }
                }
                for (int i = 1; i < q.size(); i++)
                {
                    G[q[i - 1]][q[i]] -= minn;
                    G[q[i]][q[i - 1]] += minn;
                }
                while (q.size() && q.back() != min_index)
                {
                    vis[q.back()] = false;
                    q.pop_back();
                }
                flow += minn;
            }
            else
            {
                bool flag = false;
                for (int i = 1; i <= e; i++)
                {
                    if (G[tmp][i] && !vis[i] && layer[i] == layer[tmp] + 1)
                    {
                        vis[i] = true;
                        q.push_back(i);
                        flag = true;
                        break;
                    }
                }
                if (!flag && q.size())
                {
                    q.pop_back();
                }
            }
        }
    }
    return flow;
}

int main()
{

    while (~scanf("%d%d", &P, &N))
    {

        memset(G, 0, sizeof(G));
        memset(no, 0, sizeof(no));
        cnt = 0;

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &w[i]);
            for (int j = 0; j < P; j++)
                scanf("%d", &ip[i][j]);
            for (int j = 0; j < P; j++)
                scanf("%d", &op[i][j]);
        }

        int S = cnt++;

        for (int i = 0; i < N; i++)
        {
            G[cnt][cnt + 1] = w[i];
            no[cnt][cnt + 1] = 1;
            in[i] = cnt;
            on[i] = cnt + 1;
            cnt++;
            cnt++;
        }

        int T = cnt++;

        for (int i = 0; i < N; i++)
        {
            int havei = 0;
            int haveo = 0;
            for (int j = 0; j < P; j++)
            {
                if (ip[i][j] == 1)
                    havei++;
                if (op[i][j] == 1)
                    haveo++;
            }
            if (havei == 0)
            {
                G[S][in[i]] = INF;
                no[S][in[i]] = 1;
            }

            if (haveo == P)
            {
                G[on[i]][T] = INF;
                no[on[i]][T] = 1;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                bool flag = 1;
                for (int k = 0; k < P; k++)
                {
                    if (ip[j][k] == 2)
                        continue;

                    if (ip[j][k] != op[i][k])
                        flag = 0;
                }
                if (flag)
                    G[on[i]][in[j]] = INF;
            }
        }

        memcpy(Gt, G, sizeof(G));
        int maxnflow = Max_Flow_Dinic(S, T);
        int num = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (no[on[i]][in[j]])
                    continue;

                if (G[on[i]][in[j]] != Gt[on[i]][in[j]] && Gt[on[i]][in[j]] > G[on[i]][in[j]])
                {
                    ans[num][0] = i;
                    ans[num][1] = j;
                    ans[num][2] = Gt[on[i]][in[j]] - G[on[i]][in[j]];
                    num++;
                }
            }
        }

        printf("%d %d\n", maxnflow, num);
        for (int i = 0; i < num; i++)
        {
            printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2]);
        }
    }
    return 0;
}