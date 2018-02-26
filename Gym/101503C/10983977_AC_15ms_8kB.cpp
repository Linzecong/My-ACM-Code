#include<iostream>
#include<bitset>
using namespace std;
typedef long long int ll;
const ll INF=(1LL<<62);

int getHigh(ll x){
	for(int i=62;i>=0;i--){
		if(x&(1LL<<i))
		return i;
	}
}

ll get(ll n){
		ll minn=n;
    	ll temp=n;
    	int hb=getHigh(temp);
    	do{
    		bool h=((1LL<<hb)&temp);
    		
    		temp=temp&((1LL<<hb)-1);
    		temp<<=1;
    		temp|=h;
    		
    		bool hh=((1LL<<hb)&temp);
    		
    		if(temp<minn&&(hh))
    		   minn=temp;
    		   
		}while(n!=temp);
		return minn;
}



int main(){

	ll n;
	ll ans;
	
	cin>>n;
	
	ans=get(n);
	int pos=0;
	
	
	while(n){
		if(n&1){
			
			ll temp=get((n<<pos)-1);
			
			if(ans<temp)
			ans=temp;
			
		}
		n>>=1;
		pos++;
	}	
		
	cout<<ans<<endl;

	
	return 0;
}