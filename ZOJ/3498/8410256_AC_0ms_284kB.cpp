#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

long long int func(long long int a){
    if(a/2>=1)
        return 1+func(a/2);
    else
        return 1;
}




int main()
{


    long long int i;
    cin>>i;

    while(i--){
       long long  int n;
        cin>>n;

        if(n==1)
            cout<<1<<endl;
        else
        cout<<func(n)<<endl;
    }


    return 0;
}