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

int main()
{
    int t, s, x;
    while (cin >> t >> s >> x)
    {

        if(x<t){
            cout<<"NO"<<endl;
            continue;
        }

        if (x - 1 == t)
        {
            cout << "NO" << endl;
            continue;
        }
        if ((x - t) % s == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        if ((x - 1 - t) % s == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}
