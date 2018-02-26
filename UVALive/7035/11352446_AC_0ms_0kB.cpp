#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;

int main(){

    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;

    for(int qqq=1;qqq<=t;qqq++){

        cin>>n;
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            if(temp%3!=0)
                flag=0;
        }

        if(flag)
            printf("Case #%d: Yes\n",qqq);
        else
            printf("Case #%d: No\n",qqq);
    }

    return 0;
}


