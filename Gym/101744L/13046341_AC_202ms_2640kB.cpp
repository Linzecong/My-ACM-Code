#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long int ll;

int n;
pair<int,int> a[100005];
int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
		
	
	sort(a,a+n);
	
	if(n==1)
	cout<<1<<endl;
	else{
		if(a[n-1].first==a[n-2].first)
	cout<<-1<<endl;
	else
	cout<<a[n-1].second+1<<endl;
	}
	

	
	return 0;
}