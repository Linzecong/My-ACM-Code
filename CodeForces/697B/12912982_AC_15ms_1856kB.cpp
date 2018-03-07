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

    string temp;
    while (cin >> temp)
    {
        string a, d, b;
        int flag = 0;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == '.')
            {
                flag = 1;
                continue;
            }

            if (temp[i] == 'e')
            {
                flag = 2;
                continue;
            }

            if (flag == 0)
                a.push_back(temp[i]);
            if (flag == 1)
                d.push_back(temp[i]);
            if (flag == 2)
                b.push_back(temp[i]);
        }

        int len = stoi(b);

        cout << a;
        int ii=0;
        for (ii = 0; ii < len; ii++)
        {
            if (ii < d.length())
                cout << d[ii];
            else
                cout << 0;
        }
        if (ii != len)
        {
            cout << '.';
            for (ii; ii < d.length(); ii++)
                cout << d[ii];
        }
        else
        {
            if (len == 0)
            {
                if(d.length()==1&&d[0]=='0'){
                    cout<<endl;
                    continue;
                }
                cout << '.';
                cout << d;
            }
            else
            {
                if (len != d.length()&&d.length()>len)
                    cout << '.';
                for (ii; ii < d.length(); ii++)
                    cout << d[ii];
            }
        }

        cout << endl;
    }

    return 0;
}
