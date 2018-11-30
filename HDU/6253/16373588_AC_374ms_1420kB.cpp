#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e5+10;
int ans[11]={1, 9, 41, 109, 205, 325, 473, 649, 853, 1085, 1345};
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		unsigned long long n;
		cin>>n;
		cout<<"Case #"<<i<<": ";
		if(n<=10){
			cout<<ans[n]<<'\n';
		}else{
			cout<<n*n*14-6*n+5<<'\n';
		}
	}
	return 0;
}