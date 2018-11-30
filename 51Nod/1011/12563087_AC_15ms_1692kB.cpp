#include<stdio.h> 

int A,B;

/*
GCD(x,0) = x
GCD(x,y) = GCD(y, x%y)
*/
int GCD(int a, int b){
	return b==0? a : GCD(b, a%b);
}

int main() {
	scanf("%d%d",&A,&B);
	printf("%d\n",GCD(A,B));
	return 0;
}