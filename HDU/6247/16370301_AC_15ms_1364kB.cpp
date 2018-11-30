#include<iostream>
using namespace std;

int main(){
	
	int T;
	scanf("%d",&T);
	for(int ttt=1;ttt<=T;ttt++){
		
		int tmp;
		int N;
		int ans=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d",&tmp);
			
			ans+=tmp/10+(tmp%10!=0);
			ans+=tmp;
		}
		printf("Case #%d: %d\n",ttt,ans);
		
		
		
	}
	
	
	
	
	
	
	
	
	return 0;
}










