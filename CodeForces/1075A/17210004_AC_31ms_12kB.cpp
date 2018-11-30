#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	long long n,x,y;
	scanf("%lld",&n);
	scanf("%lld%lld",&x,&y);
	if ((x-1)+(y-1)<=(n-x)+(n-y)){
		printf("White");
	}else{
		printf("Black");
	}
}