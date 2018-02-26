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

int a[1000006];

int b[1000006];

double c[1000006];

int mostsame1(int n)
{

    int now = 1;
    int most = 1;
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == b[i - 1]){
            now++;
            most = max(most, now);
        }
        else
        {
            most = max(most, now);
            now = 1;
        }
    }
    
    return most + 1;
}
int mostsame2(int n)
{

    int now = 1;
    int most = 1;
    for (int i = 2; i <= n; i++)
    {
        if (c[i] == c[i - 1]){
            now++;
            most = max(most, now);
        }
        else
        {
            most = max(most, now);
            now = 1;
        }
    }
    return most + 1;
}

int main()
{

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (n == 1)
        {
            printf("1\n");
            continue;
        }

        if (n == 0)
        {
            printf("0\n");
            continue;
        }

        b[0] = -1;
        for (int i = 1; i < n; i++){
            b[i] = a[i] - a[i - 1];
           // printf("%d ",b[i]);
        }
          //  printf("\n");

        c[0] = -1;
        for (int i = 1; i < n; i++){
            c[i] = (1.0 * a[i]) /( 1.0 * a[i - 1]);
           // printf("%lf ",c[i]);
        }
          //  printf("\n");

        printf("%d\n", max(mostsame1(n - 1), mostsame2(n - 1)));
    }

    return 0;
}