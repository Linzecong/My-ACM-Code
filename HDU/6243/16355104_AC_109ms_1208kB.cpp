#include<stdio.h>
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		printf("Case #%d: %d.0000\n",ca++,N-1);
	}
	return 0;
}
