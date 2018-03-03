#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <deque>
#include <math.h>
#include <stdio.h>
#include <stack>
using namespace std;
using namespace std;

typedef long long int ll;

const int MAXN = 300005;
int N, M;

int indegree[205];

int G[205][205];

int ans[205];
bool flag;

void topologysort()
{
    int i, k = N;

    while (k >= 1)
    {
        for (i = N; i >= 1; i--)
        {
            if (indegree[i] == 0)
            {
                for (int j = 1; j <= N; j++)
                    if (G[i][j] == 1)
                        indegree[j]--;
                    indegree[i]=-1;
                ans[i] = k--;
                break;
            }
        }
        if (i == 0)
        {
            flag = 0;
            break;
        }
    }
}

int main()
{

    int T;
    scanf("%d", &T);
    while (T--)
    {
        flag = 1;
        memset(G, 0, sizeof(G));
        memset(indegree, 0, sizeof(indegree));

        scanf("%d%d", &N, &M);
        int a, b;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);

            if (G[b][a] == 0)
            {
                G[b][a] = 1;
                indegree[a]++;
            }
        }

        topologysort();

        if (flag)
        {
            for (int i = 1; i < N; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[N]);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}