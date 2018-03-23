#include<iostream>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
    return (b>0)?gcd(b,a%b):a;
}
int main(){
	
	ll n;
	cin>>n;
	while(n--){
		ll a,b;
		cin>>a>>b;

			if(gcd(a,b)==1)
			cout<<"Nao"<<endl;
			else
			cout<<"Sim"<<endl;
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}