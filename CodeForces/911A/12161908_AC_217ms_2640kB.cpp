#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<math.h> 
using namespace std;

pair<int,int> a[100005];

int main(){
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	} 
	
	sort(a,a+n);
	
	if(a[0].first!=a[1].first){
		cout<<abs(a[0].second-a[1].second)<<endl;
	}
	else{
		int minn=10000000;
		for(int i=1;a[i].first==a[i-1].first;i++){
			minn=min(minn,abs(a[i].second-a[i-1].second));
		}
		cout<<minn<<endl;
	}
	
	
	return 0;
} 