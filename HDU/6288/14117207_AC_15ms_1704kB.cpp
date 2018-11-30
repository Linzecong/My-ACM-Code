#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

ll poww(ll a,ll b){
    ll ans=1,base=a;
    while(b!=0){
        if(b&1!=0)
            ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}

ll log2(ll x){
    for(int i=0;i<=64;i++){
        if(poww(2,i)>=x)
            return i;
    }
}

ll a,b,k;
bool judge(ll m){

    ll temp1=1;
    for(int i=0;i<a;i++)
    {
        if(temp1<k/m)
            temp1*=m;
        else
            return false;
    }
    ll temp2=1;
    ll y=log2(m);
    if(y==0){
        return true;
    }
    for(int i=0;i<b;i++)
    {
        if(temp2<=k/y)
            temp2*=y;
        else
            return false;
    }

    if(temp1<=k/temp2)
        return true;
    else
        return false;

}


int main(){

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){


        scanf("%llu%llu%llu",&a,&b,&k);

        ll l=1,r=1000000000000000000LL;
        ll m;
        while(l<=r){
            m=(l+r)/2;

            if(judge(m))
                l=m+1;
            else
                r=m-1;
        }

        cout<<r<<endl;

    }

    return 0;
}








