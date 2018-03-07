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

const int MAXN = 500;

int G[MAXN][MAXN]; //连线
int ans1[MAXN], ans2[MAXN];
int cnt;

//二分图匹配部分
int used[MAXN];
int match[MAXN];
int N;
bool hungry(int x)
{
    for (int i = 1; i <= N; i++)
    {
        if (G[x][i] && !used[i])
        {
            used[i] = 1;
            if (match[i] == 0 || hungry(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    while (~scanf("%d", &N))
    {
        memset(G, 0, sizeof(G));
        memset(match, 0, sizeof(match));
        cnt = 0;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &G[i][j]);

        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            memset(used, 0, sizeof(used));
            if (hungry(i))
                ans++;
        }

        if (ans == N)
        {

            for (int i = 1; i <= N; i++)
            {
                if (i != match[i])
                {
                    for (int j = i + 1; j <= N; j++)
                    {
                        if (match[j] == i)
                        {
                            ans1[cnt] = i;
                            ans2[cnt] = j;
                            cnt++;
                            swap(match[i], match[j]);
                        }
                    }
                }
            }
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++){
                printf("C %d %d\n",ans1[i],ans2[i]);
            }
        }
        else
            printf("-1\n");

    }

    return 0;
}
