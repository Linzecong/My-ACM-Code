#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

double ffabs(double a)
{
    if (a < 0)
        return -a;
    return a;
}

double x[1005];

double y[1005];

int main()
{
    int N, R;
    scanf("%d%d", &N, &R);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &x[i]);
        y[i] = R;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ffabs(x[i] - x[j]) <= 2 * R)
            {
                double xx = sqrtf(4 * R * R - ffabs(x[i] - x[j]) * ffabs(x[i] - x[j]));
                y[i] = max(y[j] + xx, y[i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
        printf("%.10lf ", y[i]);

    return 0;
}