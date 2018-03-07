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

int indegree[105];

int main()
{

    int N;

    while (~scanf("%d", &N))
    {
        memset(indegree, 0, sizeof(indegree));
        vector<int> ch[105];
        for (int i = 1; i <= N; i++)
        {
            int temp;
            while (~scanf("%d", &temp))
            {
                if (temp == 0)
                    break;
                indegree[temp]++;
                ch[i].push_back(temp);
            }
        }

        for (int k = 1; k <= N; k++)
        {

            for (int i = 1; i <= N; i++)
            {
                if (indegree[i] == 0)
                {
                    if (k == N)
                        cout << i << endl;
                    else
                        cout << i << " ";
                    indegree[i] = -1;
                    for (int j = 0; j < ch[i].size(); j++)
                    {
                        indegree[ch[i][j]]--;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
