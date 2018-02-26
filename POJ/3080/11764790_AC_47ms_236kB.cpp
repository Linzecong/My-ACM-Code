#include <iostream>
#include <deque>
#include <memory.h>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;
typedef long long int ll;

void getNext(char *a, int len, int *nxt)
{
    nxt[0] = nxt[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int j = nxt[i];
        while (j && a[i] != a[j])
            j = nxt[j];
        nxt[i + 1] = (a[i] == a[j]) ? j + 1 : 0;
    }
}

int KMP(char *a, char *b, int N, int M, int *nxt)
{
    int j = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        while (j && a[i] != b[j])
            j = nxt[j];
        if (a[i] == b[j])
            j++;

        if (j == M)
            ans++;
    }
    return ans;
}

char a[1000050]; //原始串
char b[15][100]; //模式串
int nxt[1000050];
int N, M;

int main()
{
    int t;
    scanf("%d", &t);

    for (int qqq = 1; qqq <= t; qqq++)
    {

        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%s", b[i]);
        }

        bool flag = 0;
        for (int len = 60; len >= 3; len--)
        {
            vector<string> ans;

            for (int i = 0; i + len <= 60; i++)
            {

                int j;
                for (j = 0; j < N; j++)
                {
                    getNext(b[0]+i, len, nxt);
                    
                    if (KMP(b[j], b[0]+i, 60, len, nxt) == 0)
                    {
                        break;
                    }
                }
                if (j == N)
                {
                    string str;
                    for (int k = 0; k < len; k++)
                    {
                        str.push_back(b[0][i + k]);
                    }
                    ans.push_back(str);
                }
            }
            if (!ans.empty() && flag == 0)
            {
                sort(ans.begin(), ans.end());
                cout << ans.front() << endl;
                flag = 1;
            }
        }
        if (flag == 0)
            printf("no significant commonalities\n");
    }

    return 0;
}