#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

ll A[200005];
ll B[200005];


int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
	}
	
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++){
		B[i]=A[i]+A[i-1];
	}
	
	bool flag=0;
	
	for(int i=2;i<n;i++){
		if(B[i]>A[i+1]){
			flag=1;
			break;
		}
		
	}
	
	if(flag)
	cout<<"possible"<<endl;
	else
	cout<<"impossible"<<endl;
	
	
	
	
	
	
	return 0;
}