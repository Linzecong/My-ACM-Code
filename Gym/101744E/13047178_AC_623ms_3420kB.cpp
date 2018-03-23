#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;

ll sum[100005];
ll a[100005];

int main(){


	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int l,r;
	for(int i=0;i<m;i++){
		cin>>l>>r;
		
		if((sum[r]-sum[l-1])%2)
		cout<<"Nao"<<endl;
		else
		cout<<"Sim"<<endl;
	}
		
	
	return 0;
}

