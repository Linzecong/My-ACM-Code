#include<bits/stdc++.h>
using namespace std;


int main(){
	

	int T;
	int N;
	while(~scanf("%d",&T)){
		while(T--){
			scanf("%d",&N);
			int sum=0;
			int temp;
			bool flag=0;
			for(int i=0;i<N;i++){
				scanf("%d",&temp);
				sum+=temp;
				if(temp>(N-1)*2)
					flag=1;
			}
			if(sum==2*((N-1)*(N)/2)&&flag==0)
				printf("T\n");
			else
				printf("F\n");
		}
	}
	
	return 0;
}