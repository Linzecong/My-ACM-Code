#include<iostream>
#include<math.h>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	while(t--){
	double a,b;
	cin>>a>>b;
	
	if(b>=a)
	printf("%.6lf\n",0);
	else
	
	printf("%.6lf\n",1+log(a)/log(2.718281828459)-log(b)/log(2.718281828459));
	
	
	
	
	}
	
	
	
	return 0;
}