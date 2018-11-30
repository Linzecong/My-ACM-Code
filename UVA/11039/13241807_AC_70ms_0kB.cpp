#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;


bool cmp(int a,int b){
	return abs(a)<abs(b);
}

int a[500008];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		cin>>N;
		
		for(int i=0;i<N;i++){
			cin>>a[i];
		}
		sort(a,a+N,cmp);
		
		int ans=0;
		int col=(a[0]<0);
		col=1-col;
		for(int i=0;i<N;i++){
			if(col){
				if(a[i]>0){
					ans++;
					col=1-col;
				}
			}
			else{
				if(a[i]<0){
						ans++;
						col=1-col;
				}
				
			}
		}
		cout<<ans<<endl;
		
		
	}


    return 0;
}
