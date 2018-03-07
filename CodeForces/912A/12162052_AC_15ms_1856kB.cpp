#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<math.h> 
using namespace std;
typedef long long int ll;

int main(){
	
	ll yn,bn;
	cin>>yn>>bn;
	
	ll a,b,c;
	cin>>a>>b>>c;
	
	ll y1=a*2+b;
	ll b1=c*3+b;
	
	ll ny=0,nb=0;
	if(y1-yn<0)
		ny=0;
	else
		ny=y1-yn;
		
	if(b1-bn<0)
		nb=0;
	else
		nb=b1-bn;	
	
	cout<<nb+ny<<endl;

	
	return 0;
} 