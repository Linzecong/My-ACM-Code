#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{

    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            int temp;
            cin>>temp;

            if(temp==1)
                cout<<abs(i-3)+abs(j-3)<<endl;
        }

    return 0;
}
