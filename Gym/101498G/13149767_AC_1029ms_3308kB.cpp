#include <stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
const int MX = 2e3 + 5; 
typedef long long ll;
const ll maxx=2000*1e9;
ll sum[MX],a[MX];
ll gcd(ll a, ll b)
 {  
    return b == 0 ? a : gcd(b, a % b);  
}  
  
ll lcm(ll a, ll b)
{  
    return a/gcd(a, b)*b;  
}  

int main()
{
	int t,n;cin>>t;
	
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++){
	  scanf("%I64d", &a[i]); 
		}
	sum[0]=0;	
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	
	for(int i=1;i<=n;i++)
	{
		ll te=a[i];
		for(int j=i;j<=n;j++){
			te=lcm(te,a[j]);
			if(te>maxx)break;
			if((sum[j]-sum[i-1])%te==0)ans++;
		}
	}
         printf("%I64d\n", ans); 
	}
	
	
	return 0;
}