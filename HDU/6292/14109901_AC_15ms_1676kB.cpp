#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005//求MAX范围内的素数  
typedef long long int ll;
const ll MOD=41234551;


int N,M;
int main(){
	
	int T;
	scanf("%d",&T);
	for(int qqq=1;qqq<=T;qqq++){
		printf("Problem %d:\n",1000+qqq);
		scanf("%d%d",&N,&M);
		int temp;
		int minn=0x3f3f3f3f;
		for(int i=1;i<=N;i++){
			scanf("%d",&temp);
			minn=min(temp,minn);
		}
		printf("Shortest judge solution: %d bytes.\n",minn);
			
		minn=0x3f3f3f3f;
		for(int i=1;i<=M;i++){
			scanf("%d",&temp);
			minn=min(temp,minn);
		}
		if(minn==0x3f3f3f3f)
		
		printf("Shortest team solution: N/A bytes.\n",minn);
		else
		printf("Shortest team solution: %d bytes.\n",minn);
		
	}

	return 0;
}













