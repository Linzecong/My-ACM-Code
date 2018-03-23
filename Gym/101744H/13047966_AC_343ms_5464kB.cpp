#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;



int main(){

	int n;
	cin>>n;
	vector<ll> floor,foot,chain;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		floor.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		foot.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		chain.push_back(temp);
	}
	
	
	ll fdis=0;
	for(int i=0;i<n;i++){
		fdis+=(foot[i]-floor[i])*(foot[i]-floor[i]);
	}
	ll cdis=0;
	for(int i=0;i<n;i++){
		cdis+=(chain[i]-floor[i])*(chain[i]-floor[i]);
	}
	
	if(fdis<=cdis)
	cout<<"Yan"<<endl;
	else
	cout<<"MaratonIME"<<endl;
	
	
	return 0;
}

