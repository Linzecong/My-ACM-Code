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
using namespace std;
using namespace std;

typedef long long int ll;
const int MAXN = 505;
int P, N;

int G[MAXN][MAXN];
int X[MAXN];
int Y[MAXN];
int vis[MAXN];

bool hungry(int x)
{
    for (int i = 1; i <= N; i++)
    {
        if (G[x][i] && !vis[i])
        {
            vis[i] = 1;
            if (Y[i] == 0 || hungry(Y[i]))
            {
                Y[i] = x;
                X[x] = i;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(G, 0, sizeof(G));
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));

        scanf("%d%d", &P, &N);
        int temp;
        int temp2;
        for (int i = 0; i < P; i++)
        {
            scanf("%d", &temp);
            for (int j = 0; j < temp; j++)
            {
                scanf("%d", &temp2);
                G[temp2][i + 1] = 1;
            }
        }

        if (P >= N)
        {
            int ans = 0;
            for (int i = 1; i <= N; i++)
            {
                memset(vis, 0, sizeof(vis));
                if (hungry(i))
                    ans++;
            }

            if (ans == N)
            {
                int flag = 1;
                for (int j = 1; j <= P; j++)
                {
                    if (Y[j] == 0)
                    {
                        int have = 0;
                        for (int k = 1; k <= N; k++)
                        {
                            if (G[k][j] == 1)
                                have = 1;
                        }
                        if (have == 0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
                printf("NO\n");
        }
        else
        {
            if (P < N)
            {
                int ans = 0;
                for (int i = 1; i <= N; i++)
                {
                    memset(vis, 0, sizeof(vis));
                    if (hungry(i))
                        ans++;
                }

                if (ans == P)
                {
                    printf("YES\n");
                }
                else
                    printf("NO\n");
            }
        }
    }

    return 0;
}
