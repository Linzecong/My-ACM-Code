#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long int ll;

int N;
char ans[100005];
int main()
{

    scanf("%d", &N);
    ans[0] = 'a';
    ans[1] = 'b';
    ans[2] = 'c';
    for (int i = 3; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ans[i / 2] != 'a' + j && ans[i - 1] != 'a' + j)
            {
                ans[i] = 'a' + j;
            }
        }
    }
    printf("%s\n", ans);

    return 0;
}
