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

struct man
{
    string name;
    int gift;
    int time;
    man(string a, int b, int c)
    {
        name = a;
        gift = b;
        time = c;
    }
    friend bool operator<(man a, man b)
    {
        if (a.gift == b.gift)
            return a.time > b.time;
        return a.gift < b.gift;
    }
};

char str[300];
main()
{

    int T;
    scanf("%d", &T);
    while (T--)
    {

        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        queue<man> list;

        int g;
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d", str, &g);
            list.push(man(str, g, i));
        }

        int a, b;
        priority_queue<man> que;

        vector<pair<int, int>> li;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            li.push_back(make_pair(a, b));
        }
        li.push_back(make_pair(n, n));
        sort(li.begin(), li.end());

        vector<string> ans;
        int last = 0;
        for (int i = 0; i < li.size(); i++)
        {
            for (int j = last; j < li[i].first; j++)
            {
                que.push(list.front());
                list.pop();
            }

            last = li[i].first;
            if (li[i].second > que.size())
                li[i].second = que.size();

            for (int j = 0; j < li[i].second; j++)
            {
                ans.push_back(que.top().name);
                que.pop();
            }
        }

        // while (!list.empty())
        // {
        //     que.push(list.front());
        //     list.pop();
        // }

        // while (!que.empty())
        // {
        //     ans.push_back(que.top().name);
        //     que.pop();
        // }

        for (int i = 0; i < q - 1; i++)
        {
            scanf("%d", &a);
            cout << ans[a - 1] << " ";
        }
        scanf("%d", &a);
        cout << ans[a - 1] << endl;
    }

    return 0;
}