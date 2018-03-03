#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int G[105][105];
int N;

int vistime = 0;
int root = 1;
int dfn[105], low[105];
int isGD[105];
void GD(int v, int u)
{
    int child = 0;
    dfn[v] = low[v] = ++vistime;
    for (int i = 1; i <= N; i++)
    {
        if (G[v][i])
        {
            if (!dfn[i])
            {
                child++;
                GD(i, v);
                low[v] = min(low[v], low[i]);
                if (v != root && low[i] >= dfn[v])
                    isGD[v] = 1;
                if (v == root && child > 1)
                    isGD[v] = 1;
            }
            else
            {
                if (i != u)
                    low[v] = min(low[v], dfn[i]);
            }
        }
    }
}

int main()
{
    while (~scanf("%d", &N))
    {
        if (N == 0)
            break;
        memset(G, 0, sizeof(G));
        vistime = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(isGD,0,sizeof(isGD));

        int temp;
        char c;
        while (~scanf("%d", &temp))
        {
            if (temp == 0)
                break;

            int temp2;
            while (1)
            {
                scanf("%c", &c);
                if (c == '\n')
                    break;
                scanf("%d", &temp2);
                G[temp][temp2] = G[temp2][temp] = 1;
            }
        }

        GD(1, 1);
        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (isGD[i])
                ans++;
        printf("%d\n", ans);
    }
}