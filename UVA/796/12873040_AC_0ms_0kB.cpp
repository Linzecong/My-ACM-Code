#include <iostream>
#include <vector>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;

int G[1005][1005];
int N;

int vistime = 0;
int dfn[1005], low[1005];
vector<pair<int, int>> GBs;

void GB(int v, int u)
{
    dfn[v] = low[v] = ++vistime;
    for (int i = 0; i < N; i++)
    {
        if (G[v][i])
        {
            if (!dfn[i])
            {
                GB(i, v);
                low[v] = min(low[v], low[i]);
                if (low[i] > dfn[v])
                    GBs.push_back(make_pair(min(v, i),max(v,i)));
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

        memset(G, 0, sizeof(G));
        vistime = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        GBs.clear();

        int temp;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &temp);
            int num;
            scanf(" (%d) ", &num);
            int temp2;
            for (int j = 0; j < num; j++)
            {
                scanf("%d", &temp2);
                G[temp][temp2] = G[temp2][temp] = 1;
                // cout<<temp2<<endl;
            }
        }

        for (int i = 0; i < N; i++)
            if (!dfn[i])
                GB(i, i);
        sort(GBs.begin(), GBs.end());
        printf("%d critical links\n", (int)GBs.size());
        for (int i = 0; i < GBs.size(); i++)
            printf("%d - %d\n", GBs[i].first, GBs[i].second);
        printf("\n");
    }
}