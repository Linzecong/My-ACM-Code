#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;


int main()
{
	int N;
	int ttt=1;
	while(cin>>N){
		if(N<0)
			break;
		
		int ans=0;
		int num=1;
		while(num<N){
			ans++;
			num*=2;
		}
		
		printf("Case %d: %d\n",ttt++,ans);
	}


    return 0;
}
