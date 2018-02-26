#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i > 0; i--)
    {
        if (a[i] < i)
        {
            printf("%d\n", i);
            flag = true;
            break;
        }
    }
    if (flag == false)
        printf("0\n");
}