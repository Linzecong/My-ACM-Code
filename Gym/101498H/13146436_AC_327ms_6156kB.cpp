#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;


int main(){

	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		cin>>n>>k;
		string ans;
		
		
		
		bool yes=1;
		
		
		
		if(k==1&&n!=1)
			yes=0;
		
		
		
		if(n%2==0){
			if(k%2)
				yes=0;
			else{
				
			
			int sum=k/2;
			
			int key=0;
			int nn=0;
			
			while(nn<n/2){
				
				if(sum>=9){
					ans.push_back('9');
					sum-=9;
				}
				else{
					ans.push_back('0'+sum);
					sum=0;
				}
				nn++;
			}
			
			int len=ans.length()-1;
			for(int j=len;j>=0;j--)
			ans.push_back(ans[j]);
			}
		}
		else{
			
					
				
			int sum=k/2;
			
			int key=0;
			int nn=0;
			
			while(nn<n/2){
				
				if(sum>=9){
					ans.push_back('9');
					sum-=9;
				}
				else{
					ans.push_back('0'+sum);
					sum=0;
				}
				nn++;
			}
			
			int len=ans.length()-1;
			
			int sss=0;
			for(int i=0;i<ans.length();i++)
				sss+=ans[i]-'0';
			
			ans.push_back('0'+k-sss*2);
			for(int j=len;j>=0;j--)
			ans.push_back(ans[j]);
			
		
			
		
		
		
		}
		
		if(yes){
			int sum=0;
			for(int i=0;i<ans.length();i++)
			if(ans[i]-'0'>9)
			sum=-0x3f3f3f3f;
			else
				sum+=ans[i]-'0';
			
			if(sum!=k)
			cout<<-1<<endl;
			else
			
			cout<<ans<<endl;
		}
		
		else
		cout<<-1<<endl;
		
	}

	
	return 0;
}