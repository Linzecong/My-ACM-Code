#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<bitset> 
using namespace std;
typedef long long int ll;

int main(){
	
	int n,a,b;
	cin>>n>>a>>b;
	
	int num=0;
	for(int i=1;i<n;i++){
		
			
		if(i!=0&&i!=n){
			int nn=a/i;
			int mm=b/(n-i);
			num=max(num,min(nn,mm));
		}

	}
	cout<<num<<endl;
	
	
	return 0;
} 


