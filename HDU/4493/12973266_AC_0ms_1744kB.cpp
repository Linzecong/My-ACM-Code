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

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double sum = 0;
        double temp = 0;
        for (int i = 0; i < 12; i++)
        {
            cin >> temp;
            sum += temp;
        }

        sum /= 12;

        int a = (sum + 0.005) * 100;

        if (a % 100 == 0)
        {
            printf("$%.0f\n", sum);
        }
        else if (a % 10 == 0)
            printf("$%.1f\n", sum);
        else
            printf("$%.2f\n", sum);
    }

    return 0;
}
