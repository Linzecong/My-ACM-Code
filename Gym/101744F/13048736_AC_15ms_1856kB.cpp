#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;



int main(){

	double n,m,k;
	while(cin>>n>>m>>k){
	
	
//	(k+ans)/n=0.7
	
	int num=(n*0.7)-k;
	
	if(n*0.7)
	
	if(num<0){
		cout<<0<<endl;
		cout<<int((n-m+k)/n*100)<<endl;
	}
	else{
		if(n*0.7-int(n*0.7)>0.000001)
			num++;
	
//	cout<<num<<endl;
	int p=int((n-m+k)/n*100);
	
	if(p>=70)
	cout<<num<<endl;
	else
	cout<<-1<<endl;
//	printf("%.0f",(n-m+k)/n*100);
	cout<<int((n-m+k)/n*100)<<endl;
	}
	
}
	
	return 0;
}

