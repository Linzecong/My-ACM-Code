#include<iostream>
using namespace std;

int main(){
	int n,u,d;
	
	while(1){
		
		cin>>n>>u>>d;
		
		if(n==0)
		break;
		
		
		int cur=0;
		int ms=0;
		
		while(cur<n){
			cur+=u;
			ms++;
			if(cur>=n)
			break;
			
			cur-=d;
			
			ms++;
		}
		
		cout<<ms<<endl;
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}