#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

const int maxn = 30005;
typedef long long int ll;

int num[30005];
int a[30005];

vector<int> need[30005];

int cnt = 1;
bool vis[30005];
int Y[30005];
bool hungry(int x)
{
    for (int i = 0; i < need[x].size(); i++)
    {
        if (!vis[need[x][i]])
        {
            vis[need[x][i]] = 1;
            if (Y[need[x][i]] == 0 || hungry(Y[need[x][i]]))
            {
                Y[need[x][i]] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int ttt = 0;
    scanf("%d", &ttt);
    for (int qqq = 1; qqq <= ttt; qqq++)
    {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < 30005; i++)
            need[i].clear();

        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            num[a[i]]++;
            for (int j = a[i]; j <= N; j+=K)
            {
                need[j].push_back(a[i]+num[a[i]]*100);
            }
        }

        memset(Y, 0, sizeof(Y));
        cnt=0;
        for (int i = 1; i <= N; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (hungry(i))
                cnt++;
        }

        if (cnt == N)
            cout << "Jerry" << endl;
        else
            cout << "Tom" << endl;
    }

    return 0;
}
