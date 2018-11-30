#include<stdio.h> 

int A,B;

/*
GCD(x,0) = x
GCD(x,y) = GCD(y, x%y)
*/
int GCD(int a, int b){
	while(b != 0) {
		int t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int main() {
	scanf("%d%d",&A,&B);
	printf("%d\n",GCD(A,B));
	return 0;
}