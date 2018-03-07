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

    int N;

    while (cin >> N)
    {
        vector<int> a, b;
        int asum = 0, bsum = 0;

        if (N % 2 == 1)
        {
            int flag=0;
            for (int i = N; i >= 3; i -= 2)
            {
                if (flag)
                {
                    a.push_back(i);
                    asum += i;
                    b.push_back(i - 1);
                    bsum += i - 1;
                }
                else{
                    b.push_back(i);
                    bsum += i;
                    a.push_back(i - 1);
                    asum += i - 1;
                }
                flag=1-flag;
            }
            
            cout << abs(abs(asum - bsum) - 1) << endl;
            if (asum > bsum)
            {
                cout << a.size() << " ";
                for (int i = 0; i < a.size(); i++)
                    cout << a[i] << " ";
                cout << endl;
            }
            else
            {
                cout << b.size() << " ";
                for (int i = 0; i < b.size(); i++)
                    cout << b[i] << " ";
                cout << endl;
            }
        }
        else
        {
            int flag=0;
            for (int i = N; i >= 2; i -= 2)
            {
                if (flag)
                {
                    a.push_back(i);
                    asum += i;
                    b.push_back(i - 1);
                    bsum += i - 1;
                }
                else{
                    b.push_back(i);
                    bsum += i;
                    a.push_back(i - 1);
                    asum += i - 1;
                }
                flag=1-flag;
            }
            cout << abs(asum - bsum) << endl;

            cout << b.size() << " ";
            for (int i = 0; i < b.size(); i++)
                cout << b[i] << " ";
            cout << endl;
        }
    }
    return 0;
}


