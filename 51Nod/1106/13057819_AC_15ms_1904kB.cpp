#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
typedef long long int ll;

ll gcd(ll a,ll b){
    ll c=a%b;
    while(c){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

ll mpow(ll a,ll b,ll c){
    ll ans=1;
    a=a%c;
    while(b>0){
        if(b%2)ans=(ans*a)%c;
        b/=2;
        a=(a*a)%c;
    }
    return ans;
}

ll mmul(ll a,ll b,ll c){
    ll ans=0;
    a=a%c;
    while(b>0){
        if(b%2)ans=(ans+a)%c;
        b/=2;
        a=(a+a)%c;
    }
    return ans;
}

const int MAXP=100007;
int prime[MAXP];
bool check[MAXP];
int tot=0;
void getprime(){
    memset(check,0,sizeof(check));
    for(int i=2;i<=MAXP;i++){
        if(!check[i])
            prime[tot++]=i;
        for(int j=0;j<tot;j++){
            if(i*prime[j]>MAXP)
                break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}


bool MillerRabintest(ll n,ll a,ll d)
{
    if(n==2) return true;
    if(n==a) return false;
    if(!(n&1)) return false;
    while(!(d&1)) d>>=1;
    ll t = mpow(a,d,n);
    while(d!=n-1&&t!=n-1&&t!=1){
        t = t*t%n;//下面介绍防止溢出的办法，对应数据量为10^18次方；
        d<<=1;
    }
    return t == n-1||(d&1)==1;//要么t能变成n-1，要么一开始t就等于1
}

bool isprime(ll n)
{
    int a[] = {2,3,5,7};//或者自己生成[2,N-1]以内的随机数rand（）%（n-2）+2
    for(int i = 0; i <= 3; ++i){
        if(n==a[i]) return true;
        if(!MillerRabintest(n,a[i],n-1)) return false;
    }
    return true;
}

int main()
{
    
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(isprime(a))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}
