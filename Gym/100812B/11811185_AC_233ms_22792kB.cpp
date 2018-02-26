#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <bitset>
#include <map>
using namespace std;
typedef long long int ll;
int N, M;

map<string, int> snum;

int main()
{

    ios::sync_with_stdio(false);
    cin >> N >> M;
    string ans;
    string temp;

    int num = 0;

    for (int i = 0; i < N; i++)
    {

        cin >> temp;

        int ones = 0;
        for (int i = 0; i < temp.size(); i++)
            if (temp[i] == '1')
                ones++;

        if (8 <= ones && ones <= 15)
        {
            if (++snum[temp] > num)
            {
                num = snum[temp];
                ans = temp;
            }
        }
    }

    if (ans == "")
    {
        ans.resize(M, '0');
        for (int i = 0; i < 8; i++)
            ans[i] = '1';
    }

    cout << ans << endl;

    return 0;
}
