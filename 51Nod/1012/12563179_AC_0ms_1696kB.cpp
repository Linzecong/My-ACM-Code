#include<stdio.h> 
typedef long long ll;

int A,B;
/*
LCM(A,B) = |A*B| / GCD(A,B)
*/
int GCD(int a, int b){
	return b==0? a : GCD(b, a%b);
}

int main() {
	scanf("%d%d",&A,&B);
	printf("%lld\n",(A*((ll)B))/GCD(A,B));
	return 0;
}