#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<bitset> 
using namespace std;
typedef long long int ll;

int main(){
	
	
	ll n,k;
	cin>>n>>k;
	
	if(k==1)
		cout<<n<<endl;
	else{
		int num=0;
		while(n){
			n/=2;
			num++;
		}
		cout<<(1ll<<num)-1<<endl;	
	}
	
	
	
	return 0;
} 


