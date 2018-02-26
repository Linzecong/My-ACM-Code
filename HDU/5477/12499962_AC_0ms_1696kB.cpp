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
#include <queue>
using namespace std;
using namespace std;

typedef long long int ll;

int main()
{

    int T;
    scanf("%d", &T);
    int nc = 1;
    while (T--)
    {

        int n, A, B, L;
        scanf("%d%d%d%d", &n, &A, &B, &L);

        int a, b;
        vector<pair<int, int>> li;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            li.push_back(make_pair(a, b));
        }
        sort(li.begin(), li.end());

        int cur = 0;
        int s = 0;
        int ans = 10000000;
        for (int i = 0; i < n; i++)
        {
            for (int j = cur; j < li[i].first; j++)
                s += B;

            for (int j = li[i].first; j < li[i].second; j++)
            {
                s -= A;
                // printf("%d\n",s);
                ans = min(s, ans);
            }

            cur = li[i].second;
        }

        if (ans >= 0)
            printf("Case #%d: %d\n", nc++, 0);
        else
            printf("Case #%d: %d\n", nc++, -ans);
    }

    return 0;
}