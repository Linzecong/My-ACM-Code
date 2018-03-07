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

const int MAXN = 500005;
int num[MAXN];
int N;

int main()
{
    cin >> N;
    int o = 0, t = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        if (num[i] == 1)
            o++;
        else
            t++;
    }

    int yu = o % 3;
    int ans = o / 3;

    cout << max(ans + min(yu, t), (o >= t ? t+((o-t)/3) : o)) << endl;

    return 0;
}
