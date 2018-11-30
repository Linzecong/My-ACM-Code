#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e6+10;
int a[MAX_N];
int n,d,t,cnt;
int main(){
	scanf("%d",&t);
	while(t--){
		cnt=0;
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
			cnt+=(a[i]==1);
		}
		if(d==1){
			if(n%3==0&&cnt==n){
				puts("No");
				continue;
			}
			puts("Yes");
		}
		else{
			if((cnt==n&&n%3==1)||(cnt==n-1&&n%3==1)||(cnt==n-1&&n%3==0))
			{
				puts("No");
				continue;
			}
			puts("Yes");
		}
	}
	return 0;
}