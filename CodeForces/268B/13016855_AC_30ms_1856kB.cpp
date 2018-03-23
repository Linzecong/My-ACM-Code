#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long int ll;

int main(){
   
    ll n;
    cin>>n;

    ll num=0;
    
    for(ll i=1;i<=n;i++){

            num+=(n-i)*i+1;

    }

    cout<<num<<endl;


    return 0;
}


