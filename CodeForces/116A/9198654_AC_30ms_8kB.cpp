#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<memory>
#include<math.h>
using namespace std;
typedef long long int ll;




int main ()
{

    int n;

    cin>>n;

    int ans=0;
    int cur=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        cur-=a;
        cur+=b;

        ans=max(cur,ans);



    }

    cout<<ans<<endl;


    return 0;
}
