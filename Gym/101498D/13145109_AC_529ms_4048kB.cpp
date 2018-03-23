#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;

ll f[100005];

ll mpow(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a) % c;
        b /= 2;
        a = (a * a) % c;
    }
    return ans;
}

//乘法逆元，即将一个除数变为乘数，就是求倒数
ll inv(ll a, ll mod)
{

    return mpow(a,mod-2,mod);//mod是质数才能用
}

int main(){

	f[0]=1;
	for(int i=1;i<=100002;i++)
		f[i]=f[i-1]*i%MOD;
	
	
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,b;
		cin>>a>>b;
		
		ll ans=2*f[a-1]*inv(f[b]*f[a-1-b]%MOD,MOD)%MOD;
		cout<<ans<<endl;
		
	}

	
	return 0;
}