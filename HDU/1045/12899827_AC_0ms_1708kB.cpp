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

const int MAXN = 50;

char maze[MAXN][MAXN];

int G[MAXN][MAXN];
int node;

int cnt;
int num[MAXN][MAXN][2];
int ptn[MAXN];

int used[MAXN];
int Y[MAXN];
bool hungry(int x)
{
    for (int i = 1; i <= node; i++)
    {
        if (G[x][i] && !used[i])
        {
            used[i] = 1;
            if (Y[i] == 0 || hungry(Y[i]))
            {
                Y[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int N;
    while (~scanf("%d", &N))
    {
        if(N==0)
            break;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", maze[i]);
        }
        memset(G, 0, sizeof(G));
        node = 1;
        memset(num, 0, sizeof(num));
        cnt = 1;
        memset(ptn, 0, sizeof(ptn));
        memset(Y, 0, sizeof(Y));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (maze[i][j] == 'X')
                {
                    node++;
                }
                else
                {
                    num[i][j][0] = node;
                }
            }
            node++;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (maze[j][i] == 'X')
                {
                    node++;
                }
                else
                {
                    num[j][i][1] = node;
                }
            }
            node++;
        }

        for (int i = 0; i < N; i++)
        {
            for(int j=0;j<N;j++)
            if (num[i][j][0] != 0 && num[i][j][1] != 0)
            {
                G[num[i][j][0]][num[i][j][1]] = 1;
            }
        }

        int ans = 0;
        for (int i = 1; i <= node; i++)
        {
            memset(used, 0, sizeof(used));
            if (hungry(i))
                ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}
