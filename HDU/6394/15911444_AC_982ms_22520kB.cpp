#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 100010;
typedef long long ll;

struct edge
{
    int u;
    int v;
    int next;
} e[MAXN << 1];
int head[MAXN], edge_num = 0;
void insert_edge(int u, int v)
{
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}
int W[MAXN];
int N;

/********树分块部分********/
int blocksize, blocknum;
int block[MAXN];         //dfs序属于哪一块
int in[MAXN], out[MAXN]; //根据dfs序，记录每一块的开始和结束
int dfn[MAXN];           //dfs序
int tot = 0;
void initBlock()
{
    blocksize = sqrt(N);
    blocknum = N / blocksize + 1;
    for (int i = 1; i <= N; i++) //分块
        block[i] = (i - 1) / blocksize + 1;
    for (int i = 1; i <= blocknum; i++) //记录出点和入点
    {
        in[i] = (i - 1) * blocknum + 1;
        out[i] = i * blocksize;
    }
    out[blocknum] = N; //别忘了这句
}
void dfs(int u, int f) //计算dfs序
{

    dfn[u] = ++tot;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == f)
            continue;
        dfs(v, u);
    }
}
/******树分块部分结束*******/

/******倍增部分********/
int fa[25][MAXN];
void initST()
{
    fa[0][1] = -1; //根
    for (int k = 0; k < 20; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (fa[k][i] < 0)
                fa[k + 1][i] = -1;
            else
                fa[k + 1][i] = fa[k][fa[k][i]]; //DP
        }
    }
}

int Find(int x, int value) //学习一下写法
{
    int d = value;
    int tmp = 0;
    while (d)
    {
        int k = 0;
        while ((1 << (k + 1)) <= d)
            k++;
        tmp = fa[k][x];
        x = tmp;
        d -= (1 << k);
    }
    return x;
}
/******倍增部分结束********/

int cn[MAXN], nxt[MAXN], pre[MAXN]; //跳出本块的次数,跳向的下一块的点,这个点会跳向的位置,下标都是dfn。
void dfs2(int u, int f)
{
    int tmp = Find(u, W[u]);
    pre[dfn[u]] = dfn[tmp];
    //dfs序性质，可以很方便判断是否已经跳出本块
    if (dfn[tmp] < in[block[dfn[u]]])
    {
        cn[dfn[u]] = 1;
        nxt[dfn[u]] = dfn[tmp];
    }
    else
    {
        cn[dfn[u]] = cn[dfn[tmp]] + 1; //肯定是从上往下遍历，所以这么做是可以的，递归思想
        nxt[dfn[u]] = nxt[dfn[tmp]];
    }
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == f)
            continue;
        dfs2(v, u);
    }
}

void update(int u, int v)
{
    int tmp = Find(u, v);
    W[u] = v;
    pre[dfn[u]] = dfn[tmp];
    if (dfn[tmp] < in[block[dfn[u]]])
    {
        cn[dfn[u]] = 1;
        nxt[dfn[u]] = dfn[tmp];
    }
    else
    {
        cn[dfn[u]] = cn[dfn[tmp]] + 1;
        nxt[dfn[u]] = nxt[dfn[tmp]];
    }
    for (int i = dfn[u] + 1; i <= out[block[dfn[u]]]; i++) //块内暴力更新
    {
        if (pre[i] >= in[block[i]]) //如果下一跳也在块内，那么很有可能会影响cn的计算，所以要算一算
        {
            cn[i] = cn[pre[i]] + 1;
            nxt[i] = nxt[pre[i]];
        }
    }
}

int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += cn[x];
        x = nxt[x];
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(head, -1, sizeof(head));
        edge_num = 0;
        tot = 0;

        scanf("%d", &N);
        int x, y;

        for (int i = 2; i <= N; i++)
        {
            scanf("%d", &x);
            insert_edge(i, x);
            insert_edge(x, i);
            fa[0][i] = x;
        }
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &W[i]);
        }
        initBlock();
        dfs(1, -1);
        initST();
        dfs2(1, -1);
        int Q;
        scanf("%d", &Q);
        while (Q--)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                int x;
                scanf("%d", &x);
                printf("%d\n", query(dfn[x]));
            }
            else
            {
                scanf("%d%d", &x, &y);
                update(x, y);
            }
        }
    }

    return 0;
}
