#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;

string str[1005];
int ccc[255];

int main()
{
	int a,b;
	int N,M;
	
	int T;
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0;i<N;i++)
			cin>>str[i];
		
		string ans;
		int num=0;
		
		for(int j=0;j<M;j++){
			for(int i=0;i<255;i++)
				ccc[i]=0;
				
			for(int i=0;i<N;i++){
				ccc[str[i][j]]++;
			}
			
			int ii=0;
			int nn=0;
			for(int i=0;i<255;i++){
				if(ccc[i]>nn){
					ii=i;
					nn=ccc[i];
				}
			}
			
			ans.push_back(ii);
			num+=N-ccc[ii];
			
			
		}
		cout<<ans<<endl;
		cout<<num<<endl;	
		
	}


    return 0;
}
