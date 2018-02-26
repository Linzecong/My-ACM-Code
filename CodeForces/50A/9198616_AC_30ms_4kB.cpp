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
    int n,m;
    cin>>n>>m;

    if(m%2==0)
        cout<<n*(m/2)<<endl;
    else{


        cout<<n*(m/2)+n/2<<endl;



    }




    return 0;
}
