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

int F, N, D;
int Fn[MAXN];
int Dn[MAXN];
int in[MAXN];
int on[MAXN];
int cnt = 1; //点的总个数，下标从1开始

//最大流部分
/*Dinic算法
    Edmonds-Karp算法每找到一条增广路径进行增广操作之后都再次回到原点重新进行BFS，这样效率较低。Dinic算法是在找到一条增广路径，增广操作完之后，并不回溯到源点，而是回到距离源点最近的边上流量为0的边的起点。因为每次增广操作，都会使得增广路径上的某些边的流量变为0，这样这条增广路径上的某些边就无法再走，需要回溯，但是回溯并不需要回溯到源点，只需要回溯到一点A，使得从源点到点A的路径上的流量不为0，且点A尽可能靠近汇点（为了遍历所有情况）即可。 
    具体的算法流程是： 
1. 先用BFS对网络进行分层，分层是指按照距离源点的最近距离大小对各个点进行标号。 
2. 然后利用DFS从前一层向后一层反复 每次选择增广路径的时候，从点u总是选择满足关系 dist[v] = dist[u] + 1的点v，这样u->v的路径肯定属于某条最短路。 
3. 找到一条增广路径之后进行增广操作 
4.路增广操作之后进行回溯，将点u回溯到点A，使得从源点到点A的路径上流量不为0，且点A尽可能靠近汇点径
5. 从点u开始继续选择可行点v（满足 dist[v] = dist[u] + 1），直到汇点，这样就又找到一条增广路径....
6. 直到点u回溯到源点，再回到1继续操作，直到在分层操作时，无法用BFS找到从源到汇的路径。
*/

int G[MAXN][MAXN]; //流量图
int layer[MAXN];   //保存标号所属层
bool vis[MAXN];
bool countLayer(int s, int e) //宽搜
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
            if (tmp == e) //即找到一条增广路径
            {
                int minn = INF;
                int min_index = 0;
                //找到最小的流量
                for (int i = 1; i < q.size(); i++)
                {
                    if (G[q[i - 1]][q[i]] && G[q[i - 1]][q[i]] < minn)
                    {
                        minn = G[q[i - 1]][q[i]];
                        min_index = i - 1;
                    }
                }
                //建立反向边
                for (int i = 1; i < q.size(); i++)
                {
                    G[q[i - 1]][q[i]] -= minn;
                    G[q[i]][q[i - 1]] += minn;
                }
                //回溯到最小的流量所属的层
                while (q.size() && q.back() != min_index)
                {
                    vis[q.back()] = false;
                    q.pop_back();
                }
                flow += minn; //更新最大流
            }
            else
            {
                //深搜
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

    while (~scanf("%d%d%d", &N, &F, &D))
    {

        memset(G, 0, sizeof(G));

        cnt = 1;

        int S = cnt++;
        for (int i = 1; i <= F; i++)
        {
            Fn[i] = cnt++;
            G[S][Fn[i]] = 1;
        }

        for (int i = 1; i <= D; i++)
            Dn[i] = cnt++;
        for (int i = 1; i <= N; i++)
        {
            in[i] = cnt++;
            on[i] = cnt++;
            G[in[i]][on[i]] = 1;
        }
        int T = cnt++;
        for (int i = 1; i <= D; i++)
            G[Dn[i]][T] = 1;

        int a, b, c;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &a, &b);
            for (int j = 0; j < a; j++)
            {
                scanf("%d", &c);
                G[Fn[c]][in[i]] = 1;
            }
            for (int j = 0; j < b; j++)
            {
                scanf("%d", &c);
                G[on[i]][Dn[c]] = 1;
            }
        }

        int maxnflow = Max_Flow_Dinic(S, T);
        printf("%d\n", maxnflow);
    }
    return 0;
}