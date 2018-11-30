#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long ll;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;

char maze[MAXN][MAXN];
int G[MAXN][MAXN];
int node;
int num[MAXN][MAXN][2];

int used[MAXN];
int Y[MAXN];

bool hungry(int x){
    for(int i=1;i<=node;i++){
        if(G[x][i]&&!used[i]){
            used[i]=1;
            if(Y[i]==0||hungry(Y[i])){
                Y[i]=x;
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
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", maze[i]);
        }
        memset(G, 0, sizeof(G));
        node = 1;
        memset(num, 0, sizeof(num));
        memset(Y, 0, sizeof(Y));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (maze[i][j] == 'X')
                    node++;
                else
                    num[i][j][0] = node;
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
            for (int j = 0; j < N; j++)
                if (num[i][j][0] != 0 && num[i][j][1] != 0) //如果有相交
                {
                    G[num[i][j][0]][num[i][j][1]] = 1; //连线
                }
        }
        int ans = 0;
        for (int i = 1; i <= node; i++)
        {
            memset(used, 0, sizeof(used));
            if (hungry(i))
                ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
