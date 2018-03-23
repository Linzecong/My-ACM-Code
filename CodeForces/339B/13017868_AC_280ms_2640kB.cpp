#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long int ll;

ll m[100005];

int main(){
   
    
    ll N,M;
    cin>>N>>M;
    for(ll i=1;i<=M;i++)
        cin>>m[i];
    
    ll ans=0;
    ll cur=1;
    for(ll i=1;i<=M;i++){
        if(m[i]>=cur){
            ans=ans+m[i]-cur;
            cur=m[i];
        }
        else{
            ans=ans+N-cur+m[i];
            cur=m[i];
        }
    }
    cout<<ans<<endl;


    return 0;
}


