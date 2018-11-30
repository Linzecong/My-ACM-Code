#include<iostream>
using namespace std;

int main(){
	
	int A,B,C;
	int A1,B1,C1;
	cin>>A>>B>>C>>A1>>B1>>C1;
	int ans=0;
	if(A1>A)
		ans+=A1-A;
	if(B1>B)
		ans+=B1-B;
	if(C1>C)
		ans+=C1-C;
	
	cout<<ans<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}