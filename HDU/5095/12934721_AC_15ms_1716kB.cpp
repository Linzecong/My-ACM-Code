#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int maxn = 30005;
typedef long long int ll;

int main()
{
    int ttt = 0;
    scanf("%d", &ttt);
    for (int qqq = 1; qqq <= ttt; qqq++)
    {
        int temp;
        int have=0;
        for (int i = 0; i < 10; i++)
        {

            cin >> temp;
            if (temp == 0)
                continue;
            if (temp > 0 && i > 0&&have)
                cout << "+";
            
            if((temp!=1||i==9)&&temp>0)
            cout << temp;
            else{
                if(temp==-1)
                    cout<<"-";
                if(temp==-1&&i==9)
                cout<<"1";
                if(temp!=-1&&temp<0)
                cout<<temp;
            }
            
            have=1;
            if (i == 0)
                cout << "p";
            if (i == 1)
                cout << "q";
            if (i == 2)
                cout << "r";
            if (i == 3)
                cout << "u";
            if (i == 4)
                cout << "v";
            if (i == 5)
                cout << "w";
            if (i == 6)
                cout << "x";
            if (i == 7)
                cout << "y";
            if (i == 8)
                cout << "z";
        }
        if(have==0)
        cout<<0;
        cout << endl;
    }

    return 0;
}
